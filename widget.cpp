#include "widget.h"
#include "ui_widget.h"
#include<QString>
#include<QImage>
#include<QPixmap>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    QString filename=":/Res/background3-1.png";
    QImage img;
    img.load(filename);
    ui->label->setPixmap(QPixmap::fromImage(img));    //背景地图
    ui->label->adjustSize();


    img2.load(tankname);
    ui->tank->setPixmap(QPixmap::fromImage(img2));  //坦克


    img_bullet.load(":/Res/Medium_Shell.png");


    this->startTimer(10);




}


Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *e)      //计时器事件
{
    bullet_time++; //子弹等待
    for (int i=0;i<bullet_num;i++)     //子弹移动
    {
        switch (bullet_status[i]) {
        case 'u':bullet[i]->move(bullet[i]->x(),bullet[i]->y()-BULLET_SPEED);bullet[i]->show();break;
        case 'd':bullet[i]->move(bullet[i]->x(),bullet[i]->y()+BULLET_SPEED);break;
        case 'l':bullet[i]->move(bullet[i]->x()-BULLET_SPEED,bullet[i]->y());break;
        case 'r':bullet[i]->move(bullet[i]->x()+BULLET_SPEED,bullet[i]->y());break;
        }

    }
    //坦克移动
    if(W_press)ui->tank->move(ui->tank->x(),ui->tank->y()-SPEED);
    if(S_press)ui->tank->move(ui->tank->x(),ui->tank->y()+SPEED);
    if(A_press)ui->tank->move(ui->tank->x()-SPEED,ui->tank->y());
    if(D_press)ui->tank->move(ui->tank->x()+SPEED,ui->tank->y());
}


void Widget::keyPressEvent(QKeyEvent *event)      //键盘按下监控
{
    if(event->key() == Qt::Key_W)
       {
        if(status!='u')
        {
            tankname=":/Res/1-blueUP";

                img2.load(tankname);
                ui->tank->setPixmap(QPixmap::fromImage(img2));
            status='u';
        }
            W_press=1;


       }
    if(event->key() == Qt::Key_S)
       {
        if(status!='d')
        {
            tankname=":/Res/1-blueDOWN";

                img2.load(tankname);
                ui->tank->setPixmap(QPixmap::fromImage(img2));
            status='d';
        }
        S_press=1;


       }
    if(event->key() == Qt::Key_A)
       {
        if(status!='l')
        {
            tankname=":/Res/1-blueL";

                img2.load(tankname);
                ui->tank->setPixmap(QPixmap::fromImage(img2));
            status='l';
        }
            A_press=1;


       }
    if(event->key() == Qt::Key_D)
       {
        if(status!='r')
        {
            tankname=":/Res/1-blueR";

                img2.load(tankname);
                ui->tank->setPixmap(QPixmap::fromImage(img2));
            status='r';
        }
        D_press=1;


       }
    if(event->key() == Qt::Key_J)
      {
        if(bullet_time<bullet_interval)
        {
            return;
        }
       else
        {
            bullet[bullet_num]=new QLabel(this,0);
            if(status=='u')
                {
                img_bullet.load(":/Res/2.png");
                bullet[bullet_num]->move(ui->tank->x()+20,ui->tank->y()-BULLET_SPEED);

                }
            else if(status=='d')
                {
                img_bullet.load(":/Res/1.png");
                bullet[bullet_num]->move(ui->tank->x()+20,ui->tank->y()+BULLET_SPEED);
                }
            else if(status=='l')
                {
                img_bullet.load(":/Res/4.png");
               bullet[bullet_num]->move(ui->tank->x()-BULLET_SPEED,ui->tank->y()+10);
               }
            else if(status=='r')
                {
                img_bullet.load(":/Res/3.png");
               bullet[bullet_num]->move(ui->tank->x()+BULLET_SPEED,ui->tank->y()+10);
                }
            bullet_status[bullet_num]=status;
            this->bullet[bullet_num]->setPixmap(QPixmap::fromImage(img_bullet));
            bullet[bullet_num]->setFixedSize(40,40);
            bullet[bullet_num]->show();
            bullet_time=0;
            bullet_num++;
        }

       }


}

void Widget::keyReleaseEvent(QKeyEvent *event)  //键盘松开监控
{
    if(event->key() == Qt::Key_W)
       {

            W_press=0;


       }
    if(event->key() == Qt::Key_S)
       {

        S_press=0;


       }
    if(event->key() == Qt::Key_A)
       {

            A_press=0;


       }
    if(event->key() == Qt::Key_D)
       {

        D_press=0;
        }
}
