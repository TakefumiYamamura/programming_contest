#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;

struct Present{
	int w, h;
	static bool Asc(const Present& x, const Present& y){
		if(x.w == y.w){
			return x.h < y.h;
		}else{
			return x.w < y.w;
		}
	}
};

// request minimum query
class SegmentTree{
public:
	int n; //要素数
	int height;
	vector<int> dat;
	SegmentTree(int n_);
	~SegmentTree();
	//k番目の値をaに変更
	void update(int k, int a);
	//区間a-bの最小値を求める。
	//後ろのほうの引数は、計算の簡単のための引数。
	int query(int a, int b, int k, int l, int r);
};

SegmentTree::SegmentTree(int n_){
	n = 1;
	while(n < n_){
		n *= 2;
		height++;
	}
	dat = vector<int>(2 * n - 1, INT_MAX);
}

SegmentTree::~SegmentTree(){}

void SegmentTree::update(int k, int a){
	k += n - 1;
	dat[k] = a;
	while(k > 0){
		k = (k - 1) / 2;
		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
}

//区間a-bの最小値を求める。
//後ろのほうの引数は、計算の簡単のための引数。
//外からはquery(a,b,0,0,n)のように呼ぶ
int SegmentTree::query(int a, int b, int k, int l, int r){
	if(r <= a || b <= l) return INT_MAX;
	if(a <= l && r <= b){
		return dat[k];
	}else{
		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
}

class PresentForMySpecial{
public:
	int n;
	vector<Present> presents;
	PresentForMySpecial();
	~PresentForMySpecial();
	void exec();
};

PresentForMySpecial::PresentForMySpecial(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Present tmpP;
		cin >> tmpP.w >> tmpP.h;
		presents.push_back(tmpP);
	}
}

PresentForMySpecial::~PresentForMySpecial(){
	sort(presents.begin(), presents.end(), Present::Asc);
	vector<vector<int > > dp;
	dp.resize(n);
	for (int i = 0; i < n; ++i)
	{
		
	}
}





int main(){
	int n;
	cin >> n;
	vector<Present> presents;
	int dp[1000001];
	for (int i = 0; i < n; ++i)
	{
		Present p;
		cin >> p.w >> p.h;
		presents.push_back(p);
	}

	sort(presents.begin(), presents.end(), Present::Asc);
	int k = 0;

	for (int i = 0; i < n-1; ++i)
	{
		if(presents[k].w == presents[k+1].w){
			remove(presents, k);
			k--;
		}
		k++;
	}

	dp[0] = 1;

	for (int i = 1; i < presents.length(); ++i)
	{
		if(presents[i].h > presents[i-1].h){
			dp[i] = dp[i-1] + 1;
		}
	}

}

