#include<bits/stdc++.h>
using namespace std;

void process(map<char, pair<long long, vector<char>>> &charInfo, map<pair<char, char>, char> rules)
{
    map<char, pair<long long, vector<char>>> newInfo;
    for(auto chi : charInfo)
    {
        for(auto elem : chi.second.second)
        {
            char inst = rules[{chi.first, elem}];
            newInfo[chi.first].second.push_back(inst);
            newInfo[inst].second.push_back(elem);
            newInfo[inst].first++;
        }
    }
    for(auto chi : charInfo)
    {
        newInfo[chi.first].first += charInfo[chi.first].first;
    }

    charInfo = newInfo;
}

int main()
{
    string inpt;
    cin >> inpt;
    
    map<pair<char, char>, char> rules;
    string s;
    while(getline(cin, s))
    {
        if(s.size() == 0)
            continue;
        else
        {
            rules[{s[0], s[1]}] = s[6];
        }
    }

    map<char, pair<long long, vector<char>>> charInfo;
    for(int i = 0; i < inpt.size() - 1; i++)
    {
        charInfo[inpt[i]].first++;
        charInfo[inpt[i]].second.push_back(inpt[i + 1]);
    }
    charInfo[inpt[inpt.size() - 1]].first++;

    for(int i = 0; i < 10; i++)
        process(charInfo, rules);

    long long mn = INT_MAX;
    long long mx = 0;

    for(auto p : charInfo)
    {
        mn = min(mn, p.second.first);
        mx = max(mx, p.second.first);
    }

    cout << mx - mn;
}
