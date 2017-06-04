#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;

#define ll long long

class Solver
{
private:
	int n, m;
	vector<vector<int> > adj;

public:
	Solver(){
		cin >> n >> m;
		adj = vector<vector<int> >(n, vector<int>(n, 0) ); 
		for (int i = 0; i < m; ++i)
		{
			int tmp_a;
			int tmp_b;
			cin >> tmp_a >> tmp_b;
			tmp_a--;
			tmp_b--;
			adj[tmp_a][tmp_b] = 1;
			adj[tmp_b][tmp_a] = 1;
		}
	}
	
	void exec(){
		// for (int i = 0; i < n; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout << adj[i][j] << " "; 
		// 	}
		// 	cout << endl;
		// }

	}
};

int main(){
	Solver solution = Solver();
	solution.exec();
}
