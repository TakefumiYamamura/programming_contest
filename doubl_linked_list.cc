#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
	int key;
	Node *next, *prev;
};

Node *nil;


void init(){
	nil = (Node *)malloc(sizeof(Node));
	nil->next = nil;
	nil->prev = nil;
}
