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
    cout << "Name: " << name << endl;
    cout << "Birth: " << birth << endl;
    cout << "Class ID: " << classid << endl;
    cout << "ID: " << id << endl;
    cout << "Address: " << address << endl << endl;
}

int Student::Size() {
    return sizeof(name) + sizeof(birth) + sizeof(classid) + sizeof(id) + sizeof(address);
}

int main()
{
    ofstream fo("output1.9.bin", ios::binary);
    Student s1, s2, s3;
    s1.Create("Nguyen Van A", "08/08/2005", "23CLC02", "23127507", "Q6");
    s2.Create("Nguyen Van B", "02/20/2005", "23CLC02", "23127508", "Q5");
    s3.Create("Nguyen Van C", "20/03/2004", "23CLC02", "23127408", "Q5");
    fo.write((char *)&s1, sizeof(s1));
    fo.write((char *)&s2, sizeof(s2));
    fo.write((char *)&s3, sizeof(s3));
    fo.close();
    return 0;
}