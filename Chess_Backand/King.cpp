#include "King.hpp"


King::King(const std::array<unsigned short, 2>& slot, const bool is_white)
	: Piece(slot, is_white), _first_turn(true)
{}


