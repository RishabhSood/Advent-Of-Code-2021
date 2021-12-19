#include <bits/stdc++.h>
using namespace std;

struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
};

void processInput(vector<line> &v)
{
    string s;
    while(getline(cin, s))
    {
        line l;
        int i = 0;
        stringstream stream(s);
        while(getline(stream, s, ' '))
        {
            if(s != "->")
            {
                stringstream stream2(s);
                while(getline(stream2, s, ','))
                {
                    if(i == 0) {
                        l.x1 = stoi(s, 0, 10);
                    } else if (i == 1) {
                        l.y1 = stoi(s, 0, 10);
                    } else if (i == 2) {
                        l.x2 = stoi(s, 0, 10);
                    } else {
                        l.y2 = stoi(s, 0, 10);
                    }
                    i++;
                }
            }
        }
        v.push_back(l);
    }
}

int main() {
    vector<line> v;
    processInput(v);

    map<pair<int, int>, int> vent;

    for(auto l : v)
    {
        if(l.x1 == l.x2)
        {
            if(l.y1 > l.y2)
                for(int i = l.y2; i <= l.y1; i++)
                {
                    vent[{l.x1, i}]++;
                }
            else
                for(int i = l.y1; i <= l.y2; i++)
                {
                    vent[{l.x1, i}]++;
                }
        }
        else if(l.y1 == l.y2)
        {
            if(l.x1 > l.x2)
                for(int i = l.x2; i <= l.x1; i++)
                {
                    vent[{i, l.y1}]++;
                }
            else
                for(int i = l.x1; i <= l.x2; i++)
                {
                    vent[{i, l.y1}]++;
                }
        }
    }

    int count = 0;
    for(auto p : vent)
    {
        if(p.second >= 2)
            count++;
    }
    cout << count;
}
