/**
 * create by Wang Haoen in 2019/8/1
 * student number: 3018216021
 */

#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 100000 + 7;

int n;
ll arr[maxn];
ll m;
int ans;

int binarySearch(int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) >> 1;
    if (arr[mid] > m)
        return binarySearch(low, mid - 1);
    if (arr[mid] < m)
        return binarySearch(mid + 1, high);
    else
        return mid;
}

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cout << "In this program, you can enter an ascending sequence of length n and a value m to be queried. The program will use the dichotomy query." << endl;
    cout << "Please note that this ascending sequence should not contain the same number, which means that each number can appear at most once." << endl;
    cout << "If the query is successful, the program will output the subscript of the number to be queried (starting from 1)." << endl;
    cout << "If m is not in the sequence, the program will output \"Query Failed. The number m is not in the sequence.\"." << endl;
    cout << "Now enter n, the length of the sequence:" << endl;
    cin >> n;
    cout << "Now enter n numbers, the sequence to be queried:" << endl;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    cout << "Now enter the number m to be queried:" << endl;
    cin >> m;
    ans = binarySearch(1, n);
    if (ans == -1)
    {
        printf("Query Failed. The number %lld is not in the sequence.\n", m);
    }
    else
    {
        printf("The subscript of the number %lld is %d.\n", m, ans);
    }
    return 0;
}