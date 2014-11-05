#include "bati.h"
#include <GL/glut.h>    // Header File For The GLUT Library
#include <GL/gl.h>    // Header File For The OpenGL32 Library
#include <GL/glu.h>
#include <iostream>
#include <QList>
#include <list>
#include "point.h"
#include "forme.h"
using namespace std;

bati::bati()
{
}



void bati::draw()
{





    glBegin(GL_QUADS);

    glColor3f(0.0f,1.0f,0.0f);      // Couleur verte
    glVertex3f( 1.0f, 1.0f,-1.0f);  // Haut droit du quadrilatere (Haut)
    glVertex3f(-1.0f, 1.0f,-1.0f);  // Haut gauche du quadrilatere (Haut)
    glVertex3f(-1.0f, 1.0f, 1.0f);  // Bas gauche du quadrilatere (Haut)
    glVertex3f( 1.0f, 1.0f, 1.0f);  // Bas droit du quadrilatere (Haut)



    glColor3f(1.0f,0.5f,0.0f);      // Couleur orange
    glVertex3f( 1.0f,-1.0f, 1.0f);  // Haut droit du quadrilatere (Bas)
    glVertex3f(-1.0f,-1.0f, 1.0f);  // Haut gauche du quadrilatere (Bas)
    glVertex3f(-1.0f,-1.0f,-1.0f);  // Bas gauche du quadrilatere (Bas)
    glVertex3f( 1.0f,-1.0f,-1.0f);  // Bas droit du quadrilatere (Bas)



    glColor3f(1.0f,0.0f,0.0f);       // Couleur rouge
    glVertex3f( 1.0f, 1.0f, 1.0f);   // Haut droit du quadrilatere (Avant)
    glVertex3f(-1.0f, 1.0f, 1.0f);   // Haut gauche du quadrilatere (Avant)
    glVertex3f(-1.0f,-1.0f, 1.0f);   // Bas gauche du quadrilatere (Avant)
    glVertex3f( 1.0f,-1.0f, 1.0f);   // Bas droit du quadrilatere (Avant)



    glColor3f(1.0f,1.0f,0.0f);      // Couleur jaune
    glVertex3f( 1.0f,-1.0f,-1.0f);  // Haut droit du quadrilatere (Arriere)
    glVertex3f(-1.0f,-1.0f,-1.0f);  // Haut gauche du quadrilatere (Arriere)
    glVertex3f(-1.0f, 1.0f,-1.0f);  // Bas gauche du quadrilatere (Arriere)
    glVertex3f( 1.0f, 1.0f,-1.0f);  // Bas droit du quadrilatere (Arriere)





    glColor3f(0.0f,0.0f,1.0f);      // Couleur bleue
    glVertex3f(-1.0f, 1.0f, 1.0f);  // Haut droit du quadrilatere (Gauche)
    glVertex3f(-1.0f, 1.0f,-1.0f);  // Haut gauche du quadrilatere (Gauche)
    glVertex3f(-1.0f,-1.0f,-1.0f);  // Bas gauche du quadrilatere (Gauche)
    glVertex3f(-1.0f,-1.0f, 1.0f);  // Bas droit du quadrilatere (Gauche)




    glColor3f(1.0f,0.0f,1.0f);      // Couleur violette
    glVertex3f( 1.0f, 1.0f,-1.0f);  // Haut droit du quadrilatere (Droite)
    glVertex3f( 1.0f, 1.0f, 1.0f);  // Haut gauche du quadrilatere (Droite)
    glVertex3f( 1.0f,-1.0f, 1.0f);  // Bas gauche du quadrilatere (Droite)
    glVertex3f( 1.0f,-1.0f,-1.0f);  // Bas droit du quadrilatere (Droite)
  glEnd();



  glutSwapBuffers();


}







