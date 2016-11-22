#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	int k = 2025 - n;

	for (int i = 1; i < 10; ++i)
	{
		if(k % i == 0 &&  k/i < 10){
			cout << i << " x " << k/i << endl;
		}
	}

}
