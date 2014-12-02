#ifndef INITGL_H
#define INITGL_H

#include "camera.h"
#include "bati.h"
#include "traitementimage.h"
#include "afficheortho.h"
#include "vegetation.h"

    void initGL(TraitementImage );
    void changeSize(int , int );
    void processNormalKeys(unsigned char key, int, int);
    void processSpecialKeys(int key, int, int);
    void mouseMove(int x, int y) ;
    void mouseMovePassive(int x, int y);
    void mouseWheel(int , int dir, int , int );
    void display(void);

#endif // INITGL_H
