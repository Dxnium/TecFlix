//
// Created by danium on 4/10/19.
//

#include "NoPag.h"
#include "../GUI/Box.h"
#include "../GUI/Page.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <QScrollArea>


using namespace std;

NoPag::NoPag(QWidget *parent): QWidget(parent) {
    resize(1920,1080);
    setWindowTitle("TecFlix");

    QPalette Pal(palette());
    // Asignar el color de fondo como Negro
    Pal.setColor(QPalette::Background, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(Pal);


    loadAll();


    grid->addWidget(scroll);
    setLayout(grid);
}

void NoPag::CSVparser(int pag) {
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

void NoPag::loadAll() {
    for(int i=1;i<556;i++){
       Page *p = new Page(i,false);
       grid_scroll->addWidget(p);
    }
    widget->setLayout(grid_scroll);
    scroll->setWidget(widget);
}
