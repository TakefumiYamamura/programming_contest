#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

#define MOD 1000000007



class Solve
{
private:
	int n, m;
	vector<int> a;
	vector<int> l, r;
public:
	Solve(){
		cin >> n >> m;
		a.resize(n);
		l.resize(m);
		r.resize(m);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> l[i] >> r[i];
			l[i]--;
			r[i]--;
		}
	}
	void exec(){
		vector<int> all_pattern;
		for (int i = 0; i < m; ++i)
		{
			all_pattern.push_back(i);
		}
		int ans = 0;
		do {
			vector<int> tmp = a;
			int tmp_ans = 0;
			for (int i = 0; i < m; ++i)
			{
				int tmp_i = all_pattern[i];
				cout << tmp_i;
				reverse(tmp.begin() + l[tmp_i], tmp.begin() + r[tmp_i] + 1 );
			}
			cout << endl;
			for (int i = 0; i < m; ++i)
			{
				tmp_ans += (i + 1) * tmp[i];
			}
			ans = max(ans, tmp_ans);
		} while ( next_permutation(all_pattern.begin(), all_pattern.end()) );
		cout << ans << endl;

	}
};

int main(){
	Solve solver = Solve();
	solver.exec();
}
