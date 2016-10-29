#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define P pair<ll, ll>
using namespace std;
const ll MAX = 1e9+7;


struct Edge
{
	ll to, cost;
};

void dijkstra(ll start, ll dis[], vector<Edge> G[], ll n){
	for (int i = 0; i < n; ++i)
	{
		dis[i] = MAX;
	}
	dis[start] = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(P(0, start));
	while(!que.empty()){
		P p = que.top();
		que.pop();
		ll cur = p.second;
		if(dis[cur] < p.first) continue;
		for (int i = 0; i < G[cur].size(); ++i)
		{
			Edge tmp = G[cur][i];
			if(dis[tmp.to] > dis[cur] + tmp.cost){
				dis[tmp.to] = dis[cur] + tmp.cost;
				que.push(P(dis[tmp.to], tmp.to));
			}
		}
	}
}

int main(){
	ll n, m, t;
	ll a[100001];
	vector<Edge> G[100001];
	vector<Edge> revG[100001];
	ll dis[100001];
	ll rev_dis[100001];
	cin >> n >> m >> t;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		Edge e;
		e.to = b;
		e.cost = c;
		G[a].push_back(e);
		Edge rev_e;
		rev_e.to = a;
		rev_e.cost = c;
		revG[b].push_back(rev_e);
	}

	dijkstra(0, dis, G, n);
	dijkstra(0, rev_dis, revG, n);

	ll ans = 0;

	for (int i = 0; i < n; ++i)
	{
		if(t >  dis[i] + rev_dis[i]){
			ans = max(ans, (t - dis[i] - rev_dis[i]) * a[i] ); 
		}
	}

	cout << ans << endl;

	return 0;

}
