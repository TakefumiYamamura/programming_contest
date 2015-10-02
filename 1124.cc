#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, q, m, date, ans, max;
  while(true){
    cin >> n >> q;
    int N[100] = {0};
    if (n == 0 && q ==0){
      break;
    }
    for (int i = 0; i < n; ++i)
    {
      cin >> m;
      for (int j = 0; j < m; ++j)
      {
        cin >> date;
        N[date-1] += 1;
      }
    }
    max = 0;
    ans = 0;
    for (int i = 99; i >= 0 ; --i)
    {
      if (N[i] >= max && N[i] >= q){
        max = N[i];
        ans = i+1;
      }
    }
    cout << ans << endl;
  }
}