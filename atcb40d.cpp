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
  static bool Asc(const Edge& x, const Edge& y){ return x.year > y.year; }
};

struct Question {
  int town_num, year, index;
  static bool Asc(const Question& x, const Question& y){ return x.year > y.year; }
};



int main(){
  int n, m, q;
  vector<Edge> edges;
  vector<Question> questions;
  int ans[QMAX];

  cin >> n >> m;
  for (int i = 0; i < m; ++i)
  {
    Edge edge;
    // cin >> edges[i].a >> edges[i].b >> edges[i].year;
    cin >> edge.a >> edge.b >> edge.year;
    edges.push_back(edge);
  }

  sort(edges.begin(), edges.end(), Edge::Asc);
    // [](const Edge &x, const Edge &y) -> bool { return x.year > y.year; } );

  cin >> q;
  for (int i = 0; i < q; ++i)
  {
    Question question;
    cin >> question.town_num >> question.year;
    question.index = i;
    questions.push_back(question);
  }

  sort(questions.begin(), questions.end(), Question::Asc);
    // [](const Question &x, const Question &y) -> bool { return x.year > y.year; } );


  DisjointSet ds = DisjointSet(n);

  int q_year, q_index;

  q_year = questions[0].year;
  q_index = 0;

  for (int i = 0; i < m; ++i)
  {
    if(edges[i].year > questions[q_index].year){
      ds.unite(edges[i].a - 1, edges[i].b - 1);
    }else{
      ans[questions[q_index].index] = ds.fetchCnt(questions[q_index].town_num - 1);
      q_index ++;
      i--;
      if(q_index == q){ break; }
    }
  }

  while(q_index != q){
    ans[questions[q_index].index] = ds.fetchCnt(questions[q_index].town_num - 1);
    q_index ++;
  }

  for (int i = 0; i < q; ++i)
  {
    cout << ans[i] << endl;
  }

  return 0;
}

