#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectNumber(int n);
void printPerfectNumber(int n);
// Kiem tra n co phai so hoan hao khong
bool isPerfectNumber(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum == n;
}

// In ra cac so hoan hao nho hon n
void printPerfectNumber(int n)
{
    if (isPerfectNumber(n))
    {
        cout << "N la so hoan hao" << endl;
    }else
    {
        cout << "N khong la so hoan hao" << endl;
    }
    cout << "Cac so hoan hao nho hon n: ";
    for (int i = 1; i < n; i++)
    {
        if (isPerfectNumber(i))
        {
            // In ra cac so hoan hao nho hon n
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    printPerfectNumber(n);
}
