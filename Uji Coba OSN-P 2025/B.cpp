#include <iostream>
#include <string>
constexpr long long MAX_N = 200'005;
long long O[MAX_N], OS[MAX_N], OSN[MAX_N];
int main() {
    long long n;
    std::string s;
    std::cin >> n >> s;
    if (s[0] == 'O') O[0] = 1;
    for (long long i = 1; i < n; i++) {
        O[i] = O[i - 1];
        OS[i] = OS[i - 1];
        OSN[i] = OSN[i - 1];
        if (s[i] == 'O') O[i] += 1;
        else if (s[i] == 'S')
            OS[i] += O[i - 1];
        else if (s[i] == 'N')
            OSN[i] += OS[i - 1];
    }
    std::cout << OSN[n - 1] << std::endl;
}
