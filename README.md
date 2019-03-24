# XMLparser
Использование XML и модели-представления Qt
*Разработать программу, производящую отображение XML-файлов в виде иерархической таблицы

Основные требования:

1. xml-Файлы данных брать с Портала открытых данных Правительства Москвы (http://data.mos.ru). Скачать не менее четырех xml-файлов, например, данные по кафе, кофейням, барам и предприятиям быстрого обслуживания.

1. Программа должна предоставлять меню (QMenu), содержащее следующие пункты:

Файл:

Открыть (загрузка xml-файла данных)

Закрыть все (Очистить область вывода данных)

Выход (Закрыть программу)

2. Для открытия файлов использовать стандартное диалоговое окно выбора файлов (QFileDialog).

3. После открытия файла должен производиться его парсинг средствами Qt (на основе DOM или SAX).

4. Данные xml-файла должны добавляться в QTreeView, элементами которого являются подтаблицы.

6. Предусмотреть поле ввода XQuery-запросов и кнопку «Выполнить». Предоставить возможность загрузить запрос в поле из xq-файла (через кнопку «Загрузить»). Результаты выполнения запросов выводить в отдельном окне с аналогичной древовидной структурой.

7. Ошибки парсинга обрабатывать выводом окна критических сообщений.
