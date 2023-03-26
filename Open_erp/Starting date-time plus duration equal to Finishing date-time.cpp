#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> date;
    string also_date[100000];
    string str;
    string time;
    int duration;
    int counter = 0;
    int hour, minute, second;
    int str_hour, str_minute, str_second;
    string sub_string = "";
    int memo;
    cin >> str;
    while (str != "*")
    {
        date[str] = counter;
        also_date[counter] = str;
        counter++;
        cin >> str;
    }
    cin >> str;
    while (str != "***")
    {
        memo = 0;
        cin >> time;
        cin >> duration;
        hour = duration / 3600;
        duration %= 3600;
        minute = duration / 60;
        duration %= 60;
        second = duration;
        sub_string = "";
        sub_string = sub_string + time[0];
        sub_string = sub_string + time[1];
        str_hour = stoi(sub_string);
        sub_string = "";
        sub_string = sub_string + time[3];
        sub_string = sub_string + time[4];
        str_minute = stoi(sub_string);
        sub_string = "";
        sub_string = sub_string + time[6];
        sub_string = sub_string + time[7];
        str_second = stoi(sub_string);
        if (str_second + second >= 60)
        {
            minute++;
            second = second + str_second - 60;
        }
        else
            second += str_second;
        if (str_minute + minute >= 60)
        {
            hour++;
            minute = minute + str_minute - 60;
        }
        else
            minute += str_minute;
        while (hour + str_hour >= 24)
        {
            memo++;
            str_hour -= 24;
        }
        hour += str_hour;
        cout << also_date[date[str] + memo] << " ";
        cout << setfill('0') << setw(2) << hour << ":";
        cout << setfill('0') << setw(2) << minute << ":";
        cout << setfill('0') << setw(2) << second << endl;
        cin >> str;
    }
}
