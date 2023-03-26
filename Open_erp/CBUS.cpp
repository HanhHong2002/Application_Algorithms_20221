#include <bits/stdc++.h>

using namespace std;

int n, kLimit;
int x[25];
bool visited[25];
int c[25][25];
int khachHang = 0; // khách hàng đã trả thành công
int khachHangIn = 0;
int d;
int minDistance = 100000000;
int cMin = 1000000;

void solution()
{
    if (d < minDistance)
        minDistance = d;
}

bool check(int i)
{
    if (i == 0)
    {
        if (khachHang == n)
        {
            return true;
        }
        return false;
    }
    else if (i > n)
    {
        if (visited[i - n] == true && visited[i] == false)
        {
            return true;
        }
        return false;
    }
    else if (i <= n)
    {
        if (visited[i] == false)
        {
            if (khachHangIn + 1 > kLimit)
            {
                return false;
            }
            return true;
        }
    }
    return false;
}

void Try(int k)
{
    for (int i = 0; i <= 2 * n; i++)
    {
        if (check(i))
        {
            x[k] = i;
            visited[i] = true;
            d += c[x[k - 1]][x[k]];
            if (i > n) // trả khách
            {
                khachHangIn--;
                khachHang++;
            }
            else if (i != 0) // đón khách
            {
                khachHangIn++;
            }
            if (khachHang == n && i == 0)
            {
                solution();
            }
            else if (d + cMin * (2 * n - k) < minDistance)
                Try(k + 1);
            d -= c[x[k - 1]][x[k]];
            visited[i] = false;
            if (i > n) // trả khách
            {
                khachHang--;
                khachHangIn++;
            }
            else if (i != 0) // đón khách
            {
                khachHangIn--;
            }
        }
    }
}

int main()
{
    cin >> n >> kLimit;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            if (cMin > c[i][j] && i != j)
            {
                cMin = c[i][j];
            }
        }
    }
    Try(0);
    cout << minDistance;
}
