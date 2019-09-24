//
// Created by danium on 23/9/19.
//

#include <QtWidgets/QVBoxLayout>
#include <QApplication>
#include <sstream>
#include <curl/curl.h>
#include "Box.h"
#include <iostream>


using namespace std;

Box::Box(std::string data, QWidget *parent, QVBoxLayout *layout) : QGroupBox(parent) {
    vbox = new QVBoxLayout;
    ParseData(data);
    //content
    btn = new QPushButton("Click me ");
    btn->setGeometry(0,0,200,20);
    connect(btn, &QPushButton::clicked, this,  &::Box::OpenLink);
    //connect(btn, , this, SLOT (handleButton()));

    //label title
    QString qstr_title = QString::fromStdString(title);
    QLabel *label = new QLabel(qstr_title);

    //load movie image poster

    //convert link to const char
    ImageLoader(link);
    QPixmap pm("/home/danium/Documents/TEC/Datos II/TecFlix/TecFlix/image/img.jpg");
    QLabel *lbImg = new QLabel();
    lbImg->setPixmap(pm);


    vbox->addWidget(label);
    vbox->addWidget(lbImg);
    vbox->addWidget(btn);
    setLayout(vbox);
}



void Box::OpenLink() {
    std::string link2 = link;
    std::string command = "firefox " +link2;
    const char *C = command.c_str();
    system(C);
}

void Box::ParseData(std::string data) {
    std::string line;
    std::stringstream ss(data);
    for(int i=0;i<18;i++){
        getline(ss,line,',');
        //std::cout<<line<<" ";
        if(i==11){
            std::cout<<line<<" ";
            title = line;
        }
    }
    std::cout<<line<<" ";
    link = line;
    std::cout<<std::endl;

};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
};

void Box::ImageLoader(std::string link) {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    const char* link_constchar = link.c_str();

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, link_constchar);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

    }

    int index = 0;
    std::string line;


    stringstream sss(readBuffer);
    while (true and index<=1500) {
        getline(sss,line,'\n');
        if(index>1340){
            if (line.find("poster") != string::npos) {
                cout<<"Found";
                for(int i=0;i<3;i++){
                    getline(sss,line,'\n');
                }
                break;
            }
        }
        index++;
    }
    cout<<endl;
    std::string token = line.substr(0, line.find(".jpg"));
    std::string formated = token.substr(5, token.find(".jpg"));
    formated = formated+".jpg";
    cout<<formated<<endl;

    const char *url = formated.c_str();



//dowload image


    CURL *image;
    CURLcode imgresult;
    FILE *fp = nullptr;
    //const char *url = "https://m.media-amazon.com/images/M/MV5BOWQ1MDE1NzgtNTQ4OC00ZjliLTllZDAtN2IyOTVmMTc5YjUxXkEyXkFqcGdeQXVyNzkwMjQ5NzM@._V1_UX182_CR0,0,182,268_AL_.jpg";
    image = curl_easy_init();
    if (image)
    {
        // Open file
        fp = fopen("/home/danium/Documents/TEC/Datos II/TecFlix/TecFlix/image/img.jpg", "wb");
        if (fp == NULL) cout << "File cannot be opened";

        curl_easy_setopt(image, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(image, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(image, CURLOPT_URL, url);
        curl_easy_setopt(image, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(image, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36");
        // Grab image
        imgresult = curl_easy_perform(image);
        if (imgresult)
            cout << "Cannot grab the image!\n";
    }
    // Clean up the resources
    curl_easy_cleanup(image);
    // Close the file
    fclose(fp);
    system("pause");

};



