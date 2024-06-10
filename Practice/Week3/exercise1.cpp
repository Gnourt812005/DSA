#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;

#define endl '\n'
#define pi pair <int, int> 
#define st first
#define nd second

typedef long long ll;
typedef unsigned long long ull;

int * genArr (int &n) {
    srand(time(0));
    n = 1000000;
    int *a = new int[n];
    for (int i = 0; i < n; i ++) 
        a[i] = rand() % 1000000000000;
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

void quickSort(int *a, int n) {
    queue <pi> q;
    q.push({0, n - 1});

    while (!q.empty()) {
        int left = q.front().st;
        int right = q.front().nd;
        q.pop();
        int l = left, r = right;
        int pivot = a[l + (r - l) / 2];
        while (l <= r) {
            while (a[l] < pivot) l++;
            while (a[r] > pivot) r--;
            if (l <= r) {
                swap(a[l], a[r]);
                l++;
                r--;
            }
        }
        if (left < r) q.push({left, r});
        if (l < right) q.push({l, right});
    }
}

void heapify (int *a, int n, int pos) {
    if (2 * pos + 1 >= n)
        return;
    int tmp = pos * 2 + 1;
    if (tmp + 1 < n && a[tmp] < a[tmp + 1])
        tmp ++;
    if (a[pos] < a[tmp]) {
        swap(a[pos], a[tmp]);
        heapify(a, n, tmp);
    }
}

void buildHeap(int * a, int n) {
    for (int i = n / 2 - 1; i >= 0; i --)
        heapify(a, n, i);
}

void heapSort(int * a, int n) {
    clock_t st = clock();
    buildHeap(a, n);
    clock_t end_time = clock();
    cout << (end_time - float(st))/CLOCKS_PER_SEC << endl << endl; 

    st = clock();
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
     end_time = clock();
    cout << (end_time - float(st))/CLOCKS_PER_SEC << endl << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    srand(time(NULL));
    int n;
    int *a = genArr(n);
    int *b = copyArr(a, n);

    clock_t start_time;
    clock_t end_time;
    start_time = clock();

    quickSort(a, n);
    end_time = clock();
    float qs_time = (end_time - float(start_time))/CLOCKS_PER_SEC; 
    cout << "Quick sort time: " << qs_time << endl;
    
    start_time = clock();
    heapSort(b, n);
    end_time = clock();
    float hs_time = (end_time - float(start_time))/CLOCKS_PER_SEC;
    cout << "Heap sort time: " << hs_time << endl;

    if (qs_time > hs_time) {
        cout << "The fastest algorithm: Heap Sort" << endl;
        cout << "The slowest algorithm: Quick Sort" << endl;
    } 
    else if (qs_time < hs_time) {
        cout << "The fastest algorithm: Quick Sort" << endl;
        cout << "The slowest algorithm: Heap Sort" << endl;
    } else 
        cout << "Both are equally fast" << endl;

    
    return 0;
}