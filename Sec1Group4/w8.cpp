#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	/* LAB 1 */

	/*
	Mat img;
	img = imread("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/ig.png", IMREAD_COLOR);
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", img);
	waitKey(0);
	*/

	/* LAB 2 */
	/*
	VideoCapture cap("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/clip.avi");
	if (!cap.isOpened()) {
		return -1;
	}

	while (1) {
		Mat frame;
		cap >> frame;
		//End of video
		if (frame.empty())
			break;

		imshow("Frame", frame);

		//Press ESC to STOP
		char c = (char)waitKey(25);
		if (c == 27)
			break;
	}

	cap.release();
	destroyAllWindows();
	*/
	

	/* LAB 3 */
	/*
	namedWindow("Example-In");
	namedWindow("Example-Out");

	Mat img = imread("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/ig.png", IMREAD_COLOR);
	imshow("Example-In", img);

	Mat out;
	GaussianBlur(img, out, Size(7, 7), 0, 0);
	imshow("Example-Out", out);

	cvWaitKey(0);
	*/

	/* LAB 4 */

	/*
	namedWindow("Example-In");
	namedWindow("Example-Out");

	Size size(300, 300);
	Mat img = imread("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/ig.png", IMREAD_COLOR);
	imshow("Example-In", img);

	Mat out;
	resize(img, out, size);
	imshow("Example-Out", out);

	cvWaitKey(0);
	*/


	/* LAB 5 */
	
	/*
	namedWindow("Example-In");
	namedWindow("Example-Out");
	namedWindow("Example-Out2");

	Mat img = imread("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/ig.png", IMREAD_COLOR);
	imshow("Example-In", img);

	Mat img_blur, out, out2;
	blur(img, img_blur, Size(3, 3));

	//Canny detector
	int lowThres = 80;
	int highThres = 100;
	int kernel_size = 3;
	Canny(img_blur, out, 20, 60, kernel_size);
	Canny(img_blur, out2, 80, 100, kernel_size);
	imshow("Example-Out", out);
	imshow("Example-Out2", out2);

	cvWaitKey(0);
	*/

	/* LAB 6 */

	/*
	namedWindow("Example-In");
	namedWindow("Example-Out");

	Mat img = imread("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/ig.png", IMREAD_COLOR);
	imshow("Example-In", img);

	Mat img_gray;
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
	imshow("Example-Out", img_gray);

	imwrite("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/ig_gray.png", img_gray);
	cvWaitKey(0);
	*/

	/* LAB 7 */
	/*
	VideoCapture cap("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/clip.avi");
	if (!cap.isOpened()) {
		return -1;
	}

	int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	VideoWriter video("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/clip2.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25, Size(frame_width, frame_height), true);

	while (1) {
		Mat frame;
		cap >> frame;

		if (frame.empty())
			break;

		video.write(frame);
	
	}

	cap.release();
	destroyAllWindows();
	*/

	/* ACTIVITY 1 */
	VideoCapture cap("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/globe.avi");
	if (!cap.isOpened()) {
		return -1;
	}
	int s, e;
	int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	int frame_rate = cap.get(CV_CAP_PROP_FPS);
	int total_frame = cap.get(CAP_PROP_FRAME_COUNT);
	int total_duration = total_frame / frame_rate;
	cout << "This video size is " << frame_width << "*" << frame_height << " pixels with FPS at " << frame_rate << "\n";
	cout << "Total frame is " << total_frame << " | Duration is " << total_duration << " seconds \n\n";
	cout << "Please enter starting second (0-" << total_duration << ") : ";
	cin >> s;
	cout << "Please enter ending second (0-" << total_duration << ") : ";
	cin >> e;
	cout << "We will cut video in between " << s << "s and " << e << "s.\n";
	int start_frame = s * frame_rate;
	int end_frame = e * frame_rate;
	int count_frame = 0;
	cout << "At second " << s << " is the frame number " << start_frame << "\n";
	cout << "At second " << e << " is the frame number " << end_frame << "\n";

	VideoWriter video("C:/Users/VectorXz/Downloads/Sec1Group4/Sec1Group4/Sec1Group4/video_cut.avi", CV_FOURCC('M', 'J', 'P', 'G'), frame_rate, Size(frame_width, frame_height), true);

	while (1) {
		count_frame++;
		Mat frame;
		cap >> frame;

		if (frame.empty())
			break;

		if (count_frame >= start_frame && count_frame <= end_frame) {
			cout << "Frame " << count_frame << " is wrote!\n";
			video.write(frame);
			if (count_frame == end_frame) {
				cout << "\n\n\nProgram finished written the video file!\n";
				break;
			}
		}
	}

	cap.release();
	system("pause");
	return 0;
}