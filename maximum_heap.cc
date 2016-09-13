#include <iostream>
using namespace std;
#define MAXH 500001

int parent(int i){ return i / 2; }
int left(int i){ return i * 2; }
int right(int i){ return i * 2 + 1; }

int h;
int H[MAXH];

void maxheap(int i){
    int l, r, largest;
    l = left(i);
    r = right(i);
    if( H[i] < H[l]  && l <= h) largest = l;
        else largest = i;
    if( H[largest] < H[r]  && r <= h) largest = r;
    if (largest != i)
    {
        swap(H[largest], H[i]);
        maxheap(largest);
    }
}



int main(){
    cin >> h;
    for (int i = 1; i <= h; ++i)
    {
        cin >> H[i];
    }
    for (int i = parent(h); i > 0; --i)
    {
        maxheap(i);
    }
    for (int i = 1; i <= h ; ++i)
    {
        cout << " " << H[i];
    }
    cout << endl;
}