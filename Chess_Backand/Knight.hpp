#include "Piece.hpp"



class Knight : public Piece
{
public:
	Knight(const std::array<unsigned short, 2>& slot, const bool is_white);
	virtual ~Knight() = default;

	
protected:
	virtual bool is_piece_blocking(const std::array<unsigned short, 2>& dst,
		const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) const;
	virtual bool can_make_move(const std::array<unsigned short, 2>& dst,
		const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board);
};