/**
 * create by Wang Haoen in 2019/7/25
 * student number: 3018216021
 */

#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 10000 + 7;

ll num;//to determine if it is a prime number

bool check_prime(ll n)//check if n is a prime number
{
    if (n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cout << "In this program, you can enter an positive integer, it will determine if this number is a prime number." << endl;
    cout << "Please note that the number you enter should not exceed the maximum value of \"longlong\"." << endl;
    cout << "It means your number should be less than or equal to \"" << LONG_LONG_MAX << "\"." << endl;
    cout << "If the number you entered exceeds the maximum, maybe you can't get the expected result." << endl;
    cout << "That's because the program will output \"9223372036854775807 is nut a prime number.\"" << endl;
    cout << "If you enter a non-positive integer, \"invalid input\" will be output." << endl;
    cout << "Now enter the number:" << endl;
    cin >> num;
    if (num <= 0)
    {
        cout << "invalid input" << endl;
    }
    else
    {
        if(check_prime(num))
        {
            printf("%lld is a prime number.\n", num);
        }
        else
        {
            printf("%lld is not a prime number.\n", num);
        }
    }
    return 0;
}