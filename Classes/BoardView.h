#pragma once
#include <cocos2d.h>
#include <Board.h>

USING_NS_CC;

class BoardView : public Layer
{
	// bảng
	Board* board;

	// độ dài một cạnh của một ô vuông trong bảng
	// chiều dài và chiều rộng của bảng
	float squareSize, width, height;

	// đối tượng sprite để truyền ảnh pokemon vào và hiển thị ảnh ra
	std::vector<std::vector<Sprite*>> pokemons;

public:

	static Layer* createBoardView		(Board* board);						

	void showBoard();

	Sprite* addPokemon					(int row, int column, int type);

	Vec2 positionOf						(int row, int column);

	std::pair<int, int> findRowAndColumnOfSprite(Node* node);

	bool removePokemon					(int row, int column);

	bool onTouchPokemon					(Touch* touch, Event* event);

	void connectPokemons				(int x, int y, int _x, int _y);

	cocos2d::FiniteTimeAction* BoardView::getConnectEffect(int x, int y, int _x, int _y);

	void createChoosePokemonEffect(Node* pokemon);

	void removeChoosePokemonEffect();

	bool isEmptyBoard();

	CREATE_FUNC(BoardView);
};