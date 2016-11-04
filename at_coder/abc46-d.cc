#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define ll long long


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
	string s;
	cin >> s;

	ll ans = 0;

	ll len = s.length();

	for (int i = 0; i < len; ++i)
	{
		if(s[i] == 'p'){
			ans--;
		}
	}

	cout << ans + len/2  << endl;
}
