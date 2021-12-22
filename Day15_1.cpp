#include<bits/stdc++.h>
using namespace std;

struct CustomComparator {
    bool operator()(pair<int, pair<int, int>> const& p1, pair<int, pair<int, int>> const& p2)
    {
        return p1.first > p2.first;
    }
};

int main()
{
    string s;
    vector<vector<int>> chiton;

    while(getline(cin, s))
    {
        vector<int> row;
        for(auto c : s)
        {
            row.push_back(c - '0');
        }
        chiton.push_back(row);
    }

    int m = chiton.size();
    int n = chiton[0].size();

    map<pair<int, int>, bool> visited;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, CustomComparator> pq;
    vector<vector<int>> cost(m, vector<int>(n));
    pq.push({0, {0, 0}});

    while(pq.size() > 0)
    {
        auto p = pq.top();
        int x = p.second.first;
        int y = p.second.second;
        int curr = p.first;

        pq.pop();
        if(visited.find({x, y}) != visited.end())
            continue;
        if(x == m-1 && y == n-1)
        {
            cout << curr;
            break;
        }
        if(x + 1 < m)
            pq.push({curr + chiton[x+1][y], {x+1, y}});
        if(x - 1 > 0)
            pq.push({curr + chiton[x-1][y], {x-1, y}});
        if(y + 1 < n)
            pq.push({curr + chiton[x][y+1], {x, y+1}});
        if(y - 1 > 0)
            pq.push({curr + chiton[x][y-1], {x, y-1}});

        visited[{x, y}] = true;
    }
}
