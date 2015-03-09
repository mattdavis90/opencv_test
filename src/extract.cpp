#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <iomanip>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        cout << "Usage:" << endl;
        cout << "\t" << argv[0] << " <input> <output-dir>" << endl;

        return -1;
    }

    string output_dir = string(argv[2]);
    char last_char = *output_dir.rbegin();
    if(last_char != '/')
    {
        output_dir += '/';
    }

    VideoCapture cap;
    cap.open(argv[1]);
    
    if(!cap.isOpened())
    {
        cout << "Can't open file" << endl;
        return -1;
    }

    int k = 0;

    Mat curr;
    cap >> curr;

    while(curr.data != NULL)
    {
        stringstream filename;
        filename << output_dir << setfill('0') << setw(8) << k << ".png";
        imwrite(filename.str(), curr);
        
        k++;
        cap >> curr;
    }

    return 0;
}

