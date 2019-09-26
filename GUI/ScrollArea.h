//
// Created by danium on 24/9/19.
//

#ifndef HELLOWORLD_SCROLLAREA_H
#define HELLOWORLD_SCROLLAREA_H

#include <QApplication>
#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>

using namespace std;

class ScrollArea : public QWidget {
public:
    ScrollArea(QWidget *parent=0);
    QScrollArea *scrollArea;
    string array[9];
    QGridLayout *grid = new QGridLayout;

    void CSVparser(int pag);
    void screeHandler();

    void wheelEvent(QWheelEvent *event);

};


#endif //HELLOWORLD_SCROLLAREA_H
