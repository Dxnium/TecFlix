//
// Created by danium on 23/9/19.
//

#include "Normal.h"
#include "Box.h"
#include <fstream>
#include <sstream>
#include <QtWidgets/QPushButton>
#include <QSpinBox>
Normal::Normal(QWidget *parent): QWidget(parent) {
    resize(700,600);
    setWindowTitle("TecFlix");

    QPalette Pal(palette());
    // Asignar el color de fondo como Negro
    Pal.setColor(QPalette::Background, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(Pal);

    //button
    QPushButton *btn_Next = new QPushButton("next",this);
    connect(btn_Next, &QPushButton::clicked, this,  &Normal::Next);
    btn_Next->setGeometry(350,0,200,20);

    QPushButton *btn_Back = new QPushButton("back",this);
    btn_Back->setGeometry(150,0,200,20);

    //spin box
    spinBox = new QSpinBox(this);
    spinBox->setValue(index);
    spinBox->setGeometry(550,0,40,20);
    CSVparser(index);


    screenHandler();

    setLayout(grid);


}

void Normal::CSVparser(int pag) {
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

void Normal::screenHandler() {
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

void Normal::Next() {
    while( grid->count() ) {
        QWidget* widget = grid->itemAt(0)->widget();

        if( widget ) {
            grid->removeWidget(widget);
            delete widget;
        }
    }


    index+=1;
    spinBox->setValue(index);

    CSVparser(spinBox->value());

    screenHandler();

}



