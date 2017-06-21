# include <opencv2/opencv.hpp>
# include "opencv2/imgproc/imgproc.hpp"
# include "opencv2/highgui/highgui.hpp"
# include "opencv2/imgcodecs.hpp"
# include <stdlib.h>
# include <iostream>
# include <unistd.h>
#include "opencv2/features2d.hpp"



using namespace cv;
using namespace std;

int main(void){
    Mat input, output, img;

    VideoCapture cap(0);
    if(!cap.isOpened()){
        return -1;
    }
    cap >> input;
    //input = imread("blob.jpg");

    std::vector<KeyPoint> keypoints;
    SimpleBlobDetector::Params params;

    params.minThreshold = 10;
    params.maxThreshold = 200;

    // Filter by Area.
    params.filterByArea = true;
    params.minArea = 1500;

    // Filter by Circularity
    params.filterByCircularity = true;
    params.minCircularity = 0.1;

    // Filter by Convexity
    params.filterByConvexity = true;
    params.minConvexity = 0.87;

    // Filter by Inertia
    params.filterByInertia = true;
    params.minInertiaRatio = 0.01;

    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
    while(1>0){
        cap>>input;

        detector->detect( input, keypoints );

        // Draw detected blobs as red circles.
        // DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures the size of the circle corresponds to the size of blob
        Mat im_with_keypoints;
        drawKeypoints( input, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
        drawKeypoints( input, keypoints, input, Scalar(0,200,0), DrawMatchesFlags::DEFAULT );
        imshow("srcssg", input);

        imshow("hey", im_with_keypoints);
        if(waitKey(2) >= 0) break;


    }

    //imshow("acax",input - im_with_keypoints);
    waitKey(0);
    destroyAllWindows();
    return 0;



}
