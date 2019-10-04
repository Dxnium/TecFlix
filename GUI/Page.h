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
    Page(int page,QWidget *parent=0);
    Page(int page,bool img,QWidget *parent=0);
    void screenHandler_noIMG();
};




#endif //HELLOWORLD_PAGE_H
