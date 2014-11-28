#ifndef TRAITEMENTIMAGE_H
#define TRAITEMENTIMAGE_H

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>


using namespace cv;
using namespace std;

class TraitementImage
{
public:
    TraitementImage(Mat *image);

    /// Destructeur
    ~TraitementImage();

    /// Detection des contours
    vector <vector<Point> > ObjectfindContour(Mat& imageFindContour);
    Mat BatimentTraitement(Mat& image);
    vector<vector<Point> > exportcontourveget();
    vector<RotatedRect> exportcontourBati();


    /// Classification des objets
    Mat DetectionBatiment(Mat& image);
    Mat DetectionVegetation();
    Mat RemplaceValuePixel(Mat& image, int minRouge, int maxRouge, int minBleu, int maxBleu, int minVert, int maxVert);
    Mat pixelOfRoad();
    void Road();
    Mat exportRoad();

    /// Dilatation et Erosion
    Mat Dilatation(Mat image, int valueOfDilatation);
    Mat Erosion(Mat image,int valueOfErosion);

    /// Squelet.
    Mat thinningIteration(Mat& img, int iter);
    Mat thinning();

    /// Visualisation des images
    Mat affiche(Mat& image, char* const title);



private:
    Mat src;
    Mat srcVeg;
    Mat srcRoad;
    Mat src_plus_road;
    vector<vector<Point> > vegetContours;
    vector<RotatedRect> batiContours;
};

#endif // TRAITEMENTIMAGE_H
