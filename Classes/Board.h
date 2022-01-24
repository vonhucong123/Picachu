#pragma once
#include <vector>

class Board
{
	int m_rows, m_columns;	// number of rows and columns

	std::vector<std::vector<int>> m_pokemons;	// pokemons

public:
	int _x = -1;

	int _y = -1;

	// khởi tạo bảng gồm số hàng số cột, tổng các loại pokemon, vector lưu tọa độ các loại pokemon
	Board(int n_rows, int n_columns, int n_types, std::vector<int> count);

	int getNRows();

	int getNColumns();

	void addPokemon			(int x, int y, int type);

	int getPokemon			(int x, int y);

	void removePokemon		(int x, int y);

	bool selectPokemon		(int x, int y);

	bool canConnect			(int _x, int _y, int x, int y);

	bool isEmptyPokemon();

	std::vector<std::pair<int, int>> findPath(int _x, int _y, int x, int y);

	std::vector<std::pair<int, int>> DFS(std::vector<std::vector<int>> e, int _x, int _y, int x, int y);

};