#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

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


int main(){
	int a[10] = {10,9,6,7,5,4,3,8,1,10};

	SegmentTree st = SegmentTree(10);
	for (int i = 0; i < 10; ++i)
	 {
	 	st.update(i, a[i]);
	 }
	 //(3,5] 6,7 => 7
	 cout << st.query(4, 5, 0, 0, 10) << endl;
}
