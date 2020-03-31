#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QRectF>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
private:
    void addTopRectF();
    void addDownRectF();
    void addLeftRectF();
    void addRightRectF();
    void deleteLastRectF();
    bool snakeStrike();
    enum Move{Left,Right,Up,Down};
protected slots:
    void timeOut();
    void rewardTimeOut();
private:
    Ui::Widget *ui;
    QList<QRectF> snake;
    //贪吃蛇本体
    int snakeNodeWidth = 10;
    int snakeNodeHeight = 10;
    QTimer *timer;
    QTimer *rewardTimer;
    int time = 100;
    int moveFlage = Up;
    bool gameOver = false;
    bool gameStart = false;
    QList<QRectF> rewardNode;//奖励节点


};
#endif // WIDGET_H
