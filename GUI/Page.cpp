//
// Created by danium on 25/9/19.
//

#include "Page.h"
#include "Box.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
Page::Page(int page,QWidget *parent) {
    CSVparser(page);
    screenHandler();
    setLayout(grid);
}
Page::Page(int page, bool img, QWidget *parent) {
    CSVparser(page);
    screenHandler_noIMG();
    setLayout(grid);
}

void Page::screenHandler() {
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

void Page::CSVparser(int pag) {
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

void Page::screenHandler_noIMG() {
    int tmp = 0;
    int tmp2 = 0;
    for(int i =0;i<9;i++){
        if(tmp2>2){
            tmp2 = 0;
            tmp += 1;
        }
        Box *b = new Box(array[i], false);

        grid->addWidget(b,tmp,tmp2);
        tmp2 +=1;
    }
}
