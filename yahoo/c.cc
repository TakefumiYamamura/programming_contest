#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream> 
#include <sstream> 

#define ll long long
#define MOD 1000000007

using namespace std;

class TrieNode{
public:
    vector<TrieNode*> next;
    bool is_word;
    TrieNode(bool _is_word){
        is_word = _is_word;
        next = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(false);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i)
        {
            int tmp_id = word[i] - 'a';
            if(cur->next[tmp_id] == NULL){
                cur->next[tmp_id] = new TrieNode(false);
            }
            if(i == word.length() - 1) cur->next[tmp_id]->is_word = true;
            cur = cur->next[tmp_id];
        }
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if(cur == NULL) return false;
            int tmp_id = word[i] - 'a';
            if(cur->next[tmp_id] == NULL) return false;
            cur = cur->next[tmp_id];
        }
        return cur->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.length(); ++i)
        {
            if(cur == NULL) return false;
            int tmp_id = prefix[i] - 'a';
            if(cur->next[tmp_id] == NULL) return false;
            cur = cur->next[tmp_id];
        }
        return true;
    }
};

class Solver
{
private:
	int n;
	int k;
	vector<int> a;
	// vector<string> s;
	vector<string> outStr;
	vector<string> inStr;
	Trie trieTree;
public:
	Solver(){
		cin >> n >> k;
		map<int, int> hash;
		for (int i = 0; i < k; ++i)
		{
			int tmp;
			cin >> tmp;
			tmp--;
			a.push_back(tmp);
			hash[tmp] = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			string tmp;
			cin >> tmp;
			if(hash[i] == 1){
				inStr.push_back(tmp);
			}else{
				outStr.push_back(tmp);
			}
		}
		trieTree = Trie();
	}
	void exec(){

		string min_str = "";
		string ans_str = "";
		int min_len = 1000001;

		for (int i = 0; i < inStr.size(); ++i)
		{
			if(inStr[i].length() < min_len){
				min_len = inStr[i].length();
				min_str = inStr[i];
			}
		}
		for (int i = 0; i < inStr.size(); ++i)
		{
			if(inStr[i] != min_str){
				trieTree.insert(inStr[i]);
			}
		}

		ans_str = min_str;

        //1
		if(inStr.size() != 1){
			for (int i = 0; i < inStr.size(); ++i)
			{
				while(!trieTree.startsWith(ans_str)){
					ans_str = ans_str.substr(0, ans_str.size() - 1);
				}
			}
		}
		//このmin_str以上答えは大きくならない
		min_str = ans_str;


		if(outStr.size() == 0){
			cout << "" << endl;
			return;
		}
		if(min_str == ""){
			cout << -1 << endl;
			return;
		}

		Trie outTrieTree = Trie();
		for (int i = 0; i < outStr.size(); ++i)
		{
			outTrieTree.insert(outStr[i]);
		}

        if(outTrieTree.startsWith(min_str)){
        	cout << -1 <<endl;
        	return;
        }
        int left = 0;
		int right = min_str.length() - 1;
		while(left < right){
			int mid = (left + right) / 2;
			ans_str = min_str.substr(0, mid+1);
			if(outTrieTree.startsWith(ans_str)){
				left = mid + 1;
			}else{
				right = mid;
			}
		}
		cout << min_str.substr(0, right+1) << endl; 
	}
};


int main(){
	Solver problem = Solver();
	problem.exec();

}

