//
// board.h
//
//
// Created by Will Dougherty on 6/10/25.
//

#ifndef board_h
#define board_h

#include "piece.h"
#include "move.h"
#include <vector>

// BOARD ATTRIBUTES:
//  - board: vector of length 64 representing the board
//  - num_red: number of remaining red pieces
//  - num_black: number of remaining black pieces

// BOARD METHODS:
//  - Winner:
//      - returns 0 if each team has pieces (no winner)
//      - returns 1 if no black pieces (red wins)
//      - returns -1 if no red pieces (black wins)
//  - AddPawn: adds pawn at index
//  - UpgradePawn: upgrades pawn at index to king
//  - Remove: removes piece from index
//  - MovePiece: moves the piece at indexi to indexf
//  - Get: returns a pointer to the piece at index
//  - GenerateMoves: returns a list of the indexes that the piece at index can move to

// note: black team is at top of board
//       red team is at botton of board

class Board
{
public:
    Board();
    
    int Winner();
    void AddPawn(int index, int team);
    void UpgradePawn(int index);
    void Remove(int index);
    void MovePiece(int indexi, int indexf);
    Piece* Get(int index) { return board[index]; }
    std::vector<int> GenerateMoves(int index, int team, Move* move, bool flag);

private:
    std::vector< Piece* > board;
    int num_red, num_black;
};

#endif /* board.h */