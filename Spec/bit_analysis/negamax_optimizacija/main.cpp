#include <iostream>
#include <cstdlib>
//#include <conio.h>
#include <ctime>
#include <fstream>
#include<vector>
#include <stdint.h>


using namespace std;

const int INF=1000000;
const int MAX_DEPTH=6; // Povećana dubina za bolju evaluaciju

bool provocation = false; // used to display a provocative screen
char input[43]; // There are 42 places to play in the board .. this array represent them
void Board();
int PlayOut = 0;
int EVA = 0;
// EVA and PlayOut are working while NegaMax Function is working .. in NegaMax's way it will definitely make any winning move
// as it goes deep so when this happens PlayOut increases by 1 and EVA increases by 1 if its a winnning move or decreases by 1 if it the opposite
// so we can evaluate neutral moves for MiniMax by dividing EVA / PlayOut * 100 so we get a percentage
uint8_t winning();
int GetValue(int t);
int AIManager();
int NegaMax(int Depth, int Alfa, int Beta, char Player);

void clean()
{
    provocation = false;
    for(int i = 1 ; i <= 42 ; i++)
        input[i]=' ';
}

int GetValue(int column) // pass this function a column (1-7) and it will return the position in input array (1-based: 1-42)
{
    if(column > 7 || column < 1)
        return 0;
    int n = 0;
    for(int i = 0 ; i <= 6 ; i++)
    {
        int pos = column + 7*i; // 1-based position: column 1-7 maps to positions 1,8,15,22,29,36,43
        if(pos > 42)
            break;
        if( input[pos] == ' '  )
        {
            n = pos;
            break;
        }
    }
    if ( n == 0 || n > 42 )
        return 0;
    return n;
}


uint8_t winning() {
    // Provera horizontalnih linija (1-based positions: 1-42)
    // Row mapping: row 0 = positions 1-7, row 1 = positions 8-14, ..., row 5 = positions 36-42
    for (int row = 0; row < 6; row++) { // 6 redova
        for (int col = 1; col <= 4; col++) { // Maksimalno 4 startne tačke po redu (columns 1-4)
            int pos = row * 7 + col; // 1-based position
            char symbol = input[pos];
            if (symbol != ' ' &&
                symbol == input[pos + 1] &&
                symbol == input[pos + 2] &&
                symbol == input[pos + 3]) {
                return (symbol == 'X') ? 1 : 2;
            }
        }
    }

    // Provera vertikalnih linija
    for (int col = 1; col <= 7; col++) { // 7 kolona (1-7)
        for (int row = 0; row <= 2; row++) { // Maksimalno 3 startne tačke po koloni
            int pos = row * 7 + col; // 1-based position
            char symbol = input[pos];
            if (symbol != ' ' &&
                symbol == input[pos + 7] &&
                symbol == input[pos + 14] &&
                symbol == input[pos + 21]) {
                return (symbol == 'X') ? 1 : 2;
            }
        }
    }

    // Provera dijagonala (desno-nadole)
    for (int row = 0; row <= 2; row++) { // 3 startne tačke po redu
        for (int col = 1; col <= 4; col++) { // 4 startne tačke po koloni
            int pos = row * 7 + col; // 1-based position
            char symbol = input[pos];
            if (symbol != ' ' &&
                symbol == input[pos + 8] &&
                symbol == input[pos + 16] &&
                symbol == input[pos + 24]) {
                return (symbol == 'X') ? 1 : 2;
            }
        }
    }

    // Provera dijagonala (levo-nadole)
    for (int row = 0; row <= 2; row++) { // 3 startne tačke po redu
        for (int col = 4; col <= 7; col++) { // 4 startne tačke po koloni
            int pos = row * 7 + col; // 1-based position
            char symbol = input[pos];
            if (symbol != ' ' &&
                symbol == input[pos + 6] &&
                symbol == input[pos + 12] &&
                symbol == input[pos + 18]) {
                return (symbol == 'X') ? 1 : 2;
            }
        }
    }

    // Provera da li je tabla puna (positions 1-42)
    for (int i = 1; i <= 42; i++) {
        if (input[i] == ' ') {
            return 0; // Igra se nastavlja
        }
    }

    return 3; // Nerešeno
}


