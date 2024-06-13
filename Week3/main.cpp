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
    n = rand() % 15 + 10;
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

//B2 Tree sort
struct NodeTree {
    int data;
    NodeTree* left;
    NodeTree* right;
};

NodeTree * createNodeTree (int key) {
    NodeTree * node = new NodeTree;
    node->data = key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void insertNode (NodeTree *&root, int key) {
    if (root == nullptr) {
        root = createNodeTree(key);
        return;
    }
    if (key > root->data) {
        if (root->right == nullptr)
            root->right = createNodeTree(key);
        else
            insertNode(root->right, key);
    }
    else {
        if (root->left == nullptr)
            root->left = createNodeTree(key);
        else
            insertNode(root->left, key);
    }
        
}

void storeSort (NodeTree *root, int *a, int &k) {
    if (root == nullptr)
        return;
    storeSort(root->left, a, k);
    a[k++] = root->data;
    storeSort(root->right, a, k);
}

void treeSort (int *a, int n) {
    NodeTree *root = nullptr;
    for (int i = 0; i < n; i++) 
        insertNode(root, a[i]);
    int tmp = 0;
    storeSort(root, a, tmp);
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
//B1
    // int n;
    // int *a = genArr(n); 
    // cout << "Original array: ";
    // printArr(a, n);
    // linkedListSort(a, n);
    // cout << "Sorted array: ";
    // printArr(a, n);


//B2 
    // int n;
    // int *a = genArr(n); 
    // cout << "Original array: ";
    // printArr(a, n);
    // treeSort(a, n);
    // cout << "Sorted array: ";
    // printArr(a, n);

// B3
    // int n = 4;
    // int *a = genArr(n); 
    // int a[] = {8, 4, 2, 1};
    // printArr(a, n);
    // cout << countInversions(a, n);
    //linkedListSort(a, n);
    //printArr(a, n);

//B4
    // string * list;
    // int n = 10;
    // list = genArrString(n);
    // cout << "Original array: ";
    // quickSort(list, n);
    // for (int i = 0; i < n; i++) cout << list[i] << " ";
    // cout << endl;
    // countDistinctString(list, n);
    // delete [] list;

    return 0;
}
