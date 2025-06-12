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
        initial_index(initial_index), final_index(final_index), team(team), capture(false) {}

    int InitIndex() { return initial_index; }
    int FinalIndex() { return final_index; }
    int Team() { return team; }
    void SetCap(bool b) { capture = b; }
    int GetCapLoc()
    {
        if (capture)
        {
            if ( initial_index > final_index )
            {
                return initial_index - 8 - (initial_index-16-final_index) / 2;
            }
            return initial_index + 8 - (initial_index+16-final_index) / 2;
        }
        return -1;
    }

private:
    int initial_index;
    int final_index;
    int team;
    bool capture;
};

#endif /* move.h */