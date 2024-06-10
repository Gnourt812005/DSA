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
    n = 100000;//rand() % 15 + 10;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        arr[i] = rand() %  100;
    return arr;
}

void printArr (int *a, int n) {
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl;
}

string * genArrString (int &n) {
    srand(time(0));
    n = rand() % 15 + 10;
    string *arr = new string[n];
    for (int i = 0; i < n; i++) { 
        char t = rand() % 26 + 65;
        arr[i] = t;
        t = rand() % 26 + 65;
        arr[i] += t;
        t = rand() % 26 + 65;
        arr[i] += t;
        
    }
    return arr;
}

//B1
struct Node {
    int data;
    Node* next;
};

Node * createNode(int key) {
    Node * res = new Node();
    res->data = key;
    res->next = nullptr;
    return res;
}   

void printNode (Node * head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void linkedListSort (int *a, int n) {
    Node* head = createNode(a[0]);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        Node* cur = createNode(a[i]);
        Node* tmp = head;
        while (tmp != nullptr && tmp->data < cur->data)
            tmp = tmp->next;
        if (tmp == nullptr) {
            tail->next = cur;
            tail = cur;
        }
        else if (tmp == head) {
            cur->next = head;
            head = cur;
        }
        else {
            swap(*(tmp), *(cur));
            tmp->next = cur;
            if (tmp == tail)
                tail = tmp->next;
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = head->data;
        Node * tmp = head;
        head = head->next;
        delete tmp;
    }
}

//B3
int countInversions (int *a, int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        int tmp = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[tmp])
                count ++;
        }
    }
    return count;
}

//B4
void quickSort (string *a, int n) {
    queue <pi> line;
    line.push(pi(0, n - 1));
    while (!line.empty()) {
        int left = line.front().st;
        int right = line.front().nd;
        line.pop();
        string pivot = a[left + (right - left) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
            if (left < j) line.push(pi(left, j));
            if (i < right) line.push(pi(i, right));
        }
    }
}

void countDistinctString (string *a, int n) {
    quickSort(a, n);
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            cout << a[i - 1] << ": " << count << endl;
            count = 1;
        }
        else 
            count++;
    }
    cout << a[n - 1] << ": " << count << endl;
}

int main()
{
    // string * list;
    // int n = 10;
    // list = genArrString(n);
    // cout << "Original array: ";
 
    // quickSort(list, n);
    
    // for (int i = 0; i < n; i++) cout << list[i] << " ";
    // cout << endl;
    // countDistinctString(list, n);
    // delete [] list;

    int n = 4;
    //int *a = genArr(n); 
    int a[] = {8, 4, 2, 1};
    printArr(a, n);
    cout << countInversions(a, n);
    //linkedListSort(a, n);
    //printArr(a, n);

    return 0;
}
