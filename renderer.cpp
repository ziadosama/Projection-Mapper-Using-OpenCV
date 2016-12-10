#include "renderer.h"

Renderer::Renderer(const Mat& image,const Mat& scene, const Mat& texture){

    Matcher match(image,scene);
    getObjects=match.getObject();
    getScenes=match.getScene();
    performRender(scene,texture);
}

void Renderer::performRender(const Mat& scene, const Mat& texture){
    scene.copyTo(drawScene);
    for(int i=0; i<getObjects.size();i++){

        double sceneArea, objectArea;
        vector<Point> sceneTemp,objectTemp; //a vector to extract the points and calculate both areas

        sceneTemp.push_back(getScenes[i].getCorner1());
        sceneTemp.push_back(getScenes[i].getCorner2());
        sceneTemp.push_back(getScenes[i].getCorner3());
        sceneTemp.push_back(getScenes[i].getCorner4());
        sceneArea=contourArea(sceneTemp);   //returns the area of the four points

        objectTemp.push_back(getObjects[i].getCorner1());
        objectTemp.push_back(getObjects[i].getCorner2());
        objectTemp.push_back(getObjects[i].getCorner3());
        objectTemp.push_back(getObjects[i].getCorner4());
        objectArea=contourArea(objectTemp);  //returns the area of the four points

        double scaleFactor=sceneArea/objectArea;    //gets a scale factor

        Mat tempTexture=texture(Rect(getObjects[i].getCorner1(),getObjects[i].getCorner4()));
        resize(tempTexture,tempTexture,Size(0,0),scaleFactor,scaleFactor);//resizes the texture image by the scale factor to make both the same size

        for(int i=getScenes[i].getCorner1().x;i<=getScenes[i].getCorner4().x;i++)
            for(int j=getScenes[i].getCorner1().y;i<=getScenes[i].getCorner4().y;j++){

                drawScene.at<uchar>(i,j)=tempTexture.at<uchar>(i,j);

            }
    }
}
