#include <iostream>
#include <vector>

using namespace std;

class GoHome
{
private:
	int x;
public:
	GoHome(){
		cin >> x;
	}

	void exec(){
		int ans = 1;
		int sum = 0;
		while(sum < x){
			sum += ans;
			ans++;
		}
		cout << ans - 1 << endl;
	}
};

int main(){
	GoHome gh = GoHome();
	gh.exec();

}