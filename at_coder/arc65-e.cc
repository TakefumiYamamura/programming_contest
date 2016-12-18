#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point{
	int x, y;
};

struct Node{
	int first;
	int second;
};

class ManhattanCompass
{
public:
	int n, a, b;
	vector<Point> points;

	ManhattanCompass();
	~ManhattanCompass();
	int calcDis(Point p1, Point p2);
	int bfs();
	void exec();
};


ManhattanCompass::ManhattanCompass(){
	cin >> n >> a >> b;
	a--; b--;
	for (int i = 0; i < n; ++i)
	{
		Point tmp;
		cin >> tmp.x >> tmp.y;
		points.push_back(tmp);
	}
}

ManhattanCompass::~ManhattanCompass(){}

int ManhattanCompass::calcDis(Point p1, Point p2){
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int ManhattanCompass::bfs(){
	queue<Node> q;
	vector<int> check1;
	vector<int> check2;
	for (int i = 0; i < n; ++i)
	{
		check1.push_back(0);
	}
	for (int i = 0; i < n; ++i)
	{
		check2.push_back(0);
	}
	vector<int> g[100001];
	for (int i = 0; i < n; ++i)
	{
		g[points[i].x].push_back(points[i].y);
	}
	if(a>b) swap(a,b);
	check1[a] = 1;
	check2[b] = 1;
	Node q1 = {a, b};
	q.push(q1);
	int ans = 1;
	while(!q.empty()){
		Node cur = q.front();
		q.pop();
		int dis = calcDis(points[cur.first], points[cur.second]);
		for (int i = 0; i < n; ++i)
		{
			int tmp1 = cur.first;
			int tmp2 = i;
			if(tmp1 == tmp2) continue;
			if(tmp1 > tmp2) swap(tmp1, tmp2);
			if(dis == calcDis(points[tmp1], points[tmp2]) && (check1[tmp1] == 0 || check2[tmp2] == 0) ){
				check1[tmp1] = 1;
				check2[tmp2] = 1;
				ans++;
				// cout << tmp1 << " " << tmp2;
				Node tmp = {tmp1, tmp2};
				q.push(tmp);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			int tmp1 = cur.second;
			int tmp2 = i;
			if(tmp1 == tmp2) continue;
			if(tmp1 > tmp2) swap(tmp1, tmp2);
			if(dis == calcDis(points[tmp1], points[tmp2]) && (check1[tmp1] == 0 || check2[tmp2] == 0) ){
				check1[tmp1] = 1;
				check2[tmp2] = 1;
				ans++;
				// cout << tmp1 << " " << tmp2;
				Node tmp = {tmp1, tmp2};
				q.push(tmp);
			}
		}
	}
	return ans;
}

void ManhattanCompass::exec(){
	cout << bfs() << endl;

}

int main(){
	ManhattanCompass mc = ManhattanCompass();
	mc.exec();
}
