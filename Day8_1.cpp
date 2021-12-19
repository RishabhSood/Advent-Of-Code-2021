#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    map<int, bool> mp;
    
    mp[2] = true;
    mp[4] = true;
    mp[3] = true;
    mp[7] = true;

    int count = 0;
    while(getline(cin, s))
    {
        stringstream stream(s);
        getline(stream, s, '|');
        getline(stream, s, '|');
        stringstream stream2(s);
        while(getline(stream2, s, ' '))
        {
            if(mp.find(s.size()) != mp.end())
            {
                count++;
            }
        }
    }

    cout << count;
}
