#include <iostream>

using namespace std;


bool primes[246913];
int max_num = 246912;
void set_primes(){
  primes[0] = false;
  primes[1] = false;
  int top_prime, count;
  top_prime = 2;
  for (int i = 2; i < max_num+1; ++i)
  {
    primes[i] = true;
  }
  while(true){
    count = top_prime;
    count += top_prime;
    for (int i = 0; count < max_num+1; ++i)
    {
      primes[count] = false;
      count += top_prime;
    }
    for (int i = top_prime+1; i < max_num+1; ++i)
    {
      if (primes[i])
      {
        top_prime = i;
        break;
      }
    }
    if (top_prime * 2 > max_num){
      break;
    }
  }
}

int primes_count(int n){
  int count;
  count = 0;
  for (int i = n+1; i <= 2*n; ++i)
  {
    if (primes[i]){
      count ++;
    }
  }
  return count;
}

int main(){
  int n;
  set_primes();
  while(cin >> n, n){
    cout << primes_count(n) << endl;
  }
  return 0;
}