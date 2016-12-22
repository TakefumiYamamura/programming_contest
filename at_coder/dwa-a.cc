#include <iostream>


using namespace std;


int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int ans = a + b - n;
	if(ans < 0 ){
		cout << 0 << endl;
	}else{
		cout << ans << endl;
	}
}
