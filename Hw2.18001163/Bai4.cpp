#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int MAX_SIZE = 50;
int strlen(string str);
string strcpy(string strDes, string strSrc);
string strcat(string strDes, string strSrc);

// Tính độ dài của 1 chuỗi
int strlen(string str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}

// Copy 1 chuỗi vào 1 chuỗi khác
string strcpy(string strDes, string strSrc)
{
    int index = 0;
    while (strSrc[index] != '\0')
    {
        strDes.push_back(strSrc[index]);
        index++;
    }
    return strDes;
}

// Nối 2 chuỗi với nhau
string strcat(string strDes, string strSrc)
{
    int index = 0;
    int lStrDes = strlen(strDes);
    while (strSrc[index] != '\0')
    {
        strDes.push_back(strSrc[index]);
        index++;
        lStrDes++;
    }
    return strDes;
}
int main()
{
    string str1 = "the quick brown fox ";
    string str2 = "jumps over the lazy dog";
    string buf;
    cout << "Kich thuoc cua chuoi "
         << "\"" << str1 << "\""
         << " la: ";
    cout << strlen(str1) << endl;
    cout << "Kich thuoc cua chuoi "
         << "\"" << str2 << "\""
         << " la: ";
    cout << strlen(str2);
    cout << endl;
    cout << "Chuoi "
         << "\"" << buf << "\""
         << " sau khi duoc sao chep tu chuoi "
         << "\"" << str1 << "\""
         << " la: ";
    cout << "\"" << strcpy(buf, str1) << "\"";
    cout << endl;
    buf = strcpy(buf, str1);
    cout << "Chuoi "
         << "\"" << buf << "\""
         << " khi duoc ghep them chuoi "
         << "\"" << str2 << "\""
         << " la: ";
    cout << "\"" << strcat(buf, str2) << "\"" << endl;
    buf = strcat(buf, str2);
    cout << "Kich thuoc cua chuoi "
         << "\"" << buf << "\""
         << " la: ";
    cout << strlen(buf) << endl;
}
