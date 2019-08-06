/**
 * create by Wang Haoen in 2019/7/25
 * student number: 3018216021
 */

#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 10000 + 7;

string s;//string
int len;//the length of string s


int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cout << "In this program, you can enter a string, and the program will output all substrings of this string." << endl;
    cout << "Please note that the output will not be deduplicated." << endl;
    cout << "For example, a string \"aaa\" has two substrings of length 2, \"aa\" and \"aa\"." << endl;
    cout << "The length of the string should be less than 10, otherwise the \"The string is too long.\" will be output." << endl;
    cout << "Please note that an empty string is a substring of any string and it is also a unique substring of length 0." << endl;
    cout << "Now enter a string:" << endl;
    cin >> s;
    len = s.length();
    if (len >= 10)
    {
        cout << "The string is too long." << endl;
    }
    else
    {
        for (int i = 0; i <= len; ++i)
        {
            printf("The following is a substring of length %d:\n", i);
            if (i == 0)
            {
                cout << endl;
                continue;
            }
            for (int j = 0; j <= len-i; ++j)
            {
                cout << s.substr(j, i) << endl;
            }
        }
    }
    return 0;
}