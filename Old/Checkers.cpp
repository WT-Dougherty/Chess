//
// ChessClasses.cpp
//
//
// Created by Will Dougherty on 6/5/25.
//

#include "ChessClasses.h"

//----------------------------------------------------------------------------------------------
// the Board class

// define the single instance
Board* Board::pboard = nullptr;

void Board :: Add( Piece* piece )
{
    char l = piece->letter;
    int n = piece->number;
    boardgrid[ int(l-'a') ][ 8-n ] = piece;
}

Piece* Board :: Remove(char l, int n)
{
    Piece* p = boardgrid[ int(l-'a') ][ 8-n ];
    boardgrid[ int(l-'a') ][ 8-n ] = nullptr;
    return p;
}

Piece* Board :: Return(char l, int n)
{
    return boardgrid[ int(l-'a') ][ 8-n ];
}

void Board :: Capture(char l, int n)
{
    Piece* p = Remove(l, n);
    deadpieces.push_back(p);
}

Board* Board :: GetInstance()
{
    // if singleton has yet to be initialized, initialize it
    if ( pboard == nullptr )
    {
        pboard = new Board();
    }
    return pboard;
}

//----------------------------------------------------------------------------------------------
// the pieces

bool Piece :: InBounds(char nl, int nn)
{
    if ( nl >= 'a' && nl <= 'h' && nn >= 1 && nn <= 8 )
    {
        return true;
    }
    return false;
}
//------------------------------------------
// the king
King :: King(char l, int n, int t):
    letter(l), number(n), team(t)
{
    // place the king on the board
    this->pboard->Add(this);
}

bool King :: ValidMove(char nl, int nn)
{
    // ensure the proposed move is on the board
    if ( InBounds(nl, nn) )
    {
        // ensure the king is allowed to make the proposed move
        if ( abs(nl-letter) <= 1 && abs(nn-number) <= 1)
        {
            // if the new square is either empty or containing an opposing piece
            if ( pboard->Return(nl, nn) == nullptr || pboard->Return(nl, nn)->team != this->team )
            {
                return true;
            }
        }
    }
    return false;
}

void King :: Move(char nl, int nn)
{
    // ensure the move is valid
    if ( ValidMove(nl, nn) )
    {
        Piece* p = pboard->Remove(letter, number);          // the king leaves his square
        if ( pboard->Return(nl, nn) != nullptr )            // if there is an opposing piece on the new square...
        {
            pboard->Capture(nl, nn);                        // capture the opposing piece
        }
        letter = nl;                                        // update the king's location
        number = nn;
        pboard->Add(p);                                     // place the king on the new square
    }
    else
    {
        std::cout << "Invalid Move!" << std::endl;
    }
}

//------------------------------------------
// the queen