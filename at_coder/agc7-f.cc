#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define MAX_N 1000001
#define ll long long
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int main(){
	int n;
	string s, t;
	cin >> n;
	cin >> s;
	cin >> t;

	char dif = '0';
	int count = 0;
	bool flag = true;
	for (int i = 1; i < n; ++i)
	{
		if(s[i] != t[i]){
			if(dif != t[i]){
				dif = t[i];
				count++;
				if(s[i-1] != t[i]) flag = false;

			}else{
				// cout << s[i-1] << " ";
				// if(s[i-1] != t[i]) flag = false; 
			}
			// flag = true;
		}else{
			// flag = false;
		}
	}
	if(!flag){
		cout << -1 << endl;
		return 0 ;
	}
	cout << count << endl;
}
