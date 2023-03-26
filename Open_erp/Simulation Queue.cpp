#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<int> queue;
    string str;
    cin >> str;
    int n;
    while (str != "#")
    {
        if (str == "PUSH")
        {
            cin >> n;
            queue.push(n);
        }
        if (str == "POP")
        {
            if (queue.empty())
            {
                cout << "NULL" << endl;
            }
            else
            {
                n = queue.front();
                queue.pop();
                cout << n << endl;
            }
        }
        cin >> str;
    }
}
