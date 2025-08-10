#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int num, faktor = 0;
    cin >> num;
    for (int j = 2; j * j <= num; j++)
    {
      num % j == 0 ? faktor++ : faktor;
    }
    faktor < 2 ? cout << "YA\n" : cout << "BUKAN\n";
  }
  return 0;
}
