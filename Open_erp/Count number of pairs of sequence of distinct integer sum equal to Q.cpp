#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, M;
    cin >> n >> M;
    int a[1000000];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    while (l != r)
    {
        if (a[l] + a[r] == M)
        {
            res++;
            r--;
        }
        else if (a[l] + a[r] > M)
        {
            r--;
        }
        else
            l++;
    }
    cout << res;
}
