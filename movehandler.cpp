//
// movehandler.cpp
//
//
// Created by Will Dougherty on 6/10/25.
//

#include "movehandler.h"
#include <iostream>
#include <algorithm>
#include <string>

void MoveHandler :: InitBoard()
{
    board = new Board();
}

void MoveHandler :: RunGame()
{
    InitBoard();                              // initialize the board
    prev_move = new Move(-1, -1, -1);         // red starts
    
    do
    {
        PrintBoard();

        // get the current move (the move is in bounds if we make it past the following line)
        Move* cur_move = GetMove( prev_move->Team() * -1 );

        // check that the move is valid
        std::vector <int> val_moves = board->GenerateMoves( cur_move->InitIndex(), cur_move->Team(), cur_move, false );         // get a vector of valid moves
        if ( std::find(val_moves.begin(), val_moves.end(), cur_move->FinalIndex()) == val_moves.end() )                         // check that the move is valid
        {
            std::cout << "Invalid Move!\n" << std::endl;
            continue;
        }

        // make sure that the proper team is trying to move
        if ( board->Get(cur_move->InitIndex())->GetTeam() != cur_move->Team() )
        {
            std::cout << "Invalid Move!\n" << std::endl;
        }

        // now we have a valid move...
        // handle a capture if needed
        if ( cur_move->GetCapLoc() != -1 )
        {
            board->Remove( cur_move->GetCapLoc() );     // capture the piece
        }

        // move the piece to its new location
        board->MovePiece(cur_move->InitIndex(), cur_move->FinalIndex());
        
        // update the previous move for the next iteration
        Move* p = prev_move;
        prev_move = cur_move;
        delete p;

    } while ( board->Winner() == 0 );

    // declare the winner
    if ( board->Winner() == 1 ) { std::cout << "Red Wins!" << std::endl; }
    else { std::cout << "Black Wins!" << std::endl; }

    // memory management
    delete board;
}

char MoveHandler :: PiecetoChar(Piece* p)
{
    if ( p->Type() )
    {
        if ( p->GetTeam() == 1 ) { return 'R'; }
        return 'B';
    }
    if ( p->GetTeam() == 1 ) { return 'r'; }
    return 'b';
}

int MoveHandler :: CoordtoIndex(std::string coord)
{
    return 8 * int( '8'-coord[1] ) + int( coord[0]-'a' );
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
                std::cout << PiecetoChar( board->Get(row*8 + col) ) << ' ';
            }
        }
        std::cout << std::endl;
    }
}

Move* MoveHandler :: GetMove(int team)
{
    std::string init_l, final_l;

    if (team==1) { std::cout << "Red's Turn" <<std::endl; }
    else{ std::cout << "Black's Turn" << std::endl; }

    std::cout << "What Piece Do You Want To Move?";
    std::cin >> init_l;
    std::cout << "\nWhere Do You Want To Move It?";
    std::cin >> final_l;
    std::cout << "\nGenerating Move..." << std::endl;

    // check in bounds
    if ( !InBounds(init_l) || !InBounds(final_l) )
    {
        std::cout << "\nMove Is Out Of Bounds!";
        GetMove(team);
    }

    // check no wraparound
    if ( init_l[0] >= 'g' && final_l[0] <= 'b'
      || init_l[0] <= 'b' && final_l[0] >= 'g' )
    {
        std::cout << "\nInvalid Move!" << std::endl;
    }

    Move* move = new Move( CoordtoIndex(init_l), CoordtoIndex(final_l), team );
    return move;
}

bool MoveHandler::InBounds(std::string coord)
{
    return coord.length() == 2
        && coord[0] >= 'a' && coord[0] <= 'h'
        && coord[1] >= '1' && coord[1] <= '8';
}