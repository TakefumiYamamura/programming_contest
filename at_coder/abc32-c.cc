#include <iostream>
#include <algorithm> 

#define ulli unsigned long long int
using namespace std;

ulli N;
ulli K;
ulli s[100001];

int main(){
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		cin >> s[i];
		if (s[i] == 0){
			cout << N << endl;
		    return 0;
		} 
	}

	int first, last;
	first = 0;
	last = -1;
	ulli mul = 1;
	int ans = 0;

	for (int last = 0; last < N; ++last)
	{
		mul *= s[last];
		while(mul > K && first <= last){
			mul /= s[first];
			first++;
		}
		ans = max(ans, last - first + 1);

	}


	cout << ans << endl;
	return 0;

}