#include <conio.h>
#include <iostream>
#include <math.h>
using namespace std;

struct DaThuc
{
    int n;
    float *a;
};

void input(DaThuc &A);
void multi(DaThuc P, DaThuc Q, DaThuc &R);
void print(DaThuc A);

// Hàm nhập đa thức
void input(DaThuc &A)
{
    cin >> A.n;
    A.a = new float[A.n + 1];
    for (int i = 0; i <= A.n; i++)
    {
        cout << "He so cua x^" << i << " : ";
        cin >> A.a[i];
    }
    cout << endl;
}

// Nhân 2 đa thức với nhau
void multi(DaThuc P, DaThuc Q, DaThuc &R)
{
    R.n = P.n + Q.n;
    R.a = new float[R.n + 1];
    for (int i = 0; i <= R.n; i++)
    {
        R.a[i] = 0;
        for (int j = 0; j <= P.n; j++)
        {

            if (i >= j && i - j <= Q.n)
            {
                R.a[i] += P.a[j] * Q.a[i - j];
            }
        }
    }
}

// Hàm in đa thức
void print(DaThuc A)
{
    cout << A.a[0];
    for (int i = 1; i <= A.n; i++)
    {
        if (A.a[i] >= 0)
            cout << "+";
        cout << A.a[i];
        cout << "*x^" << i;
    }
    cout << endl;
}

// Tính giá trị của đa thức tại x =
float cal(float x, DaThuc A)
{
    float result = A.a[0];
    for (int i = 1; i <= A.n; i++)
    {
        result += A.a[i] * pow(x, i);
    }
    return result;
}

int main()
{
    DaThuc P, Q, R, S;
    float x;
    cout << "Nhap da thuc P(x)" << endl;
    cout << "Nhap bac cua da thuc P(x): ";
    input(P);
    cout << "Nhap da thuc Q(x)" << endl;
    cout << "Nhap bac cua da thuc Q(x): ";
    input(Q);
    cout << "Da thuc P(x) = ";
    print(P);
    cout << "Da thuc Q(x) = ";
    print(Q);
    multi(P, Q, S);
    cout << "Da thuc S(x) = P(x)*Q(x) = ";
    print(S);
    cout << "Nhap tham so x de tinh: ";
    cin >> x;
    cout << "Gia tri da thuc khi x = " << x << " la: " << cal(x, S);
}