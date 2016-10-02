#include <iostream>

using namespace std;

int main(){
	long long int sum = 0;
	int n;
	int a[200001];

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int l = 0; l < n; ++l)
	{
		int min = 200001;
		for (int r = l; r < n; ++r)
		{
			if(min > a[r]) min = a[r];
			sum += min;
		}
	}
	cout << sum << endl;

}
