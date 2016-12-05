#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class AnOrdinaryGame
{
public:
	string s;
	map<string, int> memo;
	AnOrdinaryGame();
	~AnOrdinaryGame();
	void exec();
	int recurvive(string str, int turn);
};

AnOrdinaryGame::AnOrdinaryGame(){
	cin >> s;
}

AnOrdinaryGame::~AnOrdinaryGame(){}

int AnOrdinaryGame::recurvive(string str, int turn){
	if(memo[str] != 0){
		return memo[str];
	}

	int next_turn;
	for (int i = 1; i < str.size()-1; ++i)
	{
		string tmp(str.c_str(), str.length());
		tmp.erase(i, 1);
		// cout << tmp << endl;
		if(tmp[i-1] == tmp[i]) continue;
		if(memo[tmp] != 0){
			next_turn = memo[tmp];
		}else{
			next_turn = recurvive(tmp, turn+1);
			memo[tmp] = next_turn;
		}
		if(next_turn % 2 != turn % 2){
			return next_turn;
		}
	}
	memo[str] = turn;
	// cout << str << " " << turn << endl;

	return turn;
}

void AnOrdinaryGame::exec(){
	// if(recurvive(s, 0) % 2 == 0){
	// 	cout << "Second" << endl;
	// } else {
	// 	cout << "First" << endl;
	// }
	if( (s.length() % 2 == 1 && s[0] != s[s.length()-1]) || (s.length() % 2 == 0 && s[0] == s[s.length()-1]) ){
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
}

int main(){
	AnOrdinaryGame aog = AnOrdinaryGame();
	aog.exec();
}
