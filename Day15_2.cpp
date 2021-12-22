#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

struct CustomComparator {
    bool operator()(pair<int, pair<int, int>> const& p1, pair<int, pair<int, int>> const& p2)
    {
        return p1.first > p2.first;
    }
};

int getVal(vector<vector<int>> chiton, int i, int j)
{
    int m = chiton.size();
    int n = chiton[0].size();
    int x = chiton[i%m][j%n] + (int)(i/m) + (int)(j/n);
    return (x-1)%9 + 1;
}

void solve()
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
        if(x == m*5-1 && y == n*5-1)
        {
            cout << curr;
            break;
        }
        if(x + 1 < m*5)
            pq.push({curr + getVal(chiton, x+1, y), {x+1, y}});
        if(x - 1 > 0)
            pq.push({curr + getVal(chiton, x-1, y), {x-1, y}});
        if(y + 1 < n*5)
            pq.push({curr + getVal(chiton, x, y+1), {x, y+1}});
        if(y - 1 > 0)
            pq.push({curr + getVal(chiton, x, y-1), {x, y-1}});

        visited[{x, y}] = true;
    }
}

int main()
{
    FIO;
    OJ;
    
    solve();

    return 0;
}


