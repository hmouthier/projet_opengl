#include "point.h"
#include <QList>
#ifndef FORME_H
#define FORME_H


class forme
{
public:
    forme(QList<point> mylist );
    point getPoint(int i);
    int tailleForme();
private:
    QList<point> _mylist;
};

#endif // FORME_H
