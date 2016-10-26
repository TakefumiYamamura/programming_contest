#include <iostream>
#include <queue>
#define ll long long 
using namespace std;

const ll MAX = 1e9+7;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


struct Node
{
	int val;
	int depth;
};

int bfs(int start, int (*G)[10], int size){
	queue<Node> que;
	Node n = {start, 0};
	int check[10];
	Fill(check, 1);
	check[start] = 0;
	int count = 0;
	que.push(n);
 	while(!que.empty()){
		Node cur = que.front();
		que.pop();
		for (int i = 0; i < size; ++i)
		{
			if(G[cur.val][i] && check[i]){
				check[i] = 0;
				Node tmp = {i, cur.depth + 1};
				if(tmp.depth == 2) count++;
				// cout << "val: " << tmp.val << "depth: " << tmp.depth << endl;
				que.push(tmp);
			}
		}
	}
	return count;
}

int main(){
	int n, m;
	int G[10][10];
	Fill(G, 0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a][b] = 1;
		G[b][a] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << bfs(i, G, n) << endl;
	}

}
