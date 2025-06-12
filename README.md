# A C++ Implementation of Checkers
Will Dougherty
<br /><br />

TO COMPILE: g++ board.cpp movehandler.cpp main.cpp -std=c++17
<br /><br />

## Version 1.0:

### How To Play:
Terminal will prompt user to input the location (as a coordinate of the form 'a3', 'h4', 'c1', etc.) of the piece they want to move.
Terminal will then prompt the user to input the location they want to move that piece to.
Provided the move is valid, the piece will be moved to the new location and the updated board will be sent to output.
If the move is invalid, the user will be prompted to enter a new set of coordinates.
**The red team always starts**.
Normal pawns are represented by lowercase r's and b's and kings are represented by uppercase R's and B's.
It is red vs. black. A team wins and the game terminates when one team has no pieces left.
*Note: In Version 1, only single jumps are allowed. No double jumps*
<br /><br />

### Program Description:

#### General Overview:
I wrote modular code that supports future expansion. The program consists of four classes: Move, Piece, Board, & MoveHandler.
At the highest level, a MoveHandler object is created. When the game is run, the MoveHandler object initializes a Board object, which populates itself with Piece objects. The Piece class is abstract, with two concrete child classes, PawnPiece and KingPiece. Since both inherit from the Piece class, they can populate the board. Then, for as long as both teams have pieces on the board, the MoveHandler object prompts the user to enter moves. It packages the user input into Move objects that it sends to the board to process.
<br /><br />

#### Specific Functions/ Attributes for Each Class

These class descriptions can also be found as comments in the header files of the corresponding classes.
<br />

##### Move
- MOVE ATTRIBUTES:
    - initial_index: starting index
    - final_index: final index
    - team: the team that is making the move (red/ black -> 1/ -1)
    - capture: boolean that indicates if a piece is being captured in the move

- MOVE METHODS:
    - InitIndex: returns starting index
    - FinalIndex: returns final index
    - Team: returns the team that is making the move
    - SetCap: sets the capture parameter to the desired boolean
    - GetCapLoc:
        - If a piece is being captured: returns the index of the captured piece 
        - Else: returns -1

##### Piece
- PIECE ATTRIBUTES:
    - team: red team is on the bottom & black is on the top
        - when team is red, team = 1
        - when team is black, team = -1

- index:
    - top left of grid is index 0
        - first row is 0-7
        - second row is 8-15
        -        ...
        - eigth row is 56-63

- PIECE METHODS:
    - Type: returns true if piece is a king, false if pawn
    - GetTeam: returns the team



##### Board
- BOARD ATTRIBUTES:
    - board: vector of length 64 representing the board
    - num_red: number of remaining red pieces
    - num_black: number of remaining black pieces

- BOARD METHODS:
    - Winner:
        - returns 0 if each team has pieces (no winner)
        - returns 1 if no black pieces (red wins)
        - returns -1 if no red pieces (black wins)
    - AddPawn: adds pawn at index
    - UpgradePawn: upgrades pawn at index to king
    - Remove: removes piece from index
    - MovePiece: moves the piece at indexi to indexf
    - Get: returns a pointer to the piece at index
    - GenerateMoves: returns a list of the indexes that the piece at index can move to

note: black team is at top of board, red team is at botton of board

##### MoveHandler
- MOVEHANDLER ATTRIBUTES:
    - prev_move: the previous move
    - board: the board

- MOVEHANDLER METHODS:
    - BoardInit: Initializes the 
    - PrintBoard: prints the board in the terminal
    - GetMove: recieves input from terminal and returns the desired move
    - PiecetoChar: prints char corresponding to piece
    - CoordtoIndex: takes a coordinate (in form of user input) and converts it to the corresponding index
    - THE MOST IMPORTANT FUNCTION:
        - RunGame: Runs a full game of checkers
    - InBounds: Takes a coordinate (in form of user input) and returns boolean according to if the coordinate is in bounds