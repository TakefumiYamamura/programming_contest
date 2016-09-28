#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n, m, a, b;
  vector<int> A, B;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
  {
    cin >> a;
    A.push_back(a);
  }
  for (int i = 0; i < m; ++i)
  {
    cin >> b;
    B.push_back(b);
  }

  if(n < m){
    cout << "NO" << endl;
    return 0;
  }


  sort(A.begin(), A.end(), greater<int>() );
  sort(B.begin(), B.end(), greater<int>() );

  for (int i = 0; i < m; ++i)
  {
    if(B[i] > A[i]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
