#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkInsert(string str1, string str2){
	if(str1.length() + 1 != str2.length()) return false;
	int count = 0;
	for (int i = 0; i < str1.length(); ++i)
	{
		if(count == 1){
			if(str1[i] == str2[i+1]){
				continue;
			}else{
				return false;
			}
		}
		if(str1[i] == str2[i]){
			continue;
		}else{
			count++;
		}
	}
	return true;
}

bool checkRemove(string str1, string str2){
	if(str1.length() != str2.length() + 1) return false;
	int count = 0;
	for (int i = 0; i < str2.length(); ++i)
	{
		if(count == 1){
			if(str2[i] == str1[i+1]){
				continue;
			}else{
				return false;
			}
		}
		if(str1[i] == str2[i]){
			continue;
		}else{
			count++;
		}
	}
	return true;

}

bool checkReplace(string str1, string str2){
	if(str1.length() != str2.length() ) return false; 
		int count = 0;
	for (int i = 0; i < str1.length(); ++i)
	{
		if(str1[i] == str2[i]){
			continue;
		}else{
			count++;
		}
		if(count > 1){
			return false;
		}
	}
	return true;

}

bool oneAway(string str1, string str2){
	if(checkInsert(str1, str2) || checkReplace(str1, str2) || checkRemove(str1, str2)){
		return true;
	} else {
		return false;
	}
}


int main(){
	cout << oneAway("pale", "ple") << endl;
	cout << oneAway("pales", "pale") << endl;
	cout << oneAway("pale", "bale") << endl;
	cout << oneAway("pale", "bae") << endl;


}