#include <iostream>
#include <cmath>
using namespace std;

void cal(unsigned long n)
{
    unsigned long reverse = 0;
    int number = 0;
    //  Lay chu so cuoi cua n
    int last = n % 10;
    int sum = 0;
    int first;
    while (n > 0)
    {
        //  Lay chu so dau tien cua n
        first = n % 10;
        //  Tinh tong cac chu so cua n
        sum += first;
        //  Dao nguoc so n
        reverse = reverse * 10 + first;
        n /= 10;
        //  Tinh so cac chu so cua n
        number++;
    }
    cout << "So chu so cua n: " << number << endl;
    cout << "Chu so cuoi cung cua n: " << last << endl;
    cout << "Chu so dau tien cua n: " << first << endl;
    cout << "Tong cac chu cua n: " << sum << endl;
    cout << "So dao nguoc cua n: " << reverse << endl;
}

int main()
{
    unsigned long n;
    cout << "Nhap n: ";
    cin >> n;
    cal(n);
}
