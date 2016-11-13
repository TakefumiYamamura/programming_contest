#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;
#define ull unsigned long long
#define ll long long
#define eps 10e-10

ull pow(ull a, ull e){
    ull tmp = 1;
    while(e > 0){
        if( e & 1ll){
            tmp = tmp * a;
        }
        a = a * a;
        e >>= 1; 
    }
    return tmp;
}

class Conbination
{
public:
	int size;
	vector<vector<long double> > nck;
	Conbination(int n);
	~Conbination();
	void setnCk();
	long double fetchnCk(int n, int k);
};

Conbination::Conbination(int n){
	this->size = n;
	setnCk();
}

Conbination::~Conbination(){}

void Conbination::setnCk(){
	vector<long double> start;
	start.push_back(1.0);
	nck.push_back(start);

	for (int i = 0; i <= size; ++i)
	{
		vector<long double> next;
		for (int j = 0; j <= i+1; ++j)
		{
			next.push_back(0);
		}

		for (int j = 0; j < i+1; ++j)
		{
			next[j] += nck[i][j] / 2.0;
			next[j+1] += nck[i][j] / 2.0;
		}
		nck.push_back(next);
	}
}

long double  Conbination::fetchnCk(int n, int k){
	// for (int i = 0; i <= n; ++i)
	// {
	// 	for (int j = 0; j < i+1 ; ++j)
	// 	{
	// 		cout << nck[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return nck[n][k];
}


class BigJump
{
public:
	int n;
	ll d, x, y;
	BigJump();
	~BigJump();
	void exec();
	
};

BigJump::BigJump(){
	cin >> n >> d;
	cin >> x >> y;
	x = abs(x);
	y = abs(y);
}

BigJump::~BigJump(){}

void BigJump::exec(){
	Conbination c = Conbination(n);
	if(x % d != 0 || y % d != 0){
		cout << 0.0 << endl;
		return;
	}
	x /= d;
	y /= d;

	long double ans;
	ans = 0.0;
	for (int i = 0; i <= n; ++i)
	{
		if((x + i) % 2 == 1 || (y + n - i) % 2 == 1 ) continue;
		ll r = (x + i)/2;
		ll l = i - r;
		if(r > i || r < 0 || l > i || l < 0 || r + l != i) continue;
		ll u = (y + n - i)/2;
		ll d = n - i - u;
		if(u > n - i || u < 0 || d > n - i || d < 0 || u + d != n -i) continue;
		ans += c.fetchnCk(n, i) * c.fetchnCk(i, r) * c.fetchnCk(n-i, u);
		// ans += c.fetchnCk(n, r) * c.fetchnCk(n - r, l) * c.fetchnCk(n - r - l, u) * c.fetchnCk(n - r - l - u, d);
		// ans += c.fetchnCk(n, r) * c.fetchnCk(n - r, l) * c.fetchnCk(n - r - l, u) / powl(4.0, n);
	}

	if(fabs(ans - 0) < eps){
		cout << 0.0 << endl;
		return;
	} 

	// ans /= (long double)powl(4.0, n);
	printf("%.16Lf\n", ans);

}

int main(){
	BigJump bj = BigJump();
	bj.exec();
}
