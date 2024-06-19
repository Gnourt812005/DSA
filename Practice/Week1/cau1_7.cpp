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

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Queue {
    int *a;
    int n;
    Queue();
    ~Queue();
    void Enqueue(int);
    void Dequeue();
    void Clear();
    bool Empty();
    int Front();
};

Queue::Queue() {
    a = nullptr;
    n = 0;
}

Queue::~Queue() {
    delete[] a;
}

void Queue::Clear() {
    delete[] a;
    a = nullptr;
    n = 0;
}

bool Queue::Empty() {
    if (n == 0) 
        return 1;
    else
        return 0;
}

void Queue::Enqueue(int key) {
    int *temp = new int[n + 1];
    for (int i = 0; i < n; i++) {
        temp[i + 1] = a[i];
    }
    temp[0] = key;
    n ++;
    delete [] a;
    a = temp;
}

void Queue::Dequeue() {
    if (Empty()) {
        return;
    }
    int *temp = new int[n - 1];
    for (int i = 0; i < n - 1; i++) {
        temp[i] = a[i];
    }
    n --;
    delete [] a;
    a = temp;
}

int Queue::Front() {
    if (Empty()) {
        return 1e9;
    }
    return a[n - 1];
}

int main()
{
    Queue s;
    cout << "Enter 1 x: To enqueue x to queue\n";
    cout << "Enter 2: To dequeue\n";
    cout << "Enter 3: To print front of queue\n";
    cout << "Enter 4: End the program\n\n";
    while (true) {
        int x;
        cin >> x;
        if (x == 1) { 
            cin >> x;
            s.Enqueue(x);
        }
        else if (x == 2) {
            s.Dequeue();
        }
        else if (x == 3)
            cout << s.Front() << endl;
        else 
            break;
    }
    return 0;
}