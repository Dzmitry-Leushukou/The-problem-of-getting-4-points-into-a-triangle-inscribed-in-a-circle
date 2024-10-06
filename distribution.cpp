#include "distribution.h"

Distribution::Distribution(qreal r, qreal x, qreal y, QGraphicsScene * sc)
{
    radius=r;
    center_x=x;
    center_y=y;
    scene=sc;
    gen.seed(time(NULL));
    gen_phi=std::uniform_real_distribution<> (0,360);
}

void Distribution::RandomDistribution(long long count)
{
    delete_points();
    gen_r=std::uniform_real_distribution<> (0,radius);
    while(count--)
    {
        qreal dist=gen_r(gen);
        qreal corner=gen_phi(gen);
        //qDebug()<<dist<<" "<<corner;
        QPointF point(center_x+dist*cos(corner* M_PI / 180.0),center_y-dist*sin(corner* M_PI / 180.0));

        points.push_back(new QGraphicsEllipseItem(point.x(),point.y(),1,1));
        points.back()->setPen(QPen(Qt::red, 1));
        points.back()->setBrush(QBrush(Qt::red));

        scene->addItem(points.back());
    }
}

void Distribution::UpdateRadius(qreal new_radius)
{
    radius=new_radius;
}

void Distribution::delete_points()
{
    while(!points.empty())
    {
        scene->removeItem(points.back());
        points.pop_back();
    }
}
