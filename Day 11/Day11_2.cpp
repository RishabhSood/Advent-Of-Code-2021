#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<vector<int>> octopus;
    
    while(getline(cin, s))
    {
        vector<int> row;
        for(auto c : s)
        {
            row.push_back(c - '0');
        }
        octopus.push_back(row);
    }

    int m = octopus.size();
    int n = octopus[0].size();

    int idx = 1;

    while(1)
    {
        int flash = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // child elements affected by parent flashes
                stack<pair<int, int>> st;
                st.push({i, j});

                while (st.size() > 0)
                {
                    auto p = st.top();
                    st.pop();
                    int x = p.first;
                    int y = p.second;
                    // each element gets one energy point (either default or from the previous flash)
                    octopus[x][y]++;
                    // only one flash permitted
                    if (octopus[x][y] == 10)
                    {
                        flash++;
                        // traverse through neighbors (including diagonal)
                        for(int ni = -1; ni <= 1; ni++)
                        {
                            for(int nj = -1; nj <= 1; nj++)
                            {
                                int nx = x + ni;
                                int ny = y + nj;
                                // range bound check
                                if(nx >= 0 && nx < m && ny >= 0 && ny < n)
                                {
                                    // add valid neighbor to processing stack
                                    st.push({nx, ny});
                                }
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(octopus[i][j] > 9)
                    octopus[i][j] = 0;
            }
        }

        if(flash == m*n)
        {
            break;
        }

        idx++;
    }

    cout << idx;
    return 0;
}
