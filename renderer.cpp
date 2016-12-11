#include "renderer.h"

Renderer::Renderer(const Mat& image,const Mat& scene){

    Matcher match(image,scene);
    getObjects=match.getObject();
    getScenes=match.getScene();
    scene.copyTo(drawScene);
//    performRender(scene,texture);
}

void Renderer::performRender(const Mat& texture){
    for(int i=0; i<getScenes.size();i++){

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

        int scaleFactor;
        if(objectArea>0)
           scaleFactor=sceneArea/objectArea;    //gets a scale factor
        else scaleFactor=1;
        if(scaleFactor==0) scaleFactor=1;

        Rect tempRectangle=boundingRect(objectTemp);
        Mat tempTexture=texture(tempRectangle);
        resize(tempTexture,tempTexture,Size(0,0),scaleFactor,scaleFactor);//resizes the texture image by the scale factor to make both the same size

        int minX,maxX,minY,maxY;
        minX=tempRectangle.x;
        maxX=tempRectangle.x+tempRectangle.width;
        minY=tempRectangle.y;
        maxY=tempRectangle.y+tempRectangle.height;

        for(int j=minX;j<maxX;j++)
            for(int k=minY;k<maxY;k++){

                drawScene.at<Vec3b>(k,j)[0]=tempTexture.at<Vec3b>(k,j)[0];
                drawScene.at<Vec3b>(k,j)[1]=tempTexture.at<Vec3b>(k,j)[1];
                drawScene.at<Vec3b>(k,j)[2]=tempTexture.at<Vec3b>(k,j)[2];

            }
    }
    imshow("scene updated",drawScene);
    imwrite("Images/updaedScene.jpg",drawScene);
}