void Board() // Draw board
{
    cout<<endl<<"    1   "<<"    2   "<<"    3   "<<"    4   "<<"    5   "<<"    6   "<<"    7   "<<endl;

    // Display board from top (row 5) to bottom (row 0)
    // Row mapping: row 0 = positions 1-7, row 1 = positions 8-14, ..., row 5 = positions 36-42
    for(int row = 5; row >= 0; row--)
    {
        cout<<string(57,'-')<<endl;
        cout<<"|";
        for(int col = 1; col <= 7; col++)
        {
            int pos = row * 7 + col; // 1-based position
            cout<<"   "<<input[pos]<<"   |";
        }
        cout<<endl;
        cout<<"|";
        for(int col = 1; col <= 7; col++)
        {
            cout<<string(7,' ')<<"|";
        }
        cout<<endl;
    }
    cout<<string(57,'-');
    if(provocation == true)
        cout<<endl<<"Hehe I'm sure of my winning :D "<<endl;
}

void PlayPosition(char XO)
{
    static std::vector<int> moves;
    static size_t currentMoveIndex = 0;

    if (moves.empty() || currentMoveIndex >= moves.size())
    {
        moves.clear();
        int move;

        ifstream inputFile("input.txt");
        if (!inputFile.is_open())
        {
            cerr << "Can't open file" << endl;
            exit(1);
        }

        while (inputFile >> move)
        {
            moves.push_back(move);
        }
        inputFile.close();
        currentMoveIndex = 0;
    }

    if (currentMoveIndex < moves.size())
    {
        int sth = GetValue(moves[currentMoveIndex++]);
        while (sth == 0 || input[sth] != ' ')
        {
            cout << "WARNING: Invalid move or position already taken. Taking the next available position." << endl;
            sth = GetValue(moves[currentMoveIndex++]);
        }

        if (sth != 0)
        {
            input[sth] = XO;
        }
        else
        {
            cout << "ERROR: Invalid move or position already taken." << endl;
            // You might want to handle this error more gracefully, e.g., ask the user for a valid move.
        }
    }
}

int main() // main funkcija gde AI ima prvi potez
{
    srand(time(0));
    clean();
    while (true)
    {
        input[AIManager()] = 'O';  // AI bira potez prvi
        //system("clear");
        Board();
        uint8_t winningtemp = winning();
		//cout << "Velicina winning() je: " << sizeof(winning()) << endl;
        if (winningtemp != 0)
        {
            if (winningtemp == 1){
                cout << endl << "Player 2 WON !";
                return 0;}
            else if (winningtemp == 2){
                cout << endl << "Player 1 WON ! ";
                return 0;}
            else if (winningtemp == 3){
                cout << "You Tie ! ";
                return 0;}
          //  getch();
            clean();
        }
        else
        {
            PlayPosition('X');  // Korisnik bira potez
        }
    }
    return 0;
}

