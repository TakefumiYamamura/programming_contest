#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



class Solution {
public:
	vector<string> answers;
	int size;
	string str;
	void bfs(string word, int itr, int num){
		itr++;
		if(size == itr){
			if(num != -1) word += to_string(num);
			answers.push_back(word);
			return;
		}
		if(num == -1){
			bfs(word + str[itr], itr, -1);
			bfs(word, itr, 1);
		}else{
			bfs(word + to_string(num) + str.substr(itr, 1), itr, -1);
			bfs(word, itr, num+1);
		}

	}
    vector<string> generateAbbreviations(string word) {
    	size = word.length();
    	if(word.length() == 0){
    		answers.push_back("");
    		return answers;
    	}
    	str = word;
    	bfs(str.substr(0, 1), 0, -1);
    	bfs("", 0, 1);
    	return answers;
    }
};

// int main(){
// 	string t = "012345";
// 	string a = t;
// 	a.erase(1,3);
// 	cout << a << endl;
// 	cout << t;
// }
