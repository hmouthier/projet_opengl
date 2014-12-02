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

/**
 * \file      Export des contours
 * \author    Baddredine, Hippolyte, Sana
 * \version   1.0
 * \date      28 Novembre 2014
 * \brief     Traitement d'image permettant l'export des contours
 *
 * \details    Cette classe permet d'effectuer les différents traitements sur l'image raster d'origine,
 *             pour obtenir les contours vectoriels des batiments, de la route et de la végétation
 */

class TraitementImage
{

public:

    /**
     * \brief       Constructeur permettant de récuperer les contours
     * \details     Le constructeur lance l'ensemble des fonctions qui vont récuperer
     *              les contours des batiments, des routes et de la végétation
     *
     * \param[in]    image    Image en entrée
     */
    TraitementImage(Mat *image);

    // Detection et classification des objets

    /**
     * \brief:      Detection de la végetation sur l'image source
     *
     * \detail:     La fonction va classifier la végétation grâce à un seuillage.
     *              On crée ensuite un masque de celui-ci et on soustrait la
     *              végétation de l'image source
     *
     * \return      Retourne un masque de type matrice
     */
    Mat DetectionVegetation();

    /**
     * \brief:      Detection de la route sur l'image source
     *
     * \detail:     La fonction va appeler les fonctions d'érosion et de dilatation.
     *              puis grâce à une classification des pixels on créera un masque de la route.
     *
     * \return      Retourne un masque de type matrice
     */
    Mat pixelOfRoad();


    /**
     * \brief:      Traçage de la route sur l'image source
     *
     * \detail:     La fonction récupère le masque généré par la fonction pixelroad, et effectue une dilatation sur celui-ci.
     *              Puis, elle va appliquer le masque sur l'image d'origine afin d'y tracer la route.
     */
    void Road();


    /**
     * \brief:      Detection des batiments sur l'image source
     *
     * \detail:     La fonction va effectuer un filtre bilatéral sur l'image d'origine afin de diminuer le bruit et autres perturbations,
     *              tout en préservant les contours de l'image.A partir du canal rouge de l'image,une égalisation de l'histogramme va permettre
     *              d'ajuster les constrastes de l'image et de redistribuer l'intensité des pixels.
     *              Tous les pixels en dessous d'un seuil seront ensuite mis en noir.
     *              Des erosions et des dilatations de l'image permettra ensuite de ne garder que les entités les plus significatives.
     *              Les contours sont ensuites extrait via une liste de point grâce la fonction Canny puis, Findcontour d'OpenCV.
     *              Afin d'obtenir des formes rectangulaires, on utilise une fonction Rectangle Englobant et on récupère une liste
     *              de quadrilatère que l'on stocke dans une variable privée.
     *
     * \param[in]   image    Image en entrée
     * \return      Retourne un masque de type matrice
     */
    Mat BatimentTraitement(Mat& image);


    // Dilatation et Erosion

    /**
     * \brief:      Fonction de dilatation d'une image
     *
     * \detail:     La fonction effectue une dilatation de l'image, avec un kernel en ellipse.
     *
     * \param[in]   image    Image en entrée
     * \param[in]   valueOfDilatation    Valeur de la dilatation souhaité
     */
    Mat Dilatation(Mat image, int valueOfDilatation);

    /**
     * \brief:      Fonction d'erosion d'une image
     *
     * \detail:     La fonction effectue une erosion de l'image, avec un kernel en ellipse.
     *
     * \param[in]   image    Image en entrée
     * \param[in]   valueOfErosion    Valeur de la dilatation souhaité
     */
    Mat Erosion(Mat image,int valueOfErosion);

    // Squeletisation
    /**
     * \brief:      Fonction de squeletisation d'une image
     *
     * \detail:     Effectue une opperation d'amincissement
     *
     * \param[in]   img    Prend une image binaire : (0,1)
     * \param[in]   iter    0:pair 1:impair
     */
    Mat thinningIteration(Mat& img, int iter);

    /**
     * \brief:      Appel de la fonction de squeletisation d'une image
     *
     * \detail:     Effectue une opperation d'amincissement
     */
    Mat thinning();


    // Detection et récupération des contours
    /**
     * \brief:      Fonction qui va trouver les contours de l'image
     *
     * \detail:     La fonction va effectuer une fonction Canny, puis un find contour
     *              afin de récupérer une liste de point des contours.
     *
     * \param[in]   imageFindContour    Prend une image RGB en entrée
     *
     * \return      Retourne une liste de point des contours
     */
    vector <vector<Point> > ObjectfindContour(Mat& imageFindContour);

    /**
     * \brief:      Récupère la matrice src_plus_road
     *
     * \return      Retourne une matrice
     */
    Mat exportRoad();

    /**
     * \brief:      Récupère les contours de la végétation
     *
     * \return      Retourne une liste de point des contours
     */
    vector<vector<Point> > exportcontourveget();

    /**
     * \brief:      Récupère les contours des bâtiments
     *
     * \return      Retourne une liste de quadrilatère
     */
    vector<RotatedRect> exportcontourBati();


    // Destructeur
    ~TraitementImage();

private:

    // Image
    Mat src;
    Mat srcVeg;
    Mat srcRoad;
    Mat src_plus_road;

    // Export contours
    vector<vector<Point> > vegetContours;
    vector<RotatedRect> batiContours;

};

#endif // TRAITEMENTIMAGE_H
