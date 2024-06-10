#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

#define endl '\n'
#define pi pair <int, int> 
#define st first
#define nd second
#define INF 1e9 + 7

typedef long long ll;
typedef unsigned long long ull;

int * genArr (int &n) {
    srand(time(0));
    n = 1000000;
    int *a = new int[n];
    for (int i = 0; i < n; i ++) 
        a[i] = rand() % 100000000 + 2000000;
    return a;
}

int * copyArr (int * source, int n) {
    int * dest = new int[n];
    for (int i = 0; i < n; i ++) 
        dest[i] = source[i];
    return dest;
}

void printArr (int *a, int n) {
    for (int i = 0; i < n; i ++)  
        cout << a[i] << " ";
    cout << endl;
}

//Merge sort
void mergeSort (int *a, int left, int right) {
    if (left == right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    int *tmp = new int [right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while (i <= mid || j <= right) {
        if (i > mid) {
            tmp[k] = a[j];
            k++; j++;
        }
        else if (j > right) {
            tmp[k] = a[i];
            k++; i++;
        }
        else if (a[i] < a[j]) { 
            tmp[k] = a[i];
            k++; i++;
        }
        else {
            tmp[k] = a[j];
            k++; j++;
        }
    }
    
    for (i = left; i <= right; i ++)
        a[i] = tmp[i - left];
    delete [] tmp;
}

//Count sort
void countSort (int * a, int n) {
    int max_value = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max_value)
            max_value = a[i];

    int *count = new int[max_value + 1];
    for (int i = 0; i <= max_value; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[a[i]]++;

    for (int i = 1; i <= max_value; i++)
        count[i] += count[i - 1];

    int *output = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];

    delete[] count;
    delete[] output;
}

// Radix sort
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    srand(time(NULL));
    int n;
    int *a = genArr(n);
    int *b = copyArr(a, n);
    int *c = copyArr(a, n);

    clock_t start_time;
    
    start_time = clock();
    radixSort(a, n);
    cout << "Radix sort time: " << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl << endl;

    start_time = clock();
    mergeSort(b, 0, n - 1);
    cout << "Merge sort time: " << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl << endl;

    start_time = clock();
    countSort(c, n);
    cout << "Count sort time: " << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl << endl;
    
    return 0;
}