//
// Created by danium on 30/8/19.
//

#ifndef HELLOWORLD_BUTTON_H
#define HELLOWORLD_BUTTON_H

#include <QApplication>
#include <QPushButton>
#include <QFrame>
#include <QGridLayout>


class Button : public QFrame {

public:
    Button(QWidget *parent = 0);

private slots:
   void addButton(){
       QPushButton *btn = new QPushButton("Click me ",this);
       btn->setGeometry(50,50,200,50);
    }
};

Button::Button(QWidget *parent) : QFrame(parent){
    QPushButton *btn = new QPushButton("Click me ",this);
    btn->setGeometry(50,50,200,50);
    connect(btn, this, qApp,SLOT(addButton()));
}

#endif //HELLOWORLD_BUTTON_H
