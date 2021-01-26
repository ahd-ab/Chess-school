#include "Bishop.hpp"
#include <cstdlib>
#include <algorithm>


Bishop::Bishop(const std::array<unsigned short, 2>& slot, const bool is_white)
	:  Piece(slot, is_white)
{}


/*
	This function checks if the move is valid for the bishop.
*/
bool Bishop::can_make_move(const std::array<unsigned short, 2>& dst,
	const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board)
{
	return abs(dst[X] - this->_slot[X]) == abs(dst[Y] - this->_slot[Y]) // Checking if the bishop is moving diagonally.
		&& Piece::can_make_move(dst, board);
}

bool Bishop::is_piece_blocking(const std::array<unsigned short, 2>& dst,
	const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) const
{
	const short MIN_X = std::min(dst[X], this->_slot[X]);
	const short MIN_Y = std::min(dst[Y], this->_slot[Y]);

	const short MAX_X = std::max(dst[X], this->_slot[X]);
	const short MAX_Y = std::max(dst[Y], this->_slot[Y]);

	bool piece_blocking = false;

	if (this->_slot[X] - dst[X] == this->_slot[Y] - dst[Y])
	{
		//A loop which runs on all the slots betweeen the src and dst.
		for (short x = MIN_X + 1, short y = MIN_Y + 1; x < MAX_X && !piece_blocking; x++, y++)
		{
			piece_blocking = board[y][x] != nullptr;
		}
	}
	else //(MAX_X, MIN_Y)<->(MIN_X, MAX_Y)
	{
		for (short x = MAX_X, short y = MIN_Y; y < MAX_Y && !piece_blocking; x--, y++)
		{
			piece_blocking = board[y][x] != nullptr;
		}
	}

	return piece_blocking;
}