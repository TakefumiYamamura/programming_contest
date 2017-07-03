#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class TreeGraph
{
private:
	int n;
	int x;
	int ans;
	vector<int> h;
	vector<vector<int> > adj;
public:
	TreeGraph() {
		cin >> n >> x;
		x--;
		h.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> h[i];
		}
		adj.resize(n);
		for (int i = 0; i < n-1; ++i)
		{
			int a;
			int b;
			cin >> a >> b;
			a--;
			b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		ans = 0;
	}

	bool dfs(int cur, int before) {
		bool flag = false;
		if(h[cur] == 1) flag = true;
		for (int i = 0; i < adj[cur].size(); ++i)
		{
			if(adj[cur][i] == before) continue;
			if(dfs(adj[cur][i], cur)) flag = true;
		}
		if(flag) ans += 2; 
		return flag;
	}

	void exec() {
		for (int i = 0; i < adj[x].size(); ++i)
		{
			dfs(adj[x][i], x);
		}
		cout << ans << endl;
	}
};

int main() {
	TreeGraph tg = TreeGraph();
	tg.exec();
}