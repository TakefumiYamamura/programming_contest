#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
	long  sum = 0;
	int n;
	int a[200001];
	int pos[200001];
	set<int> data;

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}

	data.insert(0);
	data.insert(n+1);

	for (int i = 1; i <= n; ++i)
	{
		int l, r;
		data.insert(pos[i]);
		set<int>::iterator it = data.find(pos[i]);
		r = *(++it) - pos[i];
		--it;
		l = pos[i] - *(--it);
		sum += (long)i * r * l;
	}
	cout << sum << endl;
}
