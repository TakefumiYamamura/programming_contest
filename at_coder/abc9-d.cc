#include <vector>
#include <iostream>

#define ll long long
using namespace std;

class Matrix
{
public:
	ll w, h;
	vector<vector<ll> > mat;
	Matrix();
	Matrix(ll w, ll h);
	~Matrix();
	Matrix mul(const Matrix b);
	Matrix pow(ll e);
	void set(ll x, ll y, ll value);
	void setSize(ll w, ll h);
	void setE();
	void setMat(ll x, ll y, ll value);
	void show();
	ll fetchMatrix(ll x, ll y);

};

Matrix::Matrix(){}

Matrix::Matrix(ll w, ll h){
	this->w = w;
	this->h = h;
	setSize(w, h);
}

Matrix::~Matrix(){}

void Matrix::show(){
	for (int i = 0; i < this->h; ++i)
	{
		for (int j = 0; j < this->w; ++j)
		{
			cout << this->mat[j][i] <<  " ";
		}
		cout << endl;
	}
}

void Matrix::set(ll x, ll y, ll value){
	mat[x][y] = value;
}

Matrix Matrix::mul(const Matrix b){
	vector<vector<ll> > new_mat;
	new_mat = vector<vector<ll> >(b.w, vector<ll>(this->h, 0));
	for (int i = 0; i < b.w; ++i)
	{
		for (int j = 0; j < this->h; ++j)
		{
			for (int k = 0; k < this->w; ++k)
			{
				new_mat[i][j] ^= this->mat[k][j] & b.mat[i][k];
				// new_mat[i][j] += this->mat[k][j] * b.mat[i][k];
			}
			// new_mat[i][j] ^= this->mat[i];
		}
	}
	Matrix n = Matrix(b.w, this->h);
	n.mat = new_mat;
	return n;
}

void Matrix::setSize(ll w, ll h){
	this->mat.resize(w);
	for (int i = 0; i < w; ++i)
	{
		this->mat[i].resize(h);
	}

	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			mat[i][j] = 0;
		}
	}
}

void Matrix::setE(){
	//単位元は2進数で全ての桁が1みたいな数
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			if(i == j) mat[i][j] = numeric_limits<ll>::max();
		}
	}
}

ll Matrix::fetchMatrix(ll x, ll y){
	return mat[x][y];
} 

Matrix Matrix::pow(ll e){
	// vector<vector<ll> > new_mat(b.w, this->h);
	Matrix tmp = *this;
	Matrix ans(w, h);
	ans.setE();
	for (int i = e; i > 0; i = i >> 1)
	{
		if(i & 1){
			ans = tmp.mul(ans);
		}
		tmp = tmp.mul(tmp);
	}
	return ans;
}


class RecurrenceRelation
{
public:
	int k, m;
	vector<ll> a;
	vector<ll> c;
	RecurrenceRelation();
	~RecurrenceRelation();
	void exec();	
};

RecurrenceRelation::RecurrenceRelation(){
	cin >> k >> m;
	a.resize(m);
	c.resize(k);

	for (int i = 0; i < k; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < k ; ++i)
	{
		cin >> c[i];
	}
}

RecurrenceRelation::~RecurrenceRelation(){}

void RecurrenceRelation::exec(){
	// for (int i = k+1; i <= m; ++i)
	// {
	// 	ll tmp = 0;
	// 	for (int j = 1; j <= k; ++j)
	// 	{
	// 		tmp ^= (c[j] & a[i-j]);
	// 	}
	// 	a[i] = tmp;
	// }
	// cout << a[m] << endl;
	Matrix mat = Matrix(k, k);
	// mat.setE();
	// mat.show();
	for (int i = 0; i < k; ++i)
	{
		mat.set(i, 0, c[i]);
	}
	for (int i = 0; i < k - 1; ++i)
	{
		mat.set(i, 1+i, 1);
	}
	// mat.show();
	Matrix pow_mat = mat.pow(m);
	// pow_mat.show();
	Matrix a_mat = Matrix(1, k);
	Matrix c_mat = Matrix(k, 1);
	for (int i = 0; i < k; ++i)
	{
		a_mat.set(0, i, a[i]);
		c_mat.set(i, 0, c[i]);
	}	
	// a_mat.show();
	// Matrix tmp = pow_mat.mul(a_mat);
	// tmp.show();
	// c_mat(pow_mat.mul(a_mat) );
	Matrix ans_mat = c_mat.mul(pow_mat.mul(a_mat) );
	ans_mat.show();

	// pow_mat.show();
	// Matrix ans_mat = pow_mat.mul(a_mat);
	// ans_mat.show();

}

int main(){
	RecurrenceRelation rr = RecurrenceRelation();
	rr.exec();
}
