#include "Gameboard.hpp"
//Including chess pieces.
#include "Bishop.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Knight.hpp"


/*
	C'tor, Initializing the game board with the white and black pieces.
	In form:
	R  Kn  B  Q  Ki  B  Kn  R 
	P   P  P  P   P  P   P  P



	P   P  P  P   P  P   P  P
	R  Kn  B  Q  Ki  B  Kn  R
*/
Gameboard::Gameboard()
{
	//Initializing white rooks on board.
	this->_board[0][A] = std::make_unique<Rook>(std::array<unsigned short, 2>({ 0,A }), true);
	this->_board[0][H] = std::make_unique<Rook>(std::array<unsigned short, 2>({ 0,H }), true);

	//Initializing black rooks on board.
	this->_board[7][A] = std::make_unique<Rook>(std::array<unsigned short, 2>({ 7,A }), false);
	this->_board[7][H] = std::make_unique<Rook>(std::array<unsigned short, 2>({ 7,H }), false);

	//Initializing white knights on board.
	this->_board[0][B] = std::make_unique<Knight>(std::array<unsigned short, 2>({ 0,B }), true);
	this->_board[0][G] = std::make_unique<Knight>(std::array<unsigned short, 2>({ 0,G }), true);

	//Initializing black knights on board.
	this->_board[7][B] = std::make_unique<Knight>(std::array<unsigned short, 2>({ 7,B }), false);
	this->_board[7][G] = std::make_unique<Knight>(std::array<unsigned short, 2>({ 7,G }), false);

	//Initializing black bishops on board.
	this->_board[0][C] = std::make_unique<Bishop>(std::array<unsigned short, 2>({ 0,C }), true);
	this->_board[0][F] = std::make_unique<Bishop>(std::array<unsigned short, 2>({ 0,F }), true);
	
	//Initializing black bishops on board.
	this->_board[7][C] = std::make_unique<Bishop>(std::array<unsigned short, 2>({ 7,C }), false);
	this->_board[7][F] = std::make_unique<Bishop>(std::array<unsigned short, 2>({ 7,F }), false);

	//Initialzing white queen on board.
	this->_board[0][D] = std::make_unique<Queen>(std::array<unsigned short, 2>({ 0,D }), true);

	//Initializing black queen on board.
	this->_board[7][D] = std::make_unique<Queen>(std::array<unsigned short, 2>({ 7,D }), false);

	//Initializing white king on board.
	this->_board[0][E] = std::make_unique<King>(std::array<unsigned short, 2>({ 0,E }), true);

	//Initializing black king on board.
	this->_board[7][E] = std::make_unique<King>(std::array<unsigned short, 2>({ 7,E }), false);

	//Initializing white pawns on board.
	for (unsigned short i = A; i <= H; i++)
	{
		this->_board[1][i] = std::make_unique<King>(std::array<unsigned short, 2>({ 1,i }), true);
	}

	//Initializing black pawns on board.
	for (unsigned short i = A; i <= H; i++)
	{
		this->_board[6][i] = std::make_unique<King>(std::array<unsigned short, 2>({ 6,i }), false);
	}
}



