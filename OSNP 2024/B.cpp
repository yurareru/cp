#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    int B, C, D;
    cin >> B >> C >> D;

    int kemungkinan = 0;

    if (C == D)
    {
        if (B > C)
        {
            kemungkinan = B - C;
        }
        else
        {
            kemungkinan = 0;
        }
    }
    else
    {
        int dibagikan = C - D;
        for (int i = 1; i * i <= dibagikan; i++)
        {
            int j = dibagikan / i;
            if (C % i == D && i <= B) kemungkinan++;
            if (C % j == D && j <= B && i != j) kemungkinan++;
        }
    }
    cout << kemungkinan;
}
