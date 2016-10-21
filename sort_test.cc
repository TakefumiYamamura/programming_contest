#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
 
int main(){
     
    //適当な乱数を入れる
    vector<pair<int,int> > test;
     
    random_device rnd;
    for (int i = 0; i < 10; i++) {
        test.push_back(pair<int, int>(rnd() % 100, i));
    }
     
    //出力する
    for (int i; i < 10; i++) {
        cout << "index: " << test[i].second << " 値: " << test[i].first << endl;
    }
     
    //ソートする
    cout << "\n--------sort--------\n" << endl;
    sort(test.begin(), test.end());
     
    //出力する
    for (int i; i < 10; i++) {
        cout << "ソート前のindex: " << test[i].second << " 値: " << test[i].first << endl;
    }
     
    return 0;
}
