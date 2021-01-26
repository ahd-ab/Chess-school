#include "Rook.hpp"
#include <algorithm>
#include <cstdlib>


Rook::Rook(const std::array<unsigned short, 2>& slot, const bool is_white)
	: Piece(slot, is_white), _is_first_move(true)
{}


/*
	A function which checks if the moving to the destination is leggal.
	Checking if the piece move is leggal and if the rook is moving on only one axis.
*/
bool Rook::can_make_move(const std::array<unsigned short, 2> & dst,
	const std::array<std::array<std::unique_ptr<Piece>, 8>, 8> & board)
{
	return (dst[X] == this->_slot[X] && dst[Y] != this->_slot[Y]) //Checking if the moving is only on the x axis.
		|| (dst[Y] == this->_slot[Y] && dst[X] != this->_slot[X]) //Checking if the moving is only on the y axis.
		&&  Piece::can_make_move(dst, board);
		 
}


/*
	This function checks if the rook can make a move to dst,
	if it can it would change the slot of the rook and defines that this movement is not the 
	first one.
*/
bool Rook::make_move(const std::array<unsigned short, 2>& dst, const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board)
{
	bool movement_possible = this->can_make_move(dst, board);

	if (movement_possible)
	{
		this->_slot = dst;
		this->_is_first_move = false;
	}

	return movement_possible;
}


/*
	This function checks if there is a piece which blocks the movement.
*/
bool Rook::is_piece_blocking(const std::array<unsigned short, 2>& dst,
	const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) const
{
	//Finding in which axis the rook moves.
	const unsigned short MOVEMENT_AXIS = dst[X] != this->_slot[X] ? (unsigned short)X : (unsigned short)Y;
	//Checking the min and max values in the movement axis.
	const unsigned short MIN_VAL_OF_ASIX = std::min(dst[MOVEMENT_AXIS], this->_slot[MOVEMENT_AXIS]); 
	const unsigned short MAX_VAL_OF_AXIS = std::max(dst[MOVEMENT_AXIS], this->_slot[MOVEMENT_AXIS]);
	
	bool found_blocking_piece = false;

	/*
		A loop which runs on the movement axis from the next slot of minimum to one slot from the maximum,
		This running is to check if between the src and dst there is a blocking piece when in the src there is 
		the rook piece and in the dst can be an opponent piece.
	*/
	for (unsigned short i = MIN_VAL_OF_ASIX + 1; i < MAX_VAL_OF_AXIS && !found_blocking_piece; i++)
	{
		if (dst[X] == this->_slot[X])
		{
			found_blocking_piece = board[i][X] == nullptr;
		}
		else
		{
			found_blocking_piece = board[Y][i] == nullptr;
		}
	}

	//Checking if in the dst there is a piece with the same colour.
	if (!found_blocking_piece && board[dst[Y]][dst[X]] != nullptr
		&& this->_is_white == board[dst[Y]][dst[X]]->get_is_white())
	{
		found_blocking_piece = true;
	}

	return found_blocking_piece;
}
