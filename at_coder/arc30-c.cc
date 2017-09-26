#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <set>

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

class DirectedGraph
{
private:
	int n;
	int m;
	int k;
	vector<char> c;
	UnionFindTree uft;
	unordered_map<char, multiset<char> > um;

public:
	DirectedGraph() {
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i)
		{
			char tmp_char;
			cin >> tmp_char;
			c.push_back(tmp_char);
		}
		uft = UnionFindTree(n);
		for (int i = 0; i < m; ++i)
		{
			int a;
			int b;
			cin >> a >> b;
			a--;
			b--;
			uft.unite(a, b);
		}
	}

	void exec() {
		for (int i = 0; i < n; ++i)
		{
			um[uft.find(i)].insert(c[i]);
		}

		set<string> st;
		for(auto ele : um) {
			multiset<char> ms = ele.second;
			string ans = "";
			for(auto ch : ms) {
				ans += ch;
				if(ans.length() == k) st.insert(ans);
			}
		}
		if(st.size() == 0) {
			cout << -1 << endl;
		} else {
			auto itr = st.begin();
			cout << *itr << endl;
		}

	}
};

int main() {
	DirectedGraph dg = DirectedGraph();
	dg.exec();
}
