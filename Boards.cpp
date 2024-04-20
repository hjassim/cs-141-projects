#include <iostream>
#include <string>


#include "Boards.h"


using namespace std;




Boards::Boards() {
   char c = '1';
   for (int i=0; i<3; ++i) {
       for (int j=0; j<3; ++j){
           board[i][j] = " ";
           board[i][j].push_back(c);
           c +=1;
       }
    }


   remainingPieces[0][0] = 2;
   remainingPieces[0][1] = 2;
   remainingPieces[0][2] = 2;
   remainingPieces[1][0] = 2;
   remainingPieces[1][1] = 2;
   remainingPieces[1][2] = 2;
  
   yellowTurn = true;
}




void Boards::displayBoard() {
   for (int i=0; i<3; ++i) {
       cout << "            ";
       for (int j=0; j<3; ++j) {
           cout << board[i][j];
           if (j < 2) {
               cout << "|";
           }
       }
       cout << endl;
       if (i < 2) {
           cout << "             --------" << endl;
       }
   }


}




void Boards::playerMove(){
   displayBoard();


   char pieceSize;
   int square;
   int val;
   string pColor;
   char upperColor;
   bool validInput = false;
    if (yellowTurn == true) {
       val = 0;
   }
   else {
       val =1;
   }
    if (yellowTurn == true){
       pColor = "yellow";
   }
   else {
       pColor = "red";
   }




   if (pColor == "yellow") {
       upperColor = 'Y';
   }
   else {
       upperColor = 'R';
   }




   cout << "a. " << upperColor << upperColor << "  " << remainingPieces[val][0] << " remain." << endl;
   cout << "b. " << upperColor << "   " << remainingPieces[val][1] << " remain." << endl;
   cout << "c. " << pColor[0] << "   " << remainingPieces[val][2] << " remain." << endl;
   cout << "q to exit." << endl;




   textPrompts();
   cout << "Choose action and location, for example a2: " << endl;
   cin >> pieceSize;




   if (pieceSize == 'q') {
       cout << "Exiting the game." << endl;
       return;
   }


   cin >> square;




   if (pieceSize == 'a' && remainingPieces[val][0]== 0) {
       cout << "Invalid move. Try again." << endl;
       playerMove();
   }




   if (pieceSize == 'b' && remainingPieces[val][1]== 0) {
       cout << "Invalid move. Try again." << endl;
       playerMove();
   }


   if (pieceSize == 'c' && remainingPieces[val][2]== 0) {
       cout << "Invalid move. Try again." << endl;
       playerMove();
   }




   if (pieceSize != 'a' && pieceSize != 'b' && pieceSize != 'c') {
       cout << "Invalid move. Try again." << endl;
       playerMove();
   }


   if (square < 1 || square > 9){
       cout << "Invalid move. Try again." << endl;
       playerMove();
   }


   int r = (square - 1) / 3;
   int c = (square - 1) % 3;
   if (board[r][c] == "RR" || board[r][c] == "YY") {
       cout << "Invalid move. Try again." << endl;
       playerMove();
   }


   if (board[r][c][0] == 'Y' || board[r][c][0] == 'R') {
       if (pieceSize != 'a') {
           cout << "Invalid move. Try again." << endl;
       }
   }




   if (pieceSize == 'a') {
       pColor = toupper(pColor.at(0));
       board[r][c] = pColor + pColor;
       remainingPieces[val][0]-=1;
   }
   else if (pieceSize == 'b') {
       pColor = toupper(pColor.at(0));
       board[r][c] = pColor + board[r][c].substr(1);
       remainingPieces[val][1]-=1;
   }
   else if (pieceSize == 'c') {
       board[r][c] = pColor.at(0) + board[r][c].substr(1);
       remainingPieces[val][2]-=1;
   }
   else {
       cout << "Invalid move. Try again." << endl;
   }

   if (checkTie() == true) {
    displayBoard();
    cout << "Tie game." << endl;
    return;
   }

   if (checkWin() == true) {
       displayBoard();
       if ((pColor == "Y") || (pColor == "y")) {
           pColor = "Yellow";
       }
       else if ((pColor == "R") || (pColor == "r")) {
           pColor = "Red";
       }
       cout << pColor << " wins!" << endl;
       return;
   }

   else {
       if (yellowTurn == true) {
           yellowTurn = false;
       }
       else {
           yellowTurn = true;
       }
       playerMove();
   }


}

bool Boards::checkTie() {
    for (int i =0; i<2; ++i) {
        for (int j =0; j<3; ++j) {
            if (remainingPieces[i][j] > 0) {
                return false;
            }
        }

    }
    return true;

}




bool Boards::checkWin(){
   // checks for rows
   for (int i =0; i<3; ++i) {
       if (board[i][0][0] != ' ' && toupper(board[i][0][0]) == toupper(board[i][1][0]) && toupper(board[i][1][0]) == toupper(board[i][2][0])) {
           return true;
       }
   }


   // checks for columns
   for (int j=0; j<3;++j) {
       if (board[0][j][0] != ' ' && toupper(board[0][j][0]) == toupper(board[1][j][0]) && toupper(board[1][j][0]) == toupper(board[2][j][0])) {
           return true;
       }
   }


   //checks for diagonal - left to right
   if (board[0][0][0] != ' ' && toupper(board[0][0][0]) == toupper(board[1][1][0]) && toupper(board[1][1][0]) == toupper(board[2][2][0])) {
       return true;
   }


   //checks for diagonal - right to left
   if (board[0][2][0] != ' ' && toupper(board[0][2][0]) == toupper(board[1][1][0]) && toupper(board[1][1][0]) == toupper(board[2][0][0])) {
       return true;
   }


   return false;
}




void Boards::textPrompts() {
   cout << "It is ";


   if (yellowTurn == true) {
       cout << "yellow";
   }
   else {
       cout << "red";
   }


   cout << "'s turn." << endl;
}