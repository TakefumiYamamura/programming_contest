#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
 
#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair
 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
ll S = 0;
 
struct Mat {
	vector<vector<ll> > dat;
	int n;
 
	Mat(int n) : n(n), dat(n, vector<ll>(n)) {}
 
	Mat(vector<vector<ll> > dat) : n(dat.size()), dat(dat) {}
 
	Mat I(int n) {
		Mat ret(n);
		rep(i, n) ret.dat[i][i] = S;
		return ret;
	}
 
	Mat mul(Mat &b) {
		Mat ret(n);
		rep(i, n) rep(j, n) rep(k, n) (ret.dat[i][j] ^= (dat[i][k] & b.dat[k][j]));
		return ret;
	}
 
	Mat pow(ll b) {
		Mat ret = I(n);
		for (Mat A = *this; b > 0; A = A.mul(A) , b /= 2) if (b & 1) ret = A.mul(ret);
		return ret;
	}
};
 
int main() {
	int n, m;
	cin >> n >> m;
 
	vector<ll> a(n), c(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> c[i];
 
	rep(i, 32) {
		S += (1LL << i);
	}
 
	if(m <= n) {
		cout << a[m-1] << endl;
	} else {
 
		Mat mat(n);
		rep(i, n) mat.dat[0][i] = c[i];
		REP(i, 1, n) mat.dat[i][i-1] = S;
 
		Mat ret = mat.pow(m - n);
		// rep(i, n) {
		// 	rep(j, n) {
		// 		cout << ret.dat[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
 
		ll ans = 0;
		rep(i, n) {
			ans ^= (ret.dat[0][i] & a[n-1-i]);
		}
 
		cout << ans << endl;
	}
 
	return 0;
}