/**
    Ta Xuan Truong _ 23127506
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
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

int binarySearch(int *a, int n, int key) {
    int l = 0, r = n - 1; 
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == key) 
            return mid;
        if (a[mid] < key)
            l = mid + 1;
        else 
            r = mid - 1;
    }
    return -1;
}

void quickSort (int *a, int n) {
    queue <pi> line;
    line.push({0, n - 1});
    while (!line.empty()) {
        int left = line.front().st;
        int right = line.front().nd;
        line.pop();
        int i = left, j = right;
        int pivot = a[(left + right) / 2];
        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        if (left < j) line.push({left, j});
        if (i < right) line.push({i, right});
    }
}

// B1
int * genLottery (int &n) {
    n = 5;
    int *source = new int[n];
    bool check[41];
    for (int i = 0; i < 41; i++) 
        check[i] = 0;
    for (int i = 0; i < n; i ++) {
        int tmp = rand() % 40 + 1;
        while (check[tmp]) 
            tmp = rand() % 40 + 1;
        check[tmp] = 1;
        source[i] = tmp;
    }
    quickSort(source, n);
    return source;
}

void playLottery() {
    bool check_conitnue = 1;
    srand(time(0));
    while (check_conitnue) {
        int n = 5;
        int *source = genLottery(n);
        
        int player[n];
        for (int i = 0; i < n; i ++) {
            cout << "Enter number " << i + 1<< ": ";
            cin >> player[i];
        }
        bool check = 1;
        for (int i = 0; i < n; i ++) 
            if (binarySearch(source, n, player[i]) == -1)
                check = 0;
        for (int i = 0; i < n; i++)
            cout << source[i] << " ";
        cout << endl;
        if (check) 
            cout << "You win!\n";
        else
            cout << "You lose!\n";
        cout << "Press 0: Stop program\n";
        cout << "Press 1: Continue program\n";
        cin >> check_conitnue;
        delete [] source;
    }
}

// B2

struct Node {
    string data;
    Node *next;
};

Node * createNode (string data) {
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

int hashFunction (string key) {
    int tmp = 0;
    for (int i = 0; i < key.size(); i ++) 
        tmp += (key[i] - 'a' + 1) * (min(i * i * i * i, 200000) + 1);
    // tmp += 25 * (key.size() - 1);
    // return tmp % 1556;
    //tmp += 30001 * (key.size() - 1);
    return tmp % 370110;
}

void openAddressing () {
    //int n = 1556;
    //int n = 900900;
    int n = 370110;
    //Node * table[n];
    Node **table;
    table = new Node*[n];
    for (int i = 0; i < n; i++)
        table[i] = NULL;
    
    ifstream file("input.txt");
    string line;
    while (file >> line) {
        int key = hashFunction(line);
        Node *node = createNode(line);
        
        if (table[key] == nullptr)
            table[key] = node;
        else {
            node->next = table[key];
            table[key] = node;
        }
    }
    file.close();

    ofstream fileout("output.txt");
    for (int i = 0; i < n; i++) {
        Node *node = table[i];
        if (node == nullptr)
            continue;
        //fileout << i << endl;
        while (node != nullptr) {
            fileout <<  '\t' << node->data << endl;
            node = node->next;
        }
    }
    fileout.close();
    
    for (int i = 0; i < n; i ++) {
        Node *node = table[i];
        while (node != NULL) {
            Node *tmp = node;
            node = node->next;
            delete tmp;
        }
    }
    delete[] table;
}

int hash2 (string key) {
    int tmp = 0;
    for (int i = 0; i < key.size(); i ++) 
        tmp += (key[i] - 'a' + 1);
    //tmp += 20000 * (key.size() - 1);
    return tmp % 370110;
}

void linearProbing () {
    int n = 370110;
    string *table = new string [n];
    
    for (int i = 0; i < n; i++)
        table[i] = "";
    
    ifstream file("input.txt");
    ofstream f("out.txt");
    //string line;
    //while (file >> line) {
    for (int j = 0; j < 370104; j ++) {
        string line;
        getline(file, line);
        // f << line << '\n';
        int key = hash2(line);
        //f << key << '\n';
        int i = 0;
        while (true) {
            int tmp = (key + i * i) % n;
            if (table[tmp] == "")
                break;
            i++;
        }
        table[(key + i * i) % n] = line;
    }
    file.close();
    f.close();
    ofstream fileout("output.txt");
    for (int i = 0; i < n; i++) {
        if (table[i] != "")
        fileout << table[i] << endl;
    }
    fileout.close();
    
    delete[] table;
}

int main()
{
    //playLottery();
    //openAddressing();
    linearProbing();
    return 0;
}
