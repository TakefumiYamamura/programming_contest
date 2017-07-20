#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <set>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	ll sum = 0;
	sum -= n;
	for (ll i = 1; i <= sqrt(n); ++i)
	{
		if(n % i == 0) {
			sum += i;
			if(i != n/i) sum += n / i;
		}
	}
	if(sum == n) {
		cout << "Perfect" << endl;
	} else if (sum < n) {
		cout << "Deficient" << endl;
	} else {
		cout << "Abundant" << endl;
	}
}
