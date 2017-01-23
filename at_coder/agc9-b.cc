#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
	int index, depth;
};

class Tournament
{
public:
	int n;
	vector<int> a;
	vector<vector<int > > g;
	vector<int> depth;
	vector<int> hash;
	Tournament();
	~Tournament();
	void exec();
};

Tournament::Tournament(){
	cin >> n;
	a.push_back(0);
	// g.resize(n);
	// g[0].resize(n);
	hash = vector<int>(n, 0);
	for (int i = 1; i < n; ++i)
	{
		// g[i].resize(n);
		int tmpA;
		cin >> tmpA;
		tmpA--;
		hash[tmpA]++;

		// a.push_back(tmpA);
	}
	//g[x] xが勝利した人の番号が入ってる
	// for (int i = 1; i < n; ++i)
	// {
	// 	// g[i].push_back(a[i]);
	// 	g[a[i]].push_back(i);
	// }
	// depth = vector<int>(n, -1);
	// depth[0] = 0;
	// hash = vector<int>(n, 0);
}

Tournament::~Tournament(){}

void Tournament::exec(){
	// queue<Node> q;
	// Node s = {0, 0};
	// q.push(s);
	// while(!q.empty()){
	// 	Node cur = q.front();
	// 	q.pop();
	// 	for (int i = 0; i < g[cur.index].size(); ++i)
	// 	{
	// 		int next = g[cur.index][i];
	// 		if(depth[next] == -1){
	// 			depth[next] = cur.depth + 1;
	// 			Node tmp = {next, cur.depth + 1};
	// 			q.push(tmp);
	// 			// cout << next << " "<<cur.depth + 1<< endl;
	// 		}
	// 	}
	// }
	int ans = n-1;
	int tmpMax = 0;
	for (int i = 0; i < n; ++i)
	{
		tmpMax = max(hash[i], tmpMax);
	}
	for (int i = 0; i < n; ++i)
	{
		if(hash[i] > 0 ) ans -= hash[i] - 1;
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	ans = max(ans, depth[i] + hash[depth[i]]-1);
	// }
	cout << ans << endl;
}

int main(){
	Tournament solution = Tournament();
	solution.exec();
}
