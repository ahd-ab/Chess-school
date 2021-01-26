#include "Knight.hpp"
#include <cstdlib>
#include <iostream>


Knight::Knight(const std::array<unsigned short, 2>& slot, const bool is_white)
	: Piece(slot, is_white)
{}


/*
	This function checks whether the move is valid for knight piece.
*/
bool Knight::can_make_move(const std::array<unsigned short, 2>& dst,
	const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board)
{
	return ((abs(this->_slot[X] - dst[X]) == 2) && (abs(this->_slot[Y] - dst[Y]) == 1))
		|| ((abs(this->_slot[Y] - dst[Y]) == 2) && (abs(this->_slot[X] - dst[X]) == 1))
		&& Piece::can_make_move(dst, board);
}


/*
	This function checks if at the destination there is a piece.
*/
bool Knight::is_piece_blocking(const std::array<unsigned short, 2>& dst,
	const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) const
{
	return board[dst[Y]][dst[X]] != nullptr //Checks if the slot is empty
		&& (this->_is_white != board[dst[Y]][dst[X]]->get_is_white());//Checking if in the destination there is an opponent piece.
}