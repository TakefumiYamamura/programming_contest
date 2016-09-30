#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, m, x;
	vector<int> a;
	cin >> n >> m;
	a.resize(m+1, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		a[x]++;
		if(a[x] > n/2){
			cout << x << endl;
			return 0;
		}
	}
	cout << "?" << endl;

}
