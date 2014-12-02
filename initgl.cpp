#include "initgl.h"

using namespace std;
float verti=0.0f, hori=0.0f;
int X=0,Y=0,vuehori=0,vueverti=0;
float conthori=0,contverti=0,contvuehori=0,contvueverti=0;
camera macam;

Mat imagebis;

vegetation arbre;
bati batiment;


void initGL(TraitementImage projet)
{

    imagebis=projet.exportRoad();
    arbre.triVegeta(projet.exportcontourveget());
    batiment.tribati(projet.exportcontourBati());
    batiment.loadTexture();



    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutPassiveMotionFunc(mouseMovePassive);
    glutMotionFunc(mouseMove);
    glEnable(GL_TEXTURE_2D);
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

    glLoadIdentity();

}

void processNormalKeys(unsigned char key, int , int ) {

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

void processSpecialKeys(int key, int , int ) {


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

    //////// AFFICHAGE OPENGL////////////

    afficheortho mon( &imagebis);
    batiment.drawtotal();
    arbre.drawtotal();
    glutSwapBuffers();

}


