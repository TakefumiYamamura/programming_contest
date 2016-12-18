#include <iostream>
#include <vector>

using namespace std;

class PalindromeInstallments
{
public:
	string str;
	PalindromeInstallments(){
		cin >> str;
	}
	void exec();
};

void PalindromeInstallments::exec(){
	int bit = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if(bit >> (str[i] - 'a') & 1){
			bit = bit & ~(1 << (str[i] - 'a'));
		}else{
			bit |= 1 << (str[i] - 'a'); 
		}
	}
	int odd = 0;
	for (int i = 0; i <= 26; ++i)
	{
		if(bit >> i & 1){
			odd++;
		}
	}

	if(odd <= 1){
		cout << str.length() << endl;
		return;
	}
	cout << (str.length() - odd) / 2 / odd * 2 + 1 << endl;
}

int main(){
	PalindromeInstallments pi = PalindromeInstallments();
	pi.exec();
}
