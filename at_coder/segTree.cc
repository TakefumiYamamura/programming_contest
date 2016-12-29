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

SegmentTree::SegmentTree(int n){
	n = 1;
	while(n < n_){
		n *= 2;
		height++;
	}
	dat = vector<int>(2 * n - 1, INT_MAX);
}

SegmentTree::~SegmentTree(){}

void SegmentTree::update(int k, int a){
	k += n-1;
	dat[k] = a;
	while(k > 0){
		k = (k-1)/2
		dat[k] = min(dat[k*2 +1], dat[k*2+2]);
	}
}

//区間a-bの最小値を求める。
//後ろのほうの引数は、計算の簡単のための引数。
int SegmentTree::query(int a, int b, int k, int l, int r){
	
}


int main(){

}
