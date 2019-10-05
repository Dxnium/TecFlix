//
// Created by danium on 24/9/19.
//

#include <QtWidgets/QLabel>
#include "ScrollArea.h"
#include "Box.h"
#include "Page.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <QListWidget>
#include <QScrollBar>

using namespace std;

ScrollArea::ScrollArea(QWidget *parent) : QWidget(parent) {
    resize(1920, 1080);
    setWindowTitle("TecFlix");

    QPalette Pal(palette());
    // Asignar el color de fondo como Negro
    Pal.setColor(QPalette::Background, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(Pal);

    scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(10, 10, 1900, 1060);

    //CSVparser(1);

    //screeHandler();
    page_index = 1;
    page = new Page(page_index, false);
    page2 = new Page(page_index + 1, false);
    page3 = new Page(page_index + 2, false);


    grid->addWidget(scrollArea);

    widget = new QWidget();
    grid_scroll = new QGridLayout();
    grid_scroll->addWidget(page);
    grid_scroll->addWidget(page2);
    grid_scroll->addWidget(page3);
    widget->setLayout(grid_scroll);


    scrollArea->setWidget(widget);
    setLayout(grid);

    scroll_length = widget->height() - 900;
}

void ScrollArea::CSVparser(int pag) {
    int index = pag * 9;
    ifstream myFile;
    string line;
    string line2;

    myFile.open("/home/danium/Documents/TEC/Datos II/TecFlix/TecFlix/movie_metadata.csv");

    if (!myFile.is_open()) {
        cout << "error opening the file" << endl;
    }
    int tmp = 0;
    for (int i = 0; i < pag * 9; i++) {
        getline(myFile, line, '\n');
        stringstream data(line);
        if (i >= (pag * 9) - 9 and i <= pag * 9) {
            array[tmp] = line;
            getline(data, line2, ',');
            tmp++;
        }
    }

}

void ScrollArea::screeHandler() {
    int tmp = 0;
    int tmp2 = 0;
    for (int i = 0; i < 9; i++) {
        if (tmp2 > 2) {
            tmp2 = 0;
            tmp += 1;
        }
        Box *b = new Box(array[i]);

        grid->addWidget(b, tmp, tmp2);
        tmp2 += 1;
    }

}

void ScrollArea::wheelEvent(QWheelEvent *event) {
    QScrollBar *bar = scrollArea->verticalScrollBar();
    bar->setRange(0, scroll_length);

    if (bar->sliderPosition() == bar->maximum()) {
        scroll_length += 0;
        bar->setRange(0, scroll_length);
        page_index+=1;
        addPage();
        bar->setSliderPosition(bar->sliderPosition() - 500);
    }
    if (bar->sliderPosition() == bar->minimum()) {
        //cout<<"gg"<<endl;
        if(page_index!=1){
            page_index-=1;
            subPage();
            bar->setSliderPosition(bar->sliderPosition() + 500);
        }
    }
}

void ScrollArea::addPage() {
    delete(page);
    page = page2;
    page2 = page3;

    Page *newpage = new Page(page_index+2, false);

    page3 = newpage;
    grid_scroll->addWidget(page);
    grid_scroll->addWidget(page2);
    grid_scroll->addWidget(page3);
    widget->setLayout(grid_scroll);


    scrollArea->setWidget(widget);
}

void ScrollArea::subPage() {
    delete(page3);
    Page *tmp =page2;
    page2 = page;
    page3=tmp;
    Page *newpage = new Page(page_index, false);

    page=newpage;

    grid_scroll->addWidget(page);
    grid_scroll->addWidget(page2);
    grid_scroll->addWidget(page3);
    widget->setLayout(grid_scroll);


    scrollArea->setWidget(widget);
}