void bati::draw2(float x)
{





    glBegin(GL_QUADS);

    glColor3f(0.0f,1.0f,0.0f);      // Couleur verte
    glVertex3f( x, x,-x);  // Haut droit du quadrilatere (Haut)
    glVertex3f(-x, x,-x);  // Haut gauche du quadrilatere (Haut)
    glVertex3f(-x, x,x);  // Bas gauche du quadrilatere (Haut)
    glVertex3f( x,x,x);  // Bas droit du quadrilatere (Haut)



    glColor3f(1.0f,0.5f,0.0f);      // Couleur orange
    glVertex3f( x,-x,x);  // Haut droit du quadrilatere (Bas)
    glVertex3f(-x,-x,x);  // Haut gauche du quadrilatere (Bas)
    glVertex3f(-x,-x,-x);  // Bas gauche du quadrilatere (Bas)
    glVertex3f( x,-x,-x);  // Bas droit du quadrilatere (Bas)



    glColor3f(1.0f,0.0f,0.0f);       // Couleur rouge
    glVertex3f( x,x,x);   // Haut droit du quadrilatere (Avant)
    glVertex3f(-x,x,x);   // Haut gauche du quadrilatere (Avant)
    glVertex3f(-x,-x,x);   // Bas gauche du quadrilatere (Avant)
    glVertex3f( x,-x,x);   // Bas droit du quadrilatere (Avant)



    glColor3f(1.0f,1.0f,0.0f);      // Couleur jaune
    glVertex3f(x,-x,-x);  // Haut droit du quadrilatere (Arriere)
    glVertex3f(-x,-x,-x);  // Haut gauche du quadrilatere (Arriere)
    glVertex3f(-x,x,-x);  // Bas gauche du quadrilatere (Arriere)
    glVertex3f( x,x,-x);  // Bas droit du quadrilatere (Arriere)





    glColor3f(0.0f,0.0f,1.0f);      // Couleur bleue
    glVertex3f(-x,x,x);  // Haut droit du quadrilatere (Gauche)
    glVertex3f(-x,x,-x);  // Haut gauche du quadrilatere (Gauche)
    glVertex3f(-x,-x,-x);  // Bas gauche du quadrilatere (Gauche)
    glVertex3f(-x,-x,x);  // Bas droit du quadrilatere (Gauche)




    glColor3f(1.0f,0.0f,1.0f);      // Couleur violette
    glVertex3f( x,x,-x);  // Haut droit du quadrilatere (Droite)
    glVertex3f(x,x,x);  // Haut gauche du quadrilatere (Droite)
    glVertex3f( x,-x,x);  // Bas gauche du quadrilatere (Droite)
    glVertex3f(x,-x,-x);  // Bas droit du quadrilatere (Droite)
  glEnd();



  glutSwapBuffers();




}




void bati::draw3(float x)
{



       glBegin(GL_TRIANGLES);           // Debut du dessin de la pyramide





  glColor3f(1.0f,0.0f,0.0f);      // Couleur verte
    glVertex3f( 0, x,0);  // Haut droit du quadrilatere (Haut)

    glVertex3f(-x, -x,x);  // Haut gauche du quadrilatere (Haut)

    glVertex3f(x, -x,x);  // Bas gauche du quadrilatere (Haut)




         // Couleur orange
    glVertex3f( 0, x,0);  // Haut droit du quadrilatere (Bas)

    glVertex3f(x,-x,x);  // Haut gauche du quadrilatere (Bas)

    glVertex3f(x,-x,-x);  // Bas gauche du quadrilatere (Bas)





    glVertex3f( 0, x,0);   // Haut droit du quadrilatere (Avant)

    glVertex3f(x,-x,-x);   // Haut gauche du quadrilatere (Avant)

    glVertex3f(-x,-x,-x);   // Bas gauche du quadrilatere (Avant)




        // Couleur jaune
    glVertex3f(0, x,0);  // Haut droit du quadrilatere (Arriere)

    glVertex3f(-x,-x,-x);  // Haut gauche du quadrilatere (Arriere)

    glVertex3f(-x,-x,x);  // Bas gauche du quadrilatere (Arriere)






  glEnd();



  glutSwapBuffers();



}







