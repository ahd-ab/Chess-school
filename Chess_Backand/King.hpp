#pragma once

#include "Piece.hpp"

class King : public Piece
{
public:
	King(const std::array<unsigned short, 2>& slot, const bool is_white);
	virtual ~King() = default;

private:
	bool _first_turn;

	virtual bool is_piece_blocking(const std::array<unsigned short, 2>& dst,
		const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) const;
	virtual bool can_make_move(const std::array<unsigned short, 2>& dst,
		const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board);
};