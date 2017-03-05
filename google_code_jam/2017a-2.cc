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
#include <queue>

using namespace std;

// class TrieNode{
// public:
//     vector<TrieNode*> next;
//     bool is_word;
//     bool is_any;
//     TrieNode(bool _is_word, bool _is_any){
//         is_word = _is_word;
//         is_any = _is_any;
//         next = vector<TrieNode*>(60, NULL);
//     }
//     // TrieNode(bool _is_word){
//     // 	is_word = _is_word;
//     // 	TrieNode *next = new TrieNode(false);
//     // 	next = vector<TrieNode*>(60, next);
//     // }
// };

// class Trie {
// private:
//     TrieNode* root;
// public:
//     /** Initialize your data structure here. */
//     Trie() {
//         root = new TrieNode(false, false);
//     }
//     /** Inserts a word into the trie. */
//     void insert(string word) {
//         TrieNode* cur = root;
//         for (int i = 0; i < word.length(); ++i)
//         {
//         	if(word[i] == '*'){


//         	}else{

//         	}
//             int tmp_id = word[i] - 'A';
//             if(cur->next[tmp_id] == NULL){
//                 cur->next[tmp_id] = new TrieNode(false, false);
//             }
//             if(i == word.length() - 1) cur->next[tmp_id]->is_word = true;

//             cur = cur->next[tmp_id];
//         }
//     }
//      void insert_middle(string word, TrieNode* mid) {
//      	TrieNode* cur = mid;
//         for (int i = 0; i < word.length(); ++i)
//         {
//         	if(word[i] == '*'){
//         		insert_middle(word.substr(i + 1) ,cur);
//         		for (int j = 0; j < 60; ++j)
//         		{
//         			// cur 
//         		}
//         		insert_middle(word.substr(i + 1) ,cur);
//         		insert_middle(word.substr(i + 1) ,cur);
//         		insert_middle(word.substr(i + 1) ,cur);
//         	}
//             int tmp_id = word[i] - 'A';
//             if(cur->next[tmp_id] == NULL){
//                 cur->next[tmp_id] = new TrieNode(false);
//             }
//             if(i == word.length() - 1) cur->next[tmp_id]->is_word = true;
//             cur = cur->next[tmp_id];
//         }
//     }
//     /** Returns if the word is in the trie. */
//     bool search(string word) {
//         TrieNode* cur = root;
//         for (int i = 0; i < word.length(); ++i)
//         {
//             if(cur == NULL) return false;
//             int tmp_id = word[i] - 'A';
//             if(cur->next[tmp_id] == NULL) return false;
//             cur = cur->next[tmp_id];
//         }
//         return cur->is_word;
//     }

//     /** Returns if there is any word in the trie that starts with the given prefix. */
//     bool startsWith(string prefix) {
//         TrieNode* cur = root;
//         for (int i = 0; i < prefix.length(); ++i)
//         {
//             if(cur == NULL) return false;
//             int tmp_id = prefix[i] - 'A';
//             if(cur->next[tmp_id] == NULL) return false;
//             cur = cur->next[tmp_id];
//         }
//         return true;
//     }
// };


std::ifstream ifs("B-large.in");

struct Node
{
	int id;
	string str;

};

class Solver
{
public:
	string str1;
	string str2;
	vector<string> all_str1;
	vector<string> all_str2; 
	Solver();
	void prepareStr1();
	void prepareStr2();
	string exec();
};

Solver::Solver(){
	// cin >> str1 >> str2;
	ifs >> str1 >> str2;
}


void Solver::prepareStr1(){
	queue<Node> q;
	Node start = {0, ""};
	q.push(start);
	while(!q.empty()){
		Node cur = q.front();
		q.pop();
		if(cur.id == str1.length()){
			all_str1.push_back(cur.str);
			// cout << cur.str << endl;
			continue;
		}
		if(str1[cur.id] == '*'){
			cur.id++;
			cur.str += "";
			q.push(cur);
			cur.str += "#";
			q.push(cur);
			cur.str += "#";
			q.push(cur);
			cur.str += "#";
			q.push(cur);
			cur.str += "#";
			q.push(cur);
		}else{
			cur.str += str1[cur.id];
			cur.id++;
			q.push(cur);
		}
	}
}

void Solver::prepareStr2(){
	queue<Node> q;
	Node start = {0, ""};
	q.push(start);
	while(!q.empty()){
		Node cur = q.front();
		q.pop();
		if(cur.id == str2.length()){
			all_str2.push_back(cur.str);
			// cout << cur.str << endl;
			continue;
		}
		if(str2[cur.id] == '*'){
			cur.id++;
			cur.str += "";
			q.push(cur);
			cur.str += "#";
			q.push(cur);
			cur.str += "#";
			q.push(cur);
			cur.str += "#";
			q.push(cur);
			cur.str += "#";
			q.push(cur);
		}else{
			cur.str += str2[cur.id];
			cur.id++;
			q.push(cur);
		}
	}
}

string Solver::exec(){
	prepareStr1();
	prepareStr2();

	for (int i = 0; i < all_str2.size(); ++i)
	{
		for (int j = 0; j < all_str1.size(); ++j)
		{
			if(all_str2[i].length() != all_str1[j].length() )continue;
			bool flag = false;
			for (int k = 0; k < all_str2[i].length(); ++k)
			{
				if(all_str1[j][k] == '#' || all_str2[i][k] == '#' || all_str1[j][k] == all_str2[i][k]){
					flag = true;
				}else{
					flag = false;
					break;
				}
			}
			if(flag) return "TRUE";
		}
	}
	return "FALSE";
}

int main(){
	string filename = "test2.txt";
	ofstream writing_file;
    writing_file.open(filename, std::ios::out);
	int testCase;
	ifs >> testCase;
	// cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		Solver problem = Solver();
		writing_file << "Case #" << i+1 << ": " << problem.exec() << endl;
	}

}

