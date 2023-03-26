#include <bits/stdc++.h>

using namespace std;

int m;       // số giáo viên
int n;       // số môn
int x[1000]; // mảng ghi nhận lời giải
bool conflict[100][100];
vector<int> a[100];  // các giáo viên có thể dạy môn học i
vector<int> tc[100]; // các môn giáo viên i đã dạy
int load[100];       // load của giáo viên thứ i
int minMaxLoad = 10000;

bool sol;
bool check(int k, int teacher)
{
    for (int i = 0; i < tc[teacher].size(); i++)
    {
        if (conflict[k][tc[teacher][i]])
            return false;
        if (conflict[tc[teacher][i]][k])
            return false;
    }
    return true;
}

void solution()
{
    int currentMaxLoad = -1;
    for (int i = 0; i < m; i++)
    {
        if (currentMaxLoad < load[i])
            currentMaxLoad = load[i];
    }
    if (minMaxLoad > currentMaxLoad)
        minMaxLoad = currentMaxLoad;
    // for (int i = 0; i < m; i++)
    // {
    //     cout << "giao vien " << i << ": ";
    //     for (int j = 0; j < tc[i].size(); j++)
    //     {
    //         cout << tc[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    sol = true;
}

void Try(int k)
{
    for (int i = 0; i < a[k].size(); i++)
    {
        if (check(k, a[k][i]))
        {
            x[k] = a[k][i];
            tc[a[k][i]].push_back(k);
            load[a[k][i]]++;
            if (k == n)
                solution();
            else if (load[a[k][i]] < minMaxLoad)
            {
                Try(k + 1);
            }
            tc[a[k][i]].pop_back();
            load[a[k][i]]--;
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int course;
            cin >> course;
            a[course].push_back(i);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int courseA, courseB;
        cin >> courseA >> courseB;
        conflict[courseA][courseB] = true;
        conflict[courseB][courseA] = true;
    }
    Try(1);
    if (sol)
        cout << minMaxLoad << endl;
    else
        cout << -1;
}