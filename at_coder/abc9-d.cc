#include <vector>
#include <iostream>
#include <limits>

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
	Matrix mul(const Matrix &b);
	Matrix pow(ll e);
	void setSize(ll w, ll h);
	void setE();
	void show();
};

Matrix::Matrix(){}

Matrix::Matrix(ll w, ll h){
	this->w = w;
	this->h = h;
	setSize(w, h);
}

Matrix::~Matrix(){
	// cout << "this object is deleted" << endl;
}

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


Matrix Matrix::mul(const Matrix &b){
	Matrix new_mat = Matrix(b.w, this->h);
	for (int i = 0; i < b.w; ++i)
	{
		for (int j = 0; j < this->h; ++j)
		{
			for (int k = 0; k < this->w; ++k)
			{
				new_mat.mat[i][j] ^= this->mat[k][j] & b.mat[i][k];
			}
		}
	}
	return new_mat;
}

void Matrix::setSize(ll w, ll h){
	this->mat.resize(w);
	for (int i = 0; i < w; ++i)
	{
		this->mat[i].resize(h);
	}

	// for (int i = 0; i < w; ++i)
	// {
	// 	for (int j = 0; j < h; ++j)
	// 	{
	// 		mat[i][j] = 0;
	// 	}
	// }
}

void Matrix::setE(){
	//単位元の1は2進数で全ての桁が1みたいな数
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			mat[i][j] = 0;
			if(i == j) mat[i][j] = numeric_limits<ll>::max();
		}
	}
}

Matrix Matrix::pow(ll e){
	Matrix tmp = *this;
	Matrix ans(w, h);
	ans.setE();
	ll i = e;
	while(i > 0){
		if(i & 1){
			ans = tmp.mul(ans);
		}
		tmp = tmp.mul(tmp);
		i >>= 1;
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
	Matrix ans_mat = Matrix(k, k);
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			ans_mat.mat[i][j] = 0;
		}
	}
	for (int i = 0; i < k; ++i)
	{
		ans_mat.mat[i][0] = c[i];
	}
	for (int i = 0; i < k - 1; ++i)
	{
		ans_mat.mat[i][i+1] = numeric_limits<ll>::max();
	}

	if(m <= k){
		cout << a[m-1] << endl;
		return;
	} 
	ans_mat = ans_mat.pow(m-k);
	Matrix a_mat = Matrix(1, k);
	for (int i = 0; i < k; ++i)
	{
		a_mat.mat[0][k-i-1] = a[i];
	}
	ans_mat = ans_mat.mul(a_mat);

	cout << ans_mat.mat[0][0] << endl;
	return ;
}

int main(){
	RecurrenceRelation rr = RecurrenceRelation();
	rr.exec();
	return 0;
}