void bati::draw4()
{



     // on demande du bleu
    glBegin(GL_TRIANGLE_STRIP); // polygone convexe


glColor3ub(0, 0, 255);
        glVertex3f( -1,  -1,  0);
        glVertex3f(  1,  -1,  0);
        glVertex3f(-.5,   0,  0);
        glVertex3f( .5,   0,  0);
        glVertex3f( -1,   1,  0);
        glVertex3f(  1,   1,  0);



        glEnd();


        glBegin(GL_TRIANGLE_STRIP); // polygone convexe


glColor3ub(0, 255, 255);
            glVertex3f( -1,  -1,  1);
            glVertex3f(  1,  -1,  1);
            glVertex3f(-.5,   0,  1);
            glVertex3f( .5,   0,  1);
            glVertex3f( -1,   1,  1);
            glVertex3f(  1,   1,  1);



            glEnd();




            glBegin(GL_POLYGON); // polygone convexe
glColor3ub(255, 0, 255);
            glVertex3f( -1,  -1, 0);

            glVertex3f(-.5,   0,  0);

            glVertex3f( -1,   1,  0);




            glVertex3f( -1,   1,  1);

                glVertex3f(-.5,   0,  1);

               glVertex3f( -1,  -1,  1);



                glEnd();





                glBegin(GL_POLYGON); // polygone convexe
glColor3ub(255, 255, 255);
                glVertex3f(  1,  -1, 0);

                glVertex3f( .5,   0,  0);

                glVertex3f(  1,   1,  0);

                  glVertex3f(  1,   1,  1);


                    glVertex3f( .5,   0,  1);
                    glVertex3f(  1,  -1,  1);




                    glEnd();



                    glBegin(GL_POLYGON); // polygone convexe
glColor3ub(255, 0, 0);
                    glVertex3f( -1,  -1, 0);


                    glVertex3f( 1,  - 1,  0);
                    glVertex3f( 1,  - 1,  1);
                        glVertex3f( -1,  -1,  1);




                        glEnd();





                        glBegin(GL_POLYGON); // polygone convexe


glColor3ub(0, 255, 0);

                            glVertex3f(  -1,  1,  0);

                            glVertex3f( 1,   1,  0);
                            glVertex3f(  1,   1,  1);
glVertex3f(  -1,  1,  1);


                            glEnd();






  glutSwapBuffers();



}

void bati::drawgeneral(vector<Point> myforme){
float X_centre=0,Y_centre=0;
    for(int i=0;i<myforme.size()-1;i++){
        X_centre+=myforme.at(i).x;
        Y_centre+=myforme.at(i).y;
    }
    X_centre=X_centre/myforme.size();
     Y_centre=Y_centre/myforme.size();

    glBegin(GL_TRIANGLE_FAN);
     glColor3f(1.0f,0.0f,0.0f);
     glVertex3f( X_centre, Y_centre,60);
        for(int i=0;i<myforme.size()-1;i++){


            glColor3f(1.0f,0.0f,0.5f);
            glVertex3f( myforme.at(i).x, myforme.at(i).y,50);

        }

        glVertex3f( myforme.at(0).x, myforme.at(0).y,50);


     glEnd();



glBegin(GL_QUADS);
    for(int i=0;i<myforme.size()-1;i++){


        glColor3f(0.1f,1.0f,0.5f);      // Couleur verte
        glVertex3f( myforme.at(i).x, myforme.at(i).y,0);  // Haut droit du quadrilatere (Haut)
        glVertex3f(myforme.at(i+1).x, myforme.at(i+1).y,0);  // Haut gauche du quadrilatere (Haut)
       glColor3f(0.1f,0.5f,0.5f);
        glVertex3f(myforme.at(i+1).x, myforme.at(i+1).y,50);  // Bas gauche du quadrilatere (Haut)
        glColor3f(0.5f,1.0f,0.5f);
        glVertex3f( myforme.at(i).x, myforme.at(i).y,50);  // Bas droit du quadrilatere (Haut)

    }
    glColor3f(0.0f,1.0f,0.0f);      // Couleur verte
    glVertex3f( myforme.at(myforme.size()-1).x, myforme.at(myforme.size()-1).y,0);  // Haut droit du quadrilatere (Haut)
    glVertex3f(myforme.at(0).x, myforme.at(0).y,0);  // Haut gauche du quadrilatere (Haut)
    glVertex3f(myforme.at(0).x, myforme.at(0).y,50);  // Bas gauche du quadrilatere (Haut)
    glVertex3f( myforme.at(myforme.size()-1).x, myforme.at(myforme.size()-1).y,50);  // Bas droit du quadrilatere (Haut)

 glEnd();



}


void bati::drawtotal(vector<vector<Point> > cont_filt){
    for(int i=0;i<cont_filt.size();i++){
        drawgeneral(cont_filt.at(i));
    }
 glutSwapBuffers();
}









