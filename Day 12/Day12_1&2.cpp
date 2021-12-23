#include <bits/stdc++.h>
using namespace std;

int numPaths(map<string, vector<string>> caveMap, string curr, map<string, bool> path, string p, bool restricted)
{
    if(curr == "end")
    { 
        // print path for debug purposes
        // cout << p << endl;
        return 1;
    }

    int ans = 0;

    for(auto node : caveMap[curr])
    {
        if(restricted) {
            if(path.find(node) != path.end())
            {
                continue;
            }
            map<string, bool> newPath(path);
            if(islower(node[0]))
                newPath[node] = true;
            ans += numPaths(caveMap, node, newPath, p + node + ", ", restricted);
        } else {
            bool flag = restricted;
            if(path.find(node) != path.end())
            {
                flag = true;
            }
            map<string, bool> newPath(path);
            if(islower(node[0]))
                newPath[node] = true;
            ans += numPaths(caveMap, node, newPath, p + node + ", ", flag);
        }
    }

    return ans;
}

int main() {
    string s, key, val;

    map<string, vector<string>> caveMap;

    while(getline(cin, s))
    {
        stringstream stream(s);
        getline(stream, key, '-');
        getline(stream, val, '-');
        if(val != "start" && key != "end")
            caveMap[key].push_back(val);
        if(key != "start" && val != "end")
            caveMap[val].push_back(key);
    }

    for(auto p : caveMap)
    {
        cout << p.first << " : ";
        for(auto elem : p.second)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    map<string, bool> path;
    // part 1
    // cout << numPaths(caveMap, "start", path, "start, ", true);
    cout << numPaths(caveMap, "start", path, "start, ", false);
}
