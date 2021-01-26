#pragma once

#include <array>
#include <memory>
#include "Piece.hpp"


enum Vertical_axis : unsigned short {A, B, C, D, E, F, G, H};

class Gameboard
{
public:
    Gameboard();
    ~Gameboard() = default;

    bool make_move(const std::array<unsigned short, 2>& src, const std::array<unsigned short, 2>& dst);

private:
    std::array<std::array<std::unique_ptr<Piece>, 8>, 8> _board;
};