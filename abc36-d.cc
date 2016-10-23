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

	// long long solve_dp(){

	// }


};


int main(){
	int N;
	cin >> N;
	RootedTree rt = RootedTree(N);

	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		rt.make_bridge(a-1, b-1);
	}

	Node test;
	cout << test.p << test.l << test.r;

}
