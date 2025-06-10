//
// board.h
//
//
// Created by Will Dougherty on 6/10/25.
//

#include "board.h"
#include "piece.h"
#include <iostream>

Board :: Board():
    board(64, nullptr), num_red(12), num_black(12)
{
    for ( int i=0; i<=6; i+=2 )
    {
        // add black pieces
        AddPawn( i, -1 );
        AddPawn( 9+i, -1 );
        AddPawn( 16+i, -1 );

        // add red pieces
        AddPawn( 41+i, 1 );
        AddPawn( 48+i, 1 );
        AddPawn( 57+i, 1 );
    }
}

int Board :: Winner()
{
    if ( num_black == 0 ) { return 1; }
    else if ( num_red == 0 ) { return -1; }
    return 0;
}

void Board :: AddPawn(int index, int team)
{
    Piece* newpiece = new PawnPiece(index, team);   // allocate memory for piece
    board[index] = newpiece;                        // add piece to board
}

void Board :: UpgradePawn(int index)
{
    int t = board[index]->GetTeam();                // get team
    delete board[index];                            // free memory, remove piece

    Piece* newpiece = new KingPiece(index, t);      // allocate memory for king piece
    board[index] = newpiece;                        // add piece to board
}

void Board :: Remove(int index)
{
    int t = board[index]->GetTeam();                // get team
    delete board[index];                            // free memory, remove piece

    if ( t == 1 ) { num_red--; }                    // update the piece count
    else { num_black--; }
    
    board[index] = nullptr;                         // board management
}

Piece* Board :: Get(int index)
{
    return board[index];
}