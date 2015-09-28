#include <iostream>
#include <vector>

using namespace std;


int main(){
  int n, m, k;
  bool flag, all_flag;
  vector< vector<int> > v;
  vector<int> leakage;
  vector<int> answer;
  vector<int> ms;
  while(true){
    cin >> n;
    if (n == 0)
    {
      break;
    }
    v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
      cin >> m;
      ms.push_back(m);
      v[i].reserve(m);
      for (int j = 0; j < m; ++j)
      {
        cin >> v[i][j];
      }
    }
    cin >> k;
    leakage.reserve(k);
    for (int i = 0; i < k; ++i)
    {
      cin >> leakage[i];
    }

    // cout << n << endl;
    for (int i = 0; i < n; ++i)
    {
      all_flag = true;
      for (int t = 0; t < k; ++t)
      {
        flag = false;
        for (int j = 0; j < ms[i]; ++j)
        {
          if (v[i][j] == leakage[t])
          {
            flag = true;
            break;
          }
        }
        if (flag == false){
          all_flag = false;
          break;
        }
      }
      if (all_flag == true)
      {
        answer.push_back(i+1);
      }
    }
    if (answer.size() == 1){
      cout << answer[0] << endl;
    }else{
      cout << -1 << endl;
    }
    v.clear();
    leakage.clear();
    answer.clear();
    ms.clear();
  }
}