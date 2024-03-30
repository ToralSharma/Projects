#include <stdio.h>

char board[3][3]; // 3x3 game board

// Function to initialize the game board
void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to display the game board
void display_board() {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int is_game_over() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    // Check for draw
    int draw = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                draw = 0;
                break;
            }
        }
    }
    if (draw) {
        return 2;
    }
    return 0;
}

// Function to make a move
void make_move(int row, int col, char player) {
    board[row][col] = player;
}

int main() {
    int row, col;
    char player = 'X';
    init_board();

    printf("Welcome to Tic-Tac-Toe!\n");
    display_board();

    while (1) {
        printf("Player %c's turn. Enter row and column (0-2): ", player);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        make_move(row, col, player);
        display_board();

        int game_result = is_game_over();
        if (game_result == 1) {
            printf("Player %c wins!\n", player);
            break;
        } else if (game_result == 2) {
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
