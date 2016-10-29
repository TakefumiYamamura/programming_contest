#include <iostream>
#include <algorithm>
#define ll long long
#define INF 1LL << 60
using namespace std;

int N;
ll x;
int a[2010];
int b[2010];

int main(){
  cin >> N >> x;
  for (int i = 0; i < N; ++i)
  {
    cin >> a[i];
    b[i] = a[i];
  }

  ll ans = INF;

  for (int k = 0; k < N; ++k)
  {
    ll tmp = k * x;
    for (int i = 0; i < N; ++i)
    {
      b[i] = min(b[i], a[(i - k + N) % N]);
      tmp += b[i];
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
