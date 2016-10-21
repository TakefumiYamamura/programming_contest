#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100;

static const int INF = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];


int height, width;

int dp[1401][1401];
int tiles[1401][1401];


int compute() {
  int maxW = 0;
  for (int h = 0; h < height; ++h)
  {
    dp[h][0] = (tiles[h][0] + 1) % 2;
    maxW = max(dp[h][0], maxW);
  }

  for (int w = 0; w < width; ++w)
  {
    dp[0][w] = (tiles[0][w] + 1) % 2;
    maxW = max(dp[0][w], maxW);
  }

  for (int h = 1; h < height; ++h)
  {
    for (int w = 1; w < width; ++w)
    {
      if (tiles[h][w] == 0 && (h == 0 || w == 0) ){
        dp[h][w] = 1;
        continue;
      }
      if (tiles[h][w] == 1 ){
        dp[h][w] = 0;
      }else{
        dp[h][w] = min(dp[h][w-1], min(dp[h-1][w], dp[h-1][w-1])) + 1;
        maxW = max(dp[h][w], maxW);
      }
    }
  }

  return maxW * maxW;
}



int main(){
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      int e; cin >> e;
      M[i][j] = (e == -1) ? INF : e;
    }
  }


  cout << compute() << endl;
}
