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
	UnionFindTree(int n){
		this.n = n;
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
		root_x = find(x);
		root_y = find(y);
		if(root_x == root_y)return;
		if(rank[root_x] < rank[root_y]){
			par[root_x] = root_y;
		}else{
			par[root_y] = root_x;
			if(rank[root_x] == rank[root_y]) rank[root_x]++;
		}
	}
};


class GCDGraph
{
public:
	vector<int > > G;
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
		// int bigger = max(x, y);
		// vector<int> map_x;
		// vector<int> map_y;
		// map_x.resize(n+1);
		// map_y.resize(n+1);
		// for (int i = 0; i <= n; ++i)
		// {
		// 	map_x[i] = 0;
		// 	map_y[i] =
		// }

		// for (int i = 1; i < x; ++i)
		// {
		// 	if(x%i == 0){
		// 		map_x[i] = 1;
		// 	}else{
		// 		map_x[i] = 0;
		// 	}
		// }

		// for (int i = 1; i < y; ++i)
		// {
		// 	if(y%i == 0){
		// 		map_y[i] = 1;
		// 	}else{
		// 		map_y[i] = 0;
		// 	}
		// }


		// for (int i = bigger+1; i <= n; ++i)
		// {
		// 	for (int j = 0; j < i; ++j)
		// 	{
		// 		if(i%j == 0 && map_y[j] && map_y[i]){
		// 			return "Possible";
		// 		}
		// 	}
		// }

		// if(x == y) return "Possible";
		if(gcd(x, y) > k){
			return "Possible";
		}else{
			return "Impossible";
		}


		// G.resize(n+1);
		// for (int i = 1; i <= n; ++i)
		// {
		// 	for (int j = i+1; j <= n; ++j)
		// 	{
		// 		if(j != i && gcd(i, j) > k){
		// 			G[i].push_back(j);
		// 			G[j].push_back(i);
		// 		}
		// 	}
		// }


		// vector<bool> V;
		// V.resize(n+1);
		// for (int i = 1; i <= n; ++i)
		// {
		// 	V[i] = false;
		// }

		// queue<int> q;
		// q.push(x);
		// V[x] = true;
		// bool findFlag = false;
		// while(!q.empty()){
		// 	int cur = q.front();
		// 	q.pop();
		// 	for (int i = 0; i < G[cur].size(); ++i)
		// 	{
		// 		int next = G[cur][i];
		// 		if(V[next] == false){
		// 			q.push(next);
		// 			V[next] = true;
		// 			if(next == y){
		// 				findFlag = true;
		// 				break;
		// 			}
		// 		}
		// 	}
		// 	if(findFlag) break;
		// }

		// if(findFlag){
		// 	return "Possible";
		// }else{
		// 	return "Impossible";
		// }

	}
};


// int main(){
// 	GCDGraph g = GCDGraph();
// 	cout << g.possible(12,2, 8,9) << endl;
// }
