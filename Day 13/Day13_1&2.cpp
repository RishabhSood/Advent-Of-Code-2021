#include<bits/stdc++.h>
using namespace std;

void process(map<pair<int, int>, bool> &coord, string axis, int pos)
{
    map<pair<int, int>, bool> newCoord;
    if(axis == "x")
    {
        for(auto p : coord)
        {
            int x = p.first.first;
            int y = p.first.second;
            if(x > pos)
                newCoord[{2*pos - x, y}] = true;
            else
                newCoord[{x, y}] = true;
        }
    } else {
        for(auto p : coord)
        {
            int x = p.first.first;
            int y = p.first.second;
            if(y > pos)
                newCoord[{x, 2*pos - y}] = true;
            else
                newCoord[{x, y}] = true;
        }
    }

    coord = newCoord;
}

int main()
{
    string s;
    string x;
    string y;
    map<pair<int, int>, bool> coord;
    while(getline(cin, s))
    {
        stringstream stream(s);  
        getline(stream, x, ',');
        getline(stream, y, ',');
        if(x.size() == 0)
            break;
        coord[{stoi(x), stoi(y)}] = true;
    }

    int x_max = 0;
    int y_max = 0;

    while(getline(cin, s))
    {
        string p = s.substr(11, s.size() - 11);
        stringstream stream(p);
        string axis;
        string pos;
        getline(stream, axis, '=');
        getline(stream, pos, '=');
        if(axis == "x")
            x_max = stoi(pos);
        else
            y_max = stoi(pos);
        process(coord, axis, stoi(pos));
        cout << coord.size() << endl;
    }

    vector<vector<char>> matrix(y_max, vector<char>(x_max, ' '));
    for(auto p : coord)
    {
        matrix[p.first.second][p.first.first] = '@';
    }

    for(auto row : matrix)
    {
        for(auto elem : row)
            cout << elem << " ";
        cout << endl;
    }
}
