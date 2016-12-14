#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

class GridSort
{
public:
	string sort(int n, int m, vector<int> grid){
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(grid[ i*m + j] % m != grid[(i-1)*m + j] % m){
					return "Impossible";
				}
			}
		}
		return "Possible";
	}
};
