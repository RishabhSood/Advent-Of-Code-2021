#include <bits/stdc++.h>
using namespace std;

void processTurtles(map<int, int> &turtles)
{
    string s;
    cin >> s;

    stringstream stream(s);
    while(getline(stream, s, ','))
    {
        turtles[stoi(s, 0, 10)]++;
    }
}

int sumN(int n)
{
    return (n*(n+1)/2);
}

int main() {
    map<int, int> turtles;
    processTurtles(turtles);

    int mn = turtles.begin()->first;
    int mx = turtles.rbegin()->first;

    int cost = INT_MAX;

    for(int i = mn; i <= mx; i++)
    {
        int c = 0;
        for(auto turtle : turtles)
        {
            // c += abs(i - turtle.first)*turtle.second;
            c += sumN(abs(i - turtle.first))*turtle.second;
        }
        cost = min(cost, c);
    }

    cout << cost;
}
