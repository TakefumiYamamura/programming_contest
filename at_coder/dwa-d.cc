#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	long long val;
	int index;
	static bool ValDesc(Node& a, Node& b){
		return a.val > b.val;
	}
};


class NetaSushi
{
public:
	int n;
	int m;
	long long ans;
	vector<long long> x;
	vector<long long> y;
	vector<Node> dif;
	NetaSushi();
	void exec();
	
};

NetaSushi::NetaSushi(){
	cin >> n >> m;
	x.resize(n);
	y.resize(n);
	dif.resize(n);
	ans = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
		dif[i].val = x[i] - y[i];
		dif[i].index = i;
		ans += y[i];
	}
}

void NetaSushi::exec(){
	sort(dif.begin(), dif.end(), Node::ValDesc);
	m = min(n, m);
	int max_index = 0;
	for (int i = 0; i < m-1; ++i)
	{
		ans += dif[i].val;
		max_index = max(max_index, dif[i].index);
	}

	if(m == n){
		cout << ans +  dif[m-1].val << endl;
		return;
	}

	long long tmp_ans = ans;
	tmp_ans += dif[m-1].val;
	max_index = max(max_index, dif[m-1].index);
	for (int i = max_index + 1; i < n; ++i)
	{
		tmp_ans -= y[i];
	}
	ans = max(tmp_ans, ans);
	for (int i = max_index; i < n-1; ++i)
	{
		tmp_ans -= x[i];
		tmp_ans += y[i];
		tmp_ans += x[i+1];
		ans = max(ans, tmp_ans);
	}
	cout << ans << endl;
}

int main(){
	NetaSushi ns = NetaSushi();
	ns.exec();
}
