//
// Created by danium on 23/9/19.
//

#ifndef HELLOWORLD_STRATWINDOW_H
#define HELLOWORLD_STRATWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>

class StratWindow : public QWidget {

public:
    StratWindow(QWidget *parent = 0);

    void Normal_Aaction();

    void Infinity();

    void Nopag();
};




#endif //HELLOWORLD_STRATWINDOW_H
