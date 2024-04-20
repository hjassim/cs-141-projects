#ifndef BOARDS_H
#define BOARDS_H


#include <iostream>
#include <string>


using namespace std;




class Boards {
   private:
       string board[3][3];
       int remainingPieces[2][3];
       bool yellowTurn;
    
   public:
       Boards();
       void displayBoard();
       void playerMove();
       bool checkTie();
       bool checkWin();
       void textPrompts();


};




#endif // BOARDS_H