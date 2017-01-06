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


class GCDGraph
{
public:
	int gcd( int a, int b )
	{
	  if ( ( 0 == a ) || ( 0 == b ) )
	    return 0;
	  while( a != b )
	  {
	    if ( a > b ) a = a - b;
	    else         b = b - a;
	  }
	  return a;
	}

	string possible(int n, int k, int x, int y){
		UnionFindTree uft = UnionFindTree(n+1);
		for (int i = k+1; i <= n; ++i)
		{
			for (int j = i; j <= n; j += i)
			{
				uft.unite(i, j);
			}
		}

		if(uft.same(x, y)){
			return "Possible";
		}else{
			return "Impossible";
		}

	}
};

// int main(){
// 	GCDGraph g = GCDGraph();
// 	cout << g.possible(12,2, 8,9) << endl;
// }
