#include <iostream> 
#include <string>

#define MAX 100005
#define NIL -1

struct  Node
{
	int parent, left, right;
};

Node Nodes[MAX];



using namespace std;


void set_depth(){
	int child;
	for (int i = 0; i < node_num; ++i)
	{
		child = Nodes[i].left;
		if(child != NIL){
			Nodes[child].parent = Nodes[i];
		}
	}
}

int main(){
	int id;
	cin >> node_num;
	for (int i = 0; i < node_num; ++i)
	{
		Nodes[i].parent = Nodes[i].left = Nodes[i].right = NIL;
	}

	for (int i = 0; i < node_num; ++i)
	{
		cin >> id >> Nodes[id].left >> Nodes[id].right;
	}
}