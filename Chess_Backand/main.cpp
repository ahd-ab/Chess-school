#include "Knight.hpp"
#include <iostream>

int main()
{
	std::array<std::array<std::unique_ptr<Piece>, 8>, 8> _board;
	_board[0][0] = std::make_unique<Knight>(std::array<unsigned short, 2>({0,0}), true);

	std::cout << _board[0][0]->can_make_move({ 1,2 }, _board);
	
}