#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

class MrTakahashiProcessingImages
{
public:
	int h, w;
	vector<vector<int > > image;
	vector<vector<int > > visited;
	vector<vector<char > > ans;
	MrTakahashiProcessingImages();
	~MrTakahashiProcessingImages();
	void exec();
	
};


MrTakahashiProcessingImages::MrTakahashiProcessingImages(){
	cin >> h >> w;
	image.resize(h);
	visited.resize(h);
	ans.resize(h);
	for (int i = 0; i < h; ++i)
	{
		image[i].resize(w);
		visited[i].resize(w);
		ans[i].resize(w);
		string tmp;
		cin >> tmp;
		for (int j = 0; j < w; ++j)
		{
			if(tmp[j] == '#'){
				image[i][j] = 1;
				visited[i][j] = 0;
			}else{
				image[i][j] = 0;
				visited[i][j] = 1;
			}
			ans[i][j] = '.';
		}
	}
}

MrTakahashiProcessingImages::~MrTakahashiProcessingImages(){}

void MrTakahashiProcessingImages::exec(){
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if(image[i][j]){
				bool flag = false;
				for (int k = -1 + i; k <= 1 + i; ++k)
				{
					for (int l = -1 + j ; l <= 1 + j; ++l)
					{
						if(k < h && l < w && 0 <= k  && 0 <= l && !image[k][l]){
							flag = true;
							goto BREAK_LABEL;
						}
					}
				}
				BREAK_LABEL:
				if(flag) continue;
				for (int k = -1 + i; k <= 1 + i; ++k)
				{
					for (int l = -1 + j ; l <= 1 + j; ++l)
					{
						if(k < h && l < w && 0 <= k  && 0 <= l){
							visited[k][l] = 1;
						}
					}
				}
				ans[i][j] = '#';
			}
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if(!visited[i][j]){
				cout << "impossible" << endl;
				return ;
			}
		}
	}

	cout << "possible" << endl;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}

}

int main(){
	MrTakahashiProcessingImages mtpi = MrTakahashiProcessingImages();
	mtpi.exec();
}