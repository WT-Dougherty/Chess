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
//  - GetMove: recieves input from terminal and returns the desired move
//  - PiecetoChar: prints char corresponding to piece
//  - CoordtoIndex: takes a coordinate (in form of user input) and converts it to the corresponding index
//      THE MOST IMPORTANT FUNCTION:
//  - RunGame: Runs a full game of checkers
// 
//  - InBounds: Takes a coordinate (in form of user input) and returns boolean according to if the coordinate is in bounds

class MoveHandler
{
public:
    MoveHandler() {}
    void InitBoard();

    // used for I/O ops
    void PrintBoard();
    Move* GetMove(int team);

    // conversions
    char PiecetoChar(Piece* p);
    int CoordtoIndex(std::string coord);

    void RunGame();
    bool InBounds(std::string coord);

private:
    Move* prev_move;
    Board* board;
};

#endif /* movehandler.h */