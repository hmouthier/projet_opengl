#include "camera.h"
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
using namespace std;

camera::camera()
{

    vect1[0]=1;
    vect1[1]=0;
    vect1[2]=0;
    vect2[0]=0;
    vect2[1]=1;
    vect2[2]=0;
    vect3[0]=0;
    vect3[1]=0;
    vect3[2]=1;




    //    vect3[0]=XU-XC;
    //    vect3[1]=YU-YC;
    //    vect3[2]=ZU-ZC;

}
void camera::initcam(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(	XC, YC, ZC,
                XO, YO, ZO,
                XU,YU,ZU);
//cout << XC<<", "<< YC<<", "<<ZC<<", "<< XO<<", "<< YO<<", "<< ZO<<", "<<        XU<<", "<<YU<<", "<<ZU<< endl;
}


void camera::transl(float hori,float verti){
    XC+=hori*vect2[0]+verti*vect1[0];
    YC+=hori*vect2[1]+verti*vect1[1];
    ZC+=hori*vect2[2]+verti*vect1[2];

    XO+=hori*vect2[0]+verti*vect1[0];
    YO+=hori*vect2[1]+verti*vect1[1];
    ZO+=hori*vect2[2]+verti*vect1[2];

    XU=vect3[0];
    YU=vect3[1];
    ZU=vect3[2];
    //    vect1[0]=XO-XC;
    //    vect1[1]=YO-YC;
    //    vect1[2]=ZO-ZC;


    //vect2  = QVector3D::crossProduct(vect3,vect1);
    //vect3= QVector3D::crossProduct(vect1,vect2);
    //vect1.normalize();
    //vect3.normalize();
    //vect2.normalize();
//    cout <<"vect1 : "<< vect1[0] <<" "<< vect1[1]<<" "<< vect1[2]<<" vect2 : " << vect2[0]<<" "<< vect2[1]<<" "<< vect2[2]<<" vect3 : "<< vect3[0]<<" " << vect3[1]<<" "<< vect3[2] <<endl;

}
void camera::rotcam(float x,float y){
    vect1[1]-=x*0.005;
    vect2[0]+=x*0.005;
    vect1[2]+=y*0.005;
    vect3[0]-=y*0.005;


//    vect1.normalize();
//    vect2.normalize();
//    vect3.normalize();

    XO=XC-vect1[0]*1000;
    YO=YC-vect1[1]*1000;
    ZO=ZC-vect1[2]*1000;

}


QVector3D camera::quaternions(QVector3D axis,float RotationAngle,QVector3D vect){
    float x,y,z,w;

    x = axis[0] * sin(RotationAngle / 2);
    y =axis[1] * sin(RotationAngle / 2);
    z = axis[2] * sin(RotationAngle / 2);
    w = cos(RotationAngle / 2);

    QQuaternion monQuater=QQuaternion(w,x,y,z);
    return monQuater.rotatedVector(vect);


}
