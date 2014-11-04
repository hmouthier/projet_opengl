#include "traitementimage.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

TraitementImage::TraitementImage(Mat *image)
{
    src =*image;
    Mat Equalize, Dilatation2;

    cout << "type" << image->type();

    TraitementPhase1();

    TransformImageBlackWhite();
    Erosion(1);
    Dilatation(1);
    ZoneUniforme(&src);

    Mat canny_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    RNG rng(12345);
    //  Test(ImageSource);
    /// Detect edges using canny
    Canny( src, canny_output, 100, 100*2, 3 );
    /// Find contours
    findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    /// Draw contours
    Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    for( int i = 0; i< contours.size(); i++ )
    {
        if (contours.at(i).size() > 50)
        {
            Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
            drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
        }
    }

}

Mat TraitementImage::TraitementPhase1(){

    // Initialisation
    int z=61;
    Mat bilateral,equalize,channel[3],rouge, vert,bleu;

    /// Apply Bilateral Filter
    bilateralFilter(src, bilateral, z,z,z);

    /// Extract Channel Red
    split(bilateral, channel);
    rouge = channel[2];
    bleu = channel[0];
    vert = channel[1];


    /// Apply Histogram Equalization
    equalizeHist( rouge, src ); // prend en entrée l'image en niveau de gris, crée une image equalize

    return src;
}

Mat TraitementImage::TransformImageBlackWhite(){
    /// On passe toutes les pixels inférieurs à un seuil en noir
    for(int j=0;j<src.rows;j++)
    {
        for (int i=0;i<src.cols;i++)
        {
            if( src.at<uchar>(j,i)<180)
                src.at<uchar>(j,i) = 0; //white
            else
                src.at<uchar>(j,i) = 255; //white

        }
    }
    return src;

}

Mat TraitementImage::Erosion(int valueOfErosion){

    erode(src,src, Mat(), Point(-1,-1),valueOfErosion,1,1);
    return src;
}

Mat TraitementImage::Dilatation(int valueOfDilatation){

    dilate(src,src, Mat(), Point(-1,-1),valueOfDilatation,1,1);
    return src;
}

Mat TraitementImage::ZoneUniforme(Mat *Dilatation) {
    Mat imageDilatation = *Dilatation;

    Mat imageSoustraction,image_thresh, mask;

    Mat A= Mat::ones(imageDilatation.rows,imageDilatation.cols,CV_8U);

    imageSoustraction = src-(A*255 - imageDilatation);


    threshold(imageSoustraction, image_thresh, 125, 255, THRESH_BINARY);

    // Loop through the border pixels and if they're black, floodFill from there

    image_thresh.copyTo(mask);
    for (int i = 0; i < mask.cols; i++) {
        if (mask.at<char>(0, i) == 0) {
            floodFill(mask, Point(i, 0), 255, 0, 10, 10);
        }
        if (mask.at<char>(mask.rows-1, i) == 0) {
            floodFill(mask, Point(i, mask.rows-1), 255, 0, 10, 10);
        }
    }
    for (int i = 0; i < mask.rows; i++) {
        if (mask.at<char>(i, 0) == 0) {
            floodFill(mask, Point(0, i), 255, 0, 10, 10);
        }
        if (mask.at<char>(i, mask.cols-1) == 0) {
            floodFill(mask, Point(mask.cols-1, i), 255, 0, 10, 10);
        }
    }


    // Compare mask with original.

    for (int row = 0; row < mask.rows; ++row) {
        for (int col = 0; col < mask.cols; ++col) {
            if (mask.at<char>(row, col) == 0) {
                src.at<char>(row, col) = 255;
            }
        }

    }
    return src;

}


Mat TraitementImage::OughTransform(){
    Mat imageFinal;
    src.copyTo(imageFinal);
    cvtColor(imageFinal, src, CV_GRAY2BGR);
    vector<Vec4i> lines;
    HoughLinesP(imageFinal, lines, 1, CV_PI/180, 10, 10, 10 );
    for( size_t i = 0; i < lines.size(); i++ )
    {
        Vec4i l = lines[i];
        line( src, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
    }
    return src;

}

Mat TraitementImage::affiche(char* const title){
    namedWindow(title, CV_WINDOW_AUTOSIZE );
    imshow(title, src);
    //wait for a key press infinitely
    waitKey(0);
}

TraitementImage::~TraitementImage(){

}
