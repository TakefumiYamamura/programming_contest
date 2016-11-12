#include <iosream>
using namespace std;

#define ll long long

class BigJump
{
public:
	ll n, d;
	double x, y;
	BigJump();
	~BigJump();
	void exec();
	
};

BigJump::BigJump(){
	cin >> n >> d;
	cin >> x >> y;

}

BigJump::~BigJump(){}

BigJump::exec(){}

int main(){
	BigJump bj = BigJump();
	bj.exec();
}
