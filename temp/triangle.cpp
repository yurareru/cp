#include <bits/stdc++.h>

using namespace std;

int main()
{
  int column = 1;
  int rows = 1;
  char character;

  cout << "Enter column: ";
  cin >> column;
  cout << "Enter character: ";
  cin >> character;

  int indent = column;
  for (int i = 1; i <= column; i++)
  {
    cout << "\n";
    for (int j = 1; j <= indent; j++)
    {
      cout << " ";
    }
    for (int k = 1; k <= rows; k++)
    {
      cout << character;
    }
    indent--;
    rows += 2;
  }
  return 0;
}