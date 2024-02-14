#pragma once
#if !defined(RUMMYGAMEVIEW_H)
#define RUMMYGAMEVIEW_H

#include "IGameView.h"
#include "IGame.h"
#include "IRummyGame.h"
#include "CardAreaView.h"

class RummyGameView : public IGameView
{
private:
    IGame* rummyGame;

public:
    RummyGameView();
    ~RummyGameView();
    virtual void createGameView(IGameView*);
    virtual ICardCollection* getCards(IGame*);
    virtual void createCardAreaView(IRummyGame*, CardAreaView*);
    virtual void passCardsToView(ICardCollection*);

    virtual float getPosition();
    virtual float getExtent();
    virtual CardAreaView* getCardAreaView();
    virtual int getNumCardAreaViews();

};

#endif
