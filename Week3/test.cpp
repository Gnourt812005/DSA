/**
    Ta Xuan Truong _ 23127506
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

#define pi pair <int, int>
#define st first
#define nd second
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int * genArr (int &n) {
    srand(time(0));
    n = 10;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        arr[i] = rand() % 500 - 200;
    return arr;
}

void printArr(int *a, int n) {
    for (int i = 0; i < n; i++) 
        cout << a[i] << " "; 
    cout << endl;
}

void countRadixSort (int *a, int n, int digit) {
    int count[19];
    for (int i = 0; i < 19; i++) 
        count[i] = 0;
    for (int i = 0; i < n; i ++) {
        int tmp = abs((a[i] / digit) % 10);
        if (a[i] < 0)
            tmp = ~tmp + 1;
        count[tmp + 9] ++;
    }
    for (int i = 1; i < 19; i++)
        count[i] += count[i - 1];
    int res[n];
    for (int i = n - 1; i > -1; i--) {
        int tmp = abs((a[i] / digit) % 10);
        if (a[i] < 0)
            tmp = ~tmp + 1;
        res[count[tmp + 9] - 1] = a[i];
        count[tmp + 9] --;
    }
    for (int i = 0; i < n; i++) 
        a[i] = res[i];   
}

void radixSort (int *a, int n) {
    int max_value = a[0];
    for (int i = 1; i < n; i++) 
        if (a[i] > max_value)
            max_value = a[i];
    int digit = 1;
    while (max_value / digit > 0) {
        countRadixSort(a, n, digit);
        digit *= 10;
    }
}

using namespace std;

int main()
{
    int n;
    int *a = genArr(n);
    printArr(a, n);
    radixSort(a, n);
    printArr(a, n);
    
    return 0;
}