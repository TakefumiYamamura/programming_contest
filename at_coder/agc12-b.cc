#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;

#define ll long long

struct Question
{
	int v;
	int d;
	int c;	
};

class Solver
{
public:
	int n;
	int m;
	int q;
	vector<vector<int> > adj;
	vector<Question> qs;
	vector<vector<int> > dp;

	Solver();

	void set(int cur, int depth, int color);
	void exec();
};

Solver::Solver(){
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		Question tmpQ;
		cin >> tmpQ.v >> tmpQ.d >> tmpQ.c;
		tmpQ.v--;
		qs.push_back(tmpQ);
	}
	dp = vector<vector<int> >(n, vector<int>(11, 0));
}


void Solver::set(int cur, int depth, int color){
	if(dp[cur][depth] != 0) return;
	dp[cur][depth] = color;
	if(depth == 0) return;
	set(cur, depth-1, color);
	for (int i = 0; i < adj[cur].size(); ++i)
	{
		set(adj[cur][i] , depth-1, color);
	}
}

void Solver::exec(){
	for (int i = q-1; i >= 0; --i)
	{
		set(qs[i].v, qs[i].d, qs[i].c);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << dp[i][0] << endl;
	}
}

int main(){
	Solver solution = Solver();
	solution.exec();
}
