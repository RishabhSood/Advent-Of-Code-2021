#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<vector<int>> heightMap;
    
    while(getline(cin, s))
    {
        vector<int> row;
        for(auto c : s)
        {
            row.push_back(c - '0');
        }
        heightMap.push_back(row);
    }

    int m = heightMap.size();
    int n = heightMap[0].size();

    int sum = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            bool flag = true;
            bool f1;
            int curr = heightMap[i][j];
            if(i > 0)
            {
                f1 = (curr < heightMap[i - 1][j]) ? true : false;
                flag = flag && f1;
            }
            if(i < m - 1)
            {
                f1 = (curr < heightMap[i + 1][j]) ? true : false;
                flag = flag && f1;
            }
            if(j > 0)
            {
                f1 = (curr < heightMap[i][j - 1]) ? true : false;
                flag = flag && f1;
            }
            if(j < n - 1)
            {
                f1 = (curr < heightMap[i][j + 1]) ? true : false;
                flag = flag && f1;
            }
            if(flag)
                sum += curr + 1;
        }
    }

    cout << sum;
}
