#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

struct Point
{
	int r, c;
};


class CollectionKing
{
public:
	int r, c, k, n;
	vector<ll> r_counts;
	vector<ll> r_table;
	vector<ll> c_counts;
	vector<ll> c_table;
	vector<Point> points;
	CollectionKing();
	~CollectionKing();
	void exec();
	
};

CollectionKing::CollectionKing(){
	cin >> r >> c >> k;
	cin >> n;
	r_counts.resize(r, 0);
	r_table.resize(n+1, 0);
	c_counts.resize(c, 0);
	c_table.resize(n+1, 0);

	for (int i = 0; i < n; ++i)
	{
		Point tmp;
		cin >> tmp.r >> tmp.c;
		tmp.r--;
		tmp.c--;
		points.push_back(tmp);
	}

}


CollectionKing::~CollectionKing(){}

void CollectionKing::exec(){
	for (int i = 0; i < n; ++i)
	{
		Point cur = points[i];
		r_counts[cur.r]++;
		c_counts[cur.c]++;
	}
	
	for (int i = 0; i < r_counts.size(); ++i)
	{
		r_table[r_counts[i]]++;
	}

	for (int i = 0; i < c_counts.size(); ++i)
	{
		c_table[c_counts[i]]++;
	}

	ll ans = 0;

	for (int i = 0; i <= k; ++i)
	{
		ans += r_table[i] *  c_table[k-i];
	}

	for (int i = 0; i < n; ++i)
	{
		Point tmp = points[i];
		if(r_counts[tmp.r] + c_counts[tmp.c] == k){
			ans--;
		}
		if(r_counts[tmp.r] + c_counts[tmp.c] == k+1){
			ans++;
		}
	}

	cout << ans << endl;
}


int main(){
	CollectionKing ck = CollectionKing();
	ck.exec();
}
