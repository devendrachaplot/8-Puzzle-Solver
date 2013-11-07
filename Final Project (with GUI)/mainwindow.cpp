#include <iostream>
#include <string>
#include <QLabel>
#include <QString>
#include <stack>

#include "mainwindow.h"
#include "time.h"
#include "ui_mainwindow.h"
#include <QRect>
#include <QGridLayout>
#include <QToolBar>
#include <QPainter>
#include <QPicture>
#include <QComboBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->no_moves->setText("0");
    ui->time->setText("0");
    ui->next->setEnabled(false);
    Load_images();
    srand(time(NULL));

    connect(ui->solve, SIGNAL(clicked()), this, SLOT(handler()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionA, SIGNAL(triggered()), this, SLOT(menuA()));
    connect(ui->actionIDA_2, SIGNAL(triggered()), this, SLOT(menuIDA()));
    connect(ui->actionNone, SIGNAL(triggered()), this, SLOT(h0()));
    connect(ui->actionManhattan_Distance_2, SIGNAL(triggered()), this, SLOT(h1()));
    connect(ui->refresh, SIGNAL(clicked()), this, SLOT(myrefresh()));
    connect(ui->next, SIGNAL(clicked()), this, SLOT(nextMove()));
    connect(ui->shuffle, SIGNAL(clicked()), this, SLOT(shuffle()));

    connect(ui->algotype, SIGNAL(currentIndexChanged(int)), this, SLOT(combo_algo()));
    connect(ui->htype, SIGNAL(currentIndexChanged(int)), this, SLOT(combo_ht()));

    algo = 1;
    ht = 1;
    moves = -1;
    k=0;
}

void MainWindow::Load_images()
{
    ui->a1->show();
    ui->a2->show();
    ui->a3->show();
    ui->a4->show();
    ui->a5->show();
    ui->a6->show();
    ui->a7->show();
    ui->a8->show();
    ui->blank->show();
}

void MainWindow::handler()
{
    myrefresh();
    a algoa;
    ida algoida;
    clock_t start, finish, total;
    start = clock();

    ui->output->append("Initial State");
    QString s = ui->input->text();
    ui->output->append(s+"\n");
    i++;
    //int ar[9];

    string str;
    str = s.toStdString();
    string stemp;
    stemp = "0";
    int j;

    for (i = 0; i < 9; i++)
    {
        j = (int)str[2*i] - (int)stemp[0];
        inputArray[i] = j;
        if(j==0) blank = i;
    }
    for(i=0; i<9;i++){
        switch(inputArray[i]){
        case 1: ui->a1->setGeometry(i%3 * 60 + 20, i/3 * 60 + 130, 60, 60);
                break;
        case 2: ui->a2->setGeometry(i%3 * 60 + 20, i/3 * 60 + 130, 60, 60);
                break;
        case 3: ui->a3->setGeometry(i%3 * 60 + 20, i/3 * 60 + 130, 60, 60);
                break;
        case 4: ui->a4->setGeometry(i%3 * 60 + 20, i/3 * 60 + 130, 60, 60);
                break;
        case 5: ui->a5->setGeometry(i%3 * 60 + 20, i/3 * 60 + 130, 60, 60);
                break;
        case 6: ui->a6->setGeometry(i%3 * 60 + 20, i/3 * 60 + 130, 60, 60);
                break;
        case 7: ui->a7->setGeometry(i%3 * 60 + 20, i/3 * 60 + 130, 60, 60);
                break;
        case 8: ui->a8->setGeometry(i%3 * 60 + 20, i/3 * 60 + 130, 60, 60);
                break;
        case 0: ui->blank->setGeometry(i%3 * 60 + 20, i/3 * 60 + 130, 60, 60);
                break;
        default:break;

        }


    }

    if(!checkSolvability()){
        ui->output->append("Puzzle not solvable");
    }
    else{
        if (algo == 0)
        {
           algoa.build(str, ht);
           stk = algoa.sresult;
           d = stk.size()-2;

           while (!stk.empty())
            {
                string mystr = stk.front();
                cout<<mystr<<endl;
                QString qstr = QString::fromStdString(mystr);
                ui->output->append(qstr);
                stk.pop();
                moves++;
            }
           for(i=0;i<35;i++)
               solutionSteps[i] = algoa.solutionArray[i];
        }


        if (algo == 1)
        {
           algoida.build(str, ht);
           stk = algoida.a;
           d = stk.size()-2;

           while (!stk.empty())
            {
                string mystr = stk.front();
                cout<<mystr<<endl;
                QString qstr = QString::fromStdString(mystr);
                ui->output->append(qstr);
                stk.pop();
                moves++;
            }
           for(i=0;i<35;i++)
               solutionSteps[i] = algoida.solutionArray[i];
        }

        QString qmoves = QString::number(moves);
        ui->no_moves->setText(qmoves);
        ui->next->setEnabled(true);
    }
    i=0;
    finish = clock();
    total = finish - start;
    cout << "time: " << total << " msecs" << endl;
    QString totaltime;
    float totalm = (float)total/1000;
    totaltime = QString::number(totalm);
    ui->time->setText(totaltime);

}

