#ifndef RENDERER_H
#define RENDERER_H
#include"matcher.h"


class Renderer
{
public:
    Renderer(const Mat&,const Mat&,const Mat&);
    void performRender(const Mat&, const Mat&);

private:
    vector<BoundingBox> getObjects; //draws rectangles around objects in objects image
    vector<BoundingBox> getScenes; //draws rectangles around objects in scenes
    Mat drawScene;
};

#endif // RENDERER_H
