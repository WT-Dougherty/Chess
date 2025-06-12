//
// movehandler.h
//
//
// Created by Will Dougherty on 6/10/25.
//

#ifndef movehandler_h
#define movehandler_h

#include "board.h"
#include "move.h"
#include <iostream>
#include <vector>

// MOVEHANDLER ATTRIBUTES:
//  - prev_move: the previous move
//  - board: the board

// MOVEHANDLER METHODS:
//  - BoardInit: Initializes the 
//  - PrintBoard: prints the board in the terminal
//  - PiecetoChar: prints char corresponding to piece
//  - GetMove: recieves input from terminal and returns the desired move
//  - 

class MoveHandler
{
public:
    MoveHandler() {}

    // used for I/O ops
    void PrintBoard();
    char PiecetoChar(Piece* p);
    int CoordtoIndex(std::string coord);
    Move* GetMove(int team);

    void RunGame();
    void InitBoard();
    bool ValidateMove();
    bool InBounds(std::string coord);
    int CaptureMove();

private:
    Move* prev_move;
    Board* board;
};

#endif /* movehandler.h */