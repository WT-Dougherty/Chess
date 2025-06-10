//
// move.h
//
//
// Created by Will Dougherty on 6/10/25.
//

#ifndef move_h
#define move_h

// MOVE ATTRIBUTES:
//  - initial_index: starting index
//  - final_index: final index
//  - team: the team that is making the move (red/ black -> 1/ -1)

// MOVE METHODS:
//  - InitIndex: returns starting index
//  - FinalIndex: returns final index
//  - Team: returns the team that is making the move

class Move
{
public:
    Move(int initial_index, int final_index, int team):
        initial_index(initial_index), final_index(final_index), team(team) {}

    int InitIndex() { return initial_index; }
    int FinalIndex() { return final_index; }
    int Team() { return team; }

private:
    int initial_index;
    int final_index;
    int team;
};

#endif /* move.h */