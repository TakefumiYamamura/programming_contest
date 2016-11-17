#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Time
{
public:
	string timeS;
	int start;
	int finish;

	Time(string time);
	void convert();
	static string convertToS(int i);
};

Time::Time(string timeS){
	this->timeS = timeS;
	convert();
}

void Time::convert(){
	int hour = 0;
	int minutes = 0;

	hour += (timeS[0] - '0') * 10;
	hour += (timeS[1] - '0');

	minutes += (timeS[2] - '0') * 10;
	minutes += (timeS[3] - '0');
	minutes /= 5;

	start = hour * 12 + minutes;

	hour = 0;
	minutes = 0;

	hour += (timeS[5] - '0') * 10;
	hour += (timeS[6] - '0');

	minutes += (timeS[7] - '0') * 10;
	minutes += (timeS[8] - '0');
	minutes = (minutes + 4) / 5;

	finish = hour * 12 + minutes;
}


string Time::convertToS(int i){
	string ans = "0000";
	ans[0] = '0' + (i / 12 / 10);
	ans[1] = '0' + (i / 12 % 10);
	i = i % 12;
	ans[2] = '0' + (5 * i / 10);
 	ans[3] = '0' + (5 * i % 10);
 	return ans;
}

class SortRainTime
{
public:
	int n;
	vector<int> timeArray;
	SortRainTime();
	~SortRainTime();
	void exec();
};


SortRainTime::SortRainTime(){
	timeArray.resize(24*12+3);
	for (int i = 0; i < timeArray.size(); ++i)
	{
		timeArray[i] = 0;
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		Time t = Time(tmp);
		timeArray[t.start]++;
		timeArray[t.finish]--;
	}
	for (int i = 0; i < timeArray.size(); ++i)
	{
		timeArray[i+1] += timeArray[i]; 
	}
}

SortRainTime::~SortRainTime(){

}

void SortRainTime::exec(){
	string start;
	string finish;
	timeArray[24*12 + 1] = 0;

	if(timeArray[0] > 0) start = Time::convertToS(0);
	for (int i = 1; i <= 24 * 12; ++i)
	{
		if(timeArray[i] == 0 && timeArray[i+1] > 0){
			start = Time::convertToS(i+1);
		}
		if(timeArray[i] > 0 && timeArray[i+1] == 0){
			finish = Time::convertToS(i+1);
			cout << start << '-' << finish << endl;
		}
	}
}

int main(){
	SortRainTime srt = SortRainTime();
	srt.exec();
}
