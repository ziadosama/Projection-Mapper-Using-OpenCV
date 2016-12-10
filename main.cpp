#include "mainwindow.h"
#include <QApplication>
#include "renderer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Mat image = imread("Images/Object.jpg");
    Mat scene = imread("Images/Scene2.jpg");
    //Mat texture = imread("Images/Texture.jpg");
    imshow("Image", image);
    //Renderer render(image,scene,texture);

    return a.exec();
}
