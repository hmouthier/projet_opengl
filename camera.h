#ifndef CAMERA_H
#define CAMERA_H
#include <QVector3D>
class camera
{
public:
    camera();
    void initcam();
    void rotcam(float,float);
    void transl(float,float);
    QVector3D quaternions(QVector3D ,float ,QVector3D );
private :
    QVector3D vect1,vect2,vect3;
    float  XC=100.0f,YC=0.0f,ZC=0.0f,XO=00.0f,YO=0.0f,ZO=0.0f,XU=0.0f,YU=0.0f,ZU=1.0f;

};

#endif // CAMERA_H
