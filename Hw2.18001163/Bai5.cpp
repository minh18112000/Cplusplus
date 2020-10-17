#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAX_SIZE = 50;
string zip(string str);
string unZip(string str);

string zip(string str)
{
    int size = str.length();
    string strZip = "";
    char curChar;
    int count;
    for (int i = 0; i < size; i++)
    {
        curChar = str[i];
        count = 1;
        for (int j = i + 1; j <= size; j++)
        {
            if (str[j] == curChar)
            {
                count++;
            }
            else
            {
                if (count != 1)
                {
                    strZip.push_back(count + '0');
                }
                strZip.push_back(curChar);
                i = j - 1;
                break;
            }
        }
    }
    return strZip;
}

string unZip(string str)
{
    int size = str.length();
    string strUnZip = "";
    char curChar;
    for (int i = 0; i < size; i++)
    {
        curChar = str[i];

        if (isdigit(curChar))
        {
            int num = curChar - '0';
            for (int k = 0; k < num; k++)
            {
                strUnZip.push_back(str[i + 1]);
            }
            i++;
        }
        else
        {
            strUnZip.push_back(str[i]);
        }
    }
    return strUnZip;
}

int main()
{
    string str = "aaabccccddddeeeeeeeeefghhhhhhiiiiaaaabbbbbbccdee";
    cout << "Chuoi ban dau la: " << str << endl;
    cout << "Chuoi sau khi duoc nen la: ";
    cout << zip(str) << endl;
    cout << "Chuoi sau khi duoc giai nen la: ";
    cout << unZip(zip(str)) << endl;
    return 0;
}
