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
	NetaSushi();
	void exec();
	
};

NetaSushi::NetaSushi(){
	cin >> n >> m;
	x.resize(n);
	y.resize(n);
	sum_ans = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
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
		que.push(x[i] - y[i]);
		if(que.size() > m - 1){
			sum -= que.top();
			que.pop();
		}
	}
	
	cout << ans << endl;
}

int main(){
	NetaSushi ns = NetaSushi();
	ns.exec();
}
