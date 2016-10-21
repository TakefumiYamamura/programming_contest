#include <iostream>
using namespace std;

long long min(long long a, long long b){
	if(a > b){
		return b;
	}else{
		return a;
	}
}


int main(){
	long long a, b, c;
	cin >> a >> b >> c ;
	if(a%2 == 0 || b%2 == 0 || c%2 == 0){
		cout << 0 << endl;
		return 0;
	}

	long long ans = min(a*b, min(b*c, c*a));
	cout << ans << endl;

}
