/**
    Ta Xuan Truong _ 23127506
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>

#define pi pair <int, int>
#define ps pair <string, string>
#define st first
#define nd second
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;


using namespace std;

void convertLowercase (string &s) {
    for (int i = 0; i < s.size(); i ++) {
        s[i] = tolower(s[i]);
    }
}

void readDictionaryFile (vector <ps> &a) {
    ifstream file("dictionary.txt");
    while (!file.eof()) {
        ps tmp;
        getline(file, tmp.st, ':');
        convertLowercase(tmp.st);
        //file.get();
        getline(file, tmp.nd);
        a.push_back(tmp);
    }
}

void quickSortString (vector <ps> &a) {
    queue <pi> line;
    line.push(pi(0, a.size() - 1));
    while (!line.empty()) {
        int left = line.front().st;
        int right = line.front().nd;
        line.pop();
        string pivot = a[left + (right - left) / 2].st;
        int i = left, j = right;
        while (i <= j) {
            while (a[i].st < pivot)
                i++;
            while (a[j].st > pivot)
                j--;
            if (i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        if (left < j)
            line.push({left, j});
        if (i < right)
            line.push({i, right});
    }

}

int binarySearch(vector <ps> &a, int n, string key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        
        int mid = (l + r) / 2;
        if (a[mid].st == key) 
            return mid;
        else if (a[mid].st < key) 
            l = mid + 1;
        else 
            r = mid - 1;
    }
    return -1;
}



int main(int argc, char *argv[])
{   
    vector <ps> dictionary;
    readDictionaryFile(dictionary);
    quickSortString(dictionary);
    int n = dictionary.size();

    ofstream fileout(argv[argc - 1]);
    for (int i = 1; i < argc - 1; i++) {
        string key(argv[i]);
        convertLowercase(key);
        int pos = binarySearch(dictionary, n, key);
        if (pos != -1) 
            fileout << key << " : " << dictionary[pos].nd << endl;
        else 
            fileout << "Word not found" << endl;
    }
    fileout.close();
    return 0;
} 
