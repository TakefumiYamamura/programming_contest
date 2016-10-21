#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 101
#define Inf 2001
int n;
int G[MAX][MAX];


int read_input(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int e;
			cin >> e;
			if(e == -1) {
				G[i][j] = Inf;
			}else{
				G[i][j] = e;
			}
		}
	}
}


int main(){
	read_input();
	cout << compute() << endl;

}