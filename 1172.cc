#include <iostream>

using namespace std;

bool prime_check(int n){
  prime_count = 0;
  for (int i = 2; i < n; ++i)
  {
    if (n%i == 0){
      prime_count ++;
      if (prime_count > 1)
      {
        return false;
      }
    }
  }
  if (prime_count == 1){
    return true;
  }
}


int main(){
  int n;
  while(cin >> n, n){
    count = 0;
    for (int i =  n+1; i <= 2*n ; ++i)
    {
      if (prime_check(i)){
        count++ ;
      }
    }
    cout << count << endl;
  }
}