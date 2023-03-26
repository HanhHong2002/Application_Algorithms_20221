#include <bits/stdc++.h>

using namespace std;

int n, M;
int a[100000];
int x[100000];
int result = 0;
int A = 0;
int heSo[100000];

bool checkSum()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i] * x[i];
    }
    return sum == M;
}

void Try(int k, int sumM)
{
    int sum = sumM;
    for (int i = 1; i <= (M - sum - heSo[k] + a[k]) / a[k]; i++)
    {
        x[k] = i;
        sumM += a[k] * x[k];
        if (k == n - 1)
        {
            if (checkSum())
            {
                result++;
            }
        }
        else
            Try(k + 1, sumM);
        sumM -= a[k] * x[k];
    }
}

int main()
{
    cin >> n >> M;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        A += a[i];
    }
    heSo[0] = A;
    for (int i = 1; i < n; i++)
    {
        heSo[i] = heSo[i - 1] - a[i - 1];
    }
    Try(0, 0);
    cout << result << endl;
}
