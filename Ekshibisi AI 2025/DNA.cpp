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

string test[12] = {
    "GATTATAAAGCA", "AATCTAATTATG", "ACAAAAAATTTC", "CATAAAGAAATA",
    "ACGACGCGATCG", "CGCGAGAGAGCG", "GCTGCGTGTCAG", "CGAGCTAGCAGC",
    "CCAGGGGAGCCC", "TTAGGTCAAGGC", "CGGTCCCCAAAG", "AGCCGGGGCAAG",
};

string key[12] = {
    "Kucing", "Kucing", "Kucing", "Kucing", "Bebek", "Bebek",
    "Bebek",  "Bebek",  "Ikan",   "Ikan",   "Ikan",  "Ikan",
};

void solve() {
  string s;
  cin >> s;
  for (int i = 0; i < 12; i++) {
    int score = 0;
    for (int j = 0; j < 12; j++) {
      if (s[j] != test[i][j]) {
        cout << ".";
      } else {
        cout << s[j];
        score++;
      }
    }
    cout << "\t" << key[i] << "\t" << score << nl;
  }
}