void MainWindow::menuA()
{
    algo = 1; ui->output->append("A*");
}

void MainWindow::menuIDA()
{
    algo = 2; ui->output->append("IDA*");
}

void MainWindow::h0()
{
    ht = 0; ui->output->append("no md");
}

void MainWindow::h1()
{
    ht = 1; ui->output->append("md");
}

void MainWindow::combo_algo()
{
    algo = (algo == 0) ? 1 : 0 ;
}

void MainWindow::combo_ht()
{
    ht = (ht == 0) ? 1 : 0 ;
}

void MainWindow::myrefresh()
{
    i = 0;
    //ui->input->clear();
    ui->output->clear();
    moves=-1;
    ui->no_moves->setText("0");
    ui->time->setText("0");
    ui->next->setEnabled(false);
    //shuffle();
    ui->a1->setGeometry(20, 130, 60, 60);
    ui->a2->setGeometry(80, 130, 60, 60);
    ui->a3->setGeometry(140, 130, 60, 60);
    ui->a4->setGeometry(20, 190, 60, 60);
    ui->a5->setGeometry(80, 190, 60, 60);
    ui->a6->setGeometry(140, 190, 60, 60);
    ui->a7->setGeometry(20, 250, 60, 60);
    ui->a8->setGeometry(80, 250, 60, 60);
    ui->blank->setGeometry(140, 250, 60, 60);
}

