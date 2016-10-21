#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;
static const int MAX = 100000;
static const int INFTY = (1<<29);

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;
int indeg[MAX]; //入次数　頂点には入ってくる辺の数



void tsort() {

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < G[i].size(); ++j)
    {
      int v = G[i][j];
      cout << G[i].size() << endl;
      indeg[v]++;
    }
  }

}

int main(){
  int s, t, M;

  cin >> N >> M;

  for (int i = 0; i < N; ++i)
  {
    V[i] = false;
  }

  for (int i = 0; i < M; ++i)
  {
    // cin >> s >> t;
    G[0].push_back(2);
  }

  tsort();

  return 0;
}

