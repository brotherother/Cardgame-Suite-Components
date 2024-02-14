 #include "RummyGameView.h"
//#include "ISolitareGameView.h" 
#include "CardAreaView.h"

RummyGameView::RummyGameView(ICardCollection* stockView, ICardCollection* discardView, ICardCollection* userView, ICardCollection* AIopponentView, ICardCollection* foundationView) {
	stock = new CardAreaView(400, 250, 72, 100, stockView);
	discard = new CardAreaView(472, 250, 72, 100, discardView);
	userHand = new CardAreaView(300, 500, 432, 100, userView);
	AIopponentHand = new CardAreaView(300, 10, 396, 100, AIopponentView);
	if (foundationView != 0)
		foundation = new CardAreaView(50, 80, 200, 400, foundationView);
}

RummyGameView::RummyGameView(IRummyGame* game) {
	stock = new CardAreaView(400, 250, 72, 100, game->getStock());
	discard = new CardAreaView(472, 250, 72, 100, game->getDiscard());
	userHand = new CardAreaView(300, 500, 432, 100, game->getPlayerHand());
	AIopponentHand = new CardAreaView(300, 10, 396, 100, game->getOpponentHand());
	if(game->getFoundation() != 0)
		foundation = new CardAreaView(50, 80, 200, 400, game->getFoundation());
}

RummyGameView:: ~RummyGameView() {

}

CardAreaView* RummyGameView::getCardAreaView(int id) {
	if (id == 1) { return stock; }
	else if (id == 2) { return discard; }
	else if (id == 3) { return userHand; }
	else if (id == 4) { return AIopponentHand; }
	else { return foundation; }

}

int RummyGameView::getNumCardAreaViews() {
	return 5;
}
