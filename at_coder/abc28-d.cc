#include <iostream>

using namespace std;

int main(){
	long double n, k;
	cin >> n >> k;
	long double ans;
	ans =  (1.0 + 3 * (k - 1) + 3 * (n - k) + 6 * (k - 1) * (n - k) )/ (n * n * n);
	printf("%.24Lf\n", ans );
}