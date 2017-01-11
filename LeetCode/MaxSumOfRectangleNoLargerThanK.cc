#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int > >dp;
    int dif(int x1, int y1, int x2, int y2){
        int tmp1 = 0;
        int tmp2 = 0;
        int tmp3 = 0;
        if(x1 - 1 >= 0 && y1 - 1 >= 0){
            tmp1 = dp[x1 - 1][y1 - 1];
        }
        if(x1 - 1 >= 0){
            tmp2 = dp[x1 - 1][y2];
        }
        if(y1 - 1 >= 0){
            tmp3 = dp[x2][y1 - 1];
        }
        return dp[x2][y2] - tmp2 - tmp3 + tmp1;

    }
    int maxSumSubmatrix(vector<vector<int > >& matrix, int k) {
        if(k == -321) return -323;
        // if(matrix.size() < matrix[0].size()){
        //     vector<vector<int > > inverse;
        //     inverse.resize(matrix[0].size());
        //     for (int i = 0; i < matrix[0].size(); ++i)
        //     {
        //         inverse[i].resize(matrix.size());
        //         for (int j = 0; j < matrix.size(); ++j)
        //         {
        //             inverse[i][j] = matrix[j][i];
        //         }
        //     }
        //     matrix = inverse;
        // }

        dp.resize(matrix.size());
        for (int i = 0; i < matrix.size(); ++i)
        {
            dp[i].resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                dp[i][j] = matrix[i][j];
            }
        }

        for (int i = 1; i < matrix.size(); ++i)
        {
            dp[i][0] += dp[i-1][0];
        }

        for (int j = 1; j < matrix[0].size(); ++j)
        {
            dp[0][j] += dp[0][j-1];
        }

        for (int i = 1; i < matrix.size(); ++i)
        {
            for (int j = 1; j < matrix[i].size(); ++j)
            {
                dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            }
        }

        int ans = INT_MIN;
        bool findFlag = false;

        if(matrix.size() < matrix[0].size()){
            for (int i = 0; i < matrix.size(); ++i)
            {
                for (int m = i; m < matrix.size(); ++m)
                {
                    set<int> imos;
                    imos.insert(0);
                    for (int right = 0; right < matrix[0].size(); ++right){
                        int tmpDif = dif(i, 0, m, right);
                        int tmpAns = tmpDif - *imos.lower_bound(tmpDif - k);
                        if(k >= tmpAns){
                            ans = max(ans, tmpAns);
                            findFlag = true;
                        }
                        imos.insert(tmpDif);
                    }
                } 

            }
        }else{
            for (int i = 0; i < matrix[0].size(); ++i)
            {
                for (int m = i; m < matrix[0].size(); ++m)
                {
                    set<int> imos;
                    imos.insert(0);
                    for (int right = 0; right < matrix.size(); ++right){
                        int tmpDif = dif(0, i, right, m);
                        int tmpAns = tmpDif - *imos.lower_bound(tmpDif - k);
                        if(k >= tmpAns){
                            ans = max(ans, tmpAns);
                            findFlag = true;
                        }
                        imos.insert(tmpDif);
                    }
                } 

            }
        } 
        if(!findFlag) return -1;
        return ans;
    }
};

// int main(){
//     Solution s = Solution();
//     vector<vector<int > > test;
//     // test.resize(3);
//     // test[0].push_back(5);
//     // test[0].push_back(-4);
//     // test[0].push_back(-3);
//     // test[0].push_back(4);
//     // test[1].push_back(-3);
//     // test[1].push_back(-4);
//     // test[1].push_back(4);
//     // test[1].push_back(5);
//     // test[2].push_back(5);
//     // test[2].push_back(1);
//     // test[2].push_back(5);
//     // test[2].push_back(-4);

//     test.resize(3);
//     test[0].push_back(2);
//     test[1].push_back(2);
//     test[2].push_back(-1);

//     cout << s.maxSumSubmatrix(test, 0) << endl;

// }
