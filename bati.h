#ifndef BATI_H
#define BATI_H
#include <vector>
#include "forme.h"
class bati
{
public:
    bati();
    bati(int );

    void draw4();
    void draw3(float);
    void draw2(float);
    void draw();
    void drawgeneral(forme myforme);

    //~bati();
};

#endif // BATI_H
