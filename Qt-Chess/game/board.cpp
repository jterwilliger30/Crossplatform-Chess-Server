#include "./board.hpp"

#include <array>
#include <bitset>
#include <iostream>
#include <cstdlib>

#include "piece.hpp"

#include "./pieces/pawn.hpp"
#include "./pieces/bishop.hpp"
#include "./pieces/rook.hpp"
#include "./pieces/king.hpp"
#include "./pieces/queen.hpp"
#include "./pieces/knight.hpp"

namespace {

template <class T>
Bitboard castAndComputeMove(PlayerSPtr player, char piece_type, Bitboard isolated_piece)
{
    std::shared_ptr<T> X_Board = std::dynamic_pointer_cast<T>(player->pieceboard_map[piece_type]);
    if (X_Board)
        return X_Board->compute_attack(isolated_piece);
    else
        throw std::invalid_argument("Cast failed");
}

void getUserMove(PlayerSPtr player, char& piece_type, std::pair<Spot, Spot>& start_end)
{
    std::cout << (static_cast<bool>(player->isWhite) ? "White" : "Black") << " player's turn. \n";
    std::cout << "Please enter your move in long algebraic notation:\t";
    std::string user_input, str_start, str_end;

    while (true)
    {
        std::getline(std::cin, user_input);
        std::erase(user_input, ' ');
        for (char& c : user_input)
        {
            if (isalpha(static_cast<unsigned char>(c)))
                c = toupper(c);
        }
        piece_type = user_input[0];
        str_start = user_input.substr(1, 2);
        str_end = user_input.substr(3, 2);

        try
        {
            std::array<char, 6> valid_types = {'P', 'B', 'R', 'N', 'Q', 'K'};
            if (std::find(valid_types.begin(), valid_types.end(), piece_type) == valid_types.end())
                throw std::out_of_range("Invalid piece type");
            start_end = {::str_to_spot.at(str_start), ::str_to_spot.at(str_end)};
            break;
        }
        catch (std::out_of_range)
        {
            std::cout << "\nInvalid... Please re-enter your choice:\t";
            continue;
        }
    }
}
}

Board::Board(PlayerSPtr p1, PlayerSPtr p2, BitboardSPtr GAMESTATE, BitboardSPtr P1_OCCUPIED, BitboardSPtr P2_OCCUPIED) :
    gamestate(GAMESTATE),
    p1_occupied(P1_OCCUPIED),
    p2_occupied(P2_OCCUPIED),

    player1(p1),
    player2(p2),

    p1_pawn(std::make_shared<Pawnboard>(p1, GAMESTATE, P2_OCCUPIED)),
    p1_bishop(std::make_shared<Bishopboard>(p1, GAMESTATE, P2_OCCUPIED)),
    p1_rook(std::make_shared<Rookboard>(p1, GAMESTATE, P2_OCCUPIED)),
    p1_knight(std::make_shared<Knightboard>(p1, GAMESTATE, P2_OCCUPIED)),
    p1_queen(std::make_shared<Queenboard>(p1, GAMESTATE, P2_OCCUPIED)),
    p1_king(std::make_shared<Kingboard>(p1, GAMESTATE, P2_OCCUPIED)),

    p2_pawn(std::make_shared<Pawnboard>(p2, GAMESTATE, P1_OCCUPIED)),
    p2_bishop(std::make_shared<Bishopboard>(p2, GAMESTATE, P1_OCCUPIED)),
    p2_rook(std::make_shared<Rookboard>(p2, GAMESTATE, P1_OCCUPIED)),
    p2_knight(std::make_shared<Knightboard>(p2, GAMESTATE, P1_OCCUPIED)),
    p2_queen(std::make_shared<Queenboard>(p2, GAMESTATE, P1_OCCUPIED)),
    p2_king(std::make_shared<Kingboard>(p2, GAMESTATE, P1_OCCUPIED))
{
    p1->pieceboard_map = {{'P', p1_pawn}, {'B', p1_bishop}, {'R', p1_rook}, {'N', p1_knight}, {'Q', p1_queen}, {'K', p1_king}};
    p2->pieceboard_map = {{'P', p2_pawn}, {'B', p2_bishop}, {'R', p2_rook}, {'N', p2_knight}, {'Q', p2_queen}, {'K', p2_king}};
    reset_board();
}

