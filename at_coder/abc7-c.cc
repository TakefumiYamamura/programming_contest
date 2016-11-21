#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Point
{
	int x, y;
};

class Bfs
{
public:
	int r, c;
	Point s, g;
	vector<vector<bool> > map;
	vector<vector<int> > cost;
	Bfs();
	~Bfs();
	void exec();
	
};


Bfs::Bfs(){
	cin >> r >> c;
	cin >> s.y >> s.x;
	cin >> g.y >> g.x;
	s.x--;
	s.y--;
	g.y--;
	g.x--;
	map.resize(r);
	cost.resize(r);
	for (int i = 0; i < r; ++i)
	{
		map[i].resize(c);
		cost[i].resize(c);
		string tmp;
		cin >> tmp;
		for (int j = 0; j < c; ++j)
		{
			if(tmp[j] == '#'){
				map[i][j] = false;
			}else{
				map[i][j] = true;
			}
			cost[i][j] = -1;
		}
	}
}

Bfs::~Bfs(){}

void Bfs::exec(){
	queue<Point> q;
	q.push(s);
	cost[s.y][s.x] = 0;
	while(!q.empty()){
		Point tmp = q.front();
		q.pop();
		// cout << "x, y " << tmp.x << " "<< tmp.y << endl; 
		// cout << cost[tmp.y][tmp.x] << endl;
		if(cost[g.y][g.x] != -1){
			cout << cost[g.y][g.x] << endl;
			return;
		}
		if(map[tmp.y+1][tmp.x] && cost[tmp.y+1][tmp.x] == -1){
			Point next = {tmp.x, tmp.y+1};
			q.push(next); 
			cost[tmp.y+1][tmp.x] = cost[tmp.y][tmp.x] + 1;
		}
		if(map[tmp.y][tmp.x+1] && cost[tmp.y][tmp.x+1] == -1){
			Point next = {tmp.x+1, tmp.y};
			q.push(next); 
			cost[tmp.y][tmp.x+1] = cost[tmp.y][tmp.x] + 1;
		}
		if(map[tmp.y-1][tmp.x] && cost[tmp.y-1][tmp.x] == -1){
			Point next = {tmp.x, tmp.y-1};
			q.push(next); 
			cost[tmp.y-1][tmp.x] = cost[tmp.y][tmp.x] + 1;
		}
		if(map[tmp.y][tmp.x-1] && cost[tmp.y][tmp.x-1] == -1){
			Point next = {tmp.x-1, tmp.y};
			q.push(next); 
			cost[tmp.y][tmp.x-1] = cost[tmp.y][tmp.x] + 1;
		}
	}
}


int main(){
	Bfs bfs = Bfs();
	bfs.exec();

}
