#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#define QMAX 100001
#define MMAX 200001

using namespace std;

class DisjointSet {
  private:
    vector<int> rank, p, cnt;

  public:
    DisjointSet(int node_size){
      rank.resize(node_size, 0);
      p.resize(node_size, 0);
      cnt.resize(node_size, 0);
      for (int i = 0; i < node_size; ++i)
      {
        makeSet(i);
      }
    }

    void makeSet(int x){
      p[x] = x;
      rank[x] = 0;
      cnt[x] = 1;
    }

    void unite(int x, int y){
      link(findSet(x), findSet(y));
    }

    void link(int x, int y){
      if (!same(x, y))
      {
        int sum = cnt[x] + cnt[y];
        cnt[x] = sum;
        cnt[y] = sum;
      }

      if (rank[x] > rank[y])
      {
        p[y] = x;
        int sum;
      }else{
        p[x] = y;
        if (rank[x] == rank[y])
        {
          rank[y]++;
        }
      }
    }

    bool same(int x, int y){
      return findSet(x) == findSet(y);
    }

    int findSet(int x){
      if(p[x] != x){
        p[x] = findSet(p[x]);
      }
      return p[x];
    }

    int fetchCnt(int x){
      return cnt[findSet(x)];
    }
};

struct Edge {
  int a, b, year;
};

struct Question {
  int town_num, year, index;
};



int main(){
  int n, m, q;
  Edge edges[NMAX];
  Question questions[QMAX];

  int ans[QMAX];

  cin >> n >> m;
  vector<pair<int, int> > year(m);

  for (int i = 0; i < m; ++i)
  {
    cin >> Edges[i].a >> Edges[i].b >> year[i].first;
    year[i].second = i;
  }
  sort(year.begin(), year.end(), greater<pair<int,int> >());

  cin >> q;
  vector<pair<int, int> > ques(q); // v w
  for (int i = 0; i < q; ++i)
  {
    ques[i].second = i;
    cin >> v[i] >> ques[i].first;
  }


  sort(ques.begin(), ques.end(), greater<pair<int,int> >());
  //ques first is year second is index
  //v[] is 街の番号
  DisjointSet ds = DisjointSet(n);

  w = ques[0].first;
  int i = 0;
  while(q){
    for (int j = 0; j < m ; ++j)
    {
      if(year[j].first > w){
        int index;
        index = year[j].second ;
        ds.unite(Edges[index].a, Edges[index].b);
      }else{
        ans[ques[i].second] = ds.fetchCnt(v[ques[i].second]-1)
        cout << ds.fetchCnt(v[ques[i].second]-1) << endl;
        j--;
        i++;
        w = ques[i].first;
      }
    }
  }


  for (int i = 0; i < q; ++i)
  {
    cout << ans[i] << endl;
  }

  return 0;
}