void Board::update_board_state()
{
    p1_occupied->bitboard =
        p1_pawn->pieceboard.bitboard |
        p1_bishop->pieceboard.bitboard |
        p1_rook->pieceboard.bitboard |
        p1_knight->pieceboard.bitboard |
        p1_queen->pieceboard.bitboard |
        p1_king->pieceboard.bitboard;

    p2_occupied->bitboard =
        p2_pawn->pieceboard.bitboard |
        p2_bishop->pieceboard.bitboard |
        p2_rook->pieceboard.bitboard |
        p2_knight->pieceboard.bitboard |
        p2_queen->pieceboard.bitboard |
        p2_king->pieceboard.bitboard;

    gamestate->bitboard = p2_occupied->bitboard | p1_occupied->bitboard;
}

void Board::reset_board()
{
    p1_pawn->reset_board();
    p2_pawn->reset_board();

    p1_bishop->reset_board();
    p2_bishop->reset_board();

    p1_rook->reset_board();
    p2_rook->reset_board(); 

    p1_knight->reset_board();
    p2_knight->reset_board(); 

    p1_queen->reset_board();
    p2_queen->reset_board(); 

    p1_king->reset_board();
    p2_king->reset_board(); 

    update_board_state();
}

void Board::print_board()
{
    std::vector<std::shared_ptr<Piece>> all_boards;
    for (auto pair : player1->pieceboard_map)
        all_boards.push_back(pair.second);
    for (auto pair : player2->pieceboard_map)
        all_boards.push_back(pair.second);

    for (unsigned int i = 0; i < 64; i++)
    {
        bool flag = false;
        for (auto pcbrd : all_boards)
        {
            if (pcbrd->pieceboard.is_occupied(static_cast<Spot>(i)))
            {
                std::cout << pcbrd->unicode_str << "  ";
                flag = true;
            }
        }
        if (!flag)
        {
            std::cout << ".  ";
        }

        if ((i + 1) % 8 == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}

void Board::preview_turn(PlayerSPtr)
{

}

void Board::take_turn(PlayerSPtr player)
{
    while (true)
    {
        char piece_type;
        std::pair<Spot, Spot> start_end;
        ::getUserMove(player, piece_type, start_end);

        Bitboard chosen_piece_mask;
        chosen_piece_mask.set_bit(start_end.first);
        PieceSPtr chosen_pieceboard = player->pieceboard_map[piece_type];
        Bitboard isolated_piece(chosen_pieceboard->pieceboard.bitboard & chosen_piece_mask.bitboard);
        
        Bitboard possible_attacks;
        switch(piece_type)
        {
            case 'P':
                possible_attacks = ::castAndComputeMove<Pawnboard>(player, piece_type, isolated_piece);
                break;
            case 'B':
                possible_attacks = ::castAndComputeMove<Bishopboard>(player, piece_type, isolated_piece);
                break;
            case 'R':
                possible_attacks = ::castAndComputeMove<Rookboard>(player, piece_type, isolated_piece);
                break;
            case 'N':
                possible_attacks = ::castAndComputeMove<Knightboard>(player, piece_type, isolated_piece);
                break;
            case 'Q':
                possible_attacks = ::castAndComputeMove<Queenboard>(player, piece_type, isolated_piece);
                break;
            case 'K':
                possible_attacks = ::castAndComputeMove<Kingboard>(player, piece_type, isolated_piece);
                break;
        }

        Bitboard destination;
        destination.set_bit(start_end.second);

        // Chosen destination is not a valid move for that piece
        if (!(possible_attacks.bitboard & destination.bitboard)) 
        {
            continue;
        }
        // Valid move
        else
        {   
            // Remove opposing piece at the destination bit
            for (auto opposing_boards : player->opposing_player->pieceboard_map)
            {
                opposing_boards.second->pieceboard.pop_bit(start_end.second);
                // TODO: Add attack to the move log, and add pieces to dead piles
            }
            chosen_pieceboard->pieceboard.set_bit(start_end.second);
            chosen_pieceboard->pieceboard.pop_bit(start_end.first);
            break;
        }
    }
    update_board_state();
}
