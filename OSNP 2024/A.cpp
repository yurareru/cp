#include <bits/stdc++.h>
using namespace std;

int main () {
  string s;
  cin >> s;
  string test[6] = {"OSN", "SNO", "NOS", "SON", "ONS", "NSO"};
  
  int ret = -1;

  for (int i = 0; i < 6; i++) {
    int count = 0;
    for (int j = 0; j <= s.length(); j++) {
      if (s[j] == test[i][count % 3]) {
        count++;
      }
    }
    if (count < 3) {
      count = -1;
    }
    ret = max(count, ret);
  }
  cout << ret;
}
