#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class UnionFindTree
{
public:
	int n;
	vector<int> par;
	vector<int> rank;
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


class Connectivity
{
public:
	int n, k, l;
	Connectivity();
	~Connectivity();
	void exec();	
};

Connectivity::Connectivity(){
	cin >> n >> k >> l;
	UnionFindTree uft1 = UnionFindTree(n+1);
	UnionFindTree uft2 = UnionFindTree(n+1); 
	for (int i = 0; i < k; ++i)
	{
		int p, q;
		cin >> p >> q;
		uft1.unite(p, q);
	}
	for (int i = 0; i < l; ++i)
	{
		int r, s;
		cin >> r >> s;
		uft2.unite(r, s);
	}
	pair<int, int>
	
}

int main(){
	Connectivity c = Connectivity();
	c.exec();

}
