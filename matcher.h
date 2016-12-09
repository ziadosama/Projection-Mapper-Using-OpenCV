#ifndef MATCHER_H
#define MATCHER_H
#include "corresponder.h"
#include "ccl.h"
#include "boundingboxescreator.h"


class Matcher
{
public:
    struct sceneCorners
    {
        Point2f point1,point2,point3,point4;
    };
    Matcher(const Mat&, Mat&);
    vector<sceneCorners> getScene();

private:
    BoundingBoxesCreator boundingBoxesCreator;
    CCL ccl;
    vector<sceneCorners> getScenes; //draws rectangles around objects in scenes
    vector<Mat> objects;
    void surfBoard(Mat&);   //Surf and matching objects
    Mat binary; // a temporary Mat for getting objects
};

#endif // MATCHER_H
