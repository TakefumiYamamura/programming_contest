#include <iostream>
#include <vector>
using namespace std;

class CandidatesOfNoShortestPaths
{
public:
	int n, m;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	vector<vector<int> > g;
	CandidatesOfNoShortestPaths();
	~CandidatesOfNoShortestPaths();
	void exec();

};

CandidatesOfNoShortestPaths(){
	int n, m;
	cin >> n >> m;
	g.resize(n);
	// dp.resize(n);
	for (int i = 0; i < n; ++i)
	{
		g[i] = vector<int>(n, INT_MAX); 
		// dp[i] = vector<int>(n, INT_MAX);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		a--; b--;
		g[a][b] = c;
		g[b][a] = c;
	}
}

CandidatesOfNoShortestPaths::~CandidatesOfNoShortestPaths(){}

CandidatesOfNoShortestPaths::exec(){

	// for (int i = 1; i < n; ++i)
	// {
	// 	for (int j = 0; j < G[i].size(); ++j)
	// 	{
	// 		dp[G[i][j].to][i] = G[i][j].cost;
	// 		dp[i][G[i][j].to] = G[i][j].cost;
	// 	}
	// }

	for (int k = 0; k < n ; ++k){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
 			}
 		}
	}


}



int main(){

}