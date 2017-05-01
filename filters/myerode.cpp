//This is the first opencv code tht I wrote completely on my own
//It is an implementation of the erode filter kind of like blurring it.
//It's probably not as efficient as the inbuilt opencv one

# include "opencv2/imgproc/imgproc.hpp"
# include "opencv2/highgui/highgui.hpp"
# include <stdlib.h>
# include <stdio.h>

using namespace cv;

int main(){
  Mat input, output, kernel;
  //Each pixel is replaced by the dot of this matrix with the 3x3 matrix around it
  //the kernel for eroding/blurring
  //kernel = (Mat_<double>(3,3)<<1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0);
  kernel = (Mat_<double>(3,3)<<0, -1, 0, -1, 5, -1, 0, -1, 0);
  input = imread("Image.jpeg");

  //The third parameter iss for depth, i.e, the number of bits that are used to represent a colour.
  //the value sets the depth to 8 bits
  filter2D(input, output, -1, kernel);
  filter2D(output, output, -1, kernel);
  //filter2D(output, output, -1, kernel);
  //filter2D(output, output, -1, kernel);

  while(true){
    imshow("original", input);
    imshow("eroded",output);
    imshow("diff", input - output);
    waitKey(0);
  	destroyAllWindows();
    break;
  }
}