void MainWindow::movebmp()
{
    StartX = pic->x();
    StartY = pic->y();
    EndX = ui->blank->x();
    EndY = ui->blank->y();
    tempX = StartX,tempY = StartY;
    ui->blank->setGeometry(pic->x(),pic->y(),ui->blank->width(),ui->blank->height());
    picMoved = pic;
    Steps = 60;
    j=-1;

    timer->singleShot(5, this, SLOT(update()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){
    j++;
    picMoved->setGeometry(tempX, tempY, picMoved->width(), picMoved->height());
    tempX = tempX + (EndX-StartX)/Steps;
    tempY = tempY + (EndY-StartY)/Steps;
    if(j!=60) timer->singleShot(5, this, SLOT(update())); 
}

void MainWindow::moveHelper(int a){
    switch(a){
    case 1:
        pic = ui->a1;
        movebmp();
        break;
    case 2:
        pic = ui->a2;
        movebmp();
        break;
    case 3:
        pic = ui->a3;
        movebmp();
        break;
    case 4:
        pic = ui->a4;
        movebmp();
        break;
    case 5:
        pic = ui->a5;
        movebmp();
        break;
    case 6:
        pic = ui->a6;
        movebmp();
        break;
    case 7:
        pic = ui->a7;
        movebmp();
        break;
    case 8:
        pic = ui->a8;
        movebmp();
        break;
    default: break;

    }

}

void MainWindow::nextMove(){
    int direction = solutionSteps[d];
    d--;
    switch(direction){
    case 3:
        moveHelper(inputArray[blank + 3]);
        inputArray[blank] = inputArray[blank + 3];
        inputArray[blank + 3] = 0;
        blank = blank + 3;
        break;
    case 4:
        moveHelper(inputArray[blank - 1]);
        inputArray[blank] = inputArray[blank - 1];
        inputArray[blank - 1] = 0;
        blank = blank - 1;
        break;
    case 1:
        moveHelper(inputArray[blank - 3]);
        inputArray[blank] = inputArray[blank - 3];
        inputArray[blank - 3] = 0;
        blank = blank - 3;
        break;
    case 2:
        moveHelper(inputArray[blank + 1]);
        inputArray[blank] = inputArray[blank + 1];
        inputArray[blank + 1] = 0;
        blank = blank + 1;
        break;
    }
    if(d==-1)ui->next->setEnabled(false);
}

bool MainWindow::checkSolvability(){
        int sum = 0;
        int count;
        for (int i = 0; i<9; i++) {
                count = 0;
                for (int j=i; j<9; j++) {
                    if((inputArray[j] < inputArray[i]) && (inputArray[j] != 0)) count++;
                }
                sum = sum + count;
        }
        if(sum%2==0) {
                return true;
        }
        else return false;
}

void MainWindow::shuffle(){
    int no = 30;
    //cout<<"no = "<<no<<endl;
    //cout<<rand()<<endl;
    int in[9];
    int blank;
    for(int i=0; i<9; i++)
        in[i] = i+1;
    in[8] = 0;
    blank = 9;
    for(int i = 0; i<no; i++){
        switch(blank){
        case 1 :j = (int) ((float)rand()/RAND_MAX * 2);
            switch(j){
            case 0:
                in[0]=in[1];
                in[1]=0;
                blank = 2;
                break;
            case 1:
                in[0]=in[3];
                in[3]=0;
                blank = 4;
                break;
            default:
                break;
            }
            break;
        case 2 :j = (int) ((float)rand()/RAND_MAX * 3);
            switch(j){
            case 0:
                in[1]=in[0];
                in[0]=0;
                blank = 1;
                break;
            case 1:
                in[1]=in[2];
                in[2]=0;
                blank = 3;
                break;
            case 2:
                in[1]=in[4];
                in[4]=0;
                blank = 5;
                break;
            default:
                break;
            }
            break;
        case 3 :j = (int) ((float)rand()/RAND_MAX * 2);
            switch(j){
            case 0:
                in[2]=in[1];
                in[1]=0;
                blank = 2;
                break;
            case 1:
                in[2]=in[5];
                in[5]=0;
                blank = 6;
                break;
            default:
                break;
            }
            break;
        case 4 :j = (int) ((float)rand()/RAND_MAX * 3);
            switch(j){
            case 0:
                in[3]=in[0];
                in[0]=0;
                blank = 1;
                break;
            case 1:
                in[3]=in[4];
                in[4]=0;
                blank = 5;
                break;
            case 2:
                in[3]=in[6];
                in[6]=0;
                blank = 7;
                break;
            default:
                break;
            }
            break;
        case 5 :j = (int) ((float)rand()/RAND_MAX * 4);
            switch(j){
            case 0:
                in[4]=in[3];
                in[3]=0;
                blank = 4;
                break;
            case 1:
                in[4]=in[5];
                in[5]=0;
                blank = 6;
                break;
            case 2:
                in[4]=in[1];
                in[1]=0;
                blank = 2;
                break;
            case 3:
                in[4]=in[7];
                in[7]=0;
                blank = 8;
                break;
            default:
                break;
            }
            break;
        case 6 :j = (int) ((float)rand()/RAND_MAX * 3);
            switch(j){
            case 0:
                in[5]=in[2];
                in[2]=0;
                blank = 3;
                break;
            case 1:
                in[5]=in[4];
                in[4]=0;
                blank = 5;
                break;
            case 2:
                in[5]=in[8];
                in[8]=0;
                blank = 9;
                break;
            default:
                break;
            }
            break;
        case 7 :j = (int) ((float)rand()/RAND_MAX * 2);
            switch(j){
            case 0:
                in[6]=in[7];
                in[7]=0;
                blank = 8;
                break;
            case 1:
                in[6]=in[3];
                in[3]=0;
                blank = 4;
                break;
            }
            break;
        case 8 :j = (int) ((float)rand()/RAND_MAX * 3);
            switch(j){
            case 0:
                in[7]=in[6];
                in[6]=0;
                blank = 7;
                break;
            case 1:
                in[7]=in[4];
                in[4]=0;
                blank = 5;
                break;
            case 2:
                in[7]=in[8];
                in[8]=0;
                blank = 9;
                break;
            default:
                break;
            }
            break;
        case 9 :j = (int) ((float)rand()/RAND_MAX * 2);
            switch(j){
            case 0:
                in[8]=in[7];
                in[7]=0;
                blank = 8;
                break;
            case 1:
                in[8]=in[5];
                in[5]=0;
                blank = 6;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    QString s="";
    for (int i=0;i<9;i++){
        s = s + QString :: number(in[i]) + " ";
    }
    ui->input->setText(s);

}
