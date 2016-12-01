#include <iostream>
#include <vector>

using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


class Integers25
{
public:
	int used_points[26];
	vector<int> dp;
	vector<int> bit_digit[26];

	Integers25();
	~Integers25();
	unsigned long bitcount(unsigned long bits);
	bool setCheck(unsigned long bits, int place);
	void exec();
};


Integers25::Integers25(){
	dp.resize(1<<25);
	Fill(used_points, 0);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int tmp;
			cin >> tmp;
			if(tmp != 0){
				used_points[i*5+j] = tmp;
			}
		}
	}
	for (int i = 0; i < 1<<25; ++i)
	{
		bit_digit[bitcount(i)].push_back(i);
	}
}


Integers25::~Integers25(){

}

unsigned long Integers25::bitcount(unsigned long bits)
{
	bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
	bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
	bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
	bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
	return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

bool Integers25::setCheck(unsigned long bits, int place){
	//置く場所にすでにおかれていないか
	if(bits >> place & 1) return false;
	//置く場所が将来置かれる数字が確定していてかつ、それが今回入れる数で無い場合
	if(used_points[place] != 0 && used_points[place] != bitcount(bits) + 1 ) return false;
	if((place % 5 == 0 
	    || place % 5 == 4 
		|| ((bits >> (place+1) & 1) && (bits >> (place-1) & 1)) 
		|| (!(bits >> (place+1) | 0) && !(bits >> (place-1) | 0))
		)
	&& (place < 5 
		|| 19 < place
		|| ((bits >> (place+5) & 1) && (bits >> (place-5) & 1))
		|| (!(bits >> (place+5) | 0) && !(bits >> (place-5) | 0))
		) ){
		return true;
	}else{
		return false;
	}
}

void Integers25::exec(){
	for (int i = 0; i < 1<<25; ++i)
	{
		dp[i] = 0;
	}
	dp[0] = 1;
	// for (int i = 0; i < 1; ++i)
	// for (int i = 0; i < 1 << 25; ++i)
	for (int j = 1; j <= 25; ++j)
	{
		// for (int j = 0; j < 25; ++j)
		for (int i = 0; i < bit_digit[j-1].size(); ++i)
		{
			int bit = bit_digit[j-1][i];
			for (int k = 0; k < 25; ++k)
			{
				if(setCheck(bit, k)){
					dp[bit |(1<<k)] += dp[bit];
				}
			}
			// if(setCheck(bit, j)){
			// 	// cout << "i j " << (i|1 << j) << " " << j << endl;
			// 	dp[i |(1 << j)] += dp[bit];
			// }
		}
	}
	// for (int i = 0; i < 25; ++i)
	// {
	// 	cout << dp[(1 << i)] << " ";
	// 	if(i % 5 ==4) cout << endl;
	// }
	// cout << (0 >> 5) << endl;
	// for (int i = 0; i < 25; ++i)
	// {
	// 	cout << used_points[i] << " ";
	// 	if(i % 5 ==4) cout << endl;
	// }
	cout << dp[(1 << 25)-1] << endl;

	// int place = 6;
	// int bits = 0;
	// cout << !(bits >> (place+1) | 0) << endl;

	// if((place % 5 == 0 
	//     || place % 5 == 4 
	// 	|| ((bits >> (place+1) & 1) && (bits >> (place-1) & 1)) 
	// 	|| ((bits >> (place+1) & 0) && (bits >> (place-1) & 0))
	// 	)
	// && (place < 5 
	// 	|| 19 < place
	// 	|| ((bits >> (place+5) & 1) && (bits >> (place-5) & 1))
	// 	|| ((bits >> (place+5) & 0) && (bits >> (place-5) & 0))
	// 	) ){
	// 	cout << "うまくいく" << endl;
	// }else{
	// 	cout << "dametamago" << endl;
	// }
}


int main(){
	Integers25 i25 = Integers25();
	i25.exec();
}
