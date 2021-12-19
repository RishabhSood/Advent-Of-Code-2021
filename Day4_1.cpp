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

int checkBoard(vector<vector<int>> board, int i, int j)
{
    int sumR = 0;
    int sumC = 0;
    for(int k = 0; k < 5; k++)
    {
        sumR += board[i][k];
        sumC += board[k][j];
    }
    if(sumR == -5 || sumC == -5)
    {
        int ans = 0;
        for(auto row : board)
        {
            for(auto elem : row)
            {
                if(elem != -1)
                    ans += elem;
            }
        }
        return ans;
    }
    return -1;
}

int updateBoards(vector<vector<vector<int>>> &boards, int num)
{
    for(int idx = 0; idx < boards.size(); idx++)
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(boards[idx][i][j] == num)
                {
                    boards[idx][i][j] = -1;
                    int ans = checkBoard(boards[idx], i, j);
                    if(ans != -1)
                        return ans;
                }   
            }
        }
    }
    return -1;
}

void bingo(vector<int> calledNums, vector<vector<vector<int>>> boards)
{
    for(auto num : calledNums)
    {
        int win = updateBoards(boards, num);
        if(win != -1)
        {
            cout << num << " * " << win;
            break;
        }
    }
}

int main() {
    vector<int> calledNums;
    vector<vector<vector<int>>> boards;

    processNums(calledNums);
    processBoards(boards);

    bingo(calledNums, boards);
}
