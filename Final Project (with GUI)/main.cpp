#include <QtGui/QApplication>
#include <QIcon>
#include <QString>
#include "mainwindow.h"
//#include "a.h"
//#include "ida.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon Icon ("p.png");
    QString Title("8-Puzzle Solver");
    MainWindow w;
    w.setWindowIcon(Icon);
    w.setWindowTitle(Title);
    w.setStatusBar(0);
    w.setFixedSize(450,430);
    w.show();
    return a.exec();
}
