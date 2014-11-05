#ifndef TRAITEMENTIMAGE_H
#define TRAITEMENTIMAGE_H
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace cv;

class TraitementImage
{
public:
    TraitementImage(Mat *image);
    Mat TraitementPhase1();
    Mat TransformImageBlackWhite();
    Mat Erosion(int valueOfErosion);
    Mat Dilatation( int valueOfDilatation);
    Mat ZoneUniforme(Mat *Dilatation);
    Mat OughTransform();
    Mat affiche(char* const title);
    bool ProcedureTest();
    ~TraitementImage();
    vector<vector<Point> > exportcontour();
private:
    Mat *bilateral;
    Mat  *channel[3];
    Mat src;
    vector<vector<Point> > les_contours;
};

#endif // TRAITEMENTIMAGE_H
