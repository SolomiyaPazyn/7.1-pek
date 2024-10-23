#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Function to create matrix recursively
void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High, int i = 0, int j = 0) {
    if (i < rowCount) {
        if (j < colCount) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, rowCount, colCount, Low, High, i, j + 1);
        }
        else {
            Create(a, rowCount, colCount, Low, High, i + 1, 0);
        }
    }
}

// Function to print matrix recursively
void Print(int** a, const int rowCount, const int colCount, int i = 0, int j = 0) {
    if (i < rowCount) {
        if (j < colCount) {
            cout << setw(4) << a[i][j];
            Print(a, rowCount, colCount, i, j + 1);
        }
        else {
            cout << endl;
            Print(a, rowCount, colCount, i + 1, 0);
        }
    }
    else if (i == rowCount && j == 0)
        cout << endl;
}

// Function to swap rows
void Change(int** a, const int row1, const int row2, const int colCount, int j = 0) {
    if (j < colCount) {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
        Change(a, row1, row2, colCount, j + 1);
    }
}

// Sort function according to the three-column rule
void Sort(int** a, const int rowCount, const int colCount, int i0 = 0, int i1 = 0) {
    if (i0 < rowCount - 1) {
        if (i1 < rowCount - i0 - 1) {
            if ((a[i1][0] > a[i1 + 1][0]) ||
                (a[i1][0] == a[i1 + 1][0] &&
                    a[i1][1] > a[i1 + 1][1]) ||
                (a[i1][0] == a[i1 + 1][0] &&
                    a[i1][1] == a[i1 + 1][1] &&
                    a[i1][2] > a[i1 + 1][2]))
                Change(a, i1, i1 + 1, colCount);
            Sort(a, rowCount, colCount, i0, i1 + 1);
        }
        else
            Sort(a, rowCount, colCount, i0 + 1, 0);
    }
}

// Calculate sum and count of negative elements not multiples of 4
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0) {
    if (i == 0 && j == 0) {
        S = 0;
        k = 0;
    }

    if (i < rowCount) {
        if (j < colCount) {
            if (a[i][j] < 0 && a[i][j] % 4 != 0) {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
            Calc(a, rowCount, colCount, S, k, i, j + 1);
        }
        else {
            Calc(a, rowCount, colCount, S, k, i + 1, 0);
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 14;
    int rowCount = 8;
    int colCount = 5;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    cout << "Original matrix:" << endl;
    Print(a, rowCount, colCount);

    Sort(a, rowCount, colCount);
    cout << "Sorted matrix:" << endl;
    Print(a, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k);

    cout << "Modified matrix (negative elements not multiples of 4 replaced with 0):" << endl;
    Print(a, rowCount, colCount);
    cout << "S = " << S << " (sum of negative elements not multiples of 4)" << endl;
    cout << "k = " << k << " (count of negative elements not multiples of 4)" << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}