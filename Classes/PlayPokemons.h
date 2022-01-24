
#ifndef __PLAY_POKEMON_H__
#define __PLAY_POKEMON_H__

#include "cocos2d.h"
#include "Board.h"

class PlayPokemons : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    Layer* showBoard();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    void showProgressTimer();

    void checkTime(float dt);

    void gameOver();

    void replayGame(Ref *sender);

    void gameWin();

    void checkWinGame(float dt);
    CREATE_FUNC(PlayPokemons);

private:
    Board* board;
};

#endif // __PLAY_POKEMON_H__

