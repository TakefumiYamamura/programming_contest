#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#define ll long long
using namespace std;


class UnionFindForests{
    public:
        vector<ll> parents, ranks;
        UnionFindForests(ll size){
            for (ll i = 0; i < size; ++i)
            {
                parents.push_back(i);
                ranks.push_back(0);
            }
        }

        ll find(ll x){
            if(parents[x] == x){
                return x;
            }else{
                //　一度根をたどった場合変を直接根に貼り直してる。
                //pass compression(経路圧縮)
                return parents[x] = find(parents[x]);
            }
        }

        bool same(ll x, ll y){
            if(parents[x] == parents[y]){
                return true;
            }else{
                return false;
            }
        }

        void unite(ll x, ll y){
            ll root_x = find(x);
            ll root_y = find(y);
            if (ranks[root_x] > ranks[root_y])
            {
                parents[root_y] = root_x;
            }else if(ranks[root_x] < ranks[root_y]){
                parents[root_x] = root_y;
            }else if(ranks[root_x] == ranks[root_y]){
                parents[root_x] = root_y;
                ranks[root_y]++;
            }
        }
};

class Edge{ 
public:
	ll source, target, cost;
	
	Edge(ll source = 0, ll target = 0, ll cost = 0)
	:source(source)
	,target(target)
	,cost(cost){}

	static bool compare(const Edge& e1, const Edge& e2){
		return e1.cost < e2.cost;
	}
};

ll V, E;
vector<Edge> edges;

ll kluskal(){
	ll min_cost = 0;
	sort(edges.begin(), edges.end(), Edge::compare);
	UnionFindForests uf = UnionFindForests(V);
	for (int i = 0; i < E; ++i)
	{
		if(uf.same(edges[i].source, edges[i].target) == false){
			uf.unite(edges[i].source, edges[i].target);
			min_cost+= edges[i].cost;
		}
	}
	return min_cost;
}


ll W, H;
ll create_index(ll x, ll y){
	return x + W * y;
}

int main(){
	cin >> W >> H;

    for (ll i = 0; i < W; ++i)
	{
		ll p;
		cin >> p;
		for (ll j = 0; j <= H; ++j)
		{
			edges.push_back(Edge(create_index(i, j), create_index(i+1, j), p));
		}
	}
	for (ll i = 0; i < H; ++i)
	{
		ll q;
		cin >> q;
		for (ll j = 0; j <= W; ++j)
		{
			edges.push_back(Edge(create_index(j, i), create_index(j, i+1), q));
		}
	}
	sort(edges.begin(), edges.end());
	E = edges.size();
	cout << kluskal() << endl;


}

