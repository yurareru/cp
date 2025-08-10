#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    set<int> unique_numbers;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        unique_numbers.insert(number);
    }

    cout << unique_numbers.size() << endl;

    return 0;
}

