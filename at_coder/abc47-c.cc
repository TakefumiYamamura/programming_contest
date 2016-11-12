#include <iostream>
#include <string>

using namespace std;

class oneDimensionReverse
{
private:
	string s;
	int ans;
public:
	oneDimensionReverse(){
		cin >> s;
	}
	void execute();
};

void oneDimensionReverse::execute(){
	char start = s[0];
	this->ans = 0;
	for (int i = 0; i < this->s.length(); ++i)
	{
		if(start != s[i]){
			ans++;
			start = s[i];
		}
	}
	cout << ans << endl;
}

int main(){
	oneDimensionReverse oDR = oneDimensionReverse();
	oDR.execute();
}
