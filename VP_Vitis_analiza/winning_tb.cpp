#include <stdio.h>
#include "winning_hls.cpp"

int main() {
    unsigned char board[42];
    int result;
    
    // Test case 1: Prazna tabla
    for(int i = 0; i < 42; i++) board[i] = ' ';
    winning(board, &result);
    printf("Test 1 (prazna tabla): %d\n", result);
    
    // Test case 2: Horizontalna pobeda X
    for(int i = 0; i < 42; i++) board[i] = ' ';
    board[0] = board[1] = board[2] = board[3] = 'X';
    winning(board, &result);
    printf("Test 2 (X pobedio): %d\n", result);
    
    return 0;
}
