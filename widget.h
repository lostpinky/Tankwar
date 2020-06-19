#ifndef WIDGET_H
#define WIDGET_H
#define SPEED 3    //坦克速度
#define BULLET_SPEED 6 //子弹速度
#include<QKeyEvent>
#include <QWidget>
#include<QTimer>
#include<QPainter>
#include<QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    char status='u';  //坦克朝向u,d,l,r;
    QString tankname=":/Res/1-blueUP";
    QImage img2;   //坦克图片

    QImage img_bullet;  //子弹图片
    int bullet_interval=200;   //子弹时间间隔
    int bullet_time=200;   //子弹发射间隔记录
     QLabel *bullet[100000];
    int bullet_num=0;   //子弹数量
    char bullet_status[100000];   //子弹方向

    QTimer *timer = new QTimer();//定时器
    int W_press=0,S_press=0,A_press=0,D_press=0;

    void updatemap();
    virtual void timerEvent(QTimerEvent *e);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *e);



private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
