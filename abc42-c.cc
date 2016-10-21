#include <iostream>
#define ll long long
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int d[10];
	for (int i = 0; i < k; ++i)
	{
		cin >> d[i];
	}
	while(true){
		int tmp;
		tmp = n;
		bool flag = true;
		while(tmp != 0){
			int num;
			num = tmp % 10;
			tmp -= num;
			tmp /= 10;
			for (int i = 0; i < k; ++i)
			{
				if(d[i] == num){
					flag = false;
				}		
			}
		}
		if(flag){
			cout << n << endl;
			return 0;
		}
		n++;
	}


}
