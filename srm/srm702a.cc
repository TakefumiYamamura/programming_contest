#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

class TestTaking
{
public:
	int h, w;
	int findMax(int questions, int guessed, int actual){
		int guess_false = questions - guessed;
		int actual_false = questions - actual;
		int ans = 0;
		if(guessed > actual){
			ans += actual;
		}else{
			ans += guessed;
		}
		if(guess_false > actual_false){
			ans += actual_false;
		}else{
			ans += guess_false;
		}
		return ans;
	}
};