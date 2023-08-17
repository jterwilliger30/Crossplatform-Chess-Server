# chess
Uses bitboard representation... 1 bitboard per each piece type per player (12 total). Only pawn movement differs between players (right shift vs. left shift).

# TODO
- Implement GUI, and a message passing protocol b/w engine and GUI
- What to do about virtual destructor... probably not needed anymore with shared_ptrs
- Unicode characters printed by print_board() don't work for Windows... need to check linux as well
- It seems the colors of the unicode chess pieces are not standardized :(

# Build
- Build assumes you have Protobuf 21.12 installed to /usr/local/lib and /usr/local/include
