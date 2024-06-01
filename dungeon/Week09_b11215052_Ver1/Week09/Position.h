#pragma once
#include <iostream>

//************************************************************
// The location in the board
//************************************************************
class Position {
public:
	int x, y; // X, y Coordinate

	Position() : x(0), y(0) {}
	Position(int x, int y) : x(x), y(y) {}
	Position(const Position& ref) { *this = ref; }

	// Operator overloading
	Position operator+(const Position& rhs) const {
		return Position(x + rhs.x, y + rhs.y);
	}

	Position& operator+=(const Position& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Position operator-(const Position& rhs) const {
		return Position(x - rhs.x, y - rhs.y);
	}

	Position& operator-=(const Position& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Position operator*(int scale) const {
		return Position(x * scale, y * scale);
	}

	bool operator==(const Position& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	bool operator!=(const Position& rhs) const {
		return !(*this == rhs);
	}

	// cout 
	friend std::ostream& operator<<(std::ostream& strm, const Position& pos) {
		strm << pos.x << " " << pos.y << " ";
		return strm;
	}

	// cin
	friend std::istream& operator>>(std::istream& strm, Position& pos) {
		strm >> pos.x >> pos.y;
		return strm;
	}
};