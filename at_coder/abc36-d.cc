#include <iostream>
#include <vector>
#define NUL -1
using namespace std;

struct Node{
	int p;
	int l;
	int r;
};

class RootedTree{
    public:
	vector<Node> nodes;
	vector<long long> f;
	vector<long long> g;
	RootedTree(int n){
		for (int i = 0; i < n; ++i)
		{
			Node n = {-1, -1, -1};
		    nodes.push_back(n);
		}
	}

	void make_bridge(int a, int b){
		if(nodes[a].l != NUL){
			nodes[find_child(nodes[a].l)].r = b;
		}else{
			nodes[a].l = b;
		}
		nodes[b].p = a;
	}


	int find_child(int c){
		if(nodes[c].r != NUL){
			find_child(nodes[c].r);
		}else{
			return c;
		}
	}

};


int main(){
	int N;
	cin >> N;
	RootedTree rt = RootedTree(N);

	for (int i = 0; i < N-1; ++i)
	{
		int a, b;
		cin >> a >> b;
		rt.make_bridge(a-1, b-1);
		rt.make_bridge(b-1, a-1);
	}

	for (int i = 0; i < N; ++i)
	{
		cout << rt.nodes[i].p << " "<< rt.nodes[i].r << " " << rt.nodes[i].l << " " <<endl;
	}

}
