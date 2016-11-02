#include <iostream>
#include <vector>

using namespace std;

class Solver {
	private:
		int n, g, e;
		int ans;
		vector<int> graph[101];
		int mark[101];
		Solver(){
			cin >> n >> g >> e;
			for (int i = 0; i < g; ++i)
			{
				cin >> mark[i];
			}
			for (int i = 0; i < e; ++i)
			{
				int a, b;
				cin >> a >> b;
				graph[a].push_back(b);
				graph[b].push_back(a);
			}
		}
		void Solver::exec(){

		}
		void Solver::out_put(){
			cout << ans << endl;
		}
};


int main(){
	int n, g, e;
	cin >> n >> g >> e;

	Solver solver = Solver();
	solver.exec();
	solver.out_put();
}