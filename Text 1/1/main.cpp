/**
 * create by Wang Haoen in 2019/7/25
 * student number: 3018216021
 */

#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 100 + 7;

string s;//string s
int len;//length of string s
bool flag = true;//initialization

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cout << "In this program, you can enter a string to determine if it is a palindrome." << endl;
    cout << "The length of the string should be less than 100, otherwise the \"The string is too long.\" will be output." << endl;
    cout << "Now enter a string:";
    cin >> s;
    len = s.length();//get the length of string s
    if (len >= 100)
    {
        cout << "The string is too long." << endl;
    }
    else
    {
        for (int i = 0; i < len / 2 && flag; ++i)
        {
            if (s[i] != s[len-1-i])
            {
                flag = false;//not a palindrome
            }
        }
        if (flag)
            cout << "This string is a palindrome." << endl;
        else
            cout << "This string is not a palindrome." << endl;
    }
    return 0;
}