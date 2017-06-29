#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <climits>

using namespace std;

struct Edge{
	int a, b, c;
};

class CandidatesOfNoShortestPaths
{
private:
	int n, m;
	vector<vector<int> > adj;
public:
	CandidatesOfNoShortestPaths(){
		cin >> n >> m;
		adj = vector<vector<int> >(n, vector<int>(n, INT_MAX));
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;
			adj[a][b] = c;
			adj[b][a] = c;
		}
	}
	void exec(){}

};