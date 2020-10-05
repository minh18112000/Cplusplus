#include <iostream>
#include <cmath>
using namespace std;

// Chuyen doi nam duong lich thanh am lich theo can chi
void transfer(int year)
{
    const char *arrayCan[10] = {"canh", "tan", "nham", "quy", "giap", "at", "binh", "dinh", "mau", "ky"};
    const char *arrayChi[12] = {"than", "dau", "tuat", "hoi", "ty", "suu", "dan", "mao", "thin", "ty", "ngo", "mui"};
    int can = year % 10;
    int chi = year % 12;
    cout << arrayCan[can] << " " << arrayChi[chi];
}

int main()
{
    int year;
    cout << "Nhap nam: ";
    cin >> year;
    transfer(year);
}
