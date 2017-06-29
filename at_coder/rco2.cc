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
	string movement;
	vector<vector<int> > visited;
	bool operator<(const node &n)const{
	return val < n.val;
	}
};

struct point
{
	int x;
	int y;
	int depth;
	string str;
};

struct food{
	int x;
	int y;
	int val;
	int dec;
	bool operator<(const food &f)const{
	return val < f.val;
	}
};

class FoodCollector
{
private:
	int h, w, k, sx, sy;
	int n;
	int cur_time;
	string ans_str;
	vector<vector<int> > g;
	// vector<food> foods;
	map<pair<int, int>, food> hash;
public:
	FoodCollector(){
		cin >> h >> w >> k >> sx >> sy;
		g.resize(h);
		cur_time = 0;
		sx--;
		sy--;
		ans_str = "";
		for (int i = 0; i < h; ++i)
		{
			string tmp;
			cin >> tmp;
			g[i].resize(w);
			for (int j = 0; j < w; ++j)
			{
				if(tmp[j] == '#'){
					g[i][j] = 0;
				}else{
					g[i][j] = 1;
				}
			}
		}
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			food tmp_f;
			cin >> tmp_f.x >> tmp_f.y >> tmp_f.val >> tmp_f.dec;
			tmp_f.x--;
			tmp_f.y--;
			hash[pair<int, int>(tmp_f.x, tmp_f.y)] = tmp_f;
			// foods.push_back(tmp_f);
		}
	}

	bool bfs(int x, int y){
		cur_time = ans_str.length();
		vector<vector<int> > visited = g;
		queue<point> q;
		point start = {x, y, 0, ""};
		q.push(start);
		priority_queue<food> p;
		int max_v = -1;
		int max_depth = 0;
		string tmp_ans_str;
		while(!q.empty()){
			point cur = q.front();
			q.pop();
			// cout << cur.x << " " << cur.y << " " << cur.depth + cur_time << " "<< k <<endl; 
			if(cur.depth + cur_time >= k){
				// cout << "nee"<< endl;
				continue;
			}
			if(hash.find(pair<int, int>(cur.x, cur.y)) != hash.end()){
				// cout << "test" << endl;
				food cur_food = hash[pair<int, int>(cur.x, cur.y)];
				cur_food.val = cur_food.val - (cur.depth) * cur_food.dec;
				if(cur_food.val <= 0) continue;
				if(cur_food.val > max_v){
					tmp_ans_str = cur.str;
					max_v = cur_food.val;
					max_depth = cur.depth;
				}
				p.push(cur_food);				
			}
			if(0 <= cur.x-1 && visited[cur.x-1][cur.y] == 0){
				visited[cur.x-1][cur.y] = 1;
				point next = {cur.x-1, cur.y, cur.depth + 1, cur.str + "U"};
				q.push(next);
			}
			if(cur.x+1 < h && visited[cur.x+1][cur.y] == 0){
				visited[cur.x+1][cur.y] = 1;
				point next = {cur.x+1, cur.y, cur.depth + 1, cur.str + "D"};
				q.push(next);
				
			}
			if(cur.y+1 < w && visited[cur.x][cur.y+1] == 0){
				visited[cur.x][cur.y+1] = 1;
				point next = {cur.x, cur.y+1, cur.depth + 1, cur.str + "R"};
				q.push(next);
				
			}
			if(0 <= cur.y -1 && visited[cur.x][cur.y-1] == 0){
				visited[cur.x][cur.y-1] = 1;
				point next = {cur.x, cur.y-1, cur.depth + 1, cur.str + "L"};
				q.push(next);
			}
		}

		if(q.empty()){
			return false;
		}else{
			food new_food = p.top();
			sx = new_food.x;
			sy = new_food.y;
			cur_time += max_depth;
			ans_str += tmp_ans_str;
			map<pair<int, int>, food> new_hash;
			while(!p.empty()){
				food tmp_f = p.top();
				p.pop();
			    new_hash[pair<int, int>(tmp_f.x, tmp_f.y)] = tmp_f;
			}
			hash = new_hash;
			return true;
		}
	}


	void exec(){
		while(true){
			bool flag = bfs(sx, sy);
			if(!flag) break;
		}
		while(ans_str.length() != k){
			ans_str += "-";
		}
		cout << ans_str << endl;
	}
};

int main(){
	FoodCollector fc = FoodCollector();
	fc.exec();
}