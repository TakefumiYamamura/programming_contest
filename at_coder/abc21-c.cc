#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

struct Node
{
	int index, depth;
};


class HonestMrTakahashi
{
public:
	int n, start, goal, m;
	std::vector<int> g[101];
	int check[101];
	int dp[101];
	HonestMrTakahashi();
	~HonestMrTakahashi();
	int bfs();
	void exec();
};

HonestMrTakahashi::HonestMrTakahashi(){
	cin >> n;
	cin >> start >> goal;
	start--; goal--;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
}

HonestMrTakahashi::~HonestMrTakahashi(){}

int HonestMrTakahashi::bfs(){
	queue<Node> q;
	Node s = {start, 0};
	q.push(s);
	int sum = 0;
	Fill(check, -1); //未訪問は1s
	Fill(dp, 0);
	dp[start] = 1;
	while(!q.empty()){
		Node cur = q.front();
		q.pop();
		for (int i = 0; i < g[cur.index].size(); ++i)
		{
			int next = g[cur.index][i];
			if(check[next] == -1){
				check[next] = cur.depth + 1;
				Node tmp = {next, cur.depth+1};
				q.push(tmp);
			}
			if(check[next] == cur.depth + 1){
				dp[next] += dp[cur.index];
				dp[next] %=  1000000007;
			}
		}
	}
	return dp[goal];
}

void HonestMrTakahashi::exec(){
	cout << bfs() << endl;

}

int main(){
	HonestMrTakahashi hmt = HonestMrTakahashi();
	hmt.exec();
}
