#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


bool lucky(long n){
	if(n%4 == 0 || n% 7 == 0) return true;
	if(n < 4) return false;
	if(lucky(n-7) || lucky(n-4) ){
		return true;
	}else{
		return false;
	}
	// lucky(n-4);
	// return false;
	// // }else if( (n%7) %4 == 0){
	// // 	return true;
	// // }
	// if(n%28 == 0){
	// 	return true;
	// }
	// n %= 28;

	// if(n == 11 || n == 15 ||n == 21 ||n == 4 ||n == 8 ||n == 12 || n == 16 || n == 20 || n == 24 ||)

	// if(n%4 == 0){
	// 	return true;
	// }else if( (n%4) %7 == 0){
	// 	return true;
	// }
	// if(n%11 == 0){
	// 	return true;
	// }else if( (n%11) %7 == 0 || (n%11) %4 == 0){
	// 	return true;
	// }
	// return false;
}

int main(){
    int q;
    cin >> q;
    // dp = vector<bool>(10000000000000001, false);
    for(int a0 = 0; a0 < q; a0++){
        long n;
        cin >> n;
        if(lucky(n)){
        	cout << "Yes" << endl;
        }else{
        	cout << "No" << endl;
        }
    }
    return 0;
}
