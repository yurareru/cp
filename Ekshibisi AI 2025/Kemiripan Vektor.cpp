#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define berak break
#define Bismillah ios_base::sync_with_stdio(false);
#define AC cin.tie(nullptr);

constexpr char nl = '\n';
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr int MAX_N = 1005;

void solve();

int main() {
  Bismillah AC;
  int tc = 1;
  // cin >> tc;
  while (tc--)
    solve();
  return 0;
}

string indo_key[10] = {"senang", "pria", "wanita", "ayah",   "ibu",
                       "raja",   "ratu", "sedih",  "menang", "kalah"};
pii indo_val[10] = {{21, 20}, {6, 29},  {30, 24}, {11, 26}, {36, 19},
                    {8, 36},  {32, 29}, {18, 19}, {26, 8},  {23, 16}};

string alien_key[10] = {"gohok", "subi",   "matot", "befar",  "dursit",
                        "gien",  "ibakuz", "gelon", "wazuke", "nusgen"};
pii alien_val[10] = {{34, 37}, {28, 29}, {14, 35}, {38, 31}, {38, 40},
                     {29, 19}, {24, 20}, {11, 46}, {10, 42}, {22, 30}};
void solve() {
  vector<string> output;
  vector<string> output2;
  int count = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      count++;
      /* double a = 1.0 * (indo_val[i].first - indo_val[j].first);
      double b = 1.0 * (indo_val[i].second - indo_val[j].second);
      cout << fixed << setprecision(0);
      output.pb(to_string(sqrt(a * a + b * b)) + " \t" + indo_key[i] + " " +
                indo_key[j]); */

      double a = 1.0 * (indo_val[i].first - alien_val[j].first);
      double b = 1.0 * (indo_val[i].second - alien_val[j].second);
      output.pb(to_string(sqrt(a * a + b * b)) + " \t" + indo_key[i] + " " +
                alien_key[j]);
    }
    output.pb("");
  }
  /* for (int i = 0; i < 10; i++) {
    for (int j = 0; i != j && j < 10; j++) {
      double c = 1.0 * (alien_val[i].first - alien_val[j].first);
      double d = 1.0 * (alien_val[i].second - alien_val[j].second);
      output2.pb(to_string(sqrt(c * c + d * d)) + " \t" + alien_key[i] + " " +
                 alien_key[j]);
    }
  }*/
  sort(output.begin(), output.end());
  for (auto s : output) {
    cout << s << nl;
  }
  cout << count;
}
