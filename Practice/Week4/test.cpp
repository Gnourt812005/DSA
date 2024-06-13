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

int hashFunction (int key) {
    return key % 10;
}

void insertHash (int *a, int n, int key) {
    int index = hashFunction(key);
    a[index] = key;
}

int main()
{
    
    return 0;
}