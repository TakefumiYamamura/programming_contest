#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>
#include <queue>
#include <unordered_set>

#define MAX_M 100000 * 51

using namespace std;


struct Node
{
	int id;
	vector<int> mts;
	Node(int _id, vector<int> _mts) : id(_id), mts(_mts){} 
};

class Solver
{
private:
	int n;
	vector<int> w;
	// vector<vector<int> > dp;
public:
	Solver(){
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			w.push_back(tmp);
		}
		// dp = vector<vector<int> >(n+1, vector<int>(n+1, 0));
	}
	void exec(){
		queue<Node> q;
		vector<int> tmp;
		tmp.push_back(w[0]);
		Node start = Node(0, tmp);
		q.push(start);
		int ans = n;
		while(!q.empty()){
			Node cur = q.front();
			q.pop();
			if(cur.id == n-1){
				int tmp_size = cur.mts.size();
				ans = min(tmp_size, ans);
				// for (int i = 0; i < tmp_size; ++i)
				// {
				// 	cout << cur.mts[i] << " ";
				// }
				// cout << endl;
				continue;
			}
			bool check_flag = false;
			int min_num = MAX_M;
			int min_index = 0;
			for (int i = 0; i < cur.mts.size(); ++i)
			{
				if(cur.mts[i] <= min_num && w[cur.id + 1] <= cur.mts[i]){
					check_flag = true;
					min_index = i;
					min_num = cur.mts[i];
				}
			}
			if(check_flag){
				vector<int> new_mts = cur.mts;
				new_mts[min_index] = w[cur.id+1];
				Node newNode  = Node(cur.id+1, new_mts);
				q.push(newNode);
			}else{
				vector<int> add_mts = cur.mts;
				add_mts.push_back(w[cur.id+1]);
				Node addNode = Node(cur.id+1, add_mts);
				q.push(addNode);
			}
		}
		cout << ans << endl;
	}

};

int main(){
	Solver s = Solver();
	s.exec();
}