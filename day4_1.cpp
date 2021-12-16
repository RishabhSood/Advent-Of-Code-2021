#include <bits/stdc++.h>
using namespace std;

void processNums(vector<int> &calledNums)
{
    string s;
    cin >> s;

    stringstream stream(s);
    while(getline(stream, s, ','))
    {
        calledNums.push_back(stoi(s, 0, 10));
    }

    getline(cin, s);
}

void processBoards(vector<vector<vector<int>>> &boards)
{
    string s;

    while(getline(cin, s))
    {
        vector<vector<int>> board;
        for(int i = 0; i < 5; i++)
        {
            vector<int> row;
            getline(cin, s);
            stringstream stream(s);
            while(getline(stream, s, ' '))
            {
                if(s.size() > 0)
                    row.push_back(stoi(s, 0, 10));
            }
            board.push_back(row);
        }
        boards.push_back(board);
    }
}

int main() {
    vector<int> calledNums;
    vector<vector<vector<int>>> boards;

    processNums(calledNums);
    processBoards(boards);
}
