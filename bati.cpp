#include "bati.h"

using namespace std;

bati::bati()
{
}

void bati::tribati(vector<RotatedRect> contourbati){
    for(int i=0;i<contourbati.size();i++){
        Point2f rect_points[4]; contourbati[i].points(rect_points);
               if (40000<(pow(rect_points[0].x -rect_points[1].x,2)+pow(rect_points[0].y -rect_points[1].y,2))*(pow(rect_points[2].x -rect_points[1].x,2)+pow(rect_points[2].y -rect_points[1].y,2)))
            batifiltre.push_back(contourbati[i]);
    }
}

void bati::drawgeneral(Point2f myforme[]){
    int hauteur=20;
    float X_centre=0,Y_centre=0;
    for(int i=0;i<4;i++){
        X_centre+=myforme[i].x;
        Y_centre+=myforme[i].y;
    }
    X_centre=X_centre/4;
    Y_centre=Y_centre/4;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( X_centre, Y_centre,hauteur*1.2);
    float maNorme=0;
    for(int i=0;i<4;i++){
        maNorme=sqrt(pow(myforme[i].x-X_centre,2)+pow(myforme[i].y-Y_centre,2));

        glColor3f(1.0f,0.0f,0.5f);
        glVertex3f( myforme[i].x+5*(myforme[i].x-X_centre)/maNorme, myforme[i].y+5*(myforme[i].y-Y_centre)/maNorme,hauteur);

    }
    maNorme=sqrt(pow(myforme[0].x-X_centre,2)+pow(myforme[0].y-Y_centre,2));
    glVertex3f( myforme[0].x+5*(myforme[0].x-X_centre)/maNorme, myforme[0].y+5*(myforme[0].y-Y_centre)/maNorme,hauteur);
    glEnd();



    glBegin(GL_QUADS);
    for(int i=0;i<3;i++){


        glColor3f(0.1f,1.0f,0.5f);      // Couleur verte
        glVertex3f( myforme[i].x, myforme[i].y,0);  // Haut droit du quadrilatere (Haut)
        glVertex3f(myforme[i+1].x, myforme[i+1].y,0);  // Haut gauche du quadrilatere (Haut)
        glColor3f(0.1f,0.5f,0.5f);
        glVertex3f(myforme[i+1].x, myforme[i+1].y,hauteur);  // Bas gauche du quadrilatere (Haut)
        glColor3f(0.5f,1.0f,0.5f);
        glVertex3f( myforme[i].x, myforme[i].y,hauteur);  // Bas droit du quadrilatere (Haut)

    }
    glColor3f(0.0f,1.0f,0.0f);      // Couleur verte
    glVertex3f( myforme[3].x, myforme[3].y,0);  // Haut droit du quadrilatere (Haut)
    glVertex3f(myforme[0].x, myforme[0].y,0);  // Haut gauche du quadrilatere (Haut)
    glVertex3f(myforme[0].x, myforme[0].y,hauteur);  // Bas gauche du quadrilatere (Haut)
    glVertex3f( myforme[3].x, myforme[3].y,hauteur);  // Bas droit du quadrilatere (Haut)

    glEnd();



}


void bati::drawtotal(){


    for(int i=0;i<batifiltre.size();i++){
        Point2f rect_points[4]; batifiltre[i].points(rect_points);
        drawgeneral(rect_points);
    }

}









