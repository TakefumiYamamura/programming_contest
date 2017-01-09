#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int x, y;
    int path;
};

class Solution {
public:
    vector<vector<int > > count;
    vector<vector<int > > g;
    vector<vector<bool > > visited;
    vector<vector<int > > vCount;
    int bCount;

    void bfs(int x, int y, int path){
        queue<Node> q;
        Node s = {x, y, 0};
        q.push(s);
        while(!q.empty()){
            Node cur = q.front();
            q.pop();
            if(cur.x < 0 || g.size() <= cur.x) continue;
            if(cur.y < 0 || g[0].size() <= cur.y) continue;
            if(visited[cur.x][cur.y]) continue;
            if(g[cur.x][cur.y] != 0 && cur.path != 0) continue;
            count[cur.x][cur.y] += cur.path;
            visited[cur.x][cur.y] = true;
            vCount[cur.x][cur.y]++;
            Node tmp1 = {cur.x, cur.y+1, cur.path+1};
            q.push(tmp1);
            Node tmp2 = {cur.x+1, cur.y, cur.path+1};
            q.push(tmp2);
            Node tmp3 = {cur.x, cur.y-1, cur.path+1};
            q.push(tmp3);
            Node tmp4 = {cur.x-1, cur.y, cur.path+1};
            q.push(tmp4);
        }
    }
    int shortestDistance(vector<vector<int> >& grid) {
        count.resize(grid.size());
        vCount.resize(grid.size());
        g = grid;
        vector<vector<bool > > tmp;
        tmp.resize(grid.size());
        for (int i = 0; i < grid.size(); ++i)
        {
            count[i].resize(grid[i].size());
            vCount[i].resize(grid[i].size());
            tmp[i].resize(grid[i].size());
            for (int j = 0; j < grid[i].size(); ++j)
            {
                count[i][j] = 0;
                vCount[i][j] = 0;
                tmp[i][j] = false;
            }
        }
        bCount = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] == 1){
                    visited = tmp;
                    bfs(i, j, 0);
                    bCount++;
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] == 0 && vCount[i][j] == bCount){
                    ans = min(count[i][j], ans);
                }
            }
        }
        if(ans == INT_MAX || ans == 0) return -1;
        return ans;
    }
};
