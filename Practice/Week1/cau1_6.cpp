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

struct Stack {
    char *a;
    int n;
    Stack();
    ~Stack();
    void Push(char);
    void Pop();
    void Clear();
    bool Empty();
    char Top();
};

Stack::Stack() {
    a = nullptr;
    n = 0;
}

Stack::~Stack() {
    delete[] a;
}

void Stack::Clear() {
    delete[] a;
    a = nullptr;
    n = 0;
}

bool Stack::Empty() {
    if (n == 0) 
        return 1;
    else
        return 0;
}

void Stack::Push(char key) {
    char *temp = new char[n + 1];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i];
    }
    temp[n] = key;
    n ++;
    delete [] a;
    a = temp;
}

void Stack::Pop() {
    if (Empty()) {
        return;
    }
    char *temp = new char[n - 1];
    for (int i = 0; i < n - 1; i++) {
        temp[i] = a[i];
    }
    n --;
    delete [] a;
    a = temp;
}

char Stack::Top() {
    if (Empty()) {
        return 0;
    }
    return a[n - 1];
}

int main()
{
    Stack s;
    cout << "Enter 1 x: To push x to stack\n";
    cout << "Enter 2: To pop\n";
    cout << "Enter 3: To print top of stack\n";
    cout << "Enter 4: End the program\n\n";
    
    while (true) {
        int x;
        cin >> x;
        if (x == 1) { 
            cin.get();
            char tmp;
            cin >> tmp;
            s.Push(tmp);
        }
        else if (x == 2) {
            s.Pop();
        }
        else if (x == 3)
            cout << s.Top() << endl;
        else 
            break;
    }
    return 0;
}