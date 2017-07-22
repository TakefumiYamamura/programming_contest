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

class forbidden_book
{
private:
	double a, b;
	int n;
public:
	forbidden_book() {
		cin >> a >> b;
		cin >> n;
		if(a < b) swap(a, b); 
	}

	bool include_check(double c, double d) {
		if(c > d) swap(c, d);
		if(a <= c && b <= d) return true;
		if(a <= d && b <= c) return true;
		double low = 0;
		double high = M_PI/2;

		for (int i = 0; i < 1000; ++i)
		{
			double mid = (low + high) / 2;
			double w = a * cos(mid) + b * sin(mid);
			double h = a * sin(mid) + b * cos(mid);
			if(c >= w && d >= h) return true;
			if(w > c) {
				low = mid; 
			} else {
				high = mid;
			}
		}
		return false;
	}

	void exec() {
		for (int i = 0; i < n; ++i)
		{
			double c, d;
			cin >> c >> d;
			if(include_check(c, d)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			} 
		}
	}	
};

int main() {
	forbidden_book fb = forbidden_book();
	fb.exec();
}
