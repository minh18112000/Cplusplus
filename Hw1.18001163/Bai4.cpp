#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeNumber(int n);
void printPrimeNumber(int n);
void printNFirstPrimeNumber(int n);
void divTwoPrimeNumber(int n);
bool isDivThreePrimeNumber(int n);
void isGoldBach();

// Kiem tra n co phai so nguyen to khong
bool isPrimeNumber(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// In ra so nguyen to gan n nhat va be hon n
void printPrimeNumber(int n)
{
    if (isPrimeNumber(n))
    {
        cout << "n la so nguyen to" << endl;
    }
    else
    {
        cout << "n khong la so nguyen to" << endl;
        for (int i = n - 1; i >= 2; i--)
        {
            if (isPrimeNumber(i))
            {
                cout << "So nguyen to gan n nhat la: " << i << endl;
                break;
            }
        }
    }
}

// In ra n so nguyen to dau tien
void printNFirstPrimeNumber(int n)
{
    int number = 1;
    int i = 2;
    cout << "n so nguyen to dau tien: ";
    while (number <= n)
    {
        if (isPrimeNumber(i))
        {
            number++;
            cout << i << " ";
        }
        i++;
    }
    cout << "" << endl;
}

// Tach n thanh tong 2 so nguyen to
void divTwoPrimeNumber(int n)
{
    cout << "Cac cap so nguyen to duoc tach tu n: " << endl;
    for (int i = 2; i < n / 2; i++)
    {
        if (isPrimeNumber(i) && isPrimeNumber(n - i))
        {
            cout << i << " " << n - i << endl;
        }
    }
}

// Kiem tra 1 so co tach duoc thanh 3 so nguyen to khong
bool isDivThreePrimeNumber(int n)
{
    bool isDivThreePrime = false;
    for (int i = 2; i < n / 2; i++)
    {
        if (isPrimeNumber(i))
        {
            for (int j = i; j < n - i; j++)
            {
                if (isPrimeNumber(j))
                {
                    for (int k = j; k < n - 1; k++)
                    {
                        if (isPrimeNumber(k) && n == k + i + j)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return isDivThreePrime;
}

// Gia thuyet Goldbach
void isGoldBach()
{
    bool isGoldBachNumber = true;
    for (int i = 6; i < 1000; i++)
    {
        if (isPrimeNumber(i))
        {
            if (!isDivThreePrimeNumber(i))
            {
                isGoldBachNumber = false;
                cout << "Gia thuyet Goldbach sai!";
                break;
            }
        }
    }
    if (isGoldBachNumber)
    {
        cout << "Gia thuyet Goldbach dung!";
    }
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    printPrimeNumber(n);
    printNFirstPrimeNumber(n);
    divTwoPrimeNumber(n);
    isGoldBach();
}
