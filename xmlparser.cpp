#include "xmlparser.h"
#include "ui_xmlparser.h"

XMLParser::XMLParser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XMLParser) {
    ui->setupUi(this);
    menu = new QMenu("&Menu");
    menu->addAction("&Open File", this, SLOT(OpenFile()), Qt::CTRL + Qt::Key_O);
    menu->addAction("&Close All", this, SLOT(Close()), Qt::CTRL + Qt::Key_C);
    menu->addSeparator();
    menu->addAction("&Execute XQuery", this, SLOT(XQuery()), Qt::CTRL + Qt::Key_E);
    menu->addSeparator();
    menu->addAction("&Exit", this, SLOT(Exit()), Qt::CTRL + Qt::Key_Q);
    ui->menuBar->addMenu(menu);
    model = new QStandardItemModel(this);
    treeView = ui->treeView;
    treeView->setModel(model);
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(XQuery()));
}

XMLParser::~XMLParser() {
    delete ui;
}

void XMLParser::OpenFile() {
    QString file_path = QFileDialog::getOpenFileName(this, tr("Open file"), tr("C://"), tr("XML File (*.xml)"));
    LoadXML(file_path);
}

void XMLParser::Exit() {
    this->close();
}

void XMLParser::Close() {
    model->clear();
}

void XMLParser::XQuery() {
    QString file_path = QFileDialog::getOpenFileName(this, tr("Open file"), tr("C://"), tr("XML File (*.xml)"));
    QFile xmlFile(file_path);
    if(xmlFile.open(QIODevice::ReadOnly)) {
        QXmlQuery query;
        query.bindVariable("inputDocument", &xmlFile);
        query.setQuery(ui->textEdit->toPlainText());
        QString strOutput;
        if(!query.evaluateTo(&strOutput)) {
            QMessageBox::information(this, "Error!", "Failed to execute query");
        }
        else {
            QTextEdit* query_result = new QTextEdit;
            query_result->setText(strOutput);
            query_result->show();
        }
        xmlFile.close();
    }
}

void XMLParser::LoadXML(const QString &path) {
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(this, "Error!", "Failed to open file!");
        return;
    }
    Close();
    QDomDocument XMLReader;
    XMLReader.setContent(&file);
    QDomNode domNode = XMLReader.documentElement();
    NodeBuild(domNode, model->invisibleRootItem(), "");
}

void XMLParser::NodeBuild(const QDomNode &node, QStandardItem *parentItem, const QString& text_p) {
    QDomNode domNode = node.firstChild();
    QStandardItem *item;
    while(!domNode.isNull() && item != nullptr) {
        QDomElement domElement = domNode.toElement();
        QString text = domElement.text();
        QString tag = domElement.tagName();
        if(domNode.isElement()) {
            if(!domElement.isNull()) {
                item = new QStandardItem(QString(tag));
                parentItem->appendRow(item);
            }
        } else {
            item = new QStandardItem(QString(text_p));
            parentItem->appendRow(item);
        }
        NodeBuild(domNode, item, text);
        domNode = domNode.nextSibling();
    }
}
