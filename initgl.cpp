
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
#include "point.h"
#include "forme.h"
#include "bati.h"
#include "traitementimage.h"
#include "afficheortho.h"
using namespace std;
float verti=0.0f, hori=0.0f;
int X=0,Y=0,vuehori=0,vueverti=0;
float conthori=0,contverti=0,contvuehori=0,contvueverti=0;
camera macam;
vector<vector<Point> > s_contour,cont_filt;
bati b1;
GLfloat Blanc[] = {1.0f, 1.0f, 1.0f, 1.0f};
//Taille = 128 * 128. RGB 3 octets
char buffer[128*128*3];
Mat imagebis;

void initGL(TraitementImage projet, Mat *image)
{
imagebis=*image;



    s_contour= projet.exportcontour();

    for(int i=0;i<s_contour.size();i++){
        if (s_contour.at(i).size() > 50 )
        {
            cont_filt.push_back(s_contour.at(i));
            //            b1.drawgeneral(s_contour.at(i));
        }}

    macam=camera();
    int nbre=0;
    for(int i=0;i<s_contour.size();i++){
        if (s_contour.at(i).size() > 50)
        {
            nbre+=s_contour.at(i).size();
            //            b1.drawgeneral(s_contour.at(i));
        }}
    cout << nbre<< endl;

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(changeSize);

    // here are the new entries


    glutKeyboardFunc(processNormalKeys);

    glutSpecialFunc(processSpecialKeys);
    glutPassiveMotionFunc(mouseMovePassive);
    glutMotionFunc(mouseMove);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop() ;
}

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
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

    afficheortho mon( &imagebis);
    b1.drawtotal(cont_filt);




}


