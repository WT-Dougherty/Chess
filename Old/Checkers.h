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
#include <cstdlib>

//----------------------------------------------------------------------------------------------
// the Board class (singleton)
class Piece;                                            // forward declaration

class Board
{
private:
    // private constructor
    Board():
        boardgrid(std::vector<std::vector<Piece*>>(8, std::vector<Piece*>(8, nullptr))) {}

    // attributes
    static Board* pboard;                               // pointer to the single board instance
    std::vector <std::vector <Piece*>> boardgrid;       // the grid of pieces
    std::vector <Piece*> deadpieces;                    // the pieces that have been taken

public:
    // delete the copy constructor
    Board( const Board& brdobj ) = delete;
    
    // public methods used to update/ access the board
    void Add( Piece* piece );
    Piece* Remove(char l, int n);
    Piece* Return(char l, int n);
    void Capture(char l, int n);

    // get the single board instance
    static Board* GetInstance();
};

//----------------------------------------------------------------------------------------------
// the Piece class (abstract)
class Piece
{
protected:
    Board* pboard;                                      // pointer to the board instance (accessable to all pieces)
public:
    virtual ~Piece() {}
    virtual bool ValidMove(char nl, int nn) = 0;
    virtual void Move(char nl, int nn) = 0;
    
    bool InBounds(char nl, int nn);

    char letter;
    int number, team;
};

//----------------------------------------------------------------------------------------------
// there are two types of pieces: normal and king
class Man : public Piece
{
    ;
};

class King : public Piece
{
private:
    // letter, number is akin to position (ex. E5)
    char letter;
    int number, team;
public:
    King(char l, int n, int t);
    ~King() {}
    bool ValidMove(char nl, int nn) override;
    void Move(char nl, int nn) override;
};

// note: an empty square is represented by the nullptr

#endif /* ChessClasses_h */