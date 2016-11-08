#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	int x, y;
	cin >> n >> m;
	cin >> x >> y;
	// queue<int> a;
	// queue<int> b;
	vector<int> a;
	vector<int> b; 

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		a.push(tmp);
	}

	for (int i = 0; i < m; ++i)
	{
		int tmp;
		cin >> tmp;
		b.push(tmp);
	}

	int cur_time = 0;
	int count = 0;


	vector<int>::iterator a_index = a.begin();
	vector<int>::iterator b_index = b.begin();

	while(a_index !=  a.end() && b_index != b.end() ){
		if (count % 2 == 0){
			if(a.front() >= cur_time){
				cur_time = a.front() + x;
				count++;
			}
			a.pop();
			if(a.empty() && !b.empty() ){
				lower_bound(a.begin(), b.end(), cur_time)
				if(b.front() >= cur_time){
					cur_time = b.front() + y;
					count++;
				}
				b.pop();
			}
		}else{
			if(b.front() >= cur_time){
				cur_time = b.front() + y;
				count++;
			}
			b.pop();
			while(b.empty() && !a.empty() ){
				if(a.front() >= cur_time){
					cur_time = a.front() + x;
					count++;
				}
				a.pop();
			}
		}		

	}

	// while(!a.empty() && !b.empty()){
	// 	if (count % 2 == 0){
	// 		if(a.front() >= cur_time){
	// 			cur_time = a.front() + x;
	// 			count++;
	// 		}
	// 		a.pop();
	// 		while(a.empty() && !b.empty() ){
	// 			if(b.front() >= cur_time){
	// 				cur_time = b.front() + y;
	// 				count++;
	// 			}
	// 			b.pop();
	// 		}
	// 	}else{
	// 		if(b.front() >= cur_time){
	// 			cur_time = b.front() + y;
	// 			count++;
	// 		}
	// 		b.pop();
	// 		while(b.empty() && !a.empty() ){
	// 			if(a.front() >= cur_time){
	// 				cur_time = a.front() + x;
	// 				count++;
	// 			}
	// 			a.pop();
	// 		}
	// 	}
	// }
	cout << count / 2 << endl;
}
