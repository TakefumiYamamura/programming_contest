#include <iostream>
#include <string>

using namespace std;

void rec(int n, string s){
	string abc = "abc";
	if(n == 1){
		for (int i = 0; i < 3; ++i)
		{
			cout << s + abc[i] << endl;
		}
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		rec(n-1, s + abc[i]); 
	}

}

int main(){
	int n;
	cin >> n;
	rec(n, "");
}