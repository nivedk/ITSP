# include <opencv2/opencv.hpp>
# include <iostream>
# include <unistd.h>

using namespace std;
using namespace cv;

int main(){
  VideoCapture cap(0);
  if(!cap.isOpened()){
    return -1;
  }

  Mat frame1, frame2, frame3;
  cap >> frame1;
  usleep(100000);
  cap >> frame2;
  usleep(100000);
  cap>> frame3;

  imshow("2-1",frame2 - frame1);
  imshow("3-1",frame3 - frame1);
  waitKey(0);
  destroyAllWindows();
  return 0;  
}
