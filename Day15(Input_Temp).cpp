#include<bits/stdc++.h>
using namespace std;

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
}
