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

class RoadConstruction
{
private:
	int n, m;
	UnionFindTree uft;
public:
	RoadConstruction() {
		cin >> n >> m;
		uft = UnionFindTree(n);
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			uft.unite(a, b);
		}
	}

	void exec() {
		unordered_set<int> us;
		for (int i = 0; i < n; ++i)
		{
			us.insert(uft.find(i));
		}
		cout << us.size() - 1 << endl;

	}
};

int main() {
	RoadConstruction rc = RoadConstruction();
	rc.exec();
}