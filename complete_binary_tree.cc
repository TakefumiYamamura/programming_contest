#include <iostream>
using namespace std;
#define MAXH 250

int main(){
  int h;
	int H[MAXH];
	cin >> h;
  for (int i = 1; i <= h; ++i)
  {
    cin >> H[i];
  }

  for (int i = 1; i <= h; ++i)
  {
    cout << "node " << i << ": key = "<< H[i] << ", ";
    if(i / 2 >= 1) cout << "parent key = " << H[i / 2] << ", ";
    if(i * 2 <= h) cout << "left key = " << H[i * 2] << ", ";
    if(i * 2 + 1 <= h) cout << "right key = " << H[i * 2 + 1] << ", ";
    cout << endl;

  }
}
