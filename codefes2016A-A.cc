#include <iostream>
#include <string>
using namespace std;

int main(){
	string words;
	cin >> words;
	for (int i = 0; i < 12; ++i)
	{
		cout << words[i];
		if (i == 3)
		{
			cout << " "; 
		}
	}
	cout << endl;
}