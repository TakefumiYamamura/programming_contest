#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ParkingLot
{
private:
	int n;
	int m;
	int start;
	vector<vector<int> > g;
	vector<bool> visited;

public:
	ParkingLot() {
		cin >> n >> m >> start;
		start--;
		g.resize(n);
		visited = vector<bool>(n, false);
		for (int i = 0; i < m; ++i)
		{
			int u;
			int v;
			cin >> u >> v;
			u--;
			v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}

	void exec() {
		priority_queue<int> que;
		que.push(start);
		while(!que.empty()) {
			int cur = que.top();
			visited[cur] = true;
			que.pop();
			for (int i = 0; i < g[cur].size(); ++i)
			{
				int next = g[cur][i];
				if(next >= cur) continue;
				if(visited[next]) continue;
				que.push(next);
			}
		}

		for (int i = 0; i < visited.size(); ++i)
		{
			if(visited[i]) cout << i + 1 << endl; 
		}
	}
		
};

int main() {
	ParkingLot pl = ParkingLot();
	pl.exec();
}
