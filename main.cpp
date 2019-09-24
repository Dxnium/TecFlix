#include <QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include "GUI/Box.h"
#include "GUI/CSVparser.h"
#include "GUI/StratWindow.h"
#include <iostream>
#include <curl/curl.h>
#include <iostream>



using namespace std;



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    StratWindow *window = new StratWindow();


    window->show();
    return app.exec();
}




