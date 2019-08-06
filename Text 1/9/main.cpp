/**
 * create by Wang Haoen in 2019/7/25
 * student number: 3018216021
 */

#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 200 + 7;

int m, n, q;
ll A[maxn][maxn];//a matrix of size m * n
ll B[maxn][maxn];//a matrix of size n * q
ll ans[maxn][maxn];//a matrix of size m * q


int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);
    INIT(A, 0);//initialization
    INIT(B, 0);//initialization
    INIT(ans, 0);//initialization
    cout << "In this program, you can enter two matrices A and B, and the program will output their product." << endl;
    cout << "The size of matrix A should be m * n." << endl;
    cout << "The size of matrix B should be n * q." << endl;
    cout << "The size of matrix ans should be m * q." << endl;
    cout << "In order to facilitate reading data, the program needs you to enter the size of two matrices m, n, q." << endl;
    cout << "Now enter the size of the two matrices m, n and q:" << endl;
    cin >> m >> n >> q;
    cout << "Now enter matrix A, which is m * n in size:" << endl;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> A[i][j];
        }
    }
    cout << "Now enter matrix B, which is n * q in size:" << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= q; ++j)
        {
            cin >> B[i][j];
        }
    }
    //calculate matrix ans
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= q; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                ans[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "The result of multiplying matrix A by matrix B is:" << endl;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= q; ++j)
        {
            cout << ans[i][j];
            if (j == q)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}