#include <iostream>

using namespace std;

int gcd( int m, int n )
{
  if ( ( 0 == m ) || ( 0 == n ) )
    return 0;
  while( m != n )
  {
    if ( m > n ) m = m - n;
    else         n = n - m;
  }
  return m;
}

int lcm( int m, int n )
{
  if ( ( 0 == m ) || ( 0 == n ) )
    return 0;
  return ((m / gcd(m, n)) * n);
}

int solve(int a, int b, int c){
  int max, destination;
  destination = c;
  max = lcm(a+b, 60);
  while(max > destination){
    if ((destination % (a+b) ) <= a){
      return destination;
    }
    destination += 60;
  }
  return -1;
}

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  cout << solve(a, b, c) << endl;
}