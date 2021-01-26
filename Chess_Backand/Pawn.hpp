#pragma once

#include "Piece.hpp"

class Pawn : public Piece
{
public:
	Pawn(const std::array<unsigned short, 2>& slot, const bool is_white);
	virtual ~Pawn() = default;

	

protected:
	bool _is_first_move;

	virtual bool is_piece_blocking(const std::array<unsigned short, 2>& dst,
		const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) const;
	virtual bool can_make_move(const std::array<unsigned short, 2>& dst,
		const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board);
};