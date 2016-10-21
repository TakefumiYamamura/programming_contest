;#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
	public:
		vector<int> rank, p;

    DisjointSet(){}
    DisjointSet(int size){
      rank.resize(size, 0);
      p.resize(size, 0);
      for (int i = 0; i < size; ++i)
      {
        makeSet(i);
      }
    }

    void makeSet(int x){
      p[x] = x;
      rank[x] = 0;
    }

    void unite(int x, int y){
      link(findSet(x), findSet(y));
    }

    void link(int x, int y){
      if (rank[x] > rank[y])
      {
        p[y] = x;
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
};

int main(){
  int n, q;
  int com, x, y;
  cin >> n >> q;
  DisjointSet ds = DisjointSet(n);

  for (int i = 0; i < q; ++i)
  {
    cin >> com >> x >> y;
    if(com == 0){
      ds.unite(x, y);
    } else if( com == 1){
      if(ds.same(x, y)){
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }

}

