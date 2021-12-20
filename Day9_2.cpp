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
    priority_queue<int> basin;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(heightMap[i][j] == -1 || heightMap[i][j] == 9)
            {
                continue;
            }

            stack<pair<int, int>> st;
            st.push({i, j});

            int count = 0;

            while(!st.empty())
            {
                int x = st.top().first;
                int y = st.top().second;
                st.pop();

                if(heightMap[x][y] == -1 || heightMap[x][y] == 9)
                {
                    continue;
                }

                count++;

                heightMap[x][y] = -1;

                if(x - 1 >= 0)
                {
                    st.push({x - 1, y});
                }
                if(x + 1 < m)
                {
                    st.push({x + 1, y});
                }
                if(y - 1 >= 0)
                {
                    st.push({x, y - 1});
                }
                if(y + 1 < n)
                {
                    st.push({x, y + 1});
                }
            }

            basin.push(count);
        }
    }

    int ans = 1;
    for(int i = 0; i < 3; i++)
    {
        ans *= basin.top();
        basin.pop();
    }
    cout << ans;
  
    return 0;
}
