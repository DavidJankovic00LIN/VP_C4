#include <ap_int.h>
#include <hls_stream.h>

// BRAM interface - Vitis HLS koristi AXI Lite za BRAM pristup
// Treba da definišeš kako ćeš pristupati BRAM-u
// Opcija 1: Array parameter (najjednostavnije za po�?etak)
void winning(unsigned char board[42],int *result) {
    #pragma HLS INTERFACE ap_ctrl_hs port=return
    #pragma HLS INTERFACE bram port=board
    #pragma HLS INTERFACE ap_none port=result
    
    // Provera horizontalnih linija
    for(int row = 0; row < 6; row++) {
        for (int col = 0; col <= 3; col++) {
            int pos = row * 7 + col;
            unsigned char symbol = board[pos];
            
            if (symbol != ' ' &&
                symbol == board[pos + 1] &&
                symbol == board[pos + 2] &&
                symbol == board[pos + 3]) {
                *result = (symbol == 'X') ? 1 : 2;
                return;
            }
        }
    }
    
    // Provera vertikalnih linija
    for (int col = 0; col < 7; col++) {
        for (int row = 0; row <= 2; row++) {
            int pos = row * 7 + col;
            unsigned char symbol = board[pos];
            
            if (symbol != ' ' &&
                symbol == board[(row + 1) * 7 + col] &&
                symbol == board[(row + 2) * 7 + col] &&
                symbol == board[(row + 3) * 7 + col]) {
                *result = (symbol == 'X') ? 1 : 2;
                return;
            }
        }
    }
    
    // Provera dijagonala (desno-nadole)
    for (int row = 0; row <= 2; row++) {
        for (int col = 0; col <= 3; col++) {
            int pos = row * 7 + col;
            unsigned char symbol = board[pos];
            
            if (symbol != ' ' &&
                symbol == board[(row + 1) * 7 + col + 1] &&
                symbol == board[(row + 2) * 7 + col + 2] &&
                symbol == board[(row + 3) * 7 + col + 3]) {
                *result = (symbol == 'X') ? 1 : 2;
                return;
            }
        }
    }
    
    // Provera dijagonala (levo-nadole)
    for (int row = 0; row <= 2; row++) {
        for (int col = 3; col < 7; col++) {
            int pos = row * 7 + col;
            unsigned char symbol = board[pos];
            
            if (symbol != ' ' &&
                symbol == board[(row + 1) * 7 + col - 1] &&
                symbol == board[(row + 2) * 7 + col - 2] &&
                symbol == board[(row + 3) * 7 + col - 3]) {
                *result = (symbol == 'X') ? 1 : 2;
                return;
            }
        }
    }
    
    // Provera da li je tabla puna
    for (int i = 0; i < 42; i++) {
        if (board[i] == ' ') {
            *result = 0; // Igra se nastavlja
            return;
        }
    }
    
    *result = 3; // Nerešeno
}
