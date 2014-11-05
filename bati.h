#ifndef BATI_H
#define BATI_H
#include <vector>
#include "forme.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace cv;
class bati
{
public:
    bati();
    bati(int );

    void draw4();
    void draw3(float);
    void draw2(float);
    void draw();
    void drawgeneral(vector<Point>);
    void drawtotal(vector<vector<Point> > );
    //~bati();
};

#endif // BATI_H
