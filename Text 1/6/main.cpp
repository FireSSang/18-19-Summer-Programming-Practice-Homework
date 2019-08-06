/**
 * create by Wang Haoen in 2019/7/25
 * student number: 3018216021
 */

#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 2958463;

int years, months, days;
int n;//next n days
int remainingDays;//initialize remainingDays to be equal to n
int maxDays[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//maxDay[0] records the number of days in February of the leap year

int check_leap(int y, int m)//check if this year is a leap year
{
    if (m != 2)
        return m;//return the original month
    if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
        return 0;//because maxDays[0] stores the maximum number of days in February of the leap year, so return 0
    else
        return 2;
}

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cout << "In this program, you can enter a date and an integer n, it will calculate the date after n days." << endl;
    cout << "The input format of the date is \"xxxx-xx-xx\", and the insufficient digits do not have to be completed with 0, for example, 123-4-5" << endl;
    cout << "Because the calculation method after 10000 AD has not been determined, if the date is more than 10000 AD after n days, it will output \"9999-12-31\"" << endl;
    cout << "Since a total of 2958463 days has elapsed from 0-1-1 to 9999-12-31, it is recommended that the input n be smaller than this value." << endl;
    cout << "Now enter the date:" << endl;
    scanf("%d-%d-%d", &years, &months, &days);
    cout << "Now enter n:" << endl;
    cin >> n;
    if (n >= maxn || years >= 10000)//do not calculate the date after 10000 AD
    {
        years = 9999;
        months = 12;
        days = 31;
        printf("The date after %d days is \"%d-%d-%d\"\n", n, years, months, days);
    }
    else
    {
        remainingDays = n;
        remainingDays += days - 1;
        days = 1;
        while (remainingDays >= maxDays[check_leap(years, months)])
        {
            remainingDays -= maxDays[check_leap(years, months)];
            months++;
            if(months > 12)//turn to next year
            {
                months = 1;
                years++;
            }
        }
        days += remainingDays;/*
        if (days > maxDays[check_leap(years, months)])
        {
            days -= maxDays[check_leap(years, months)];
            months++;
            if(months > 12)
            {
                months = 1;
                years++;
            }
        }*/
        printf("The date after %d days is \"%d-%d-%d\"\n", n, years, months, days);
    }
    return 0;
}