#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

const int MAX_SIZE = 10;

void sortColumns(int n, int a[][MAX_SIZE]);
void transposeMatrix(int n, int a[][MAX_SIZE]);
void duongCheoSongSong(int n, int a[][MAX_SIZE]);
void diemYenNgua(int n, int a[][MAX_SIZE]);
int maxColumn(int j, int n, int a[][MAX_SIZE]);
int minRow(int i, int n, int a[][MAX_SIZE]);
void printMatrix(int n, int a[][MAX_SIZE]);

// In ma trận chuyển vị
void transposeMatrix(int n, int a[][MAX_SIZE])
{
    cout << "Ma tran chuyen vi:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[j][i] << "\t";
        }
        cout << endl;
    }
}

// Sắp xếp các cột theo thứ tự tổng các cột tăng dần
void sortColumns(int n, int a[][MAX_SIZE])
{
    // Khởi tạo mảng mới giống mảng a
    int array[MAX_SIZE][MAX_SIZE] = {};
    // Khởi tạo mảng lưu giá trị tổng các cột
    int sumColumns[n] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Gán giá trị mảng a vào mảng aray
            array[i][j] = *(*(a + i) + j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Gán giá trị tổng vào mảng
            sumColumns[i] += array[j][i];
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Kiểm tra giá trị tổng của cột để đổi chỗ
            if (sumColumns[i] > sumColumns[j])
            {
                for (int k = 0; k < n; k++)
                {
                    // Đổi chỗ giá trị tổng các cột
                    int temp1 = sumColumns[i];
                    sumColumns[i] = sumColumns[j];
                    sumColumns[j] = temp1;

                    // Đổi chỗ các phần tử của 2 cột
                    int temp = array[k][j];
                    array[k][j] = array[k][i];
                    array[k][i] = temp;
                }
            }
        }
    }
    cout << "Ma tran sau khi sap xep cac hang:" << endl;
    printMatrix(n, array);
}

// In ma trận
void printMatrix(int n, int a[][MAX_SIZE])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

// Tìm và in các đường chéo // với đường chéo phụ
void duongCheoSongSong(int n, int a[][MAX_SIZE])
{
    int count = 1;
    int i = 0;
    cout << "Cac duong cheo // duong cheo phu: " << endl;
    for (int j = 1; j < n - 1; j++)
    {
        if (i + j == count)
        {
            int k = j;
            while (i < n - 1 && k >= 0)
            {
                cout << a[i][k] << " ";
                i++;
                k--;
            }
        }
        i = 0;
        if (count == n - 2)
        {
            count += 2;
        }
        else
        {
            count++;
        }
        cout << endl;
    }
    i = n - 1;
    count = n;
    for (int j = 1; j < n - 1; j++)
    {
        if (i + j == count)
        {
            int k = j;
            while (i >= 1 && k <= n - 1)
            {
                cout << a[i][k] << " ";
                i--;
                k++;
            }
        }
        i = n - 1;
        count++;
        cout << endl;
    }
}

// Tìm phần tử max của cột
int maxColumn(int j, int n, int a[][MAX_SIZE])
{
    int max = numeric_limits<int>::min();
    for (int i = 0; i < n; i++)
    {
        if (a[i][j] > max)
        {
            max = a[i][j];
        }
    }
    return max;
}

// Tìm phần tử min của hàng
int minRow(int i, int n, int a[][MAX_SIZE])
{
    int min = numeric_limits<int>::max();
    for (int j = 0; j < n; j++)
    {
        if (a[i][j] < min)
        {
            min = a[i][j];
        }
    }
    return min;
}

// Tìm điểm yên ngựa của ma trận
void diemYenNgua(int n, int a[][MAX_SIZE])
{
    int count = 0;
    cout << "Diem yen ngua: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Kiểm tra 1 phần tử có là max của cột và min của hàng không
            if (a[i][j] == maxColumn(j, n, a) && a[i][j] == minRow(i, n, a))
            {
                cout << a[i][j] << " ";
                count++;
            }
        }
    }
    if (count == 0)
        cout << "Khong co";
    cout << endl;
}
int main()
{
    int n;
    char option;
    cout << "Nhap kich thuoc cua ma tran n x n: ";
    cin >> n;
    int a[MAX_SIZE][MAX_SIZE];
    // Nếu kích thước <= 3 thì tự nhập ma trận
    if (n <= 3)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
    }
    // Nếu kích thước > 3 thì sinh ma trận ngẫu nhiênf
    else
    {
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = rand() % 201 - 100;
            }
        }
    }
    cout << "Ma tran vua nhap la: " << endl;
    printMatrix(n, a);
    cout << endl;
    do
    {
        cout << "Menu: " << endl;
        cout << "b. In ma tran chuyen vi." << endl;
        cout << "c. Sap xep cac cot va in ma tran." << endl;
        cout << "d. In tat ca duong cheo song song." << endl;
        cout << "e. Tim diem yen ngua cua ma tran." << endl;
        cout << "f. Thuc hien tat ca cac y cua bai." << endl;
        cout << "q. Quit" << endl;
        cout << "Ban chon: ";
        cin >> option;
        switch (option)
        {
        case 'b':
            transposeMatrix(n, a);
            break;
        case 'c':
            sortColumns(n, a);
            break;
        case 'd':
            duongCheoSongSong(n, a);
            break;
        case 'e':
            diemYenNgua(n, a);
            break;
        case 'f':
            cout << "Ma tran vua nhap la: " << endl;
            printMatrix(n, a);
            transposeMatrix(n, a);
            duongCheoSongSong(n, a);
            diemYenNgua(n, a);
            sortColumns(n, a);
            break;
        case 'q':
            cout << "Ban da thoat chuong trinh" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai" << endl;
            break;
        }
        cout << "===============================================" << endl;
    } while (option != 'q');
}
