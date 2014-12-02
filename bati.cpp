#include "bati.h"

using namespace std;

bati::bati()
{
}

void bati::tribati(vector<RotatedRect> contourbati){
    for(int i=0;i<contourbati.size();i++){

        Point2f rect_points[4]; contourbati[i].points(rect_points);

        int a=(pow(rect_points[0].x -rect_points[1].x,2)+pow(rect_points[0].y -rect_points[1].y,2))*(pow(rect_points[2].x -rect_points[1].x,2)+pow(rect_points[2].y -rect_points[1].y,2));

        if (40000<a){
            batifiltre.push_back(contourbati[i]);
            aire.push_back(a);
        }
    }
}

void bati::drawgeneral(Point2f myforme[],int hauteur){
    hauteur=pow(hauteur,0.2);

    //----------Calcul du centre du batiment
    float X_centre=0,Y_centre=0;
    for(int i=0;i<4;i++){
        X_centre+=myforme[i].x;
        Y_centre+=myforme[i].y;
    }
    X_centre=X_centre/4;
    Y_centre=Y_centre/4;

    //---------Texture du toit en fonction de la hauteur du batiment

    glColor4f(255,255,255,255);
    if(hauteur<30)
        glBindTexture(GL_TEXTURE_2D, _texture[0]);
    else
        glBindTexture(GL_TEXTURE_2D, _texture[1]);

    //--------Toits des batiments

    glBegin(GL_TRIANGLE_FAN);

    glTexCoord2f(1, 1);    glVertex3f( X_centre, Y_centre,hauteur*1.2);

    float maNorme=0;
    for(int i=0;i<4;i++){
        maNorme=sqrt(pow(myforme[i].x-X_centre,2)+pow(myforme[i].y-Y_centre,2));

        if(0==i%2)
            glTexCoord2f(-1, -1);
        else
            glTexCoord2f(1, -1);

        glVertex3f( myforme[i].x+5*(myforme[i].x-X_centre)/maNorme, myforme[i].y+5*(myforme[i].y-Y_centre)/maNorme,hauteur);

    }
    maNorme=sqrt(pow(myforme[0].x-X_centre,2)+pow(myforme[0].y-Y_centre,2));

    glTexCoord2f(-1, -1);
    glVertex3f( myforme[0].x+5*(myforme[0].x-X_centre)/maNorme, myforme[0].y+5*(myforme[0].y-Y_centre)/maNorme,hauteur);

    glEnd();
    glDisable(GL_TEXTURE_2D);

    //      Murs des batiments

//    glEnable(GL_TEXTURE_2D);
//    if(hauteur<30)  //---------->Texture en fonction de la hauteur du batiment
//        glBindTexture(GL_TEXTURE_2D, _texture[4]);


glEnable(GL_TEXTURE_2D);
    for(int i=0;i<3;i++){

        if(hauteur<30)
            glBindTexture(GL_TEXTURE_2D, _texture[4+i]);
        else
            glBindTexture(GL_TEXTURE_2D, _texture[3]);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0);        glVertex3f( myforme[i].x, myforme[i].y,0);
        glTexCoord2f(1, 0);        glVertex3f(myforme[i+1].x, myforme[i+1].y,0);
        glTexCoord2f(1, 1);        glVertex3f(myforme[i+1].x, myforme[i+1].y,hauteur);
        glTexCoord2f(0, 1);        glVertex3f( myforme[i].x, myforme[i].y,hauteur);
        glEnd();

    }

    if(hauteur<30)
        glBindTexture(GL_TEXTURE_2D, _texture[4]);
    else
        glBindTexture(GL_TEXTURE_2D, _texture[3]);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);    glVertex3f( myforme[3].x, myforme[3].y,0);
    glTexCoord2f(1, 0);    glVertex3f(myforme[0].x, myforme[0].y,0);
    glTexCoord2f(1, 1);    glVertex3f(myforme[0].x, myforme[0].y,hauteur);
    glTexCoord2f(0, 1);    glVertex3f( myforme[3].x, myforme[3].y,hauteur);

    glEnd();


 glDisable(GL_TEXTURE_2D);
}


void bati::drawtotal(){

    for(int i=0;i<batifiltre.size();i++){
        glEnable(GL_TEXTURE_2D);
        Point2f rect_points[4]; batifiltre[i].points(rect_points);
        drawgeneral(rect_points,aire.at(i));

    }

}



void bati::loadTexture()
{
    vector<QString> imagesTexture;
    imagesTexture.push_back("tuile1.bmp");
    imagesTexture.push_back("roof.jpg");
    imagesTexture.push_back("wall.jpg");
    imagesTexture.push_back("building_wall.jpg");
    imagesTexture.push_back("face3.png");
    imagesTexture.push_back("face1.png");
     imagesTexture.push_back("porte.png");

    int taille=imagesTexture.size();

    for(int i=0;i<taille;i++){

    QImage buf_tuile,tuile;
    buf_tuile.load(imagesTexture.at(i));
    tuile = QGLWidget::convertToGLFormat(buf_tuile);

    glGenTextures(taille, &_texture[i]);
    glBindTexture( GL_TEXTURE_2D, _texture[i] );
    glTexImage2D(GL_TEXTURE_2D, 0, 3, tuile.width(), tuile.height(),
                 0, GL_RGBA, GL_UNSIGNED_BYTE, tuile.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

}

}