int AIManager() 
{
    float bestScore = -INF;
    int bestPos   = 0;   
    int bestCol   = 4;   

    for (int column = 1; column <= 7; ++column)
    {
        int pos = GetValue(column);  
        if (pos == 0) 
            continue; 

        input[pos] = 'O';
        
        // Proveri da li AI pobedjuje odmah
        if(winning() == 2)
        {
            input[pos] = ' ';
            return pos;
        }
        
        // Proveri da li protivnik pobedjuje u sledećem potezu (blokiraj)
        bool mustBlock = false;
        int blockColumn = 0;
        for(int col = 1; col <= 7; col++)
        {
            int testPos = GetValue(col);
            if(testPos != 0)
            {
                input[testPos] = 'X';
                if(winning() == 1)
                {
                    mustBlock = true;
                    blockColumn = col;
                    input[testPos] = ' ';
                    break;
                }
                input[testPos] = ' ';
            }
        }
        
        // Ako mora da blokira, biraj samo tu kolonu
        if(mustBlock && column != blockColumn)
        {
            input[pos] = ' ';
            continue;
        }
        
        // Resetuj Monte Carlo brojače
        PlayOut = 0;
        EVA = 0;
        
        // NegaMax sa alpha-beta pruning
        int negamaxScore = -NegaMax(1, -INF, INF, 'X');
        
        // Kombinuj NegaMax rezultat sa Monte Carlo evaluacijom
        // Koristimo manje skale da EVA/PlayOut ima realnu težinu
        float score = -negamaxScore; // NegaMax već daje dobre vrednosti
        
        // Monte Carlo evaluacija - daje dodatnu težinu u opsegu -100 do +100
        if(PlayOut != 0)
        {
            float mcEval = (100.0f * EVA) / PlayOut;
            score += mcEval; // Dodaj Monte Carlo evaluaciju direktno
        }
        
        // Bonus za centar (kolona 4 je najbolja)
        if(column == 4)
            score += 10;
        else if(column == 3 || column == 5)
            score += 5;
        
        // Veliki bonus za blokiranje protivničke pobede
        if(mustBlock)
            score += 500;
        
        input[pos] = ' ';

        if (score > bestScore)
        {
            bestScore = score;
            bestPos   = pos;
            bestCol   = column;
        }
    }

    if (bestPos == 0)
        bestPos = GetValue(bestCol);

    return bestPos; 
}


// Heuristička evaluacija pozicije (koristi se na MAX_DEPTH)
int evaluatePosition(char Player)
{
    int score = 0;
    char opponent = (Player == 'O') ? 'X' : 'O';
    
    // Broji potencijalne pobede (2 i 3 u nizu)
    // Ovo je pojednostavljena heuristika
    // Može se poboljšati brojanjem svih mogućih linija
    
    // Za sada vraćamo 0 jer Monte Carlo evaluacija daje bolje rezultate
    // Ali struktura je tu za buduća poboljšanja
    return 0;
}

int NegaMax(int Depth, int Alfa, int Beta, char Player)
{
    uint8_t win=winning();
    
    if(win==2){
        // AI (O) pobedio
        PlayOut++;
        EVA++;
        return 1000 - Depth;
    }
    if(win==1){
        // Player (X) pobedio
        PlayOut++;
        EVA--;
        return -1000 + Depth;
    }
    if(win==3){
        // Nerešeno
        return 0;
    }

   if(Depth>=MAX_DEPTH){
    // Heuristička evaluacija umesto čistog 0
    int eval = evaluatePosition(Player);
    if(Player == 'O')
        return eval;
    else
        return -eval;
   }
   
   int bestScore=-INF;
   int PlayNumber[8] = {0,0,0,0,0,0,0,0};
   
   // Prvo proveri sve kolone za pobede/blokade
   for(int column = 1; column <= 7; column++)
   {
       PlayNumber[column] = GetValue(column);
       if(PlayNumber[column] != 0)
       {
           input[PlayNumber[column]] = Player;
           win = winning();
           if(win != 0)
           {
               PlayOut++;
               if(Player == 'O')
               {
                   EVA++;
                   input[PlayNumber[column]] = ' ';
                   return 1000 - Depth; // Konzistentno sa drugim povratnim vrednostima
               }
               else
               {
                   EVA--;
                   input[PlayNumber[column]] = ' ';
                   return -1000 + Depth; // Konzistentno sa drugim povratnim vrednostima
               }
           }
           input[PlayNumber[column]] = ' ';
       }
   }

   // Sada rekurzivno pretraži
   for(int column=1;column<=7;column++)
   {
    int pos = PlayNumber[column];
    if(pos==0){
        continue;
    }
    input[pos]=Player;
    char nextPlayer=(Player=='O')?'X':'O';
    int score=-NegaMax(Depth+1,-Beta,-Alfa,nextPlayer);
    input[pos]=' ';
    
    if (score > bestScore)
        bestScore = score;
    if (score > Alfa)
        Alfa = score;

    if (Alfa >= Beta)
        break;
   }

   if (bestScore == -INF)
       return 0;

   return bestScore;
}