//
// Created by danium on 24/9/19.
//

#ifndef HELLOWORLD_SCROLLAREA_H
#define HELLOWORLD_SCROLLAREA_H

#include <QApplication>
#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include "Page.h"

using namespace std;

class ScrollArea : public QWidget {
public:
    ScrollArea(QWidget *parent=0);
    QScrollArea *scrollArea;
    string array[9];
    QGridLayout *grid = new QGridLayout;
    QGridLayout *grid_scroll = new QGridLayout();
    QWidget *widget;

    int scroll_length;
    int page_index;
    Page *page;
    Page *page2;
    Page *page3;

    void CSVparser(int pag);
    void screeHandler();

    void wheelEvent(QWheelEvent *event);

    void addPage();
    void subPage();


};


#endif //HELLOWORLD_SCROLLAREA_H
