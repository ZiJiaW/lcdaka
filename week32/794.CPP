class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        function<bool(int)> dfs = [&](int d) {
            if (d == 1) {
                if (board[0][0]+board[0][1]+board[0][2] == 3*'O' ||
                    board[1][0]+board[1][1]+board[1][2] == 3*'O' ||
                    board[2][0]+board[2][1]+board[2][2] == 3*'O' ||
                    board[0][0]+board[1][0]+board[2][0] == 3*'O' ||
                    board[0][1]+board[1][1]+board[2][1] == 3*'O' ||
                    board[0][2]+board[1][2]+board[2][2] == 3*'O' ||
                    board[0][0]+board[1][1]+board[2][2] == 3*'O' ||
                    board[0][2]+board[1][1]+board[2][0] == 3*'O')
                    return false;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[i][j] == 'X') {
                            board[i][j] = ' ';
                            if (dfs(0)) return true;
                            board[i][j] = 'X';
                        }
                    }
                }
                return false;
            } else {
                if (board[0][0]+board[0][1]+board[0][2] == 3*'X' ||
                    board[1][0]+board[1][1]+board[1][2] == 3*'X' ||
                    board[2][0]+board[2][1]+board[2][2] == 3*'X' ||
                    board[0][0]+board[1][0]+board[2][0] == 3*'X' ||
                    board[0][1]+board[1][1]+board[2][1] == 3*'X' ||
                    board[0][2]+board[1][2]+board[2][2] == 3*'X' ||
                    board[0][0]+board[1][1]+board[2][2] == 3*'X' ||
                    board[0][2]+board[1][1]+board[2][0] == 3*'X')
                    return false;
                int count = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[i][j] == 'O') {
                            count++;
                            board[i][j] = ' ';
                            if (dfs(1)) return true;
                            board[i][j] = 'O';
                        }
                    }
                }
                return count == 0;
            }
        };
        int diff = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') diff++;
                else if (board[i][j] == 'O') diff--;
            }
        }
        if (diff != 0 && diff != 1) return false;
        return dfs(diff);
    }
};