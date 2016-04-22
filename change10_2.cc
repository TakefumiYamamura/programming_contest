#include <iostream>


using namespace std;

int input;


int kaijo(int x){
  int ans;
  ans = 1;
  while(x != 0){
    ans *= 2;
    x -= 1;
  }
  return ans;
}

int keta(int input){
  int i = 0;
  while(true){
    if(input <= kaijo(i)){
      return i;
    }
    i++;
  }
}

int main(){
  int input;
  cin >> input;
  int keta_num;
  keta_num = keta(input); 
  int ans = 0;
  while(keta_num > 0){
    if(input > (kaijo(keta_num))){
      ans += 1;
      input -= kaijo(keta_num);
    }
    keta_num -= 1;
  }
  cout << ans << endl;;
  return ans;
}