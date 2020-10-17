#include <iostream>
using namespace std;

// Hàm in ra các số nguyên tố <= n
void printPrimes(int n)
{
    int a[n - 1];
    int index = 0;
    // Thêm vào mảng các số tự nhiên từ 2 đến n
    for (int i = 2; i <= n; i++)
    {
        a[index] = i;
        index++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        // Những số có giá trị = -1 sẽ bỏ qua
        if (a[i] == -1)
        {
            continue;
        }
        else
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                if (a[j] % a[i] == 0)
                {
                    // Những số bị gạch sẽ được gán = -1
                    a[j] = -1;
                }
            }
        }
    }
    cout << "So nguyen to nho hon " << n << ": ";
    for (int i = 0; i < n - 1; i++)
    {
        // In ra các số không bị gạch
        if (a[i] != -1)
        {
            cout << a[i] << " ";
        }
    }
}

int main()
{
    int n;
    do
    {
        cout << "Nhap+ n < 100: ";
        cin >> n;
    } while (n >= 100);
    printPrimes(n);
}
