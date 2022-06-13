#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>


#include "dilatation.h"
#include "resize.h"
#include "lightenDarken.h"
#include "panorama.h"
#include "canny.h"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    String dogImage = "/Users/dys/Desktop/Multimedia_FinalProject/Multimedia_FinalProject/dogImage.jpg";
    String lenaImage = "/Users/dys/Desktop/Multimedia_FinalProject/Multimedia_FinalProject/lena.png";

    cout << "Hello, Welcome to Gimp Project! Type the menu number you want to try." << "\n";

    while(1){
        int menu_num = 0;
        cout << "===========Menu===========" << "\n";
        cout << "  1: Dilatation / erosion" << "\n";
        cout << "  2: Resizing" << "\n";;
        cout << "  3: Lighten / darken" << "\n";;
        cout << "  4: Panorama / stitching" << "\n";;
        cout << "  5: Canny edge detection" << "\n";
        cout << "============================" << "\n\n";
        cin >> menu_num;

        if (menu_num == 1) {
            cout << "-- Menu1: Dilatation / erosion --" << "\n";
            myDilatationFunction(lenaImage);
            waitKey(2000);
            continue;
        } else if (menu_num == 2) {
            cout << "-- Menu2: Resizing --" << "\n";
            myResizeFunction(dogImage);
            waitKey(2000);
            continue;
        } else if (menu_num == 3) {
            cout << "-- Menu3: Lighten / darken --" << "\n";
            myLightDarkFunction(lenaImage);
            waitKey(2000);
            continue;
        } else if (menu_num == 4) {
            cout << "-- Menu4: Panorama / stitching --" << "\n";
            myPanoramaFunction();
            waitKey(2000);
            continue;
        } else if (menu_num == 5) {
            cout << "-- Menu5: Canny edge detection --" << "\n";
            myCannyFunction(lenaImage);
            waitKey(2000);
            continue;
        } else {
            cout << "Thank you for using our Gimp. Goodbye!" << "\n";
            break;
        }
    }
    return 0;
}
