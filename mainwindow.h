#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <numbers>
#include "distribution.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Constructors
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Fields



private slots:
    void on_Radius_valueChanged(double arg1);

    void on_distributeButton_clicked();

private:
    //Methods
    void show_problem_statement();
    void build_triangle();
    void build_circle(qreal radius);
    //Fields
    Ui::MainWindow *ui;
    QGraphicsScene *scene=new QGraphicsScene();

    QGraphicsPolygonItem *triangle=nullptr;
    QGraphicsEllipseItem *circle=nullptr;

    Distribution * distribution;
    //Consts
    const short QGV_HORIZONTAL_CENTER=485,QGV_VERTICAL_CENTER=349;
};
#endif // MAINWINDOW_H
