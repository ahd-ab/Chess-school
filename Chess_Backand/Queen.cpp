#include "Queen.hpp"


Queen::Queen(const std::array<unsigned short, 2>& slot, const bool is_white)
	: Rook(slot, is_white), Bishop(slot, is_white), Piece(slot, is_white)
{}


bool Queen::can_make_move(const std::array<unsigned short, 2>& dst,
const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board)
{
	return Rook::can_make_move(dst, board)
		|| Bishop::can_make_move(dst, board);
}


