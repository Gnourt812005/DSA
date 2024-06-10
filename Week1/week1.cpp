/**
    Ta Xuan Truong _ 23127506

*/
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <stack>

#define pi pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
// B1 ================================================================================== //
bool checkBracket(string s)
{
    stack <char> tmp;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            tmp.push(s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (tmp.empty())
                return 0;
            char ram;
            switch (tmp.top())
            {
            case '(':
                ram = ')';
                break;
            case '[':
                ram = ']';
                break;
            case '{':
                ram = '}';
                break;
            }
            if (s[i] == ram)
                tmp.pop();
            else
                return 0;
        }
    }
    if (tmp.empty())
        return 1;
    return 0;
}

// B2 ================================================================================== //
struct Data
{
    string name;
    int x;
};

struct Node
{
    Data key;
    Node *next;
};

struct PQ
{
    Node *head;
    Node *tail;
    PQ();
    ~PQ();
    Node *Create(Data);
    void Insert(Data);
    void Show();
    void ExtractMin();
    bool Empty();
};

PQ::PQ()
{
    head = tail = nullptr;
}

PQ::~PQ()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        Node *ram = tmp;
        tmp = tmp->next;
        delete ram;
    }
}

Node *PQ::Create(Data key)
{
    Node *tmp = new Node;
    tmp->key = key;
    tmp->next = nullptr;
    return tmp;
}

bool PQ::Empty()
{
    if (head == nullptr)
        return 1;
    return 0;
}

void PQ::Insert(Data key)
{
    Node *q = Create(key);
    if (Empty())
    {
        head = q;
        tail = q;
        return;
    }
    Node *tmp = head;
    while (tmp != nullptr && tmp->key.name < key.name)
        tmp = tmp->next;
    if (tmp == nullptr)
    {
        tail->next = q;
        tail = q;
    }
    else
    {
        swap(*tmp, *q);
        tmp->next = q;
    }
}

void PQ::Show()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->key.name << " " << tmp->key.x << '\n';
        tmp = tmp->next;
    }
}

void PQ::ExtractMin()
{
    if (head == nullptr)
        return;
    Node *tmp = head;
    head = head->next;
    delete tmp;
    if (head == nullptr)
        tail = nullptr;
}

// B3 ================================================================================== //

int countAngryCustomer(queue<pi> q)
{
    int count = 0;
    int end_last = 0;
    while (!q.empty())
    {
        pi cur = q.front();
        q.pop();
        int time = max(0, end_last - cur.first);
        if (time > 10)
            count++;
        else
            end_last = time + cur.first + cur.second;
    }
    return count;
}

int main()
{
    // PQ head;
    // head.Insert({"ADAM", 5});
    // head.Insert({"Bard", 4});
    // head.Insert({"ABAA", 5});
    // head.Insert({"ABAA", 5});
    // head.Show();
    // head.ExtractMin();
    // head.Show();
    // head.ExtractMin();
    // head.Show();
    // head.ExtractMin();
    // head.Show();

    queue<pi> q;
    int n;
    cin >> n;
    while (n != 0)
    {
        n--;
        int a, b;
        cin >> a >> b;
        q.push({a, b});
    }
    cout << countAngryCustomer(q);
    return 0;
}