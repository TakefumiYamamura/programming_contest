#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
	int index;
	int min_index;
	bool operator<(const Node& node) const
    {
        return min_index < node.min_index;
    }
	// static bool asc(const Node& x, const Node& y){
	// 	return x.min_index < y.min_index; 
	// }
};

class Parking
{
public:
	int n, m, s;
	vector<vector<int > > adj;
	vector<int> g[300001];
	vector<int> dis;
	vector<int> check;
	Parking();
	~Parking();
	void bfs();
	void dijkstra();
	void exec();
};

Parking::Parking(){
	cin >> n >> m >> s;
	s--;
	adj.resize(n);
	for (int i = 0; i < n; ++i)
	{
		check.push_back(0);
		dis.push_back(n);
	}
	for (int i = 0; i < n; ++i)
	{
		adj[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			adj[i][j] = 0;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u][v] = 1;
		g[max(u,v)].push_back(min(u,v));
		// g[v].push_back(u);
		adj[v][u] = 1;
	}
}

Parking::~Parking(){}

void Parking::bfs(){
	// queue<int> que;
	priority_queue<int, vector<int>, greater<int> > que;
	// vector<int> check(n, 0);
	que.push(s);
	check[s] = 1;
 	// while(!que.empty()){
 	for (int j = 0; j < n; ++j)
 	{
 		if(!que.empty()) break;
		int cur = que.top();
		que.pop();
		// for (int i = cur-1; i >= 0; --i)
		// {
		// 	if(adj[cur][i] && !check[i]){
		// 		check[i] = 1;
		// 		que.push(i);
		// 	}
		// }
		for (int i = 0; i < g[cur].size(); ++i)
		{
			if(!check[i]){
				check[i] = 1;
				que.push(i);
			}
		}
	}
	// if(check[goal]){
	// 	return true;
	// }else{
	// 	return false;
	// }
}

void Parking::dijkstra(){
	priority_queue<Node> que;
	dis[s] = s;
	Node top = {s, s};
	que.push(top);
	while(!que.empty()){
		Node cur = que.top();
		que.pop();
		int cur_index = cur.index;
		if(dis[cur_index] < cur.min_index) continue;
		//今より大きい数字へしかいかない
		for (int i = cur_index-1; i >= 0; --i)
		{
			if(adj[cur_index][i] && dis[i] > dis[cur.min_index]){
				dis[i] = min(i, cur.min_index);
				Node tmp = {i, dis[i]};
				que.push(tmp);
			}
		}
	}  
}

void Parking::exec(){
	// dijkstra();
	bfs();
	for (int i = 0; i < n; ++i)
	{
		// cout << dis[i]+1 << endl;
		// if(dis[i] == i) cout << i+1 << endl;
		if(check[i]) cout << i+1 << endl;
		// if(bfs(i)){
		// 	cout << i+1 << endl;
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		adj[i][j] = 0;
		// 	}
		// }	
	}
}

int main(){
	Parking p = Parking();
	p.exec();
}
