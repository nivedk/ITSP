# include <opencv2/opencv.hpp>
# include "opencv2/imgproc/imgproc.hpp"
# include "opencv2/highgui/highgui.hpp"
# include "opencv2/imgcodecs.hpp"
# include <stdlib.h>
# include <iostream>
# include <unistd.h>

using namespace cv;
using namespace std;

int main(void){
    Mat input, output, img;

    VideoCapture cap(0);
    if(!cap.isOpened()){
        return -1;
    }

    Vec2i position;
    while(true){
        cap >> input;

        //usleep(100000);


        cvtColor(input, img, COLOR_BGR2GRAY);

        vector<Vec3f> circles;

        medianBlur(img, img, 5);


        //Check out the fourth parameter, not too clear about it
        HoughCircles(img, circles, CV_HOUGH_GRADIENT, 2, 10, 100, 50, 20, 100 );
        //position.push_back(Vec2i(circles[0][0], circles[0][1]));

        Vec3i circle1 = circles[0];
        cout<<"x: "<<circle1[0]<<" y: "<<circle1[1]<<endl;
        //circle(input, Point((int)circle[0], (int)circle[1]),circle[2], Scalar(40, 40, 40), 5);
        circle( input, Point(circle1[0], circle1[1]), circle1[2], Scalar(0,0,255), 3, LINE_AA);
        //cout<<"hey"<<endl;
        imshow("hey", input);
        //usleep(10000000);
        //cout<<"yo"<<endl;
        //destroyAllWindows();
        //cout<<"hello"<<endl;
        if(waitKey(1)>=0) break;
        //cout<<"yo"<<endl;
    }
    destroyAllWindows();
    return 0;



}
