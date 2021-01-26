#include "Piece.hpp"
#include <algorithm>

Piece::Piece(const std::array<unsigned short, 2>& slot, const bool is_white)
	: _slot(slot), _is_white(is_white)
{ }


/*
	A function for checking if the moving to the dst slot is leggal.
	Checking if the destination is on the board, the source and destination are different slots
	and if there is any piece which is blocking the movement.
*/
bool Piece::can_make_move(const std::array<unsigned short, 2> & dst, 
	const std::array<std::array<std::unique_ptr<Piece>, 8>, 8> & board)
{
	return  (dst[X] == std::clamp((int)dst[X], 0, 7))
		&& (dst[Y] == std::clamp((int)dst[Y], 0, 7))//Checking whether the dst in the board.
		&& !(dst[X] == this->_slot[X] && dst[Y] == this->_slot[Y]) // Checking if the src and dst are different.
		&& !(this->is_piece_blocking(dst, board)); //Checking if there is a piece which blocks this movement.
}


/*
	A function which makes a move of a piece.
*/
bool Piece::make_move(const std::array<unsigned short, 2>& dst, const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board)
{
	bool movement_possible = this->can_make_move(dst, board);

	if (movement_possible)
	{
		this->_slot = dst;
	}

	return movement_possible;
}


bool Piece::get_is_white() const
{
	return this->_is_white;
}



