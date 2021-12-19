#include <bits/stdc++.h>
using namespace std;

void populate(vector<string> &encode, map<int, vector<string>> inpt)
{
    encode[1] = inpt[2][0];
    encode[7] = inpt[3][0];
    encode[4] = inpt[4][0];
    encode[8] = inpt[7][0];

    // find 3 by matching 1
    for(auto elem : inpt[5])
    {
        bool flag = true;
        for(auto c : encode[1])
        {
            if(elem.find(c) == string::npos)
                flag = false;
        }
        if(flag)
        {
            encode[3] = elem;
            break;
        }
    }

    // find 6 by matching 1
    for(auto elem : inpt[6])
    {
        bool flag = true;
        for(auto c : encode[1])
        {
            if(elem.find(c) == string::npos)
                flag = false;
        }
        if(!flag)
        {
            encode[6] = elem;
            break;
        }
    }

    // find 9 by matching 3 - remaining len 6 string will be 0 thus
    for(auto elem : inpt[6])
    {
        if(elem != encode[6])
        {
            bool flag = true;
            for(auto c : encode[3])
            {
                if(elem.find(c) == string::npos)
                    flag = false;
            }
            if(flag)
            {
                encode[9] = elem;
            } else {
                encode[0] = elem;
            }
        }
    }

    // find 5 by matching 6, else 2
    for(auto elem : inpt[5])
    {
        if(elem != encode[3])
        {
            bool flag = true;
            for(auto c : elem)
            {
                if(encode[6].find(c) == string::npos)
                    flag = false;
            }
            if(flag) {
                encode[5] = elem;
            } else {
                encode[2] = elem;
            }
        }
    }
}

bool isAnagram(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
 
    // Compare sorted strings
    for (int i = 0; i < n1; i++)
        if (s1[i] != s2[i])
            return false;
 
    return true;
}

int getNum(string s, vector<string> encode)
{
    if(s.size() == 2)
        return 1;
    if(s.size() == 3)
        return 7;
    if(s.size() == 4)
        return 4;
    if(s.size() == 7)
        return 8;
    
    if(s.size() == 5)
    {
        int myIdx[] = {2, 3, 5};
        for(auto elem : myIdx)
        {
            if(isAnagram(s, encode[elem]))
                return elem;
        }
    } else {
        int myIdx[] = {0, 6, 9};
        for(auto elem : myIdx)
        {
            if(isAnagram(s, encode[elem]))
                return elem;
        }
    }

    return -1;
}

int main() {
    string s;
    map<int, bool> mp;
    
    mp[2] = true;
    mp[4] = true;
    mp[3] = true;
    mp[7] = true;

    int totalNum = 0;

    while(getline(cin, s))
    {
        stringstream stream(s);
        
        getline(stream, s, '|');
        stringstream stream2(s);

        map<int, vector<string>> inpt;
        while(getline(stream2, s, ' '))
        {
            inpt[s.size()].push_back(s);
        }

        vector<string> encode(10);
        populate(encode, inpt);

        getline(stream, s, '|');
        stringstream stream3(s);

        int myNum = 0;

        while(getline(stream3, s, ' '))
        {
            myNum *= 10;
            myNum += getNum(s, encode);
        }

        totalNum += myNum;
    }

    cout << totalNum;
}
