#include "mainwindow.h"
#include <QApplication>
#include "renderer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Mat image = imread("Images/object.jpg");
    Mat scene = imread("Images/scene.jpg");
    Mat texture = imread("Images/texture.jpg");
    imshow("Image", image);
    Renderer render(image,scene);
    render.performRender(texture);
    return a.exec();
}
