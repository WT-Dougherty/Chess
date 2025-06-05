//
// ChessClasses.h
//
//
// Created by Will Dougherty on 6/5/25.
//

#ifndef ChessClasses_h
#define ChessClasses_h

#include <iostream>
#include <string>
#include <vector>

// The Piece Class (Abstract)
class Piece
{
public:
    virtual Piece();
    virtual Move(char letter, int number);
};

// The Board class (Singleton)
class Board
{
private:
    Board() {}
    Init();


    static Board* InstancePtr;                          // Pointer to the single board instance
    std::vector <std::vector <Piece*>> boardgrid;       // The grid of pieces

public:
    // Delete the copy constructor
    Board( const Board& brdobj ) = delete;

    // Get the Singleton Instance
    static Board* GetInstance();
};

#endif /* ChessClasses_h */