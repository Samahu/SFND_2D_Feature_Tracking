# WRITEUP

## MP.1 Data Buffer Optimization
I achieved this task by removing elements from the vector once it exceed the alotted size
https://github.com/Samahu/SFND_2D_Feature_Tracking/blob/9ed10b6f6e5f9a84b83748e47cc21e25878f8c61/src/MidTermProject_Camera_Student.cpp#L63-L66

## MP.2 Keypoint Detection
I have implemented the Harris key detector in `matching2D_student.cpp` as shown here:
https://github.com/Samahu/SFND_2D_Feature_Tracking/blob/9ed10b6f6e5f9a84b83748e47cc21e25878f8c61/src/matching2D_Student.cpp#L129
then proceeded implementing the rest of modern detectors:
https://github.com/Samahu/SFND_2D_Feature_Tracking/blob/9ed10b6f6e5f9a84b83748e47cc21e25878f8c61/src/matching2D_Student.cpp#L187-L206

## MP.3 Keypoint Removal
I have used the contains method of `cv::Rect` to check if points belong the focus vehicle, if they don't belong I would remove them:
https://github.com/Samahu/SFND_2D_Feature_Tracking/blob/9ed10b6f6e5f9a84b83748e47cc21e25878f8c61/src/MidTermProject_Camera_Student.cpp#L115-L128

## MP.4 Keypoint Descriptors
I have added all the requried descriptors here:
https://github.com/Samahu/SFND_2D_Feature_Tracking/blob/9ed10b6f6e5f9a84b83748e47cc21e25878f8c61/src/matching2D_Student.cpp#L66-L81

## MP.5 Descriptor Matching
Here I have implemented the FLANN matcher:
https://github.com/Samahu/SFND_2D_Feature_Tracking/blob/9ed10b6f6e5f9a84b83748e47cc21e25878f8c61/src/matching2D_Student.cpp#L21-L30
and I made sure to cast the type of both image to `CV_32F` when FLANN is selected 

## MP.6 Descriptor Distance Ratio
Here I implement the KNN selector with descriptor distance ratio:
https://github.com/Samahu/SFND_2D_Feature_Tracking/blob/9ed10b6f6e5f9a84b83748e47cc21e25878f8c61/src/matching2D_Student.cpp#L38-L50

## MP.7 Performance Evaluation 1
## MP.8 Performance Evaluation 2
## MP.9 Performance Evaluation 3
I have summarized all my perofmance evalution results in this excel sheet:
https://docs.google.com/spreadsheets/d/1XNhGTc7V1QnEKSWW3W1W1Dgmb8IJvlCjF2-eHo4UkgQ/edit?usp=sharing
