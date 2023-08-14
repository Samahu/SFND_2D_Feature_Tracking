/* INCLUDES FOR THIS PROJECT */
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include <map>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

#include "dataStructures.h"
#include "matching2D.hpp"

using namespace std;

/* MAIN PROGRAM */
int main(int argc, const char *argv[])
{

    /* INIT VARIABLES AND DATA STRUCTURES */

    // data location
    string dataPath = "../";

    // camera
    string imgBasePath = dataPath + "images/";
    string imgPrefix = "KITTI/2011_09_26/image_00/data/000000"; // left camera, color
    string imgFileType = ".png";
    int imgStartIndex = 0; // first file index to load (assumes Lidar and camera names have identical naming convention)
    int imgEndIndex = 9;   // last file index to load
    int imgFillWidth = 4;  // no. of digits which make up the file index (e.g. img-0001.png)

    // misc
    int dataBufferSize = 2;       // no. of images which are held in memory (ring buffer) at the same time
    vector<DataFrame> dataBuffer; // list of data frames which are held in memory at the same time
    bool bVis = false;            // visualize results

    /* MAIN LOOP OVER ALL IMAGES */

    std::vector<std::tuple<string, string, string>> detector_desscriptor_combinations = {
        {"SHITOMASI", "BRISK", "MAT_BF"},
        {"SHITOMASI", "BRIEF", "MAT_FLANN"},
        {"SHITOMASI", "ORB", "MAT_FLANN"},
        {"SHITOMASI", "FREAK", "MAT_FLANN"},
        {"SHITOMASI", "AKAZE", "MAT_FLANN"},   // crash
        {"SHITOMASI", "SIFT", "MAT_FLANN"},

        {"HARRIS", "BRISK", "MAT_FLANN"},
        {"HARRIS", "BRIEF", "MAT_FLANN"},
        {"HARRIS", "ORB", "MAT_FLANN"},
        {"HARRIS", "FREAK", "MAT_FLANN"},
        {"HARRIS", "AKAZE", "MAT_FLANN"},   // crash
        {"HARRIS", "SIFT", "MAT_FLANN"},

        {"FAST", "BRISK", "MAT_FLANN"},
        {"FAST", "BRIEF", "MAT_FLANN"},
        {"FAST", "ORB", "MAT_FLANN"},
        {"FAST", "FREAK", "MAT_FLANN"},    // crash
        {"FAST", "AKAZE", "MAT_FLANN"},     // crash
        {"FAST", "SIFT", "MAT_FLANN"},

        {"BRISK", "BRISK", "MAT_FLANN"},
        {"BRISK", "BRIEF", "MAT_FLANN"},
        {"BRISK", "ORB", "MAT_FLANN"},
        {"BRISK", "FREAK", "MAT_FLANN"},   //?
        {"BRISK", "AKAZE", "MAT_FLANN"},
        {"BRISK", "SIFT", "MAT_FLANN"},

        {"ORB", "BRISK", "MAT_FLANN"},
        {"ORB", "BRIEF", "MAT_FLANN"},
        {"ORB", "ORB", "MAT_FLANN"},
        {"ORB", "FREAK", "MAT_FLANN"},
        {"ORB", "AKAZE", "MAT_FLANN"},
        {"ORB", "SIFT", "MAT_FLANN"},

        {"AKAZE", "BRISK", "MAT_FLANN"},
        {"AKAZE", "BRIEF", "MAT_FLANN"},
        {"AKAZE", "ORB", "MAT_FLANN"},
        {"AKAZE", "FREAK", "MAT_FLANN"},
        {"AKAZE", "AKAZE", "MAT_FLANN"},
        {"AKAZE", "SIFT", "MAT_FLANN"},

        {"SIFT", "BRISK", "MAT_FLANN"},
        {"SIFT", "BRIEF", "MAT_FLANN"},
        {"SIFT", "ORB", "MAT_FLANN"},
        {"SIFT", "FREAK", "MAT_FLANN"},
        {"SIFT", "AKAZE", "MAT_FLANN"},
        {"SIFT", "SIFT", "MAT_FLANN"},
    };

    for (auto kv : detector_desscriptor_combinations) {

    int total_detected_points = 0;
    int total_matches = 0;
    double total_detection_time = 0;
    double total_extraction_time = 0;
    string detectorType = std::get<0>(kv);   // SHITOMASI, HARRIS, FAST, BRISK, ORB, AKAZE, SIFT
    string descriptorName = std::get<1>(kv); // BRISK, BRIEF, ORB, FREAK, AKAZE, SIFT
    string matcherType = std::get<2>(kv);    // MAT_BF, MAT_FLANN
    string descriptorType = "DES_HOG"; // DES_BINARY, DES_HOG
    string selectorType = "SEL_KNN";       // SEL_NN, SEL_KNN

    try {


    for (size_t imgIndex = 0; imgIndex <= imgEndIndex - imgStartIndex; imgIndex++)
    {
        /* LOAD IMAGE INTO BUFFER */

        // assemble filenames for current index
        ostringstream imgNumber;
        imgNumber << setfill('0') << setw(imgFillWidth) << imgStartIndex + imgIndex;
        string imgFullFilename = imgBasePath + imgPrefix + imgNumber.str() + imgFileType;

        // load image from file and convert to grayscale
        cv::Mat img, imgGray;
        img = cv::imread(imgFullFilename);
        cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

        //// STUDENT ASSIGNMENT
        //// TASK MP.1 -> replace the following code with ring buffer of size dataBufferSize

        if (dataBuffer.size() >= dataBufferSize) {
            // We are going to exceed our alotted size so remove the oldest element.
            dataBuffer.erase(dataBuffer.begin());
        }

        // push image into data frame buffer
        DataFrame frame;
        frame.cameraImg = imgGray;
        dataBuffer.push_back(frame);

        //// EOF STUDENT ASSIGNMENT
        // cout << "#1 : LOAD IMAGE INTO BUFFER done" << endl;

        /* DETECT IMAGE KEYPOINTS */

        // extract 2D keypoints from current image
        vector<cv::KeyPoint> keypoints; // create empty feature list for current image

        //// STUDENT ASSIGNMENT
        //// TASK MP.2 -> add the following keypoint detectors in file matching2D.cpp and enable string-based selection based on detectorType
        //// -> HARRIS, FAST, BRISK, ORB, AKAZE, SIFT

        // Apply corner detection
        double t = (double)cv::getTickCount();

        if (detectorType.compare("SHITOMASI") == 0)
        {
            detKeypointsShiTomasi(keypoints, imgGray, bVis);
        }
        else if (detectorType.compare("HARRIS") == 0)
        {
           detKeypointsHarris(keypoints, imgGray, bVis);
        }
        else
        {
            detKeypointsModern(keypoints, imgGray, detectorType, bVis);
        }
        t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
        // cout << detectorType << " took " << 1000 * t / 1.0 << " ms" << endl;
        total_detection_time += t;

        //// EOF STUDENT ASSIGNMENT

        //// STUDENT ASSIGNMENT
        //// TASK MP.3 -> only keep keypoints on the preceding vehicle

        // only keep keypoints on the preceding vehicle
        bool bFocusOnVehicle = true;
        cv::Rect vehicleRect(535, 180, 180, 150);
        std::map<int, int> hist;
        
        if (bFocusOnVehicle)
        {
            // cout << "filtering points with rect: " << vehicleRect << endl;
            // cout << "number of points before filter: " << keypoints.size();
            for (auto it = keypoints.begin(); it != keypoints.end();) {
                if (vehicleRect.contains(it->pt)) {
                    int bin = (int(it->size) / 10) * 10; 
                    ++hist[bin];
                    ++it;
                }
                else
                {
                    it = keypoints.erase(it);
                }
            }
            // cout << ", after filter: " << keypoints.size() << endl;
        }

        static int img_nb = 0;
        // cout << "image: " << ++img_nb << ";number of selected key points for focus vehicle = " << keypoints.size() << endl;
        /*
        for (const auto& kv : hist)
            cout << "size: " << kv.first << ", count: " << kv.second << endl;
        */
        // cout << "=====" << endl;

        //// EOF STUDENT ASSIGNMENT

        // optional : limit number of keypoints (helpful for debugging and learning)
        bool bLimitKpts = false;
        if (bLimitKpts)
        {
            int maxKeypoints = 20;

            if (detectorType.compare("SHITOMASI") == 0)
            { // there is no response info, so keep the first 50 as they are sorted in descending quality order
                keypoints.erase(keypoints.begin() + maxKeypoints, keypoints.end());
            }
            cv::KeyPointsFilter::retainBest(keypoints, maxKeypoints);
            cout << " NOTE: Keypoints have been limited!" << endl;
        }

        // push keypoints and descriptor for current frame to end of data buffer
        (dataBuffer.end() - 1)->keypoints = keypoints;
        total_detected_points += keypoints.size();
        // cout << "#2 : DETECT KEYPOINTS done" << endl;

        /* EXTRACT KEYPOINT DESCRIPTORS */

        //// STUDENT ASSIGNMENT
        //// TASK MP.4 -> add the following descriptors in file matching2D.cpp and enable string-based selection based on descriptorName
        //// -> BRIEF, ORB, FREAK, AKAZE, SIFT

        cv::Mat descriptors;
        descKeypoints((dataBuffer.end() - 1)->keypoints, (dataBuffer.end() - 1)->cameraImg, descriptors, descriptorName);
        //// EOF STUDENT ASSIGNMENT

        // push descriptors for current frame to end of data buffer
        (dataBuffer.end() - 1)->descriptors = descriptors;

        // cout << "#3 : EXTRACT DESCRIPTORS done" << endl;

        if (dataBuffer.size() > 1) // wait until at least two images have been processed
        {

            /* MATCH KEYPOINT DESCRIPTORS */

            vector<cv::DMatch> matches;
            

            //// STUDENT ASSIGNMENT
            //// TASK MP.5 -> add FLANN matching in file matching2D.cpp
            //// TASK MP.6 -> add KNN match selection and perform descriptor distance ratio filtering with t=0.8 in file matching2D.cpp

            double t = (double)cv::getTickCount();

            matchDescriptors((dataBuffer.end() - 2)->keypoints, (dataBuffer.end() - 1)->keypoints,
                             (dataBuffer.end() - 2)->descriptors, (dataBuffer.end() - 1)->descriptors,
                             matches, descriptorType, matcherType, selectorType);

            t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
            // cout << detectorType << " took " << 1000 * t / 1.0 << " ms" << endl;
            total_extraction_time += t;

            //// EOF STUDENT ASSIGNMENT

            // store matches in current data frame
            (dataBuffer.end() - 1)->kptMatches = matches;

            // cout << "#4 : MATCH KEYPOINT DESCRIPTORS done" << endl;

            // cout << "matches = " << matches.size() << endl;
            total_matches += matches.size();

            // visualize matches between current and previous image
            bVis = false;
            if (bVis)
            {
                cv::Mat matchImg = ((dataBuffer.end() - 1)->cameraImg).clone();
                cv::drawMatches((dataBuffer.end() - 2)->cameraImg, (dataBuffer.end() - 2)->keypoints,
                                (dataBuffer.end() - 1)->cameraImg, (dataBuffer.end() - 1)->keypoints,
                                matches, matchImg,
                                cv::Scalar::all(-1), cv::Scalar::all(-1),
                                vector<char>(), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

                string windowName = "Matching keypoints between two camera images";
                cv::namedWindow(windowName, 7);
                cv::imshow(windowName, matchImg);
                cout << "Press key to continue to next image" << endl;
                cv::waitKey(0); // wait for key to be pressed
            }
            bVis = false;
        }

    } // eof loop over all images

    cout << "detector: " << detectorType << ",\tdescriptor: " << descriptorName
        << ",\tpoints " << total_detected_points << ",\tmatches " << total_matches
        << ",\tt1 " << 1000 * total_detection_time / 1.0 << " ms"
        << ",\tt2 = " << 1000 * total_extraction_time / 1.0 << " ms" << endl;

    }
    // catch (const std::exception& ex) {
    //     cout << "detector: " << detectorType << ", descriptor: " << descriptorName << " CRASHED: " << ex.what() << endl;
    // }
    catch (...) {
        cout << "detector: " << detectorType << ",\tdescriptor: " << descriptorName << "\tCRASHED!" << endl;
    }
       
    }


    return 0;
}