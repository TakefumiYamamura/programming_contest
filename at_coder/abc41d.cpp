#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <bitset>

using namespace std;

int node_num, edge_num;
int dp[1<<16];
// struct Edge
// {
//   int from_node, to_node;
// };
// vector<Edge> edges;
bool edges[16][16];


int main(){
  cin >> node_num >> edge_num;
  for (int i = 0; i < edge_num; ++i)
  {
    // Edge edge;
    // cin >> edge.from_node >> edge.to_node;
    // edges.push_back(edge);
    int a, b;
    cin >> a >> b;
    edges[a][b] = true;
  }

  for (int i = 0; i < (1<<n); ++i)
  {
    dp[i]
  }



  cout << dp[(1<<n)-1] << endl;
 


  bitset<node_num> bit 

  return 0
}