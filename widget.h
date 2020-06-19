#ifndef WIDGET_H
#define WIDGET_H
#define SPEED 10    //坦克速度
#include<QKeyEvent>
#include <QWidget>
#include<QTimer>
#include<QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QTimer m_Timer;       //计时器
    char status='u';  //坦克朝向u,d,l,r;
    QString tankname="C:/Qt/PlaneWar/Res/1-blueUP";
    QImage img2;   //坦克图片
    void keyPressEvent(QKeyEvent *event);



private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
