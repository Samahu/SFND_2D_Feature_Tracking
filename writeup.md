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


After several trials here is a summary of my last run:
```bash
detector: SHITOMASI,    descriptor: BRISK,      points 1179,    matches 690,    t1 289.328 ms,  t2 = 2.90708 ms
detector: SHITOMASI,    descriptor: BRIEF,      points 1179,    matches 822,    t1 107.06 ms,   t2 = 52.7485 ms
detector: SHITOMASI,    descriptor: ORB,        points 1179,    matches 764,    t1 185.61 ms,   t2 = 13.4894 ms
detector: SHITOMASI,    descriptor: FREAK,      points 1179,    matches 580,    t1 98.9264 ms,  t2 = 15.1889 ms
detector: SHITOMASI,    descriptor: AKAZE       CRASHED!
detector: SHITOMASI,    descriptor: SIFT,       points 1179,    matches 929,    t1 118.24 ms,   t2 = 16.4753 ms
detector: HARRIS,       descriptor: BRISK,      points 59,      matches 29,     t1 69.0376 ms,  t2 = 0.66183 ms
detector: HARRIS,       descriptor: BRIEF,      points 59,      matches 39,     t1 181.207 ms,  t2 = 0.530779 ms
detector: HARRIS,       descriptor: ORB,        points 59,      matches 40,     t1 137.742 ms,  t2 = 0.506149 ms
detector: HARRIS,       descriptor: FREAK,      points 59,      matches 32,     t1 62.3692 ms,  t2 = 0.5189 ms
detector: HARRIS,       descriptor: AKAZE       CRASHED!
detector: HARRIS,       descriptor: SIFT,       points 59,      matches 42,     t1 152.494 ms,  t2 = 0.646109 ms
detector: FAST, descriptor: BRISK,      points 4094,    matches 1844,   t1 13.8428 ms,  t2 = 50.1434 ms
detector: FAST, descriptor: BRIEF,      points 4094,    matches 2224,   t1 44.3969 ms,  t2 = 48.0419 ms
detector: FAST, descriptor: ORB,        points 4094,    matches 2113,   t1 13.7228 ms,  t2 = 48.3852 ms
detector: FAST, descriptor: FREAK       CRASHED!
detector: FAST, descriptor: AKAZE       CRASHED!
detector: FAST, descriptor: SIFT,       points 4094,    matches 2789,   t1 13.3595 ms,  t2 = 59.3191 ms
detector: BRISK,        descriptor: BRISK,      points 2762,    matches 1314,   t1 4632.77 ms,  t2 = 36.4893 ms
detector: BRISK,        descriptor: BRIEF,      points 2762,    matches 1357,   t1 3705.44 ms,  t2 = 32.2541 ms
detector: BRISK,        descriptor: ORB,        points 2762,    matches 975,    t1 3647.62 ms,  t2 = 75.6252 ms
detector: BRISK,        descriptor: FREAK,      points 2762,    matches 1124,   t1 3862.22 ms,  t2 = 32.8974 ms
detector: BRISK,        descriptor: AKAZE       CRASHED!
detector: BRISK,        descriptor: SIFT,       points 2762,    matches 1660,   t1 3847 ms,     t2 = 39.6702 ms
detector: ORB,          descriptor: BRISK,      points 1161,    matches 652,    t1 65.362 ms,   t2 = 33.8535 ms
detector: ORB,          descriptor: BRIEF,      points 1161,    matches 453,    t1 102.965 ms,  t2 = 12.1169 ms
detector: ORB,          descriptor: ORB,        points 1161,    matches 540,    t1 50.6608 ms,  t2 = 13.3422 ms
detector: ORB,          descriptor: FREAK       CRASHED!
detector: ORB,          descriptor: AKAZE       CRASHED!
detector: ORB,          descriptor: SIFT,       points 1161,    matches 765,    t1 222.216 ms,  t2 = 15.5458 ms
detector: AKAZE,        descriptor: BRISK,      points 1670,    matches 1115,   t1 1884.01 ms,  t2 = 20.8005 ms
detector: AKAZE,        descriptor: BRIEF,      points 1670,    matches 1089,   t1 1927.85 ms,  t2 = 18.9872 ms
detector: AKAZE,        descriptor: ORB,        points 1670,    matches 927,    t1 1854.03 ms,  t2 = 19.0838 ms
detector: AKAZE,        descriptor: FREAK,      points 1670,    matches 977,    t1 1845.83 ms,  t2 = 64.3892 ms
detector: AKAZE,        descriptor: AKAZE,      points 1670,    matches 1175,   t1 1961.82 ms,  t2 = 21.4787 ms
detector: AKAZE,        descriptor: SIFT,       points 1670,    matches 1273,   t1 1773.19 ms,  t2 = 26.5576 ms
detector: SIFT,         descriptor: BRISK,      points 1386,    matches 543,    t1 1208.26 ms,  t2 = 16.8836 ms
detector: SIFT,         descriptor: BRIEF,      points 1386,    matches 597,    t1 1636.99 ms,  t2 = 14.7167 ms
detector: SIFT,         descriptor: ORB CRASHED!
detector: SIFT,         descriptor: FREAK,      points 1386,    matches 518,    t1 1517.95 ms,  t2 = 57.5761 ms
detector: SIFT,         descriptor: AKAZE       CRASHED!
detector: SIFT,         descriptor: SIFT,       points 1386,    matches 805,    t1 1725.55 ms,  t2 = 19.9822 ms
```

