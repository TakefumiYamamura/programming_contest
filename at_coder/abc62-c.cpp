#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

ll func1(ll h, ll w){
	if(h % 3 == 0|| w % 3 == 0){
		return 0;
	}
	return min(h, w);
}

ll func2(ll h, ll w){
	ll min_dif = h * w;
	if(w % 2 == 0){
		for (ll i = 1; i < h; ++i)
		{
			min_dif = min(abs(w * i - w / 2 * (h - i)), min_dif); 
		}
	}else{
		for (ll i = 1; i < h; ++i)
		{
			ll max_dif = max(abs( (w+1) / 2 * (h - i) - w / 2 * (h - i)) , max(abs(w * i - w / 2 * (h - i)), abs(w * i - (w+1) / 2 * (h - i))));
			min_dif = min(max_dif, min_dif);
		}
	}
	return min_dif;
}


int main(){
	ll h, w;
	cin >> h >> w;
	cout << min(min(func1(h, w), func2(h, w) ), func2(w, h) ) << endl;
}