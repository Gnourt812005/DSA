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

int linearSearch (int *a, int n, int k) {
    for (int i = 0; i < n; i++) 
        if (a[i] == k) return i;
    return -1;
} 

int linearSearchWithSentinal (int *a, int n, int k) {
    a[n] = k;
    int i = 0;
    while (a[i] != k)
        i++;
    if (i == n)
        return -1;
    return i;
}

int binarySearch (int *a, int n, int k) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == k) return mid;
        if (a[mid] < k) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void inputData (char *fileName, int *&a, int &n) {
    ifstream file(fileName);
    file >> n;
    a = new int [n];
    for (int i = 0; i < n; i++) 
        file >> a[i]; 
    file.close();
}

void outputData (char *fileName, int data) {
    ofstream file(fileName);
    file << data;
    file.close();
}

int main(int argc, char *argv[])
{
    int *a, n;
    inputData(argv[3], a, n);
    
    char t = argv[1][0];
    int key = atoi(argv[2]); 
    int pos;
    switch (t)
    {
    case '1':
        pos = linearSearch(a, n, key);
        break;
    case '2':
        pos = linearSearchWithSentinal(a, n, key);
        break;
    case '3':
        pos = binarySearch(a, n, key);
        break;
    default:
        break;
    }

    outputData (argv[4], pos);
    return 0;
}