To pick the best combination we start by removing incompatbile ones (such as AKAZE as a descriptor):
```bash
detector: SHITOMASI,    descriptor: BRISK,      points 1179,    matches 690,    t1 289.328 ms,  t2 = 2.90708 ms
detector: SHITOMASI,    descriptor: BRIEF,      points 1179,    matches 822,    t1 107.06 ms,   t2 = 52.7485 ms
detector: SHITOMASI,    descriptor: ORB,        points 1179,    matches 764,    t1 185.61 ms,   t2 = 13.4894 ms
detector: SHITOMASI,    descriptor: FREAK,      points 1179,    matches 580,    t1 98.9264 ms,  t2 = 15.1889 ms
detector: SHITOMASI,    descriptor: SIFT,       points 1179,    matches 929,    t1 118.24 ms,   t2 = 16.4753 ms
detector: HARRIS,       descriptor: BRISK,      points 59,      matches 29,     t1 69.0376 ms,  t2 = 0.66183 ms
detector: HARRIS,       descriptor: BRIEF,      points 59,      matches 39,     t1 181.207 ms,  t2 = 0.530779 ms
detector: HARRIS,       descriptor: ORB,        points 59,      matches 40,     t1 137.742 ms,  t2 = 0.506149 ms
detector: HARRIS,       descriptor: FREAK,      points 59,      matches 32,     t1 62.3692 ms,  t2 = 0.5189 ms
detector: HARRIS,       descriptor: SIFT,       points 59,      matches 42,     t1 152.494 ms,  t2 = 0.646109 ms
detector: FAST,         descriptor: BRISK,      points 4094,    matches 1844,   t1 13.8428 ms,  t2 = 50.1434 ms
detector: FAST,         descriptor: BRIEF,      points 4094,    matches 2224,   t1 44.3969 ms,  t2 = 48.0419 ms
detector: FAST,         descriptor: ORB,        points 4094,    matches 2113,   t1 13.7228 ms,  t2 = 48.3852 ms
detector: FAST,         descriptor: SIFT,       points 4094,    matches 2789,   t1 13.3595 ms,  t2 = 59.3191 ms
detector: BRISK,        descriptor: BRISK,      points 2762,    matches 1314,   t1 4632.77 ms,  t2 = 36.4893 ms
detector: BRISK,        descriptor: BRIEF,      points 2762,    matches 1357,   t1 3705.44 ms,  t2 = 32.2541 ms
detector: BRISK,        descriptor: ORB,        points 2762,    matches 975,    t1 3647.62 ms,  t2 = 75.6252 ms
detector: BRISK,        descriptor: FREAK,      points 2762,    matches 1124,   t1 3862.22 ms,  t2 = 32.8974 ms
detector: BRISK,        descriptor: SIFT,       points 2762,    matches 1660,   t1 3847 ms,     t2 = 39.6702 ms
detector: ORB,          descriptor: BRISK,      points 1161,    matches 652,    t1 65.362 ms,   t2 = 33.8535 ms
detector: ORB,          descriptor: BRIEF,      points 1161,    matches 453,    t1 102.965 ms,  t2 = 12.1169 ms
detector: ORB,          descriptor: ORB,        points 1161,    matches 540,    t1 50.6608 ms,  t2 = 13.3422 ms
detector: ORB,          descriptor: SIFT,       points 1161,    matches 765,    t1 222.216 ms,  t2 = 15.5458 ms
detector: AKAZE,        descriptor: BRISK,      points 1670,    matches 1115,   t1 1884.01 ms,  t2 = 20.8005 ms
detector: AKAZE,        descriptor: BRIEF,      points 1670,    matches 1089,   t1 1927.85 ms,  t2 = 18.9872 ms
detector: AKAZE,        descriptor: ORB,        points 1670,    matches 927,    t1 1854.03 ms,  t2 = 19.0838 ms
detector: AKAZE,        descriptor: FREAK,      points 1670,    matches 977,    t1 1845.83 ms,  t2 = 64.3892 ms
detector: AKAZE,        descriptor: AKAZE,      points 1670,    matches 1175,   t1 1961.82 ms,  t2 = 21.4787 ms
detector: AKAZE,        descriptor: SIFT,       points 1670,    matches 1273,   t1 1773.19 ms,  t2 = 26.5576 ms
detector: SIFT,         descriptor: BRISK,      points 1386,    matches 543,    t1 1208.26 ms,  t2 = 16.8836 ms
detector: SIFT,         descriptor: BRIEF,      points 1386,    matches 597,    t1 1636.99 ms,  t2 = 14.7167 ms
detector: SIFT,         descriptor: FREAK,      points 1386,    matches 518,    t1 1517.95 ms,  t2 = 57.5761 ms
detector: SIFT,         descriptor: SIFT,       points 1386,    matches 805,    t1 1725.55 ms,  t2 = 19.9822 ms
```

