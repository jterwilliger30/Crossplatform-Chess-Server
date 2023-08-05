#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "networkinterface.h"

#include "protobuf/schema.pb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    engine(PlayerType::human, PlayerType::human),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto scene = new QGraphicsScene(this);

    int x=0,y=0, flag=0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            QRect r(x,y,48,48);
            if (flag)
                scene->addRect(r, QPen(Qt::black), QBrush(Qt::black));
            else
                scene->addRect(r, QPen(Qt::black), QBrush(Qt::white));

            x+=48;
            flag = (flag + 1) % 2;
        }
        x=0;
        y+=48;

        flag = (flag + 1) % 2;
    }
    ui->graphicsView->setScene(scene);

    //engine.beginGameLoop();
}

MainWindow::~MainWindow()
{
    delete ui;
}

