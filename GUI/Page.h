//
// Created by danium on 25/9/19.
//

#ifndef HELLOWORLD_PAGE_H
#define HELLOWORLD_PAGE_H


#include <QtWidgets/QWidget>
#include <QGridLayout>

class Page : public QWidget {

    QGridLayout *grid = new QGridLayout();
    std::string array[9];

    void CSVparser(int pag);
    void screenHandler();

public:
    Page(QWidget *parent=0);
};


#endif //HELLOWORLD_PAGE_H
