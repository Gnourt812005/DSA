/**
    Ta Xuan Truong _ 23127506
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <time.h>
#include <ctime>

#define pi pair <int, int>
#define st first
#define nd second
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Employee {
    string id;
    string name;
    short birth;
    void show() {
        cout << id << " " << name << " " << birth << endl;
    }
};

void inputFile (vector <Employee> &a) {
    ifstream file("employee.txt");
    string tmp;
    getline(file, tmp);

    time_t now = time(0);
    tm *ltn = localtime(&now);
    int cur_year = ltn->tm_year + 1900;
    while (!file.eof()) {
        getline(file, tmp);

        Employee x;
        int pos_now = tmp.find(',', 0);
        int pos_pre = pos_now + 1;

        x.id = tmp.substr(0, pos_now);
        pos_now = tmp.find(',', pos_pre);
        x.name = tmp.substr(pos_pre, pos_now - pos_pre);
        int tmp2 = stoi(tmp.substr(pos_now + 1) );
        if (tmp2 > cur_year) {
            tmp2 %= 100;
            if (tmp2 + 2000 > cur_year)
                x.birth = tmp2 + 1900;
            else
                x.birth = tmp2 + 2000;
        }
        else 
            x.birth = tmp2;

        a.push_back(x);
        file.peek();
    }
}

void outputFile (vector <Employee> a) {
    ofstream file("sortedemponage.txt");
    for (auto x : a) 
        file << x.id << "," << x.name << "," << x.birth << endl;
}

void sortSelection (vector <Employee> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int tmp = i;
        for (int j = i + 1; j < n; j++) {
            if (a[tmp].birth > a[j].birth) {
                tmp = j;
            }
            else if (a[tmp].birth == a[j].birth) {
                if (a[tmp].name > a[j].name) {
                    tmp = j;
            }
            }
        }
        swap(a[i], a[tmp]);
    }
}

void sortInterchange (vector <Employee> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].birth > a[j].birth) {
                swap(a[i], a[j]);
            }
            else if (a[i].birth == a[j].birth) {
                if (a[i].name > a[j].name)
                    swap(a[i], a[j]);
            }
        }
    }
}

void sortInsertion(vector <Employee> &a) {
    int size = a.size();
    for (int i = 1; i < size; i++) {
        Employee key = a[i];
        int j = i - 1;
        while (j > -1 && a[j].birth > key.birth) {
            a[j + 1] = a[j];
            j--;
        }
        while (j > -1 && a[j].birth == key.birth && a[j].name > key.name) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    vector <Employee> a;
    inputFile(a);
    int option;
    cout << "Press 1: Selection sort\n";
    cout << "Press 2: Interchange sort\n";
    cout << "Press 3: Insertion sort\n";
    cout << "Press others: Stop program\n";
    cin >> option;
    switch (option)
    {
    case 1:
        sortSelection(a);
        break;
    case 2:
        sortInterchange(a);
        break;
    case 3:
        sortInsertion(a);
        break;
    default:
        return 0;
        break;
    }
    outputFile(a);
    return 0;
}