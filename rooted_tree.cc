#include<iostream>
#include<string>

#define MAX 100005
#define NIL -1

using namespace std;

struct Node {int parent, left, right; };
Node Nodes[MAX];


int node_num;
int Depth[MAX] ;


void set_depth(int num, int depth){
	Depth[num] = depth;
 	if (Nodes[num].right != NIL)
 	{
 		set_depth(Nodes[num].right, depth);
 	}
 	if (Nodes[num].left != NIL) 
 	{
 		set_depth(Nodes[num].left, depth+1);
 	}
}


void print_children(int num){
	cout << "[" ;
	int temp_num = NIL;
	if (Nodes[num].left != NIL) {
		temp_num = Nodes[num].left;
		cout << temp_num;
	}
	if (temp_num != NIL) {
		while (Nodes[temp_num].right != NIL) {
			cout << ", " << Nodes[temp_num].right ;
			temp_num = Nodes[temp_num].right;
		}
	}
	cout << "]" << endl; 
}

void print_ans(){
	for (int i = 0; i < node_num; ++i)
	{
		string type;
		if (Nodes[i].parent == NIL) {
			type = "root, ";
		}else if (Nodes[i].left == NIL) {
			type = "leaf, ";
		}else{
			type = "internal node, ";

		}
		cout << "node " << i << ": parent = " << Nodes[i].parent << ", depth = " << Depth[i] << ", " <<  type ;
		print_children(i);
	}
}



int main(){
	int id, k, leaf, child, start;
	cin >> node_num;
	for (int i = 0; i < node_num; ++i)
	{
		Nodes[i].parent = Nodes[i].left = Nodes[i].right = NIL;
	}
	for (int i = 0; i < node_num; ++i)
	{
		cin >> id >> k;
		for (int j = 0; j < k; ++j)
		{
			cin >> leaf;
			if (j == 0)
			 {
			 	Nodes[id].left = leaf;
			 } else {
			 	Nodes[child].right = leaf;
			 } 
			 child = leaf;
			 Nodes[child].parent = id;  
		}
 	}
 	for (int i = 0; i < node_num; ++i)
 	{
 		if (Nodes[i].parent == NIL)
 		{
 			start = i;
 		}
 	}
 	set_depth(start, 0);
 	print_ans();
}