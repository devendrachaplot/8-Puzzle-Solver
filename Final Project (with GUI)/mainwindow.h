#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <string>
#include <QLabel>
#include <stack>
#include <QMainWindow>
#include <QGridLayout>
#include <QPainter>
#include <QPicture>
#include <QTimer>
#include <queue>
#include <QThread>
#include "a.h"
#include "ida.h"

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void Load_images();
    int algo, ht, i, moves;
    queue<string> stk;
    float tempX,tempY,StartX,StartY,EndX,EndY;
    int Steps,j,k,g,d;
    QTimer *timer;
    QLabel *picMoved;
    QLabel *pic;
    QObject temp;
    int inputArray[9];
    int blank;
    int solutionSteps[35];
    void moveHelper(int a);


public slots :
    void handler();
    void movebmp();
    void menuA();
    void menuIDA();
    void h0();
    void h1();
    void combo_algo();
    void combo_ht();
    void myrefresh();
    void update();
    void nextMove();
    bool checkSolvability();
    void shuffle();
};

#endif // MAINWINDOW_H
