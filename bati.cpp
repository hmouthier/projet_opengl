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

void bati::drawgeneral(forme myforme){



glBegin(GL_QUADS);
    for(int i=0;i<myforme.tailleForme()-1;i++){


        glColor3f(0.1f,1.0f,0.5f);      // Couleur verte
        glVertex3f( myforme.getPoint(i).getX(), myforme.getPoint(i).getY(),0);  // Haut droit du quadrilatere (Haut)
        glVertex3f(myforme.getPoint(i+1).getX(), myforme.getPoint(i+1).getY(),0);  // Haut gauche du quadrilatere (Haut)
       glColor3f(0.1f,0.5f,0.5f);
        glVertex3f(myforme.getPoint(i+1).getX(), myforme.getPoint(i+1).getY(),1);  // Bas gauche du quadrilatere (Haut)
        glColor3f(0.5f,1.0f,0.5f);
        glVertex3f( myforme.getPoint(i).getX(), myforme.getPoint(i).getY(),1);  // Bas droit du quadrilatere (Haut)

    }
    glColor3f(0.0f,1.0f,0.0f);      // Couleur verte
    glVertex3f( myforme.getPoint(myforme.tailleForme()-1).getX(), myforme.getPoint(myforme.tailleForme()-1).getY(),0);  // Haut droit du quadrilatere (Haut)
    glVertex3f(myforme.getPoint(0).getX(), myforme.getPoint(0).getY(),0);  // Haut gauche du quadrilatere (Haut)
    glVertex3f(myforme.getPoint(0).getX(), myforme.getPoint(0).getY(),1);  // Bas gauche du quadrilatere (Haut)
    glVertex3f( myforme.getPoint(myforme.tailleForme()-1).getX(), myforme.getPoint(myforme.tailleForme()-1).getY(),1);  // Bas droit du quadrilatere (Haut)

 glEnd();
     glutSwapBuffers();













//    list<list<float> > li;
//    list<float> points;
//    points.push_back(0);
//    points.push_back(0);
//    li(0)=points;
//    points[0]=1;
//    li(1)=points;
//    points[1]=1;
//    li(2)=points;
//    points[1]=0;
//    li[3]=points;
//cout<<li.size()<<endl;
//vector<float> points1;
//vector<float> points2;
// glBegin(GL_QUADS);
//    for(int i=0;i<li.size();i++){
//        points1=li[i];
//        points2=li[i+1];

//        glColor3f(0.0f,1.0f,0.0f);      // Couleur verte
//        glVertex3f( points1[0], points1[1],0);  // Haut droit du quadrilatere (Haut)
//        glVertex3f(points2[0], points2[1],0);  // Haut gauche du quadrilatere (Haut)
//        glVertex3f(points1[0], points1[1],1);  // Bas gauche du quadrilatere (Haut)
//        glVertex3f( points2[0], points2[1],1);  // Bas droit du quadrilatere (Haut)

//    }
// glEnd();
//     glutSwapBuffers();

//    glColor3f(0.0f,1.0f,0.0f);      // Couleur verte
//    glVertex3f( x, x,-x);  // Haut droit du quadrilatere (Haut)
//    glVertex3f(-x, x,-x);  // Haut gauche du quadrilatere (Haut)
//    glVertex3f(-x, x,x);  // Bas gauche du quadrilatere (Haut)
//    glVertex3f( x,x,x);  // Bas droit du quadrilatere (Haut)



//    glColor3f(1.0f,0.5f,0.0f);      // Couleur orange
//    glVertex3f( x,-x,x);  // Haut droit du quadrilatere (Bas)
//    glVertex3f(-x,-x,x);  // Haut gauche du quadrilatere (Bas)
//    glVertex3f(-x,-x,-x);  // Bas gauche du quadrilatere (Bas)
//    glVertex3f( x,-x,-x);  // Bas droit du quadrilatere (Bas)



//    glColor3f(1.0f,0.0f,0.0f);       // Couleur rouge
//    glVertex3f( x,x,x);   // Haut droit du quadrilatere (Avant)
//    glVertex3f(-x,x,x);   // Haut gauche du quadrilatere (Avant)
//    glVertex3f(-x,-x,x);   // Bas gauche du quadrilatere (Avant)
//    glVertex3f( x,-x,x);   // Bas droit du quadrilatere (Avant)



//    glColor3f(1.0f,1.0f,0.0f);      // Couleur jaune
//    glVertex3f(x,-x,-x);  // Haut droit du quadrilatere (Arriere)
//    glVertex3f(-x,-x,-x);  // Haut gauche du quadrilatere (Arriere)
//    glVertex3f(-x,x,-x);  // Bas gauche du quadrilatere (Arriere)
//    glVertex3f( x,x,-x);  // Bas droit du quadrilatere (Arriere)





//    glColor3f(0.0f,0.0f,1.0f);      // Couleur bleue
//    glVertex3f(-x,x,x);  // Haut droit du quadrilatere (Gauche)
//    glVertex3f(-x,x,-x);  // Haut gauche du quadrilatere (Gauche)
//    glVertex3f(-x,-x,-x);  // Bas gauche du quadrilatere (Gauche)
//    glVertex3f(-x,-x,x);  // Bas droit du quadrilatere (Gauche)




//    glColor3f(1.0f,0.0f,1.0f);      // Couleur violette
//    glVertex3f( x,x,-x);  // Haut droit du quadrilatere (Droite)
//    glVertex3f(x,x,x);  // Haut gauche du quadrilatere (Droite)
//    glVertex3f( x,-x,x);  // Bas gauche du quadrilatere (Droite)
//    glVertex3f(x,-x,-x);  // Bas droit du quadrilatere (Droite)
//  glEnd();








}












