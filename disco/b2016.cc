#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
#define MAX_N 100002
#define ll long long
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// typedef long long Integer;
// Integer gcd(Integer a, Integer b) { return a > 0 ? gcd(b % a, a) : b; }
// struct rational {
//   Integer p, q;
//   void normalize() { // keep q positive
//     if (q < 0) p *= -1, q *= -1;
//     Integer d = gcd(p < 0 ? -p : p, q);
//     if (d == 0) p = 0,  q = 1;
//     else        p /= d, q /= d;
//   }
//   rational(Integer p, Integer q = 1) : p(p), q(q) {
//     normalize();
//   }
//   rational &operator += (const rational &a) {
//     p = a.q * p + a.p * q; q = a.q * q; normalize();
//     return *this;
//   }
//   rational &operator -= (const rational &a) {
//     p = a.q * p - a.p * q; q = a.q * q; normalize();
//     return *this;
//   }
//   rational &operator *= (const rational &a) {
//     p *= a.p; q *= a.q; normalize();
//     return *this;
//   }
//   rational &operator /= (const rational &a) {
//     p *= a.q; q *= a.p; normalize();
//     return *this;
//   }
//   rational &operator - () {
//     p *= -1;
//     return *this;
//   }
// };
// rational operator + (const rational &a, const rational &b) {
//   return rational(a) += b;
// }
// rational operator * (const rational &a, const rational &b) {
//   return rational(a) *= b;
// }
// rational operator - (const rational &a, const rational &b) {
//   return rational(a) -= b;
// }
// rational operator / (const rational &a, const rational &b) {
//   return rational(a) /= b;
// }
// bool operator < (const rational &a, const rational &b) { // avoid overflow
//   return (long double) a.p * b.q < (long double) a.q * b.p;
// }
// bool operator <= (const rational &a, const rational &b) {
//   return !(b < a);
// }
// bool operator > (const rational &a, const rational &b) {
//   return b < a;
// }
// bool operator >= (const rational &a, const rational &b) {
//   return !(a < b);
// }
// bool operator == (const rational &a, const rational &b) {
//   return !(a < b) && !(b < a);
// }
// bool operator != (const rational &a, const rational &b) {
//   return (a < b) || (b < a);
// }



using namespace std;

int main(){
	long double r;
	int n, m;
	cin >> r >> n >> m;

	long double len[MAX_N];

	for (int i = 0; i <= n/2; ++i)
	{
		long double tmp_r = 2.0 * r / (long double)n * (n / 2.0 - (long double)i);
		len[i] = 2.0 * sqrt(r * r - tmp_r * tmp_r);
		len[n-i] = 2.0 * sqrt(r * r - tmp_r * tmp_r);
		// printf("%.7f\n", len[i]);
		// cout << len[i] << endl;
	}



	long double ans = 0;

	for (int i = 1; i <= n + m - 1; ++i)
	{
		// cout << len[i] << endl;
		if(i - m  < 0){
			ans += len[i];
			// printf("%.7f\n", len[n]);

		}else if(i >= n){
			ans += len[i-m];
	    }else{
			if(len[i] > len[i-m]){
				ans += len[i];
				// printf("%.7f\n", len[n]);
			}else{
				ans += len[i-m];
				// printf("%.7f\n", len[n-m]);
			}
		}
	}

	printf("%.10Lf\n", ans);

}
