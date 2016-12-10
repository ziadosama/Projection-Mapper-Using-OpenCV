#ifndef MATCHER_H
#define MATCHER_H
#include "corresponder.h"
#include "ccl.h"
#include "boundingboxescreator.h"


class Matcher
{
public:

    Matcher(const Mat&,const Mat&);
    vector<BoundingBox> getScene();
    vector<BoundingBox> getObject();

private:

    BoundingBoxesCreator boundingBoxesCreator;
    CCL ccl;
    vector<BoundingBox> getobjects; //draws rectangles around objects in objects image
    vector<BoundingBox> getScenes; //draws rectangles around objects in scenes
    vector<Mat> objects;
    void surfBoard(const Mat&);   //Surf and matching objects
    Mat binary; // a temporary Mat for getting objects
};

#endif // MATCHER_H
