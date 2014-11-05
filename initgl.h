#ifndef INITGL_H
#define INITGL_H
#include <vector>
#include "traitementimage.h"

    void initGL(TraitementImage );
    void changeSize(int , int );
    void processNormalKeys(unsigned char key, int x, int y);
    void processSpecialKeys(int key, int x, int y);
    void mouseMove(int x, int y) ;
    void mouseMovePassive(int x, int y);
    void mouseWheel(int , int dir, int , int );
    void display(void);

#endif // INITGL_H
