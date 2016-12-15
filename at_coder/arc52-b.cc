#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Figure
{
	int x;
	int r;
	int h;
};

struct Query
{
	int a;
	int b;
};


class Corn
{
public:
	int n, q;
	vector<Figure> figures;
	vector<Query> queries;
	long double ans[200001];
	
	Corn(){
		cin >> n >> q;
		for (int i = 0; i < n; ++i)
		{
			Figure tmp_f;
			cin >> tmp_f.x >> tmp_f.r >> tmp_f.h;
			figures.push_back(tmp_f);
		}
		for (int i = 0; i < q; ++i)
		{
			Query tmp_q;
			cin >> tmp_q.a >> tmp_q.b;
			queries.push_back(tmp_q);
		}
	}

	long double calcV(long double r, long double h){
		return r*r*h*M_PI/3.0;
	}

	void setCalc(){
		for (int j = 0; j <= 200000; ++j)
		{
			ans[j] = 0;
			for (int i = 0; i < n; ++i)
			{
				long double x = figures[i].x;
				long double r = figures[i].r;
				long double h = figures[i].h;
				if(figures[i].x + figures[i].h <= j){
					ans[j] += calcV(r, h);
				}else if(figures[i].x + figures[i].h > j && figures[i].x < j){
					ans[j] += calcV(r, h) - calcV(r*(x+h-j)/h, x+h-j); 
				}
			}
		}
	}

	void exec(){
		setCalc();
		for (int i = 0; i < q; ++i)
		{
			printf("%.16Lf\n", ans[queries[i].b] - ans[queries[i].a]);
		}
	}
};

int main(){
	Corn c = Corn();
	c.exec();
}
