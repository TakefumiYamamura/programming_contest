#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	string words;
	cin >> words;
	int len = words.size();
	for (int i = 1; i < len; ++i)
	{
		if(words[i-1] == 'S' && words[i] == 'T'){
			words.erase(words.begin() + i);
			words.erase(words.begin() + i - 1);
			i -= 2;
			len -= 2;
		}
	}
	cout << words.size() << endl;
}
