#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class UnionFindTree
{
public:
	int n;
	vector<int> par;
	vector<int> rank;
	UnionFindTree(){}
	UnionFindTree(int num){
		n = num;
		par.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; ++i)
		{
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y){
		int root_x = find(x);
		int root_y = find(y);
		if(root_x == root_y) return;
		if(rank[root_x] < rank[root_y]){
			par[root_x] = root_y;
		}else{
			par[root_y] = root_x;
			if(rank[root_x] == rank[root_y]) rank[root_x]++;
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};

class BaumTest
{
public:
	int n, m;
	UnionFindTree uft;
	vector<int> edge_count;
	BaumTest() {
		cin >> n >> m;
		uft = UnionFindTree(n);
		edge_count = vector<int>(n, 0);
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			edge_count[u]++;
			uft.unite(u, v);
		}

	}

	void exec() {
		int ans = 0;
		unordered_map<int, int> hash_node_nums;
		unordered_map<int, int> hash_node_edges;
		for (int node = 0; node < n; ++node)
		{
			hash_node_nums[uft.find(node)]++;
			hash_node_edges[uft.find(node)] += edge_count[node];
		}

		for(auto hash : hash_node_nums) {
			if(hash_node_edges[hash.first] + 1 == hash.second) ans++;
		}
		cout << ans << endl;
	}
	
};

int main(){
	BaumTest bt = BaumTest();
	bt.exec();
}
