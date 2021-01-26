#pragma once

#include <array>
#include <memory>

enum AXIS : unsigned short {X, Y};

class Piece
{
public:
    Piece(const std::array<unsigned short, 2>& slot , const bool is_white);
    virtual ~Piece() = default;
	
    virtual bool make_move(const std::array<unsigned short, 2>& dst,
        const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board);

    bool get_is_white()const;
protected:
    std::array<unsigned short, 2> _slot; // coordinate in form of [x,y].  
    bool _is_white;

    virtual bool can_make_move(const std::array<unsigned short, 2>& dst,
        const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board);
    virtual bool is_piece_blocking(const std::array<unsigned short, 2>& dst,
        const std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) const = 0;
};