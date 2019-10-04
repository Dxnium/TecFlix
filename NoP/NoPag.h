//
// Created by danium on 4/10/19.
//


#ifndef HELLOWORLD_NOPAG_H
#define HELLOWORLD_NOPAG_H

#include <QWidget>
#include <QGridLayout>
#include <QtWidgets/QScrollArea>

class NoPag : public QWidget {
public:
    NoPag(QWidget *parent = 0);
    QGridLayout *grid = new QGridLayout();
    QScrollArea *scroll = new QScrollArea();
    std::string array[9];

    QWidget *widget = new QWidget();
    QGridLayout *grid_scroll = new QGridLayout();

    void CSVparser(int pag);
    void loadAll();
};


#endif //HELLOWORLD_NOPAG_H
