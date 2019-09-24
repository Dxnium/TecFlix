//
// Created by danium on 2/9/19.
//

#ifndef HELLOWORLD_CSVPARSER_H
#define HELLOWORLD_CSVPARSER_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class CSVparser{

public:
    int index = 0;
    ifstream myFile;
    string line;
    string line2;


    CSVparser();

    string array[9];
};

CSVparser::CSVparser(){
    myFile.open("/home/danium/Documents/GitHub/CE2103/Projecto-1-DatosII/database.csv");

    if (!myFile.is_open()) {
        cout << "error opening the file" << endl;
    }

    while (myFile.good() and index<=9) {
        getline(myFile,line,'\n');
        stringstream data(line);
        while(index>0){
            cout<<line<<endl;
            array[index-1] = line;
            //for(int i=0;i<27;i++){
                getline(data,line2,',');
                //cout<<line2<<" ";
            //}
            cout<<endl;
            break;
        }

        index++;
    }

};



#endif //HELLOWORLD_CSVPARSER_H
