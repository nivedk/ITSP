# include <opencv2/opencv.hpp>
# include "opencv2/imgproc/imgproc.hpp"
# include "opencv2/highgui/highgui.hpp"
# include "opencv2/imgcodecs.hpp"
# include <stdlib.h>
# include <iostream>
# include <unistd.h>
# include <vector>
# include <cmath>
# include <csignal>

using namespace cv;
using namespace std;

vector<Point> centres;

double getSlope(){
    double xSum = 0, ySum = 0;
    for(int i = 0; i<centres.size();i++){
        xSum = xSum + centres[i].x;
        ySum = ySum + centres[i].y;
    }
    double num = 0, den = 0;
    for(int i = 0; i<centres.size(); i++){

        num = num + (centres[i].x - xSum/(centres.size()+1))*(centres[i].y - ySum/(centres.size()+1));
        den = den + (centres[i].x - xSum/(centres.size()+1))*(centres[i].x - xSum/(centres.size()+1));

    }
    return num/den;

}

double getYInt(double slope){
    double xSum = 0, ySum = 0;

    for(int i = 0; i<centres.size();i++){
        xSum = xSum + centres[i].x;
        ySum = ySum + centres[i].y;
    }
    return (ySum/(centres.size()+1) - slope*xSum/(centres.size()+1));
}




int main(void){
    Mat input, output, img;
    double slope, yInt;

    VideoCapture cap(0);
    if(!cap.isOpened()){
        return -1;
    }

    cap>>input;

    Vec2i position;
    int loopcount;
    while(true){
        loopcount++;
        cap >> input;
        //cout <<  input.cols<<endl;
        //raise(SIGINT);
        if(input.empty()){
            cout << "can not open " << endl;
            continue;
        }

        //usleep(100000);


        cvtColor(input, img, COLOR_BGR2GRAY);

        threshold(img, img, 150, 255, THRESH_BINARY);

        //imshow("hey", img);
        //waitKey(0);
        vector<Vec3f> circles;

        medianBlur(img, img, 17);


        //Check out the fourth parameter, not too clear about it
        HoughCircles(img, circles, CV_HOUGH_GRADIENT, 2, 190, 100, 50,60, 200 );
        //position.push_back(Vec2i(circles[0][0], circles[0][1]));

        /*
        Vec3i circle1 = circles[0];
        cout<<"x: "<<circle1[0]<<" y: "<<circle1[1]<<endl;
        //circle(input, Point((int)circle[0], (int)circle[1]),circle[2], Scalar(40, 40, 40), 5);
        circle( input, Point(circle1[0], circle1[1]), circle1[2], Scalar(0,0,255), 3, LINE_AA);
        circle1 = circles[1];
        cout<<"x: "<<circle1[0]<<" y: "<<circle1[1]<<endl;
        //circle(input, Point((int)circle[0], (int)circle[1]),circle[2], Scalar(40, 40, 40), 5);
        circle( input, Point(circle1[0], circle1[1]), circle1[2], Scalar(0,255,255), 3, LINE_AA);

        */
        for(int i = 0; i<circles.size();i++){
            Vec3i circle1 = circles[i];
            circle( input, Point(circle1[0], circle1[1]), circle1[2], Scalar(0,0,255), 3, LINE_AA);
            centres.push_back(Point(circle1[0], circle1[1]));
        }
        //cout<<circles.size();
        //cout<<"hey"<<endl;

        if(centres.size()>1){
            slope = getSlope();
            yInt = getYInt(slope);

        }

        line(input, Point(0,yInt), Point(1200, slope*1200 + yInt), Scalar(200, 200, 200));

        imshow("hey", input);
        //usleep(10000000);
        //cout<<"yo"<<endl;
        //destroyAllWindows();
        //cout<<"hello"<<endl;
        if(waitKey(1)>=0){
            cout<<"loopcount :  "<<loopcount<<endl;
            break;

        }
        //cout<<"yo"<<endl;
    }
    destroyAllWindows();
    return 0;



}
