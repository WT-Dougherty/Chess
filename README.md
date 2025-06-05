# A C++ Implementation of Chess
Will Dougherty
<br /><br />

## Overview
This repository contains an implementation of chess using c++.
I'm writing this code with the goal of making it expandable in the future.
Version 1.0 will be the standard version of chess.
See the following sections for version notes.
**Ensure you read Version 1.0.**
It contains general information about my implementation.
<br /><br />

TO COMPILE: g++ ChessClasses.cpp Game.cpp -std=c++17
<br /><br />

## Version 1.0
*Classes:*
- Board:
  - Singleton Class
- Piece:
  - Abstract Class Containing 
- 
TODO:
- There is a problem with the board class. Something to do w singleton implementation. See compilation error
- Had to make number, letter, team public variables in the abstract Piece class. This may cause problems when
new pieces are created with private variables of the same name. Can I make these protected variables? See about
difference between these normal variables & the singleton.