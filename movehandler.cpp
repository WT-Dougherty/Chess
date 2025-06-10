//
// movehandler.cpp
//
//
// Created by Will Dougherty on 6/10/25.
//

#include "movehandler.h"
#include <iostream>

void MoveHandler :: RunGame()
{
    board = new Board();                // initialize the board
    
    do while
    {
        PrintBoard();

    } ( board->Winner() != 0 );
}


char MoveHandler :: TeamtoChar(int t)
{
    if ( t == 1 ) { return 'R'; }
    return 'B';
}

void MoveHandler :: PrintBoard()
{
    std::cout << "   a b c d e f g h " << std::endl << std::endl;      // print the column labels
    for ( int row=0; row<=7; row++ )
    {
        std::cout << std::to_string(8-row) << "  ";                    // print the row labels
        for (int col=0; col<=7; col++ )
        {
            if ( board->Get(row*8 + col) == nullptr )
            {
                std::cout << "0 ";
            }
            else
            {
                std::cout << TeamtoChar( board->Get(row*8 + col)->GetTeam() ) << ' ';
            }
        }
        std::cout << std::endl;
    }
}

Move* MoveHandler :: GetMove()
{
    ;
}