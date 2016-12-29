#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

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


class ConnectedComponentConstruction
{
public:
	vector<string> construct(vector<int> s){
		vector<string> ans;
		int check = 0;
		check -= s.size();
		for (int i = 0; i < s.size(); ++i)
		{
			check += s[i];
			if(s[i] < 1){
				return ans;
			}
		}
		if(check % 2 == 1){
			return ans;
		}
		vector<vector<int > > ret;
		ret.resize(s.size());
		for (int i = 0; i < s.size(); ++i)
		{
			ret[i].resize(s.size());
			for (int j = 0; j < s.size(); ++j)
			{
				ret[i][j] = -1;
			}
		}

		vector<int> tmp_data(s.size(), 1);

		UnionFindTree uft = UnionFindTree(s.size());
		for (int i = 0; i < s.size(); ++i)
		{
			while(tmp_data[i] != s[i]){
				for (int j = 0; j < s.size(); ++j)
				{
					if(i == j) continue;
					if(s[i] != tmp_data[j]){
						UnionFindTree tmpUft = uft;
						tmpUft.unite(i, j);
						bool flag = true;
						for (int k = 0; k < s.size() ; ++k)
						{
							int tmpCount = 0;
							for (int l = 0; l < s.size(); ++l)
							{
								if(tmpUft.same(k, l)) tmpCount++;
							}
							if(tmpCount > s[k]){
								flag = false;
								break;
							}
						}
						if(flag){
							uft = tmpUft;
							for (int k = 0; k < s.size() ; ++k)
							{
								int tmpCount = 0;
								for (int l = 0; l < s.size(); ++l)
								{
									if(tmpUft.same(k, l)) tmpCount++;
								}
								tmp_data[k] = tmpCount;
							} 
						}
					}
					if(tmp_data[i] == s[i]) break;
				}

			}
		}


		for (int i = 0; i < s.size(); ++i)
		{
			string tmp = "";
			for (int j = 0; j < s.size(); ++j)
			{
				if(i == j){
					tmp += "N";
					continue;
				}
				if(uft.same(i, j)){
					tmp += "Y";
				} else{
					tmp += "N";
				}
			}
			ans.push_back(tmp);
		}
		return ans;
	}
};
