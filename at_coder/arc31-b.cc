#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;


class Island
{
private:
	int n;
	vector<vector<int> > map;
public:
	Island() {
		n = 10;
		map = vector<vector<int> >(10, vector<int>(10, 0));
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			for (int j = 0; j < n; ++j)
			{
				if(str[j] == 'o') {
					map[i][j] = 1;
				} else {
					map[i][j] = 0;
				}
			}
		}
	}

	bool bfs(int x, int y) {
		vector<vector<int>> visited = vector<vector<int> >(10, vector<int>(10, 0));
		visited[x][y] = 1;
		queue<pair<int, int>> q;
		q.push(pair<int, int>(x, y));
		while(!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			int i = p.first;
			int j = p.second;
			if(i+1 < n && map[i+1][j] == 1 && visited[i+1][j] == 0) {
				visited[i+1][j] = 1;
				q.push(pair<int, int>(i+1, j));
			} 
			if(j+1 < n && map[i][j+1] == 1 && visited[i][j+1] == 0) {
				visited[i][j+1] = 1;
				q.push(pair<int, int>(i, j+1));
			}
			if(i-1 >= 0 && map[i-1][j] == 1 && visited[i-1][j] == 0) {
				visited[i-1][j] = 1;
				q.push(pair<int, int>(i-1, j));
			}
			if(j-1 >= 0 && map[i][j-1] == 1 && visited[i][j-1] == 0) {
				visited[i][j-1] = 1;
				q.push(pair<int, int>(i, j-1));
			} 
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(visited[i][j] == 0 && map[i][j] == 1) {
					return false;
				}
			}
		}
		return true;

	}

	void exec() {
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(bfs(i, j)) {
					cout << "YES" << endl;
					return;
				}
			}
		}

		cout << "NO" << endl;
		return;
	}
};

int main() {
	Island is = Island();
	is.exec();
}
