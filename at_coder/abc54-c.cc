#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
	vector<int> visited;
	int count;
	int cur_pos;
	Node(int n_){
		count = 0;
		visited = vector<int>(n_, 0);
	}
};

class oneStrokePath
{
private:
	int n, m;
	vector<vector<int> > adj;
public:
	oneStrokePath(){
		cin >> n >> m;
		adj.resize(n);
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
			int tmp_a, tmp_b;
			cin >> tmp_a >> tmp_b;
			tmp_a--;
			tmp_b--;
			adj[tmp_a][tmp_b] = 1;
			adj[tmp_b][tmp_a] = 1;
		}
	}
	void execute();
};

void oneStrokePath::execute(){
	queue<Node> q;
	Node start = Node(n);
	start.visited[0] = 1;
	start.count = 1;
	start.cur_pos = 0;
	q.push(start);
	int ans = 0;
	while(!q.empty()){
		Node cur = q.front();
		q.pop();
		if(cur.count == n) ans++;
		for (int i = 0; i < n; ++i)
		{
			if(adj[cur.cur_pos][i] == 1 && cur.visited[i] == 0){
				Node next = cur;
				next.visited[i] = 1;
				next.count++;
				next.cur_pos = i;
				q.push(next);
			}
		}
	}
	cout << ans << endl;
}

int main(){
	oneStrokePath osp = oneStrokePath();
	osp.execute();
}
