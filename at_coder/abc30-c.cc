#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long long n, m;
	long long x, y;
	cin >> n >> m;
	cin >> x >> y;

	vector<long long> a;
	vector<long long> b; 

	for (int i = 0; i < n; ++i)
	{
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	for (int i = 0; i < m; ++i)
	{
		long long tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	long long cur_time = 0;
	long long count = 0;

	vector<long long>::iterator a_index = a.begin();
	vector<long long>::iterator b_index = b.begin();

	while(*a_index != 0 && *b_index != 0){
		//while(!*a_index && !*b_index ){ why is this error?
		if (count % 2 == 0){
			a_index = lower_bound(a_index, a.end(), cur_time);
			if(!*a_index) break;
			count++;
			cur_time = *a_index + x;		
		}else{
			b_index = lower_bound(b_index, b.end(), cur_time);
			if(!*b_index) break;
			count++;
			cur_time = *b_index + y;
		}
	}

	cout << count / 2 << endl;
}
