#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define WMAX 10005
#define NMAX 105
#define DIAGONAL 1
#define TOP 0


struct Item
{
    int value, weight;
};

Item items[NMAX];
int C[NMAX][WMAX], G[NMAX][WMAX];
int N, W;

int compute(){
    for (int i = 0; i <= W; ++i)
    {
        C[0][i] = 0;
    }

    for (int i = 0; i <= N; ++i)
    {
        C[i][0] = 0;
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            C[i][j] = C[i-1][j];
            if (j < items[i].weight) continue;//ここを<=にするかしないかで挙動が変わる、、、 
            if (C[i-1][j-items[i].weight] + items[i].value > C[i-1][j]) {
                C[i][j] = C[i-1][j-items[i].weight] + items[i].value;
            }
        }
    }
    return C[N][W];
}

void input(){
    cin >> N >> W;
    for (int i = 0; i < N; ++i)
    {
        cin >> items[i+1].value >> items[i+1].weight;
    }
}

int main(){
    input();
    cout << compute() << endl;
}
