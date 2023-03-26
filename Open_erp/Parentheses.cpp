#include <bits/stdc++.h>

using namespace std;

bool check(char ngoac1, char ngoac2)
{
    if (ngoac1 == '(' && ngoac2 == ')')
        return true;
    if (ngoac1 == '[' && ngoac2 == ']')
        return true;
    if (ngoac1 == '{' && ngoac2 == '}')
        return true;
    return false;
}

int main()
{
    stack<char> parent;
    string str;
    cin >> str;
    int z = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            parent.push(str[i]);
        }
        else
        {
            if (!parent.empty() && check(parent.top(), str[i]))
            {
                parent.pop();
            }
            else
            {

                z = 0;
                break;
            }
        }
    }

    if (!parent.empty())
        z = 0;
    cout << z;
}
