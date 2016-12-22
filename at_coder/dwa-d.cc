#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class NetaSushi
{
public:
	int n;
	int m;
	long long sum_ans;
	vector<long long> x;
	vector<long long> y;
	vector<long long> dif;
	NetaSushi();
	void exec();
	
};

NetaSushi::NetaSushi(){
	cin >> n >> m;
	x.resize(n);
	y.resize(n);
	dif.resize(n);
	sum_ans = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
		dif[i] = x[i] - y[i];
		sum_ans += y[i];
	}
}

void NetaSushi::exec(){
	priority_queue<int, vector<int>, greater<int> > que;
	long long ans = 0;
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += x[i];
		ans = max(sum, ans);
		// cout << ans << endl;
		que.push(x[i] - y[i]);
		if(que.size() > m - 1){
			sum -= que.top();
			que.pop();
		}
	}
	sort(dif.begin(), dif.end(), greater<int>());
	m = min(n, m);
	for (int i = 0; i < m-1; ++i)
	{
		sum_ans += dif[i];
	}
	ans = max(sum_ans, ans);
	
	cout << ans << endl;
}

int main(){
	NetaSushi ns = NetaSushi();
	ns.exec();
}
