#include <iostream>
#include <vector>
#define ll long long
#define NMAX 21
using namespace std;

const ll INF = 1LL<<60;


struct Worker{
	ll salary;
	int manager;
};


class MrTakahashiSalary
{
public:
	int n;
	vector<Worker> workers;
	vector<int> graph[NMAX]; 


	MrTakahashiSalary();
	~MrTakahashiSalary();
	void exec();
	ll dfs(int index);
	
};

MrTakahashiSalary::MrTakahashiSalary(){
	cin >> n;
	Worker takahashi = {-1, -1};
	workers.push_back(takahashi);
	for (int i = 1; i < n; ++i)
	{
		Worker w;
		cin >> w.manager;
		w.manager--;
		w.salary = -1;
		graph[w.manager].push_back(i);
		workers.push_back(w);
	}
}

MrTakahashiSalary::~MrTakahashiSalary(){}

void MrTakahashiSalary::exec(){
	cout << dfs(0) << endl;
}

ll MrTakahashiSalary::dfs(int index){
	if(workers[index].salary != -1) return workers[index].salary;
	if(graph[index].size() == 0) return 1;
	ll min_salary = INF;
	ll max_salary = 0;
	for (int i = 0; i < graph[index].size(); ++i)
	{
		min_salary = min(dfs(graph[index][i]), min_salary);
		max_salary = max(dfs(graph[index][i]), max_salary);
	}
	workers[index].salary = min_salary + max_salary + 1;
	return workers[index].salary;
}

int main(){
	MrTakahashiSalary mts = MrTakahashiSalary();
	mts.exec();
}
