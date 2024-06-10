/**
    Ta Xuan Truong _ 23127506
*/

#include <iostream>
#include <stdlib.h>

#define pi pair <int, int>
#define st first
#define nd second
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int ** gen2DArr (int &m, int &n) {
    srand(time(0));
    m = rand() % 6 + 1;
    n = rand() % 6 + 1;
    
    int **arr = new int*[m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j ++) {
            arr[i][j] = rand() % 100;
        }
    }
    return arr;
}

int ** input2DArr(int &m, int &n) {
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    int **arr = new int *[m];
    for (int i = 0; i < m; i ++) {
        arr[i] = new int [n];
        for (int j = 0; j < n; j ++) 
            cin >> arr[i][j];
    }
    return arr;
}

void print2DArr (int **a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void fillSpiralOrder (int **dest, int m, int n, int *source) {
    int count = 0;
    int end_col_right = n - 1;
    int end_col_left = 0;
    int end_row_down = m - 1;
    int end_row_up = 0;
    int i, j;
    int pass = 0, num_element = m * n;
    
    if (m == n && (n % 2 == 1)) {
        dest[n / 2][n / 2] = source[n * n - 1];
        num_element --;
    }

    while (count < num_element) {
        i = pass; j = pass;
        for (j; j < end_col_right && count < num_element; j++) {
            dest[i][j] = source[count];
            count++;
        }
        
        for (i; i < end_row_down && count < num_element; i++) {
            dest[i][j] = source[count];
            count++;
        }
       
        for (j; j > end_col_left && count < num_element; j--) {
            dest[i][j] = source[count];
            count++;
        }
       
        for (i; i > end_row_up && count < num_element; i--) {
            dest[i][j] = source[count];
            count++;
        }
 
        end_col_right--;
        end_col_left++;
        end_row_down--;
        end_row_up++;
        pass ++;
    }
}

int* sortAndConvertTo1DArr (int ** a, int m, int n) {
    int *arr = new int[m * n];
    int count = 0;
    
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            arr[count++] = a[i][j];
    
    for (int i = 1; i < count; i ++) {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = tmp;
    }
    return arr;
}

int main()
{
    int m, n;

    //int **a = input2DArr(m, n);
    int **a = gen2DArr(m, n);
    int * b = sortAndConvertTo1DArr(a, m, n);
    
    print2DArr(a, m, n);
    cout << '\n';
    fillSpiralOrder(a, m, n, b);
    print2DArr(a, m, n);

    delete [] b;
    for (int i = 0; i < n; i ++)
        delete [] a[i];
    delete [] a;
    return 0;
}