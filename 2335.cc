#include <iostream>

using namespace std;


int con(int a, int b){
  int ans, under;
  ans = 1;
  under = 1;
  for (int i = 0; i < b ; ++i)
  {
    ans *= (a - i);
    under *= (b - i);
  }
  return ans/under;
}



int main(){
  int n, m, k, ans;
  cin >> n >> m >> k;
  ans = 0;
  ans = con(n+m+2*k, n) + con(m+2*k, m);
  for (int i = 0; i < k; ++i)
  {
    ans = ans*2;
  }
  cout << ans % 1000000007 << endl;
}