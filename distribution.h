#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include <qtypes.h>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <ctime>
#include <random>
#include <QPen>
#include <QBrush>

class Distribution
{
public:
    Distribution(qreal r, qreal x, qreal y, QGraphicsScene * sc);
    void RandomDistribution(long long count);
    void UpdateRadius(qreal new_radius);
private:
    void delete_points();

    qreal radius,center_x,center_y;
    QGraphicsScene *scene;
    std::mt19937 gen;
    std::uniform_real_distribution<> gen_r,gen_phi;
    QVector<QGraphicsEllipseItem*>points;
};

#endif // DISTRIBUTION_H
