// 11.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void ExtractFrames(const string& videoName, const string& imagePath, const string& imagePrefix)//文件地址、保存地址、保存名称前缀
{
	VideoCapture cap;
	Mat m;
	int n = 0;
	// 打开视频
	cap.open(videoName);
	if (!cap.isOpened())
	{
		cout << "Error : could not load video" << endl;
		exit(-1);
	}

	// 取得视频帧数
	size_t count = (size_t)cap.get(CAP_PROP_FRAME_COUNT);
	for (size_t i = 0; i < count; ++i)
	{
		cap >> m;

		if (i % 2 == 0)
		{

			if (i / 2 >= 10 & i / 2 < 100)
			{
				string imgName = imagePath + "/" + imagePrefix + "0" + to_string(i / 2) + ".jpg";
				imwrite(imgName, m);
				cout << "Frames " << i / 2 << " ... done" << endl;
				continue;

			}
			if (i / 2 >= 100)
			{
				string imgName = imagePath + "/" + imagePrefix + to_string(i / 2) + ".jpg";
				imwrite(imgName, m);
				cout << "Frames " << i / 2 << " ... done" << endl;
				continue;
			}
			else {
				string imgName = imagePath + "/" + imagePrefix + "00" + to_string(i / 2) + ".jpg";
				imwrite(imgName, m);
				cout << "Frames " << i / 2 << " ... done" << endl;
				continue;
			}
			// 将当前帧保存


		}


	}
}
int main(int argc, char* argv[])
{
	ExtractFrames("D:\\project\\video\\走动3.avi", "D:/kcf", "0");//ExtractFrames("C:/Users/Shy/source/repos/11.1/11.1/没有人脸的视频.avi", "E:/shy/meiyou", "meiyou");

	return 0;
}