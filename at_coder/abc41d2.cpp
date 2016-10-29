#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <bitset>

using namespace std;

int node_num, edge_num;
int dp[1<<16];
bool edges[16][16];

int f(int n){
  // cout << dp[n] << endl;
  if(dp[n] != -1) return dp[n];
  for (int i = 0; i < node_num; ++i)
  {
    // cout << (n >> i) << endl;
    if((n >> i) & 1){
      // cout << "test" << endl;
      bool flag = true;
      for (int j = 0; j < node_num; ++j)
      {
        if(edges[i][j]) flag = false;
      }
      if(flag) dp[n] += dp[n-(1 << i)];
    }
  }
  return dp[n];
}


int main(){

  cin >> node_num >> edge_num;
  for (int i = 0; i < edge_num; ++i)
  {
    int a, b;
    cin >> a >> b;
    edges[a-1][b-1] = true;
  }

  for (int i = 0; i < (1<<16); ++i)
  {
    dp[i] = -1;
  }

  for (int i = 1; i < node_num; ++i)
  {
    dp[(1 << node_num) - 1] = 1;
  }

  cout << f((1 << node_num) - 1) << endl;
  return 0;
}