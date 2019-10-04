//
// Created by danium on 2/9/19.
//

#ifndef HELLOWORLD_BOX_H
#define HELLOWORLD_BOX_H

#include <iostream>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <iostream>



class Box : public QGroupBox {
    QVBoxLayout *vbox;
    QPushButton *btn;
    std::string link;
    std::string title;

public:
    Box(std::string data, QWidget *parent = 0, QVBoxLayout *layout=0);
    Box(std::string data,bool img, QWidget *parent = 0, QVBoxLayout *layout=0);

    void OpenLink();

    void ParseData(std::string data);

    void ImageLoader(std::string link);
};





#endif //HELLOWORLD_BOX_H