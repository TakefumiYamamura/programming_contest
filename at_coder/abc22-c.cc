#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

#define ll long long
#define P pair<ll, ll>
#define NMAX 301

const ll MAX = 1e9+7;

struct Edge
{
	ll to, cost;
};

ll dijkstra(int start, int finish, vector<Edge> G[]){
	priority_queue<P, vector<P>, greater<P> > que;
	ll dis[NMAX];
	Fill(dis, MAX);
	dis[start] = 0;
	que.push(P(0, start));
	while(!que.empty()){
		P cur = que.top();
		que.pop();
		int cur_index = cur.second;
		if(dis[cur_index] < cur.first) continue;
		for (int i = 0; i < G[cur_index].size(); ++i)
		{
			int next_index = G[cur_index][i].to;
			if(next_index == 0) continue;
			if (G[cur_index][i].cost + dis[cur_index] < dis[next_index])
			{
				dis[next_index] = G[cur_index][i].cost + dis[cur.second];
				que.push(P(dis[next_index], next_index));
			}
		}
	}
	return dis[finish];

}

void  warshallFloyd(vector<Edge>G[], ll dp[][NMAX], int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j] = MAX;
		}
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < G[i].size(); ++j)
		{
			dp[G[i][j].to][i] = G[i][j].cost;
			dp[i][G[i][j].to] = G[i][j].cost;
		}
	}

	for (int k = 1; k < n ; ++k){
		for (int i = 1; i < n; ++i){
			for (int j = 1; j < n; ++j){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
 			}
 		}
	}
}

int main(){
	int n, m;
	vector<Edge> G[NMAX];

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v, l;
		cin >> u >> v >> l;
		u--;
		v--;
		Edge e1 = {v, l};
		Edge e2 = {u, l};
		G[u].push_back(e1);
		G[v].push_back(e2);
	}

	ll ans = MAX;

	ll dp[NMAX][NMAX];
	warshallFloyd(G, dp, n);

	for (int i = 0; i < G[0].size(); ++i)
	{
		for (int j = i+1; j < G[0].size(); ++j)
		{
			ans = min(ans, G[0][i].cost + G[0][j].cost + dp[G[0][i].to][G[0][j].to] );
		}
	}

	if(ans == MAX){
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;
	return 0;

}
