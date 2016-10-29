#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
#define MAX_N 51
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


int main(){
	int t, n, m;
	queue<int> a;
	queue<int> b;
	
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		a.push(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int tmp;
		cin >> tmp;
		b.push(tmp);
	}

	while(!a.empty() && !b.empty()){
		if(a.front() <= b.front() && b.front() <= a.front() + t){
			a.pop();
			b.pop();
		}else{
			a.pop();
		}
	}

	if(b.empty()){
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}


}
