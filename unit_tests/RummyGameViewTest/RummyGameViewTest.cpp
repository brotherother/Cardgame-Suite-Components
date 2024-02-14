
#include "../../GUILayer/include/RummyGameView.h"

RummyGameView::RummyGameView() {}

RummyGameView::~RummyGameView() {}

// Implements IGameView, and supports the factory method for creating itself.
// Created and deleted by Controller. 
void RummyGameView::createGameView(IGameView *gameView) {}

// Uses the game to get the appropriate cardCollection for each cardAreaView
*CardCollection RummyGameView::getCards(IGame *game) {}

// then creates each cardAreaView and tells each its position and extent.
float [] RummyGameView::createCardAreaView(IRummyGame *RummyGame, CardAreaView *cardAreaView) {}

//Passes the game’s stock, discard, foundation, tableau, hands (as appropriate for the game) to the cardAreaView.
void RummyGameView::passCardsToView(ICardCollection *cardCollection) {}
