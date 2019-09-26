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

ScrollArea::ScrollArea(QWidget *parent): QWidget(parent) {
    resize(700,600);
    setWindowTitle("TecFlix");

    QPalette Pal(palette());
    // Asignar el color de fondo como Negro
    Pal.setColor(QPalette::Background, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(Pal);

    scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(10,10,680,580);


    CSVparser(1);

    //screeHandler();

    Page *p = new Page();
    scrollArea->setWidget(p);

   // scrollArea->takeWidget();



}

void ScrollArea::CSVparser(int pag) {
    int index = pag*9;
    ifstream myFile;
    string line;
    string line2;

    myFile.open("/home/danium/Documents/TEC/Datos II/TecFlix/TecFlix/movie_metadata.csv");

    if (!myFile.is_open()) {
        cout << "error opening the file" << endl;
    }
    int tmp = 0;

    for(int i=0;i<pag*9;i++){
        getline(myFile,line,'\n');
        stringstream data(line);
        if(i>=(pag*9)-9 and i<=pag*9){
            //cout<<line<<endl;
            array[tmp] = line;
            //for(int i=0;i<27;i++){
            getline(data,line2,',');
            //cout<<line2<<" ";
            //}
            //cout<<endl;
            tmp++;
        }
    }

}

void ScrollArea::screeHandler() {
    int tmp = 0;
    int tmp2 = 0;
    for(int i =0;i<9;i++){
        if(tmp2>2){
            tmp2 = 0;
            tmp += 1;
        }
        Box *b = new Box(array[i]);

        grid->addWidget(b,tmp,tmp2);
        tmp2 +=1;
    }

}

void ScrollArea::wheelEvent(QWheelEvent *event) {
    QScrollBar *bar = scrollArea->verticalScrollBar();
    //cout<<bar->sliderPosition()<<endl;
    bar->setRange(0,8000);

    if(bar->sliderPosition() == bar->maximum() ){
        bar->setSliderPosition(0);
        cout<<"llegó"<<endl;
    }
}




