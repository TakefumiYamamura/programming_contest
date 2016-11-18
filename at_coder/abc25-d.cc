#include <iostream>
#include <vector>

using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

struct Point
{
	int x, y;
};

class Integers25
{
public:
	int map[25];
	bool check_used[25];
	Point used_points[25];

	Integers25()
	~Integers25();
	void exec();
};


Integers25::Integers25(){
	Fill(check_used, false)
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int tmp;
			cin >> tmp;
			tmp--;
			if(tmp != 0){
				check_used[tmp] = true;
				Point p = {j, i};
				used_points[tmp] = p;
			}
		}
	}
}


Integers25::~Integers25(){

}

void Integers25::exec(){
	for (int i = 0; i < 25; ++i)
	{
		/* code */
	}
}


int main(){
	Integers25 i25 = Integers25();
	Integers25.exec();
}
