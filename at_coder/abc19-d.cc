#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class TakahashiTreeDiameter{
public:
	int n;
	TakahashiTreeDiameter();
	void dijkestra();
	void exec();
};

TakahashiTreeDiameter::TakahashiTreeDiameter(){
	cin >> n;
}

void TakahashiTreeDiameter::exec(){
	int max_v = 0;
	int max_i = 0;
	for (int i = 2; i <= n; ++i)
	{
		int dist;
		cout << "? " << 1 << " " << i << endl;
        cin >> dist;
        if(dist > max_v){
        	max_v = dist;
        	max_i = i;
        }
	}
	for (int i = 2; i <= n; ++i)
	{
		if(max_i == i) continue;
		int dist;
		cout << "? " << max_i << " " << i << endl;
        cin >> dist;
        max_v = max(dist, max_v);
	}
	cout << "! " << max_v << endl;
}

int main(){
	TakahashiTreeDiameter ttd = TakahashiTreeDiameter();
	ttd.exec();
}

