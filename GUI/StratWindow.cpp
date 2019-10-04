//
// Created by danium on 23/9/19.
//

#include "StratWindow.h"
#include <iostream>
#include "Normal.h"
#include "ScrollArea.h"
#include "../NoP/NoPag.h"

using namespace std;

StratWindow::StratWindow(QWidget *parent): QWidget(parent) {
    resize(700,400);
    setWindowTitle("TecFlix");


    QPalette Pal(palette());
    // Asignar el color de fondo como Negro
    Pal.setColor(QPalette::Background, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(Pal);


    QPushButton *btn_Infinity = new QPushButton("Scroll",this);
    connect(btn_Infinity, &QPushButton::clicked, this, &StratWindow::Infinity);
    btn_Infinity->setStyleSheet("background-color: rgb(181,56,56);border: none; ");
    btn_Infinity->setGeometry(150,200,200,20);

    QPushButton *btn_noInfinity = new QPushButton("Normal",this);
    connect(btn_noInfinity, &QPushButton::clicked, this, &StratWindow::Normal_Aaction);
    btn_noInfinity->setStyleSheet("background-color: rgb(0,147,56);border: none; ");
    btn_noInfinity->setGeometry(350,200,200,20);

    QPushButton *btn_nopag = new QPushButton("NO-Pag",this);
    connect(btn_nopag, &QPushButton::clicked, this, &StratWindow::Nopag);
    btn_nopag->setStyleSheet("background-color: rgb(0,147,56);border: none; ");
    btn_nopag->setGeometry(250,300,200,30);

}

void StratWindow::Normal_Aaction() {
    this->close();
    delete this;

    Normal *normal = new Normal();
    normal->show();
}

void StratWindow::Infinity() {
    this->close();
    delete this;

    ScrollArea *scroll = new ScrollArea();
    scroll->show();

}

void StratWindow::Nopag() {
    this->close();
    delete this;

    NoPag *noPag = new NoPag();
    noPag->show();

}

