/**
 * create by Wang Haoen in 2019/7/25
 * student number: 3018216021
 */

#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 10000 + 7;

string binaryNumber;//using string save the binary number
int lenBin;//length of the binary number, not bigger than 64
ll decimalNumber;//the decimal number
ll base;//pow of 2

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cout << "In this program, you can enter several binary strings, it will convert them to several decimal integers." << endl;
    cout << "Please note that the string length should be within 64 bits, otherwise \"The string is too long.\" will be output." << endl;
    cout << "The binary string should be represented by the complement, that is, the highest bit represents its symbol." << endl;
    cout << "A positive number should start with \"0\" and a negative number should start with \"1\"." << endl;
    cout << "Therefore, the length of the string should be at least 2, for example, a positive number \"1\" should be entered as \"01\"." << endl;
    while (true)
    {
        cout << "Now enter the binary string, or enter \"END\" to terminate the program:" << endl;
        cin >> binaryNumber;//enter the binary string
        if (binaryNumber == "END")//end the program
        {
            break;
        }
        lenBin = binaryNumber.length();//get the length of the binary string
        if (lenBin > 64)//long long max
        {
            cout << "The string is too long." << endl;
        }
        else if (lenBin == 1)
        {
            cout << "Invalid input." << endl;
        }
        else
        {
            decimalNumber = 0ll;
            base = 1ll;
            if (binaryNumber[0] == '1')//negative number
            {
                for (int i = lenBin - 1; i >= 1 ; --i)
                {
                    if (binaryNumber[i] == '1')
                    {
                        binaryNumber[i] = '0';
                        break;
                    }
                    else
                    {
                        binaryNumber[i] = '1';
                    }
                }

                for (int i = 1; i < lenBin; ++i)
                {
                    if (binaryNumber[i] == '0')
                        binaryNumber[i] = '1';
                    else
                        binaryNumber[i] = '0';
                }
            }

            for (int i = lenBin - 1; i >= 1; --i)
            {
                if (binaryNumber[i] == '1')
                {
                    decimalNumber += base;
                }
                base <<= 1;
            }
            if (binaryNumber[0] == '1')
            {
                decimalNumber *= -1;
            }
            cout << "The corresponding decimal integer is:";
            cout << decimalNumber << endl;
        }
    }
    return 0;
}