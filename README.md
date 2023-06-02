# chess
Uses bitboard representation... 1 bitboard per each piece type per player (12 total). Only pawn movement differs between players (right shift vs. left shift).

# TODO
- Consider some sort of global "pop_bit" function that sends a signal to all pieceboards to remove that bit if they have it...
- Left off at rook attack...

# To Research
- Can an abstract class have a static member initialized at run-time? Ideally this would allow all pieces to share a single gamestate.