/**
    Ta Xuan Truong _ 23127506
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <chrono>

#define pi pair <int, int>
#define st first
#define nd second
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int * genArr (int &n) {
    srand(time(0));
    n = rand() % 15 + 10;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        arr[i] = rand() % 1000 - 400;
    return arr;
}

void printArr (int * a, int n) {
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << '\n';
}

//B1
/*
    function SUMPOWER2 is better than another
    because time complexity of SUMPOWER2 only O(1)
    however SUMPOWER has time function: f(n) = n(n + 1) / 2
    -> O(n^2)   
*/
int POWER (int n) {
    int res = 1;
    for (int i = 0; i < n; i ++)
        res *= 2;
    return res;
}

int SUMPOWER (int n) {
    int res = 0;
    for (int i = 1; i <= n; i ++)
        res += POWER (i);
    return res;
}

int SUMPOWER2 (int n) {
    // base on operation + on binary notation
    return (1 << (n + 1)) - 2;
}

//B2
void printFibo1 (int n, int index = 1, ull first_num = 0, ull second_num = 1) {
    // if (n < 3) {
    //     return 1;
    // }
    // int c = printFibo1(n - 1) + printFibo1(n - 2);
    // return c;
    cout << second_num;
    if (index < n) {
        cout << " ";
        ull temp = first_num + second_num;
        first_num = second_num;
        second_num = temp;
        printFibo1(n, index + 1, first_num, second_num);
    }
}

void printFibo2 (int n) {
    ull a = 1, b = 1;
    int i = 3;
    cout << 1 << ' ' << 1 << ' ';
    while (i <= n) {
        i ++;
        ull c = a + b;
        cout << c << ' ';
        a = b;
        b = c;
    }
}

//B3
void maxSum1 (int *a, int n) {
    int max_sum = a[0];
    int start_pos = 0;
    int end_pos = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i; j < n; j ++) {
            int cur_sum = 0;
            for (int k = i; k <= j; k ++) 
                cur_sum += a[k];
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                start_pos = i;
                end_pos = j;
            } 
        }
    }
    // for (int i = start_pos; i <= end_pos; i ++)
    //     cout << a[i] << " ";
    // cout << '\n';
} 

void maxSum2 (int *a, int n) {
    int *temp = new int [n + 1];
    temp[0] = 0;
    for (int i = 1; i <= n; i ++)
        temp[i] = a[i - 1] + temp[i - 1];

    int max_sum = temp[1];
    int start_pos = 0;
    int end_pos = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            int cur_sum = temp[j] - temp[i - 1];
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                start_pos = i - 1;
                end_pos = j - 1;
            }
        }
    }

    // for (int i = start_pos; i <= end_pos; i ++)
    //     cout << a[i] << " ";
    // cout << '\n';
    delete [] temp;
} 

void maxSum3 (int *a, int n) {
    int max_sum = a[0];
    int cur_sum = a[0];
    int start_pos = 0;
    int end_pos = 0;
    int temp_start = 0;
    for (int i = 1; i < n; i ++) {
        if (cur_sum < 0) {
            cur_sum = a[i];
            temp_start = i;
        } 
        else {
            cur_sum += a[i];
        }
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
            start_pos = temp_start;
            end_pos = i;
        }
    }
    // for (int i = start_pos; i <= end_pos; i ++)
    //     cout << a[i] << " ";
    // cout << '\n';
}

//B4
void stimualteHydra () {
    string line;
    getline(cin, line);
    queue <string> q;
    q.push(line);
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        cout << cur << "\n";
        cur.erase(0, 1);
        if (cur.size() != 0) {
            q.push(cur);
            q.push(cur);
        }
    }
}

int main()
{
    //B2
    int n;
    cin >> n; 
    printFibo1(n);
    cout << endl;
    printFibo2(n);

    // B3
    // int n;
    // int *a;
    // a = genArr(n);
    // clock_t st = clock();
    // maxSum1(a, n); 
    // clock_t nd = clock();
    // cout << ((float)nd - st)/CLOCKS_PER_SEC << '\n';

    
    // st = clock();
    // maxSum2(a, n); 
    // nd = clock();
    // cout << ((float)nd - st)/CLOCKS_PER_SEC << '\n'; 
    
    // st = clock();
    // maxSum3(a, n); 
    // nd = clock();
    // cout << ((float)nd - st)/CLOCKS_PER_SEC << '\n'; 

    // delete [] a;
    //
    
    //B4
    //stimualteHydra();
    return 0;
}