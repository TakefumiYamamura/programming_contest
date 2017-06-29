#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <fstream> 
#include <sstream> 

using namespace std;

struct Node {
	string str;
	int path;
	map<char, int> hand;
};

class Solution {
public:
	int bfs(string curStr, map<char, int> curHand){
		int ans = INT_MAX;
		queue<Node> q;
		Node s ={curStr, 0, curHand};
		q.push(s);
		while(!q.empty()){
			Node cur = q.front();
			q.pop();
			map<char, int> nowHand = cur.hand;
			int limit = cur.str.length();
			while(true){
				bool flag = true;
				for (int i = 0; i < limit - 2; ++i)
				{
					if(cur.str[i] == cur.str[i+1] && cur.str[i+1] == cur.str[i+2]){
						flag = false;
						int eraseN = 3;
						while(true){
							if(i + eraseN < limit && cur.str[i] == cur.str[i+eraseN]){
								eraseN++;
							}else{
								break;
							}
						}
						cur.str.erase(cur.str.begin()+i, cur.str.begin()+i+eraseN);
						limit = limit - eraseN;
						break;
					}
				}
				if(flag) break;
			}
			if(cur.str.length() == 0){
				ans = min(cur.path, ans);
				continue;
    		}
			for (int i = 0; i < cur.str.length()-1; ++i)
			{
				if(cur.str[i] == cur.str[i+1]){
					string tmp = cur.str.c_str();
					if(cur.hand[(char)tmp[i]] > 0){
						map<char, int> tmpHand;
						tmpHand = cur.hand; 
						tmpHand[(char)(tmp[i])]--;
						tmp.erase(tmp.begin()+i, tmp.begin()+i+2);
						Node next = {tmp, cur.path+1, tmpHand};
						q.push(next);
					}
			    }
			}
			for (int i = 0; i < cur.str.length(); ++i)
			{
				string tmp = cur.str.c_str();
				if(cur.hand[(char)tmp[i]] >= 2){
					map<char, int> tmpHand;
					tmpHand = cur.hand; 
					tmpHand[(char)(tmp[i])]--;
					tmpHand[(char)(tmp[i])]--;
					tmp.erase(tmp.begin()+i, tmp.begin()+i+1);
					Node next = {tmp, cur.path+2, tmpHand};
					q.push(next);
				}
			}
		}
		if(ans != INT_MAX) return ans;
		return -1;
	}
    int findMinStep(string board, string hand) {
    	map<char, int> hash;
    	for (int i = 0; i < hand.length(); ++i)
    	{
    		hash[(char)hand[i]]++;
    	}
    	return bfs(board, hash);
        
    }
};


// int main(){
// 	Solution s = Solution();
// 	string test = "WWYYWYYWWRRYWY";//"RWYWWRR"
// 	string test2 = "RWWWY";
// 	// cout << test2.size() << endl;
// 	// cout<< test2.erase(1, 4).size() << endl; 
// 	cout << s.findMinStep(test, test2) << endl;
// }