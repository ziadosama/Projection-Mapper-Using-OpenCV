#include "mainwindow.h"
#include <QApplication>
#include "corresponder.h"
#include "ccl.h"
#include "boundingboxescreator.h"
#include "matcher.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    vector<Matcher::sceneCorners> sceneObjects;

    Mat image = imread("Images/Object.jpg");
    Mat scene = imread("Images/Scene2.jpg");

    imshow("Image", image);
    Matcher match(image,scene);   //gets objects from the objects image
    sceneObjects=match.getScene();

    return a.exec();
}
