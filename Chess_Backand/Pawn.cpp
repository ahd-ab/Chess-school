#include "Pawn.hpp"
#include <algorithm>
#include <cstdlib>


Pawn::Pawn(const std::array<unsigned short, 2>& slot, const bool is_white)
	: Piece(slot, is_white), _is_first_move(true)
{}



bool Pawn::can_make_move(const std::array<unsigned short, 2>& dst, const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board)
{
	const short DOUBLE_MOVE = 2;
	/*
		If the pawn is white so the positive subtraction should be dst - curr, 
		if the pawn is black the subtraction should the oposite: curr - dst.
	*/
	const short VERTICAL_MOVING_SLOTS = this->_is_white ? dst[Y] - this->_slot[Y] : this->_slot[Y] - dst[Y];
	const short HORIZONAL_MOVING_SLOTS = abs(dst[X] - this->_slot[X]);


	/*
	Checking if the pawn moves in this rules:
	1. 2 vertical slots when its the first move.
	2. 1 vertical and 1 horizonal slots and the dst is not empty.
	3. 1 vertical slot.
	*/
	return ((VERTICAL_MOVING_SLOTS == DOUBLE_MOVE && this->_is_first_move && HORIZONAL_MOVING_SLOTS == 0) //Checking if its the first moving of the pawn.
		|| (VERTICAL_MOVING_SLOTS == 1 && HORIZONAL_MOVING_SLOTS == 1 && board[dst[Y]][dst[X]] != nullptr)
		|| (VERTICAL_MOVING_SLOTS == 1 && HORIZONAL_MOVING_SLOTS == 0))
		&& Piece::can_make_move(dst, board);
}


bool Pawn::is_piece_blocking(const std::array<unsigned short, 2>& dst,
	const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) const
{
	const unsigned short MAX_VERTICAL_SLOT = std::max(dst[Y], this->_slot[Y]);
	const unsigned DOUBLE_MOVE = 2;

	/*
		1. Checking if there is a double move, if there is it checks if between the slots there is a piece.
		2. Checking if at the destination there is a piece.
	*/
	return (abs(this->_slot[Y] - dst[Y]) == DOUBLE_MOVE && board[MAX_VERTICAL_SLOT - 1][dst[X]] != nullptr) 
		|| (board[dst[Y]][dst[X]] != nullptr);
}