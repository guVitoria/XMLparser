#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QMainWindow>

#include <QStandardItemModel>
#include <QTreeView>
#include <QFileDialog>
#include <QMenu>
#include <QFile>
#include <QtXml/qdom.h>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QDomNode>
#include <QMessageBox>
#include <QtXmlPatterns/QXmlQuery>
#include <QTextEdit>

namespace Ui {
class XMLParser;
}

class XMLParser : public QMainWindow {
    Q_OBJECT

public:
    explicit XMLParser(QWidget *parent = nullptr);
    ~XMLParser();

private:
    Ui::XMLParser *ui;
    QStandardItemModel *model;
    QTreeView *treeView;
    QMenu *menu;

    void LoadXML(const QString &path);
    void NodeBuild(const QDomNode &node, QStandardItem *parentItem, const QString& text_p);
private slots:

    void OpenFile();
    void Close();
    void XQuery();
    void Exit();
};

#endif // XMLPARSER_H
