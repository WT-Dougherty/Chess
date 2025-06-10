//
// Game.cpp
//
//
// Created by Will Dougherty on 6/5/25.
//

#include "Move.h"

int Move :: GetInitPos_x()
{
    return init_letter - 'a';
}

int Move :: GetFinalPos_x()
{
    return final_letter - 'a';
}

int Move :: GetInitPos_y()
{
    return 8 - init_number;
}

int Move :: GetFinalPos_y()
{
    return 8 - final_number;
}

std::string Move :: GetType()
{
    return ptype;
}


bool Move :: InBounds()
{
    // ensure that all coordinates involved in the move are inbounds
    if ( final_letter >= 'a' && final_letter <= 'h' && final_number >= 1 && final_number <= 8
       && init_letter >= 'a' && init_letter <= 'h' && init_number >= 1 && init_number <= 8 )
    {
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------------------------
bool PawnMove :: CheckDir()
{
    if ( final_y * team < init_y )
    {
        return true;
    }
    return false;
}

bool PawnMove :: ValidMove()
{
    // ensure the move is valid
    if ( InBounds() )
    {
        // TODO
    }
}