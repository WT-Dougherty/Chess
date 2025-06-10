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
//  - TeamtoChar: maps (1,-1) --> ('R','B')
//  - GetMove: recieves input from terminal and returns the desired move
//  - 

class MoveHandler
{
public:
    MoveHandler() {}

    // used for I/O ops
    void PrintBoard();
    char TeamtoChar(int t);
    Move* GetMove();

    void RunGame();
    bool ValidateMove();
    int CaptureMove();

private:
    Move* prev_move;
    Board* board;
};

#endif /* movehandler.h */