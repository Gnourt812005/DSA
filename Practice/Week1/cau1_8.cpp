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

bool checkPalindrome (string s) {
    int len = s.size();

    for (int i = len - 1; i >= 0; i--) {
        if (!isalnum(s[i])) {
            s.erase(i, 1);
        }
    }
    len = s.size();
    for (int i = 0; i < len / 2; i++) {
        if (tolower(s[i]) != tolower(s[len - i - 1])) 
            return false;
    }
    return true;
}

int main()
{
    ifstream fi;
    fi.open("input1.8.1.txt");
    while(!fi.eof()){
        string s("");
        getline(fi, s);
        if (s == "")
            continue;
        if (checkPalindrome(s)) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }

    return 0;
}