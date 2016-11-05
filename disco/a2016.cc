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
	double a, b, c;
	cin >> a >> b >> c;

	printf("%.7f\n", c * b / a );

// 
	// cout << c * b / a << endl;
}
