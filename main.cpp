#include <QCoreApplication>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <traitementimage.h>
#include <iostream>
#include "initgl.h"

using namespace std;


int main(int argc, char *argv[])
{
    Mat image = imread( argv[1]);

    TraitementImage projet(&image);


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,1000);
    glutCreateWindow(argv[0]) ;
    initGL(projet);

    glutMainLoop() ;
    return 0 ;



}