We can then drop HARRIS as detector since it yield very low number of keypoints when compared to the rest:
```bash
detector: SHITOMASI,    descriptor: BRISK,      points 1179,    matches 690,    t1 289.328 ms,  t2 = 2.90708 ms
detector: SHITOMASI,    descriptor: BRIEF,      points 1179,    matches 822,    t1 107.06 ms,   t2 = 52.7485 ms
detector: SHITOMASI,    descriptor: ORB,        points 1179,    matches 764,    t1 185.61 ms,   t2 = 13.4894 ms
detector: SHITOMASI,    descriptor: FREAK,      points 1179,    matches 580,    t1 98.9264 ms,  t2 = 15.1889 ms
detector: SHITOMASI,    descriptor: SIFT,       points 1179,    matches 929,    t1 118.24 ms,   t2 = 16.4753 ms
detector: FAST,         descriptor: BRISK,      points 4094,    matches 1844,   t1 13.8428 ms,  t2 = 50.1434 ms
detector: FAST,         descriptor: BRIEF,      points 4094,    matches 2224,   t1 44.3969 ms,  t2 = 48.0419 ms
detector: FAST,         descriptor: ORB,        points 4094,    matches 2113,   t1 13.7228 ms,  t2 = 48.3852 ms
detector: FAST,         descriptor: SIFT,       points 4094,    matches 2789,   t1 13.3595 ms,  t2 = 59.3191 ms
detector: BRISK,        descriptor: BRISK,      points 2762,    matches 1314,   t1 4632.77 ms,  t2 = 36.4893 ms
detector: BRISK,        descriptor: BRIEF,      points 2762,    matches 1357,   t1 3705.44 ms,  t2 = 32.2541 ms
detector: BRISK,        descriptor: ORB,        points 2762,    matches 975,    t1 3647.62 ms,  t2 = 75.6252 ms
detector: BRISK,        descriptor: FREAK,      points 2762,    matches 1124,   t1 3862.22 ms,  t2 = 32.8974 ms
detector: BRISK,        descriptor: SIFT,       points 2762,    matches 1660,   t1 3847 ms,     t2 = 39.6702 ms
detector: ORB,          descriptor: BRISK,      points 1161,    matches 652,    t1 65.362 ms,   t2 = 33.8535 ms
detector: ORB,          descriptor: BRIEF,      points 1161,    matches 453,    t1 102.965 ms,  t2 = 12.1169 ms
detector: ORB,          descriptor: ORB,        points 1161,    matches 540,    t1 50.6608 ms,  t2 = 13.3422 ms
detector: ORB,          descriptor: SIFT,       points 1161,    matches 765,    t1 222.216 ms,  t2 = 15.5458 ms
detector: AKAZE,        descriptor: BRISK,      points 1670,    matches 1115,   t1 1884.01 ms,  t2 = 20.8005 ms
detector: AKAZE,        descriptor: BRIEF,      points 1670,    matches 1089,   t1 1927.85 ms,  t2 = 18.9872 ms
detector: AKAZE,        descriptor: ORB,        points 1670,    matches 927,    t1 1854.03 ms,  t2 = 19.0838 ms
detector: AKAZE,        descriptor: FREAK,      points 1670,    matches 977,    t1 1845.83 ms,  t2 = 64.3892 ms
detector: AKAZE,        descriptor: AKAZE,      points 1670,    matches 1175,   t1 1961.82 ms,  t2 = 21.4787 ms
detector: AKAZE,        descriptor: SIFT,       points 1670,    matches 1273,   t1 1773.19 ms,  t2 = 26.5576 ms
detector: SIFT,         descriptor: BRISK,      points 1386,    matches 543,    t1 1208.26 ms,  t2 = 16.8836 ms
detector: SIFT,         descriptor: BRIEF,      points 1386,    matches 597,    t1 1636.99 ms,  t2 = 14.7167 ms
detector: SIFT,         descriptor: FREAK,      points 1386,    matches 518,    t1 1517.95 ms,  t2 = 57.5761 ms
detector: SIFT,         descriptor: SIFT,       points 1386,    matches 805,    t1 1725.55 ms,  t2 = 19.9822 ms
```
the following narrowed selection can produce results in less than 100 millseconds which is more suitable for
realtime processing so we are only going to consider these combinations:
```bash
detector: FAST,         descriptor: BRISK,      points 4094,    matches 1844,   t1 13.8428 ms,  t2 = 50.1434 ms
detector: FAST,         descriptor: BRIEF,      points 4094,    matches 2224,   t1 44.3969 ms,  t2 = 48.0419 ms
detector: FAST,         descriptor: ORB,        points 4094,    matches 2113,   t1 13.7228 ms,  t2 = 48.3852 ms
detector: FAST,         descriptor: SIFT,       points 4094,    matches 2789,   t1 13.3595 ms,  t2 = 59.3191 ms
detector: ORB,          descriptor: BRISK,      points 1161,    matches 652,    t1 65.362 ms,   t2 = 33.8535 ms
detector: ORB,          descriptor: ORB,        points 1161,    matches 540,    t1 50.6608 ms,  t2 = 13.3422 ms
```

By considering the match rate (matches/keypoints), the following three would be my top pick sorted by the highest rank:
```bash
detector: FAST,         descriptor: SIFT,       points 4094,    matches 2789,   t1 13.3595 ms,  t2 = 59.3191 ms
detector: ORB,          descriptor: BRISK,      points 1161,    matches 652,    t1 65.362 ms,   t2 = 33.8535 ms
detector: FAST,         descriptor: BRIEF,      points 4094,    matches 2224,   t1 44.3969 ms,  t2 = 48.0419 ms
```