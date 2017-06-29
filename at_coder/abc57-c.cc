#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class DigitsInMultiplication
{
private:
	long long n;
public:
	DigitsInMultiplication(){
		cin >> n;
	}

	int cout_digits(long long x){
		int digits = 0;
		while(x > 0){
			x /= 10;
			digits++;
		}
		return digits;
	}

	void exec(){
		int ans = 11;
		for (long long i = 1; i*i <= n; i++)
		{
			if(n % i == 0){
				ans = min(ans, max(cout_digits(i), cout_digits(n/i)));
			}
		}
		cout << ans << endl;
	}
};

int main(){
	DigitsInMultiplication dim = DigitsInMultiplication();
	dim.exec();
}