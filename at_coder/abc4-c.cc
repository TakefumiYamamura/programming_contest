#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main(){
	int n;
	vector<int> array;
	cin >> n;
	for (int i = 1; i <= 6; ++i)
	{
		array.push_back(i);
	}
	map<vector<int >, int> memo;
	map<int, vector<int > > hash;
	vector<int> cur = array;
	int count = 0;
	memo[array] = -1;
	hash[0] = array;
	while(true){
		vector<int> tmp = cur;
		swap(tmp[count % 5], tmp[count % 5 + 1]);
		count++;
		if(memo[tmp] == -1) break;
		memo[tmp] = count;
		hash[count] = tmp;
		cur = tmp;
	}
	for (int i = 0; i < array.size(); ++i)
	{
		cout << hash[n%count][i];
	}
	cout << endl;


}
