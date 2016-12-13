#include <iostream>
#include <algorithm>
using namespace std;
#define eps 10e-10

int main(){
	double l, x, y, s, d;
	double ans1;
	double ans2;
	cin >> l >> x >> y >> s >> d;
	if(d - s > eps){
		ans1 = (d - s) / (x + y);
	}else{
		ans1 = (l - s + d) / (x + y);
	}
	// cout << ans1 << endl;
	if(y - x > eps){
		if(d - s > eps){
			ans2 = (l - d + s) / (y - x);
		}else{
			ans2 = (s - d) / (y - x);
		}
		// cout << ans2 << endl;
		if(ans1 - ans2 > eps){
			ans1 = ans2;
		}else{
			ans1 = ans1;
		}
	}
	printf("%.12lf\n", ans1);

}