#include <iostream>
#define ll long long
using namespace std;

int x[51];

struct set
{
	ll tak, ao;
};

ll solve(int a, int n){
	set max = {-50*n, -50*n};
	for (int i = n-1; i >= 0; --i)
	{
		if(a == i) continue;
		set tmp = {0, 0};

		int start, finish;
		if(i < a){
			start = i;
			finish = a; 
		} else{
			finish = i;
			start = a;
		}

		while(start <= finish){
			if( (finish - start) % 2 == 0){
				tmp.tak += x[finish];
			}else{
				tmp.ao += x[finish];
			}
			finish--;
		}
		if(tmp.ao >= max.ao) max = tmp;
	}
	return max.tak;
}


int main(){
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}

    ll ans = -50*n;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, solve(i, n));
	}

	cout << ans << endl;

}
