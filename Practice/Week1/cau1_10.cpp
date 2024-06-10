/**
    Ta Xuan Truong _ 23127506
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>

#define pi pair <int, int>
#define st first
#define nd second
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

struct Student {
    char name[50] = "";
    char birth[11] = "";
    char classid[10] = "";
    char id[9] = "";
    char address[100] = "";
    void Create(const char *, const char *, const char *, const char *, const char *);
    void Show();
    int Size();
};

using namespace std;

void Student::Create(const char * n, const char * b, const char * c, const char * i, const char * a) {
    strcpy(name, n);
    strcpy(birth, b);
    strcpy(classid, c);
    strcpy(id, i);
    strcpy(address, a);
}

void Student::Show() {
    cout << id;
    for (int i = strlen(id); i <= sizeof(id); i ++)
        cout << " ";
    cout << "  ";

    cout << name;
    for (int i = strlen(name); i <= sizeof(name); i ++)
        cout << " ";
    cout << "  ";

    cout << birth;
    for (int i = strlen(birth); i <= sizeof(birth); i ++)
        cout << " ";
    cout << "  ";

    cout << classid;
    for (int i = strlen(classid); i <= sizeof(classid); i ++)
        cout << " ";
    cout << "  ";

    cout << address << endl;
}

int Student::Size() {
    return sizeof(name) + sizeof(birth) + sizeof(classid) + sizeof(id) + sizeof(address);
}

int main()
{
    ifstream fi("output1.9.bin", ios::binary);
    Student s0, s1, s2, s3;
    s0.Create("Name", "Birth", "Classid", "ID", "Address");

    while (fi.read((char*)&s1, sizeof(s1))) {
        s1.Show();
    }

    return 0;
}