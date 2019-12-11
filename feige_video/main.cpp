// 11.1.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//


#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void ExtractFrames(const string& videoName, const string& imagePath, const string& imagePrefix)//�ļ���ַ�������ַ����������ǰ׺
{
	VideoCapture cap;
	Mat m;
	int n = 0;
	// ����Ƶ
	cap.open(videoName);
	if (!cap.isOpened())
	{
		cout << "Error : could not load video" << endl;
		exit(-1);
	}

	// ȡ����Ƶ֡��
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
			// ����ǰ֡����


		}


	}
}
int main(int argc, char* argv[])
{
	ExtractFrames("D:\\project\\video\\�߶�3.avi", "D:/kcf", "0");//ExtractFrames("C:/Users/Shy/source/repos/11.1/11.1/û����������Ƶ.avi", "E:/shy/meiyou", "meiyou");

	return 0;
}