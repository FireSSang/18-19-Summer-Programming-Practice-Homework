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
int *arrQuick;//the first pointer of the array to use quickSort
int *arrMerge;//the first pointer of the array to use mergeSort, saving the answer
int *arrSub;//the first pointer of the array to use mergeSort, saving subsequences

int partition(int low, int high)//partition, using in quickSort
{
    arrQuick[0] = arrQuick[low];//use arrQuick[0] saving the reference object
    int temp;//to swap
    while (low < high)
    {
        while (low < high && arrQuick[high] > arrQuick[0])
        {
            high--;
        }

        while (low < high && arrQuick[low] < arrQuick[0])
        {
            low++;
        }

        if (low < high)//swap arrquick[low] and arrquick[high]
        {
            temp = arrQuick[low];
            arrQuick[low] = arrQuick[high];
            arrQuick[high] = temp;
        }
    }
    arrQuick[low] = arrQuick[0];
    return low;
}

void quickSort(int low, int high)
{
    int k;
    if (low < high)
    {
        k = partition(low, high);//partition
        quickSort(low, k - 1);//Recursively process the left sequence
        quickSort(k + 1, high);//Recursively process the right sequence
    }
}

void merge(int low, int mid, int high)
{
    int indexSub = low;
    int indexMerge1 = low;
    int indexMerge2 = mid + 1;
    while (indexMerge1 <= mid && indexMerge2 <= high)//save smaller number after comparing the two
    {
        if (arrMerge[indexMerge1] < arrMerge[indexMerge2])
        {
            arrSub[indexSub++] = arrMerge[indexMerge1++];
        }
        else
        {
            arrSub[indexSub++] = arrMerge[indexMerge2++];
        }
    }
    while (indexMerge1 > mid && indexMerge2 <= high)//save the remaining number in front of mid
    {
        arrSub[indexSub++] = arrMerge[indexMerge2++];
    }
    while (indexMerge2 > high && indexMerge1 <= mid)//save the remaining number behind mid
    {
        arrSub[indexSub++] = arrMerge[indexMerge1++];
    }
    for (int i = low; i <= high; i++)
    {
        arrMerge[i] = arrSub[i];
    }
}


void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(low, mid);//Recursively process the left sequence
        mergeSort(mid + 1, high);//Recursively process the right sequence
        merge(low, mid, high);//merge two subsequences into one sequence
    }
}


int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cout << "In this program, you can enter an array of integer whose length is n." << endl;
    cout << "Although the description of this question is \"using quickSort or mergeSort\"," << endl;
    cout << "this program still uses these two methods respectively." << endl;
    cout << "Now enter the length of the array:";
    cin >> n;//length of the array
    cout << "Now enter the array, separating with space or newline:";
    arrQuick = new int[n + 1];
    arrMerge = new int[n];
    arrSub = new int[n];
    for (int i = 1; i <= n; ++i)
    {
        cin >> arrQuick[i];
        arrMerge[i - 1] = arrQuick[i];
    }

    quickSort(1, n);
    cout << "After using quickSort:" << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << arrQuick[i];
        if (i == n)
            cout << endl;
        else
            cout << " ";
    }

    mergeSort(0, n - 1);
    cout << "After using mergeSort:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arrMerge[i];
        if (i == n - 1)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}