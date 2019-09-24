//
// Created by danium on 23/9/19.
//

#ifndef HELLOWORLD_NORMAL_H
#define HELLOWORLD_NORMAL_H

#include <QWidget>
#include <iostream>
#include <QtWidgets/QGridLayout>
#include <QSpinBox>
#include "Box.h"

using namespace std;
class Normal : public QWidget {
public:
    int index=1;

    Normal(QWidget *parent = 0);
    QGridLayout *grid = new QGridLayout();;
    void CSVparser(int pag);
    string array[9];




    QSpinBox *spinBox;


    void Next();
    void screenHandler();
};


#endif //HELLOWORLD_NORMAL_H
