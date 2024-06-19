/**
    Ta Xuan Truong _ 23127506

    Structure of file candidate.txt
    m
    1 a[1]
    2 a[2]
    ...
    n a[m]
    n
    line[1]
    line[2]
    line[3]
    ...
    line [n]

    m: number of options
    a[i]: is number of availiable candidate for option i
    n: number of candidate
    line[i]: is the preference of candidate i
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

#define pi pair <int, int>
#define st first
#define nd second
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Candidate {
    string name;
    float p1, p2, ave;
    int *opt_order;
    void show() {
        cout << name << " " << p1 << " " << p2 << '\n';
    }
};

using namespace std;

void inputList (Candidate *&, int &, int *&, int &);
void quickSort (Candidate*, int, bool (*cmp)(Candidate &, Candidate &));
bool cmpP1 (Candidate &, Candidate &);
bool cmpP2 (Candidate &, Candidate &);
bool cmpAve (Candidate &, Candidate &);

void process (Candidate *, int, int *, int );

int main()
{
    int m;
    int * opt;
    int n;
    Candidate *list;
    inputList(list, n, opt, m);
    process(list, n, opt, m);
    return 0;
}

void inputList (Candidate * &list, int &n, int * &opt, int &m) {
    ifstream file("candidate.txt");
    
    file >> m;
    opt = new int [m];
    for (int i = 0; i < m; i++) {
        file >> opt[i];
        file >> opt[i]; 
    }
    file >> n;
    
    list = new Candidate [n];
    for (int i = 0; i < n; i++) {
        file.get();
        file.get();
        getline(file, list[i].name, '\"');
        file.get();
        file >> list[i].p1;
        file.get();
        file >> list[i].p2;
        list[i].ave = (list[i].p1 + list[i].p2) / 2;

        list[i].opt_order = new int[m];
        for (int j = 0; j < m; j++) {
            file.get();
            file >> list[i].opt_order[j];
            list[i].opt_order[j]--;
        }
    }
} 

bool cmpP1 (Candidate &a, Candidate &b) {
    return a.p1 < b.p1;
}

bool cmpP2 (Candidate &a, Candidate &b) {
    return a.p2 < b.p2;
}

bool cmpAve (Candidate &a, Candidate &b) {
    if (a.ave == b.ave)
        return a.p1 > b.p1;
    return a.ave > b.ave;
}

void quickSort (Candidate *a, int n, bool (*cmp)(Candidate &, Candidate &)) {
    queue <pi> line;
    line.push ({0, n - 1});
    while (!line.empty()) {
        int left = line.front().st, right = line.front().nd;
        line.pop();
        Candidate pivot = a[left + (right - left) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (cmp(a[i], pivot)) i++;
            while (cmp(pivot, a[j])) j--;
            if (i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        if (left < j) line.push ({left, j});
        if (i < right) line.push ({i, right});
    }
}

void process (Candidate *list, int n, int * opt, int m) {
    quickSort(list, n, cmpAve);

    vector <Candidate> res[m];
    vector <Candidate> rejected;
    for (int i = 0; i < n; i++) {
        int * tmp = list[i].opt_order;
        int j;
        for (j = 0; j < m; j ++) {
            if (opt[tmp[j]] != 0) {
                res[tmp[j]].push_back(list[i]);
                opt[tmp[j]]--;
                break;
            }
            else {
                int size = res[tmp[j]].size();
                if (list[i].ave == res[tmp[j]][size - 1].ave 
                    && list[i].p1 == res[tmp[j]][size - 1].p1) {
                    res[tmp[j]].push_back(list[i]);
                    break;
                }   
            }
        }
        if (j == m)
            rejected.push_back(list[i]);
    }


    // print the output
    for (int i = 0; i < m; i++) {
        cout << "Option: " << i + 1 << ":\n";
        for (int j = 0; j < res[i].size(); j++) {
            cout << j + 1 << ". " <<  res[i][j].name << " " << res[i][j].ave << '\n';
        }
        cout << '\n';
    }

    cout << "Rejected candidate:\n";
    for (int i = 0; i < rejected.size(); i++)
        cout << i + 1 << ". " << rejected[i].name << rejected[i].ave << '\n';
}
