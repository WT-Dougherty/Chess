//
// Game.h
//
//
// Created by Will Dougherty on 6/5/25.
//

#ifndef Move_h
#define Move_h

#include <iostream>

// coordinates on board will be defined as follows:
//  - top left: (0,0)
//  - top right: (7,0)
//  - bottom left: (0,7)
//  - bottom right:(7,7)
// this is inline with the way the 2D board array is indexed.

// team:
//  - red team is on the bottom & black is on the top
//      - when team is red, team = 1
//      - when team is black, team = -1

// TODO:
//  - Move should not have an initialization function (pure virtual)
//  - Implement PawnMove, Kingmove
//  - Question: Do I need to redefine variables init_letter, final_letter, etc.

class Move
{
public:
    Move() {}
    virtual ~Move() {}
    
    int GetInitPos_x();
    int GetFinalPos_x();
    int GetInitPos_y();
    int GetFinalPos_y();

    bool InBounds();
    virtual bool ValidMove() = 0;

protected:
    char init_letter, final_letter;
    int init_number, final_number, team;
};

//---------------------------------------------------------------------------------------------

class PawnMove : public Move
{
public:
    PawnMove(char li, int ni, char lf, int nf, int team):
        init_letter(li), final_letter(lf), init_number(ni), final_number(nf), team(team) {}
    
    bool ValidMove() override;
}

//---------------------------------------------------------------------------------------------
class KingMove : public Move
{
public:
    KingMove(char li, int ni, char lf, int nf, int team):
        init_letter(li), final_letter(lf), init_number(ni), final_number(nf), team(team) {}
    
        bool ValidMove() override;
}



// MOVE THIS TO A NEW FILE
//---------------------------------------------------------------------------------------------
// MoveHandler: handles requests and runs the simulation
class MoveHandler
{
public:
    MoveHandler();
    RunGame();
    ValidMove();

}

#endif /* Move_h */