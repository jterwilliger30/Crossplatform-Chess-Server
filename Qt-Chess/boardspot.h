#ifndef BOARDSPOT_H
#define BOARDSPOT_H
#include <QRect>
#include <QMouseEvent>


class BoardSpot : public QObject
{
public:
    BoardSpot(int x, int y, int w, int h);
    QRect rect;

};

#endif // BOARDSPOT_H
