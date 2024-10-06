#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    distribution=new Distribution(0,QGV_HORIZONTAL_CENTER,QGV_VERTICAL_CENTER,scene);

    show_problem_statement();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_problem_statement()
{
    ui->graphicsView->setScene(scene);

    build_triangle();
}

void MainWindow::build_triangle()
{
    qreal radius=ui->Radius->value();

    if(triangle) //If triangle already added to scene, remove it to add triangle with new coords
    scene->removeItem(triangle);

    triangle=new QGraphicsPolygonItem({QPointF(QGV_HORIZONTAL_CENTER,QGV_VERTICAL_CENTER-radius),
                                         QPointF(QGV_HORIZONTAL_CENTER+radius*sqrtl(3)/(qreal)2,QGV_VERTICAL_CENTER+radius/qreal(2)),
                                         QPointF(QGV_HORIZONTAL_CENTER-radius*sqrtl(3)/(qreal)2,QGV_VERTICAL_CENTER+radius/qreal(2))});
    scene->addItem(triangle);

    build_circle(radius);
}

void MainWindow::build_circle(qreal radius)
{
    if(circle) //If cricle already added to scene, remove it to add triangle with new coords
    scene->removeItem(circle);

    circle=new QGraphicsEllipseItem(QGV_HORIZONTAL_CENTER-radius,QGV_VERTICAL_CENTER-radius,2*radius,2*radius);
    scene->addItem(circle);

}

void MainWindow::on_Radius_valueChanged(double arg1)
{
    show_problem_statement();
    on_distributeButton_clicked();
}


void MainWindow::on_distributeButton_clicked()
{
    distribution->UpdateRadius(ui->Radius->value());
    if(ui->distributionType->currentIndex()==0)
    {
        distribution->RandomDistribution(ui->numberOfPoints->value());
    }
}

