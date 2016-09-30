#include <iostream>
#define  NMAX 100001
using namespace std;


int main(){
	int n, count;
	int a[NMAX];
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	count = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (a[a[i]] == i){
			count++;
		}
	}
	cout << count/2 << endl;

}
