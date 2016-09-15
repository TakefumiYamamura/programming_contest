#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, q, l, r;
	cin >> n >> q;
	vector<int> osero;
	osero.resize(n+1, 0);
	for (int i = 0; i < q; ++i)
	{
		cin >> l >> r;
		osero[l-1]++;
		osero[r]--;
	}
	for (int i = 1; i < n; ++i)
	{
		osero[i] += osero[i-1];
	}
	for (int i = 0; i < n; ++i)
	{
		cout << osero[i] % 2;
	}
	cout << endl;
}
