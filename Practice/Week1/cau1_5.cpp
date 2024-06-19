/**
    Ta Xuan Truong _ 23127506
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

#define pi pair<int, int>
#define st first
#define nd second
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void readNFirstLineInFile(int n, string s)
{
    ifstream file(s);
    string line;
    for (int i = 0; i < n && !file.eof(); i++)
    {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}

void readNLastLineInFile(int n, string s)
{
    ifstream file(s);
    string line;
    queue<string> lines;
    while (!file.eof())
    {
        getline(file, line);
        lines.push(line);
        if (lines.size() > n)
            lines.pop();
    }
    while (!lines.empty())
    {
        cout << lines.front() << endl;
        lines.pop();
    }
    file.close();
}

int main()
{
    int k, n;
    string file_name;
    cin >> k >> n;
    cin.get();
    getline(cin, file_name);
    if (k == 0)
        readNFirstLineInFile(n, file_name);
    else
        readNLastLineInFile(n, file_name);
    return 0;
}