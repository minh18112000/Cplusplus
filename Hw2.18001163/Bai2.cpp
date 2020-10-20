#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <limits>
using namespace std;

void avgOddNegativeInt(int a[], int n);
void removeElement(int a[], int n);

// Hàm tính trung bình cộng các số nguyên âm lẻ
void avgOddNegativeInt(int a[], int n)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // Kiểm tra có phải số nguyên âm lẻ không
        if (a[i] < 0 && a[i] % 2 != 0)
        {
            sum += a[i];
            count++;
        }
    }
    // Kiểm tra mảng có số nguyên âm lẻ không
    if (count == 0)
        cout << "Khong co so le trong day" << endl;
    else
        cout << "Trung binh cong cua cac so nguyen am le: " << (float)sum / count << endl;
}

// Hàm xóa các phần tử trùng nhau trong dãy
void removeElement(int a[], int n)
{
    list<int> arrayList;
    int count;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != numeric_limits<int>::max())
        {
            int curElement = a[i];
            for (int j = i + 1; j < n; j++)
            {
                // Kiểm tra các phần tử giống phần tử hiện tai đang xét
                if (a[j] == curElement)
                {
                    a[j] = numeric_limits<int>::max();
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != numeric_limits<int>::max())
        {
            arrayList.push_back(a[i]);
        }
    }
    cout << "Mang sau khi xoa het cac phan tu trung nhau: ";
    for (auto element : arrayList)
    {
        cout << element << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    char option;
    cout << "Nhap n phan tu cua day: ";
    cin >> n;
    int a[n];
    if (n < 10)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 201 - 100;
        }
    }
    cout << "Day vua nhap la: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    do
    {
        cout << "Menu: " << endl;
        cout << "b. Tinh trung binh cong cua cac so nguyen am le trong day." << endl;
        cout << "c. Xoa cac phan tu co gia tri trung nhau trong day." << endl;
        cout << "f. Chay tat ca cac y cua bai" << endl;
        cout << "e. Exit" << endl;
        // Ý d trùng với ý c
        cout << "Ban chon: ";
        cin >> option;
        switch (option)
        {
        case 'b':
            avgOddNegativeInt(a, n);
            break;
        case 'c':
            removeElement(a, n);
            break;
        case 'f':
            avgOddNegativeInt(a, n);
            removeElement(a, n);
            break;
        case 'e':
            cout << "Ban da thoat chuong trinh" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai" << endl;
            break;
        }
        cout << "===============================================" << endl;
    } while (option != 'e');
}
