#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>

#define rep(i,n) for (int i=0; i < int(n); i++)

using namespace std;

// 素集合データ構造
struct UnionFind
{
  // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
  vector<int> par;
  // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    // 最初は全てのデータiがグループiに存在するものとして初期化
    rep(i,n) par[i] = i;
  }

  // データxが属する木の根を得る
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
  }

  // 2つのデータx, yが属する木をマージする
  void unite(int x, int y) {
    // データの根ノードを得る
    x = find(x);
    y = find(y);

    // 既に同じ木に属しているならマージしない
    if (x == y) return;

    // xの木がyの木より大きくなるようにする
    if (sizes[x] < sizes[y]) swap(x, y);

    // xがyの親になるように連結する
    par[y] = x;
    sizes[x] += sizes[y];
    // sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
  }

  // 2つのデータx, yが属する木が同じならtrueを返す
  bool same(int x, int y) {
    return find(x) == find(y);
  }

  // データxが含まれる木の大きさを返す
  int size(int x) {
    return sizes[find(x)];
  }
};

class Connectivity
{
public:
	int n, k, l
	Connectivity();
	~Connectivity();
	int dfs(int k);
	void exec();
};


Connectivity::Connectivity(){
	cin >> s;
	checkString.push_back("dream");
	checkString.push_back("dreamer");
	checkString.push_back("erase");
	checkString.push_back("eraser");
}

Connectivity::~Connectivity(){}

int Connectivity::dfs(int k){
	if(k == s.size()) return s.size();
	int maxV = 0;
	for (int i = 0; i < 4; ++i)
	{
		bool flag = false;
		for (int j = 0; j < checkString[i].size(); ++j)
		{
			if(s.size() >= k+j && s[k+j] == checkString[i][j]){
				flag = true;
			}else{
				flag = false;
				break;
			}
		}
		if(flag){
			maxV = max(maxV, dfs(k+checkString[i].size()) );
		}
	}
	return maxV;
}

void Connectivity::exec(){
	if(dfs(0) == s.size()){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

}

int main(){
	Connectivity c = Connectivity();
	c.exec();
}
