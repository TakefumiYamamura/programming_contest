#include <iostream>
#include <vector>

using namespace std;

int digit_check(int n){
  int digit = 0;
  while(n!= 0){
    n = n/10;
    ++digit;
  }
  return digit;
}

bool archive_check(vector< int >& archive, int n){
  for (int i = 0; i < archive.size(); ++i)
  {
    if (archive[i] == n)
    {
      return true;
    }
  }
  return false;
}

int solve(int n){
  vector<int> ans;
  vector<int> archive;
  int digit, mul, upper, low, max;
  int count ;
  count = 0;
  while (true){
    digit = digit_check(n);
    // cout << n << endl;
    if (archive_check(archive, n)){
      return -1;
    }
    if (digit == 1 || digit == 0){
      return count;
    }
    for (int i = 1; i < digit; ++i)
    {
      mul = 1;
      for (int j = 0; j < i; ++j)
      {
        mul = mul*10;
      }
      upper = n / mul;
      low = n - mul * upper;
      ans.push_back(upper * low);
    }
    max = ans[0];
    for (int i = 0; i < digit-1; ++i)
    {
      if (max < ans[i])
      {
        max = ans[i];
      }
    }
    n = max;
    ans.clear();
    count ++;
  }

}

int main(){
  int q, n;
  cin >> q;
  for (int i = 0; i < q; ++i)
  {
    cin >> n;
    cout << solve(n) << endl;
  }
}