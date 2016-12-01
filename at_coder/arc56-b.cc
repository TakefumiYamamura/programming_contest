#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
	int val;
	int depth;
	bool operator<(const Node& node) const
    {
        return depth < node.depth;
    }
	// static bool asc(const Node& x, const Node& y){
	// 	return x.depth < y.depth; 
	// }
};

class Parking
{
public:
	int n, m, s;
	vector<vector<int > > adj;
	std::vector<int> dis;
	Parking();
	~Parking();
	// bool bfs(int goal);
	void dijkstra();
	void exec();
};

Parking::Parking(){
	cin >> n >> m >> s;
	s--;
	adj.resize(n);
	for (int i = 0; i < n; ++i)
	{
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
		adj[v][u] = 1;
	}
}

Parking::~Parking(){}

// bool Parking::bfs(int goal){
// 	queue<int> que;
// 	vector<int> check(n, 0);
// 	que.push(s);
// 	check[s] = 1;
//  	while(!que.empty()){
// 		int cur = que.front();
// 		que.pop();
// 		for (int i = 0; i < n; ++i)
// 		{
// 			if(adj[cur][i] && !check[i]){
// 				check[i] = 1;
// 				que.push(i);
// 			}
// 		}
// 	}
// 	if(check[goal]){
// 		return true;
// 	}else{
// 		return false;
// 	}
// }

void Parking::dijkstra(){
	priority_queue<Node > que;
	dis[s] = -1;
	Node top = {s, -1};
	que.push(top);
	while(!que.empty()){
		Node cur = que.top();
		que.pop();
		int cur_index = cur.val;
		if(dis[cur_index] < cur.depth) continue;
		for (int i = cur_index; i < n; ++i)
		{
			if(adj[cur_index][i] && cur_index < dis[i]){
				dis[i] = cur_index;
				Node tmp = {i, cur_index};
				que.push(tmp);
			}
		}
	}  
}

void Parking::exec(){
	dijkstra();
	for (int i = 0; i < n; ++i)
	{
		if(dis[i] > i) cout << i+1 << endl;
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
