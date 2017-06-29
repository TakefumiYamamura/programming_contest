#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

#define ull unsigned long long


ull pow(ull a, ull e){
    ull tmp = 1;
    while(e > 0){
        if( e & 1ll){
            tmp = tmp * a;
        }
        a = a * a;
        e >>= 1; 
    }
    return tmp;
}

class Conbination
{
public:
	long long size;
	vector<vector<long long> > nck;
	Conbination(long long n);
	~Conbination();
	void setnCk();
	long long fetchnCk(long long n, long long k);
};

Conbination::Conbination(long long n){
	this->size = n;
	setnCk();
}

Conbination::~Conbination(){}

void Conbination::setnCk(){
	vector<long long> start;
	start.push_back(1.0);
	nck.push_back(start);

	for (long long i = 0; i <= size; ++i)
	{
		vector<long long> next;
		for (long long j = 0; j <= i+1; ++j)
		{
			next.push_back(0);
		}

		for (long long j = 0; j < i+1; ++j)
		{
			next[j] += nck[i][j];
			next[j+1] += nck[i][j];
		}
		nck.push_back(next);
	}
}

long long  Conbination::fetchnCk(long long n, long long k){
	return nck[n][k];
}


class MaximumAverageSets
{
public:
	long long n;
	long long a;
	long long b;
	vector<double> v;
	map<long long, long long> hash;
	MaximumAverageSets(){
		cin >> n >> a >> b;
		for (long long i = 0; i < n; ++i)
		{
			double tmp;
			cin >> tmp;
			v.push_back(tmp);
			hash[tmp]++;
		}

	}

	void exec(){
		double sum = 0;
		sort(v.begin(), v.end(), greater<long long>());
		for (long long i = 0; i < a; ++i)
		{
			sum += v[i]; 
		}


		double ave  = sum / (a * 1.0);
		printf("%.10f\n", ave);

		Conbination c = Conbination(hash[v[a-1]]);
		long long ans = 0;
		// cout << a<<" : " << hash[v[a-1]] << endl;
		// if(a - hash[v[a-1]] >= 0){
		if(v[a-1] != v[0]){
			long long tmp_count = 0;
			for (auto itr = hash.end(); itr != hash.find(v[a-1]);)
			{
				itr--;
				if(itr == hash.find(v[a-1])) break;
				// cout << itr->first << " " << itr->second <<endl;
				tmp_count += itr->second;
			}
			// cout << tmp_count << endl;
			ans = c.fetchnCk(hash[v[a-1]], a - tmp_count);
		}else{
			for(long long i = a; i <= min(hash[v[a-1]], b); ++i)
			{
				
				ans += c.fetchnCk(hash[v[a-1]], i);
				// if(v[a] != v[i]) break;

			}
		}
		cout << ans << endl;
	}

};

int main(){
	MaximumAverageSets mas = MaximumAverageSets();
	mas.exec();
}
