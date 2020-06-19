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
    QString filename="C:/Qt/PlaneWar/Res/img_bg_level_1";
    QImage img;
    img.load(filename);
    ui->label->setPixmap(QPixmap::fromImage(img));    //背景地图
    ui->label->adjustSize();


    img2.load(tankname);
    ui->tank->setPixmap(QPixmap::fromImage(img2));




}


Widget::~Widget()
{
    delete ui;
}


void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
       {
        if(status!='u')
        {
            tankname="C:/Qt/PlaneWar/Res/1-blueUP";

                img2.load(tankname);
                ui->tank->setPixmap(QPixmap::fromImage(img2));
            status='u';
        }
        else
          ui->tank->move(ui->tank->x(),ui->tank->y()-SPEED);
        return;
       }
    if(event->key() == Qt::Key_S)
       {
        if(status!='d')
        {
            tankname="C:/Qt/PlaneWar/Res/1-blueDOWN";

                img2.load(tankname);
                ui->tank->setPixmap(QPixmap::fromImage(img2));
            status='d';
        }
        else
          ui->tank->move(ui->tank->x(),ui->tank->y()+SPEED);
          return;
       }
    if(event->key() == Qt::Key_A)
       {
        if(status!='l')
        {
            tankname="C:/Qt/PlaneWar/Res/1-blueL";

                img2.load(tankname);
                ui->tank->setPixmap(QPixmap::fromImage(img2));
            status='l';
        }
        else
          ui->tank->move(ui->tank->x()-SPEED,ui->tank->y());
        return;
       }
    if(event->key() == Qt::Key_D)
       {
        if(status!='r')
        {
            tankname="C:/Qt/PlaneWar/Res/1-blueR";

                img2.load(tankname);
                ui->tank->setPixmap(QPixmap::fromImage(img2));
            status='r';
        }
        else
          ui->tank->move(ui->tank->x()+SPEED,ui->tank->y());
        return;
       }


}
