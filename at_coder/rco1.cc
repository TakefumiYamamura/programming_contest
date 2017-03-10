#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream> 
#include <sstream> 
#include <queue>


using namespace std;

struct node
{
	int x;
	int y;
	int val;
	int depth;
	vector<pair<int, int> > answers;
	vector<vector<int> > visited;
	bool operator<(const node &n)const{
	return val < n.val;
	}
};


struct point
{
	int x;
	int y;
	int val;
	bool operator<(const point &p)const{
	return val < p.val;
	}
};


class MultiplePieces
{
private:
	int h, w, k;
	vector<vector<int> > grid;
	vector<vector<int> > visited;
	int c;
	vector<vector<pair<int, int> >  > answers;
	priority_queue<point> points;
public:
	MultiplePieces(){
		cin >> h >> w >> k;
		c = 0;
		grid.resize(h);
		visited.resize(h);
		for (int i = 0; i < h; ++i)
		{
			grid[i].resize(w);
			visited[i].resize(w);
			string tmp;
			cin >> tmp;
			for (int j = 0; j < w; ++j)
			{
				visited[i][j] = 0;
				grid[i][j] = tmp[j] - '0';
				if(tmp[j] == '0'){
					visited[i][j] = 1;
				}
				point tmp = {i, j, grid[i][j]};
				points.push(tmp);
			}
		}
	}
	void dfs(int x, int y){
		priority_queue<node> q;
		vector<pair<int, int> >  tmp_ans;
		tmp_ans.push_back(pair<int, int>(x, y) );
		vector<vector<int> > tmp_visited = visited;
		tmp_visited[x][y] = 1;
		node start = {x, y, grid[x][y], 1, tmp_ans, tmp_visited};
		q.push(start);
		while(!q.empty()){
			node cur = q.top();
			q.pop();
			// cout << cur.depth << " " << cur.x + 1<<" "<< cur.y + 1<<endl;
			if(cur.depth == k){
				c++;
				// cout << cur.depth << endl;
				answers.push_back(cur.answers);
				visited = cur.visited;
				return;
			}
			if(0 <= cur.x - 1 && cur.visited[cur.x-1][cur.y] == 0){
				vector<pair<int, int> >  tmp_next_ans = cur.answers;
				tmp_next_ans.push_back(pair<int, int>(cur.x - 1, cur.y) );
				vector<vector<int> > next_visited = cur.visited;
				next_visited[cur.x-1][cur.y] = 1;
				node next = {cur.x - 1, cur.y, cur.val * grid[cur.x - 1][cur.y], cur.depth + 1, tmp_next_ans, next_visited};
				q.push(next);
			}
			if(0 <= cur.y - 1 && cur.visited[cur.x][cur.y-1] == 0){
				vector<pair<int, int> >  tmp_next_ans = cur.answers;
				tmp_next_ans.push_back(pair<int, int>(cur.x, cur.y - 1) );
				vector<vector<int> > next_visited = cur.visited;
				next_visited[cur.x][cur.y - 1] = 1;
				node next = {cur.x, cur.y - 1, cur.val * grid[cur.x ][cur.y - 1], cur.depth + 1, tmp_next_ans, next_visited};
				q.push(next);
			}
			if(h > cur.x + 1 && cur.visited[cur.x+1][cur.y] == 0){
				vector<pair<int, int> >  tmp_next_ans = cur.answers;
				tmp_next_ans.push_back(pair<int, int>(cur.x + 1, cur.y) );
				vector<vector<int> > next_visited = cur.visited;
				next_visited[cur.x + 1][cur.y] = 1;
				node next = {cur.x + 1, cur.y, cur.val * grid[cur.x + 1][cur.y], cur.depth + 1, tmp_next_ans, next_visited};
				q.push(next);
			}
			if(w > cur.y + 1 && cur.visited[cur.x][cur.y+1] == 0){
				vector<pair<int, int> >  tmp_next_ans = cur.answers;
				tmp_next_ans.push_back(pair<int, int>(cur.x, cur.y + 1) );
				vector<vector<int> > next_visited = cur.visited;
				next_visited[cur.x][cur.y + 1] = 1;
				node next = {cur.x, cur.y + 1, cur.val * grid[cur.x ][cur.y + 1], cur.depth + 1, tmp_next_ans, next_visited};
				q.push(next);
			}
		}
	}



	void exec(){
		// for (int i = 0; i < h; ++i)
		// {
		// 	for (int j = 0; j < w; ++j)
		// 	{
		// 		if(visited[i][j] == 0){
		// 			dfs(i, j);
		// 		}
		// 	}
		// }
		while(!points.empty()){
			point cur = points.top();
			points.pop();
			if(visited[cur.x][cur.y] == 0){
				dfs(cur.x, cur.y);
			}
		}
	// 	string filename = "rco1.txt";
	// ofstream writing_file;
 //    writing_file.open(filename, std::ios::out);


 //        writing_file << c << endl;
		cout << c << endl;
		for (int i = 0; i < c; ++i)
		{
			for (int j = 0; j < answers[i].size(); ++j)
			{
				// writing_file << answers[i][j].first + 1 << " " << answers[i][j].second  + 1 << endl;
				cout << answers[i][j].first + 1 << " " << answers[i][j].second  + 1<< endl;
			}
			// cout << answers[i].size();
		}
	}
};

int main(){
	MultiplePieces problem = MultiplePieces();
	problem.exec();
	// string filename = "rco1.txt";
	// ofstream writing_file;
 //    writing_file.open(filename, std::ios::out);
	// int testCase;
	// cin >> testCase;
	// for (int i = 0; i < testCase; ++i)
	// {
	// 	MultiplePieces problem = MultiplePieces();
	// 	writing_file << "Case #" << i+1 << ": " << problem.exec() << endl;
	// }
}
