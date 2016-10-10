#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#define ll long long

using namespace std; 

int main(){
	int N, A, B;
	cin >> N >> A >> B;
	string s;
	cin >> s;
	int sum = 0;
	int sum_b = 0;
	for (int i = 0; i < N; ++i)
	 {
	 	if (s[i] == 'c')
	 	{
	 		cout << "No" << endl;
	 	}else if(s[i] == 'a' && sum < (A+B) ){
	 		cout << "Yes" << endl;
	 		sum++;
	 	}else if(s[i] == 'b' && sum < (A+B) && sum_b < B){
	 		cout << "Yes" << endl;
	 		sum++;
	 		sum_b++;
	 	}else{
	 		cout << "No" << endl;
	 	}
	 } 
}