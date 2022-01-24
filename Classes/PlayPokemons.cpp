#include "BoardView.h"
#include "PlayPokemons.h"
#include "SimpleAudioEngine.h"
#include <vector>
#include "AudioManager.h"

USING_NS_CC;

Scene* PlayPokemons::createScene()
{
    auto scene = Scene::create();
    auto layer = PlayPokemons::create();
    scene->addChild(layer);
    return scene;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool PlayPokemons::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();

    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("Background.jpg");
    background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    background->setScale(1.4);
    this->addChild(background);

    showBoard();
    showProgressTimer();

    this->schedule(schedule_selector(PlayPokemons::checkTime,), 1);
    this->schedule(schedule_selector(PlayPokemons::checkWinGame, ), 1);

    return true;
}


void PlayPokemons::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

}

Layer* PlayPokemons::showBoard()
{
    std::vector<int> count(16, 4);
    board = new Board(8, 8, 16, count);

    auto boardView = BoardView::createBoardView(board);
    boardView->setName("boardView");
    this->addChild(boardView, 1);
    float x = (Director::getInstance()->getVisibleSize().width - boardView->getContentSize().width) / 2;
    float y = (Director::getInstance()->getVisibleSize().height - boardView->getContentSize().height) / 2;
    boardView->setPosition({ x, y });
    return boardView;
}

void PlayPokemons::showProgressTimer()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto progressTimer = ProgressTimer::create(Sprite::create("ProgressBar.png"));
    progressTimer->setType(ProgressTimer::Type::BAR);
    progressTimer->setMidpoint(Vec2(0.0f, 0.5f));
    progressTimer->setBarChangeRate(Vec2(1.0f, 0.0f));
    progressTimer->setPercentage(100);
    progressTimer->setPosition(visibleSize.width/2, visibleSize.height*0.9);
    progressTimer->setTag(10);
    progressTimer->setScale(0.5);
    progressTimer->setName("TIME");
    this->addChild(progressTimer);
    progressTimer->runAction(ProgressFromTo::create(5*60, 100, 0));
}

void PlayPokemons::checkTime(float dt)
{
    if (Director::getInstance()->getActionManager()->getNumberOfRunningActions() == 0)
    {
        // pause all active and remove child
        this->pauseSchedulerAndActions();
        this->removeAllChildren();
        gameOver();
    }
    
}

void PlayPokemons::gameOver()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // show background
    auto background = Sprite::create("Background.jpg");
    background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    background->setScale(1.4);
    this->addChild(background);

    // show gameover
    auto gameover = Sprite::create("gameover.png");
    gameover->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    gameover->setScale(1);
    this->addChild(gameover);

    // buttom replay
    auto buttonReplay = MenuItemImage::create("Retry1.png", "Retry2.png", CC_CALLBACK_1(PlayPokemons::replayGame, this));
    auto menu = Menu::create(buttonReplay, NULL);
    menu->setPosition(visibleSize.width / 2, visibleSize.height * 0.85);
    this->addChild(menu);

}

void PlayPokemons::replayGame(Ref *sender)
{
    auto start = PlayPokemons::createScene();
    Director::getInstance()->replaceScene(start);
}

void PlayPokemons::gameWin()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    this->getChildByName("TIME")->setVisible(false);

    auto gamewin = Sprite::create("youWin.png");
    gamewin->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    gamewin->setScale(0.7);
    this->addChild(gamewin);

}

void PlayPokemons::checkWinGame(float dt)
{
    if (board->isEmptyPokemon())
    {
        gameWin();
    }
}



