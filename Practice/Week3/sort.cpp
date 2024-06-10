#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define FOR(i,a,b) for(int i = a ; i < b ;i ++)
#define _FOR(i,a,b) for(int i = a ; i >= b ;i --)
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
    FOR(i, 0, n) 
        a[i] = rand() % 100000 + 1000000000;
    
    return a;
}

int * copyArr (int * source, int n) {
    int * dest = new int[n];
    FOR(i, 0, n)
        dest[i] = source[i];
    return dest;
}

void printArr (int *a, int n) {
    FOR(i, 0, n) 
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

// void mergeFunction(int *a, int start1, int mid, int end) {
//     int start2 = mid + 1;
//     if (a[mid] <= a[start2]) return;
//     while (start1 <= mid && start2 <= end) {
//         if (a[start1] <= a[start2])
//             start1 ++;
//         else {
//             int value = a[start2];
//             for (int i = start2; i != start1; i --)
//                 a[i] = a[i - 1];
//             a[start1] = value;
//             start1 ++;
//             mid ++;
//             start2 ++;
//         }
//     }
// }

// left là vị trí bắt, right là vị trí kết thúc của vùng đang xét
void mergeSort (int *a, int left, int right) {
    // Base case: left = right
    if (left == right)
        return;
    int mid = left + (right - left) / 2;
    // left -> mid va mid + 1 -> right in order
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    // sắp xếp lại vị trí
    // mảng phụ có độ dài bằng vùng đang xét
    int *tmp = new int [right - left + 1];
    // i đại diện cho vị trí đang xét của nửa bên trái
    // j đại diện cho vị trí đang xét của nửa bên phải
    // i           j 
    // 1 2 3 4 5 | 8 19 26 72
    int i = left, j = mid + 1, k = 0;
    while (i <= mid || j <= right) {
        if (i > mid)
            tmp[k++] = a[j++];
        else if (j > right)
            tmp[k++] = a[i++];
        else if (a[i] < a[j]) 
            tmp[k++] = a[i++];
        else 
            tmp[k++] = a[j++];
    }
    
    for (i = left; i <= right; i ++)
        a[i] = tmp[i - left];
    delete [] tmp;
}

void heapify (int *a, int n, int pos) {
    if (2 * pos + 1 >= n)
        return;
    int tmp = pos * 2 + 1;
    if (tmp + 1 < n && a[tmp] > a[tmp + 1])
        tmp ++;
    if (a[pos] > a[tmp]) {
        swap(a[pos], a[tmp]);
        heapify(a, n, tmp);
    }
}

void buildHeap(int * a, int n) {
    for (int i = n / 2 - 1; i >= 0; i --)
        heapify(a, n, i);
}

void sortHeap(int * a, int n) {
    buildHeap(a, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void countSort (int * & a, int n) {
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
    for (int i = n - 1; i >= 0; i--)
        output[count[a[i]] - 1] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = output[i];

    delete[] count;
    delete[] output;
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
    quickSort(a, n);
    cout << "Quick sort time: " << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl << endl;
    
    start_time = clock();
    mergeSort(b, 0, n - 1);
    cout << "Merge sort time: " << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl << endl;

    start_time = clock();
    countSort(c, n);
    cout << "Count sort time: " << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl << endl;
    
    return 0;
}