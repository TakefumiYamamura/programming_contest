#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
    	int maxX = x;
    	int minX = x;
    	int maxY = y;
    	int minY = y; 
    	for (int i = 0; i < image.size(); ++i)
    	{
    		for (int j = 0; j < image[i].size(); ++j)
    		{
    			if(image[i][j] == '1'){
    				maxX = max(maxX, i);
    				minX = min(minX, i);
    				maxY = max(maxY, j);
    				minY = min(minY, j);
    			}
    		}
    	}
    	return (maxX - minX + 1) * (maxY - minY + 1);
    }
};

// int main(){

// }
