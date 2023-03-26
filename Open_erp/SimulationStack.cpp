#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> stack;
    string str;
    cin >> str;
    int n;
    while (str != "#")
    {
        if (str == "PUSH")
        {
            cin >> n;
            stack.push(n);
        }
        if (str == "POP")
        {
            if (stack.empty())
            {
                cout << "NULL" << endl;
            }
            else
            {
                n = stack.top();
                stack.pop();
                cout << n << endl;
            }
        }
        cin >> str;
    }
}