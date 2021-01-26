#pragma once

#include "Piece.hpp"

class Rook : virtual public Piece
{
public:
	Rook(const std::array<unsigned short, 2>& slot, const bool is_white);
	~Rook() = default;

	virtual bool make_move(const std::array<unsigned short, 2>& dst,
		const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board);
protected:
	virtual bool is_piece_blocking(const std::array<unsigned short, 2>& dst,
		const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) const;
	virtual bool can_make_move(const std::array<unsigned short, 2>& dst,
		const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board);

private:
	bool _is_first_move;
};

