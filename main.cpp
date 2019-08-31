#include <QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include "GUI/Button.h"
#include <QGridLayout>


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QWidget window;
    Button btn = new Button(&window);
    btn.setLayout(new QGridLayout());
    window.resize(700,700);
    window.setWindowTitle("TecFlix");


    window.show();
    return app.exec();
}