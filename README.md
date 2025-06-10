# A C++ Implementation of Chess
Will Dougherty
<br /><br />

TO COMPILE: g++ board.cpp movehandler.cpp main.cpp -std=c++17
<br /><br />

## Version 1.0

move.h
// MOVE ATTRIBUTES:
//  - initial_index: starting index
//  - final_index: final index
//  - team: the team that is making the move (red/ black -> 1/ -1)

// MOVE METHODS:
//  - InitIndex: returns starting index
//  - FinalIndex: returns final index
//  - Team: returns the team that is making the move



piece.h
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



board.h
// BOARD ATTRIBUTES:
//  - board: vector of length 64 representing the board
//  - num_red: number of remaining red pieces
//  - num_black: number of remaining black pieces

// BOARD METHODS:
//  - Winner:
//      - returns 0 if each team has pieces (no winner)
//      - returns 1 if no black pieces (red wins)
//      - returns -1 if no red pieces (black wins)
//  - AddPawn: adds pawn at index
//  - UpgradePawn: upgrades pawn at index to king
//  - Remove: removes piece from index
//  - Get: returns a pointer to the piece at index

// note: black team is at top of board
//       red team is at botton of board