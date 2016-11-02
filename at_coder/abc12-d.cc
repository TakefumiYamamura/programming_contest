#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long
#define P pair<ll, ll>

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

const ll MAX = 1e9+7;

struct Edge
{
	int to;
	int cost;
};

ll dijkstra(const vector<Edge> G[], int n, int start){
	priority_queue<P, vector<P>, greater<P> > que; //P　first is cost, second is index
	vector<ll> dis(n, MAX);
	dis[start] = 0;
	// vector<int> check(n, 1); // 未訪問が1
	// check[start] = 0;
	que.push(P(0, start) );

	while(!que.empty()){
		P cur = que.top();
		que.pop();
		// que にはindexが重複するものがあるため
		if(cur.first > dis[cur.second]) continue;
		for (int i = 0; i < G[cur.second].size() ; ++i)
		{
			Edge next = G[cur.second][i];
			if(dis[cur.second] + next.cost < dis[next.to] ){
				dis[next.to] = dis[cur.second] + next.cost; 
				que.push(P(dis[next.to], next.to) );
			}
		}
	}
	sort(dis.begin(), dis.end());
	return dis[n-1];
}


int main(){
	int n, m;
	vector<Edge> G[301];

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, t;
		cin >> a >> b >> t;
		a--;
		b--;
		Edge e1 = {b, t};
		Edge e2 = {a, t}; 
		G[a].push_back(e1);
		G[b].push_back(e2);
	}

    ll ans = MAX;

	for (int i = 0; i < n; ++i)
	{
		ans = min(ans, dijkstra(G, n, i) ); 
	}

	cout << ans << endl;

}
