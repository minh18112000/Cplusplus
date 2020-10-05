#include <iostream>
#include <cmath>
using namespace std;

void cal(int n)
{
    int tol = 0;
    int sum = 0;
    cout << "Cac uoc cua n: ";
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            // In ra cac uoc cua n
            cout << i << " ";
            // Tinh so uoc cua n
            tol++;
            // Tinh tong cac uoc cua n
            sum += i;
        }
    }
    cout << endl;
    cout << "So uoc cua n: " << tol << endl;
    cout << "Tong so uoc cua n: " << sum << endl;
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cal(n);
}
