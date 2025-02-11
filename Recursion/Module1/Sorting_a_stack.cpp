#include <bits/stdc++.h>

using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void insertSorted(stack<int> &s, int element)
{
    if (s.empty() || s.top() < element)
    {
        s.push(element);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertSorted(s, element);
    s.push(topElement);
}

void SortedStack ::sort()
{
    // Your code here
    if (s.empty())
    {
        return;
    }
    int topElement = s.top();
    s.pop();
    sort(); // Recursively sort the remaining stack
    insertSorted(s, topElement);
}