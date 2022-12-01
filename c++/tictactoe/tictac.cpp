#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void drawboard_game( vector<vector<char>> board_game);
char win_check( vector<vector<char>> board_game);
int main()
{
    vector<vector<char>> board_game;
    for(int i = 0 ; i < 3; i++){
        vector<char> temp;
        for(int j = 0 ; j < 3 ; j++){
            temp.push_back(' ');
        }
        board_game.push_back(temp);
    }
    char player = 'X';
    char player_winner = ' ';
    int row;
    int column;
    bool is_valid;
    bool is_row;
    bool is_column;
    while (player_winner == ' ')
    {
        is_valid = false;
        is_row = false;
        is_column = false;
        drawboard_game(board_game);
        if (player == 'X')
        {
            cout << 'X';
        }
        else
        {
            cout << 'O';
        }
        cout << "'s turn:" << endl;
        is_valid = false;
        while (!is_valid)
        {
            is_row = false;
            while (!is_row)
            {
                cout << "row: ";
                cin >> row;
                if (row == 1 || row == 2 || row == 3)
                {
                    is_row = true;
                }
                else
                {
                    cout << endl
                         << "Invalid!" << endl;
                }
            }
            is_column = false;
            while (!is_column)
            {
                cout << "column: ";
                cin >> column;
                if (column == 1 || column == 2 || column == 3)
                {

                    is_column = true;
                }
                else
                {
                    cout << endl
                         << "Invalid!" << endl;
                }
            }
            if (board_game[row - 1][column - 1] == ' ')
            {
                board_game[row - 1][column - 1] = player;
                is_valid = true;
                if (player == 'X')
                {
                    player = 'O';
                }
                else
                {
                    player = 'X';
                }
            }
            else
            {
                cout << "Already used space." << endl;
                cout << "Input another space:" << endl
                     << endl;
                drawboard_game(board_game);
            }
        }
        cout << endl;
        player_winner = win_check(board_game);
        if (player_winner == 'X' || player_winner == 'O')
        {
            drawboard_game(board_game);
            cout << "Congratulations! player ";
            if (player_winner == 'X')
            {
                cout << 'X';
            }
            else
            {
                cout << 'O';
            }
            cout << " wins!" << endl;
        }
        else if (player_winner == 'T')
        {
            drawboard_game(board_game);
            cout << "It's a tie!" << endl;
        }
    }
    system("pause");
    return 0;
}
void drawboard_game( vector<vector<char>> board_game)
{
    cout << "     1   2   3" << endl;
    cout << " -------------" << endl;

    cout << " 1"
         << " | " << board_game[0][0] << " | " << board_game[0][1] << " | "
         << board_game[0][2] << " | " << endl;
    cout << " -------------" << endl;
    cout << " 2"
         << " | " << board_game[1][0] << " | " << board_game[1][1] << " | "
         << board_game[1][2] << " | " << endl;
    cout << " -------------" << endl;
    cout << " 3"
         << " | " << board_game[2][0] << " | " << board_game[2][1] << " | "
         << board_game[2][2] << " | " << endl;
    cout << " -------------" << endl;
}
char win_check( vector<vector<char>> board_game)
{
    for (int i = 0; i < 3; i++)
    {
        if (board_game[i][0] == board_game[i][1] && board_game[i][0] == board_game[i]
                                                                                  [2])
        {
            return board_game[i][0];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (board_game[0][i] == board_game[1][i] && board_game[0][i] == board_game[2]
                                                                                  [i])
        {
            return board_game[0][i];
        }
    }
    if (board_game[0][0] == board_game[1][1] && board_game[1][1] == board_game[2][2])
    {
        return board_game[0][0];
    }
    if (board_game[0][2] == board_game[1][1] && board_game[1][1] == board_game[2][0])
    {
        return board_game[0][2];
    }
    return ' ';
}