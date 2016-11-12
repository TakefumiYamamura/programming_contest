#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	std::vector<int> v;

	v.push_back(1);
	v.push_back(3);

	cout << *lower_bound(v.begin(), v.end(), 2) << endl;

}
