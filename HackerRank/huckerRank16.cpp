#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int n;
	int c[100001];
	vector<int> count;
	count = vector<int>(100001, 0);
	int minC = 100010;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
		minC = min(minC, c[i]);
		count[c[i]]++;
	}
	// bool flag = false;
	if(count[minC] > 1){
		cout << minC << " " << n << endl;
		return 0;
	}
	for (int i = minC+1; i <= min(10000, 2*minC); ++i)
	 {
	 	if(count[i] != 0){
	 		// flag = true;
	 		cout << i << " " << count[minC] << endl;
	 		return 0;
	 	}
	 } 
	 cout << minC * 2 << " " << count[minC] << endl;

}
