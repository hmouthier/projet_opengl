
#include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <math.h>
#include <QVector3D>
#include <QQuaternion>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "initgl.h"
#include "camera.h"

#include "bati.h"
#include "traitementimage.h"
#include "afficheortho.h"
#include "vegetation.h"
#include "route.h"
using namespace std;
float verti=0.0f, hori=0.0f;
int X=0,Y=0,vuehori=0,vueverti=0;
float conthori=0,contverti=0,contvuehori=0,contvueverti=0;
camera macam;
vector<vector<Point> > s_contour,cont_filt;


GLfloat Blanc[] = {1.0f, 1.0f, 1.0f, 1.0f};
//Taille = 128 * 128. RGB 3 octets
char buffer[128*128*3];
Mat imagebis;
vector<vector<Point> > petitArbre,foret;
vector<Point> centrArbre,centreForet;
vector<RotatedRect> batim,batifiltre;
vegetation arbre;
bati batiment;
//route maroute;

void initGL(TraitementImage projet)
{
    imagebis=projet.exportRoad();
    arbre.triVegeta(projet.exportcontourveget());
    batiment.tribati(projet.exportcontourBati());

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutPassiveMotionFunc(mouseMovePassive);
    glutMotionFunc(mouseMove);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop() ;
}


void changeSize(int w, int h) {

    if (h == 0)
        h = 1;

    float ratio =  w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(40.0,ratio,0.01,10000.0);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y) {

    switch(key) {

    case 122 :
        verti -= 1.0;
        break;
    case 115 :
        verti += 1.0;
        break;
    case 113 :
        hori += 1.0;
        break;
    case 100 :
        hori -= 1.0;
        break;
    }


}

void processSpecialKeys(int key, int x, int y) {


    switch(key) {

    case GLUT_KEY_LEFT :
        hori = 1.0;
        break;
    case GLUT_KEY_RIGHT :
        hori = -1.0; break;
    case GLUT_KEY_UP :

        verti= +1.0; break;
    case GLUT_KEY_DOWN :
        verti= -1.0; break;


    }

}

void mouseMove(int x, int y) {

    // this will only be true when the left button is down


    vuehori = -(x-X);
    vueverti = -(y-Y);
    X=x;
    Y=y;
}

void mouseMovePassive(int x, int y) {

    X=x;
    Y=y;
}

//http://www.mhzn.net/index.php/8-c-opengl/2-first-post


void display(void)
{
    if(conthori==hori)
        hori=0;
    if(contverti==verti)
        verti=0;

    macam.initcam();
    macam.transl(hori,verti);
    conthori=hori;
    contverti=verti;

    if(contvuehori==vuehori)
        vuehori=0;
    if(contvueverti==vueverti)
        vueverti=0;
    macam.rotcam(vuehori,vueverti);
    contvuehori=vuehori;
    contvueverti=vueverti;

    //////// AFFICHAGE OPENGL////////////

    afficheortho mon( &imagebis);
    batiment.drawtotal();
    arbre.drawtotal();
    glutSwapBuffers();

}


