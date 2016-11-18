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
	int h, w;
	// string a[9][9];
	cin >> h >> w;
	int count = 0;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			char s;
			cin >> s;
			if(s == '#') count++;
		}
	}

	if(count == h + w - 1){
		cout << "Possible" << endl;
	} else {
		cout << "Impossible" << endl;
	}


}
