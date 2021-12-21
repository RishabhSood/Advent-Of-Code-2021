#include<bits/stdc++.h>
using namespace std;

void process(map<string, long long> &pairs, map<string, string> rules)
{
    map<string, long long> newPairs;
    for(auto p : pairs)
    {
        long long count = p.second;
        string inst = rules[p.first];
        newPairs[p.first[0] + inst] += count;
        newPairs[inst + p.first[1]] += count;
    }
    pairs = newPairs;
}

int main()
{
    string inpt;
    cin >> inpt;
    
    map<string, string> rules;
    string s;
    while(getline(cin, s))
    {
        if(s.size() == 0)
            continue;
        else
        {
            rules[s.substr(0, 2)] = s.substr(6, 1);
        }
    }

    map<string, long long> pairs;
    for(int i = 0; i < inpt.size() - 1; i++)
    {
        pairs[inpt.substr(i, 2)]++;
    }

    for(int i = 0; i < 40; i++)
        process(pairs, rules);

    map<char, long long> charCnt;
    charCnt[inpt[0]]++;
    charCnt[inpt[inpt.size() - 1]]++;

    for(auto p : pairs)
    {
        charCnt[p.first[0]] += p.second;
        charCnt[p.first[1]] += p.second;
    }

    long long mn = LLONG_MAX;
    long long mx = 0;
    for(auto p : charCnt)
    {
        p.second = p.second/2;
        mx = max(mx, p.second);
        mn = min(mn, p.second);
    }

    cout << mx - mn;
}
