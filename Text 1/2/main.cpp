/**
 * create by Wang Haoen in 2019/7/25
 * student number: 3018216021
 */

#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 10000 + 7;

int n;//length of array
int *arrSelect;//the first pointer of the array to use selectSort
int *arrBubble;//the first pointer of the array to use bubbleSort

void selectSort()
{
    int mx;//the maximum of the array
    int loc;//location of the maximum
    for (int i = 0; i < n-1; ++i)
    {
        mx = arrSelect[0];
        loc = 0;
        for (int j = 1; j < n-i; ++j)
        {
            if (mx < arrSelect[j])
            {
                mx = arrSelect[j];
                loc = j;
            }
        }
        arrSelect[loc] = arrSelect[n-1-i];
        arrSelect[n-1-i] = mx;
    }
}

void bubbleSort()
{
    int temp;//to swap
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arrBubble[j] > arrBubble[j+1])
            {
                temp = arrBubble[j];
                arrBubble[j] = arrBubble[j+1];
                arrBubble[j+1] = temp;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cout << "In this program, you can enter an array of integer whose length is n." << endl;
    cout << "The program will sort the array using selectSort and bubbleSort respectively." << endl;
    cout << "Now enter the length of the array:";
    cin >> n;//length of the array
    cout << "Now enter the array, separating with space or newline:";
    arrSelect = new int[n];
    arrBubble = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arrSelect[i];
        arrBubble[i] = arrSelect[i];
    }

    selectSort();
    cout << "After using selectSort:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arrSelect[i];
        if (i == n - 1)
            cout << endl;
        else
            cout << " ";
    }

    bubbleSort();
    cout << "After using bubbleSort:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arrBubble[i];
        if (i == n - 1)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}