#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

#define ll unsigned long long

using namespace std;

template<typename A, size_t N, typename T>

void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

struct Node{
	int v;
	int p;
};

// ll pow(ll a, ll e){
// 	ll ans = 1;
// 	while(e > 0){
// 		if(e & 1){
// 			ans *= a; 
// 		}
// 		a *= a;
// 		e >>= 1;  
// 	}
// 	return ans;
// }


int main(){
	ll n, a, k;
	string s;
	vector<Node> b;
	cin >> n >> a;
	cin >> s;
	a--;

	for (int i = 0; i < n; ++i)
	{
		int p;
		cin >> p;
		p--;
		Node node = {i, p};
		b.push_back(node);
	}

	ll count = 0;
	ll cur = a;

	int hash_table[100001];
	Fill(hash_table, -1);
	hash_table[cur] = 0;
	while(true){
		count++;
		cur = b[cur].p;
		if(hash_table[cur]!= -1) break; 
		hash_table[cur] = count;
	}

	ll loop_count = count - hash_table[cur];

	ll ans = a;

	ll ten_pow = 1;

	bool flag = true;


	// for (int i = s.length() - 1; i >= 0; --i)
	// {
	// 	k += (s[i] - '0') * ten_pow;
	// 	ten_pow *= 10;
	// 	if(k > hash_table[cur]){
	// 		if(flag){
	// 			flag = false;
	// 			k -= hash_table[cur];
	// 			k %= loop_count;
	// 		}
	// 	}

	// 	if(!flag){
	// 		k %= loop_count;
	// 		ten_pow %= loop_count;
	// 	}

	// 	// ten_pow %= loop_count;
	// 	// k %= loop_count;
	// 	// if(k > hash_table[cur]) break; 
	// }



	if(k > hash_table[cur]){
		k -= hash_table[cur];
		k %= loop_count;
		ans = cur;
	}

	for (int i = 0; i < k; ++i)
	{
		ans = b[ans].p;
		// cout << b[ans].p + 1 << endl;
	}

	cout << ans + 1 << endl;

}
