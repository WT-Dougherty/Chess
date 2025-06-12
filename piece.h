//
// piece.h
//
//
// Created by Will Dougherty on 6/10/25.
//

#ifndef piece_h
#define piece_h

// PIECE ATTRIBUTES:
// team:
//  - red team is on the bottom & black is on the top
//      - when team is red, team = 1
//      - when team is black, team = -1

// index:
//  - top left of grid is index 0
//      - first row is 0-7
//      - second row is 8-15
//               ...
//      - eigth row is 56-63

// PIECE METHODS:
//  - Type: returns true if piece is a king, false if pawn
//  - GetTeam: returns the team

class Piece
{
public:
    Piece(int index, int team) : index(index), team(team) {}
    virtual ~Piece() {}
    virtual bool Type() = 0;

    int GetTeam() { return team; }

protected:
    int index;
    int team;
};

class KingPiece : public Piece
{
public:
    KingPiece(int index, int team):
        Piece(index, team) {}
    
    bool Type() override { return true; }
};

class PawnPiece : public Piece
{
public:
    PawnPiece(int index, int team):
        Piece(index, team) {}
    
    bool Type() override { return false; }
};

#endif /* piece.h */