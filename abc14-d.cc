#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 100001
#define MAX_LOG_N 16

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


using namespace std;

struct Edge
{
	int a, b;
};

struct Node
{
	int val, depth, parent;
	
};


void bfs(int start, vector<int> G[], int size, vector<vector<int> >& p, vector<int> &d){
	queue<Node> q;
	vector<int> check(size, 1); //　未訪問は1
	Node n = {start, 0, -1};
	p[0][start] = -1;
	d[start] = 0;
	check[start] = 0;
	q.push(n);
	while(!q.empty()){
		Node cur = q.front();
		q.pop();
		for (int i = 0; i < G[cur.val].size(); ++i)
		{
			// cout << G[cur.val][i] << endl;
			int next = G[cur.val][i];
			if(check[next]){
				check[next] = 0;
				Node tmp = {next, cur.depth + 1, cur.val};
				p[0][tmp.val] = tmp.parent;
				d[tmp.val] = tmp.depth;
				q.push(tmp);
			}
		}
	}
}

void init_p(vector<vector<int> >& p, int size){
	for (int i = 0; i < MAX_LOG_N - 1; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(p[i][j] == -1){
				p[i+1][j] = -1;
				continue;
			}
			p[i+1][j] = p[i][ p[i][j] ];
			// cout << "i: " << i << " j: " << j << " " << p[i][j] << endl;
		}
	}
}


int lca(int a, int b, vector<vector<int> >& p, int size, vector<int> &d){
	if(d[a] > d[b]) swap(a, b);
	int diff = d[b] - d[a];
	for (int i = 0; i < MAX_LOG_N - 1 ; ++i)
	{
		if(diff >> i & 1){
			b = p[i][b];
		}
	}
	if(a == b) return a;

	for (int i = MAX_LOG_N - 1; i >= 0; --i)
	{
		if(p[i][a] != p[i][b]){
			a = p[i][a];
			b = p[i][b];
		}
	}
	return p[0][a];
}


int main(){
	int n, q;
	vector<int> G[MAX_N];
	cin >> n;
	for (int i = 0; i < n-1; ++i)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		G[x].push_back(y);
		G[y].push_back(x); 
	}

	cin >> q;
	vector<Edge> edges;
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		Edge e = {a, b};
		edges.push_back(e);
	}

	// vector<int> p(size, -1);
	vector< vector<int> > p(MAX_LOG_N, vector<int>(n, -1)); 
	vector<int> d(n, -1);
	bfs(0, G, n, p, d);
	init_p(p, n);


	for (int i = 0; i < edges.size(); ++i)
	{
		cout << d[edges[i].a] + d[edges[i].b] - d[lca(edges[i].a, edges[i].b, p, n, d) ] + 1 << endl;
	}



}