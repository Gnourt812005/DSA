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

void findDiff2Files(string f1, string f2) {
    ifstream file1(f1), file2(f2);
    int i = 0;
    while (!file1.eof() || !file2.eof()) {
        i ++;
        string line1(""), line2("");
        getline(file1, line1);
        getline(file2, line2);
        if (line1 != line2) {
            cout << i << "// " << line1 << '\n'; 
            cout << i << "\\\\ " << line2 << '\n';
        }
    }
    file1.close();
    file2.close();
}

int main()
{
    findDiff2Files("input1.4.1.txt", "input1.4.2.txt");
    return 0;
}