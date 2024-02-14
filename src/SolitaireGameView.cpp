//All of this code came directly from hofmiester during my group meeting with her.

#include "SolitaireGameView.h"
#include "ISolitaireGame.h"
#include "CardAreaView.h"

SolitaireGameView::SolitaireGameView(ISolitaireGame* game)
{

	stock = new CardAreaView(20, 50, CARDWIDTH, CARDHEIGHT, game->getStock());

	discard = new CardAreaView(102, 50, CARDWIDTH, CARDHEIGHT, game->getDiscard());

	foundation = new CardAreaView(266, 50, 700, 100, game->getFoundation());

	tableau = new CardAreaView(20, 200, 900, 800, game->getTableau());

}

SolitaireGameView::SolitaireGameView(CardList* card1, CardList* card2, RowOfStacks* foundation1, RowOfStacks* tableau1)
{
	stock = new CardAreaView(20, 50, 72, 100, card1);

	discard = new CardAreaView(102, 50, 72, 100, card2);

	foundation = new CardAreaView(266, 50, 318, 100, foundation1);

	tableau = new CardAreaView(20, 200, 600, 400, tableau1);
}

SolitaireGameView::~SolitaireGameView() 
{

}

CardAreaView* SolitaireGameView::getCardAreaView(int id)
{
		 if (id == 1)
		 {
					return stock;
		 }
		 else if (id == 2)
		 {
					return discard;
		 }
		 else if (id == 3)
		 {
					return foundation;
		 }
		 else
		 {
					return tableau;
		 }
}


int SolitaireGameView::getNumCardAreaViews()
{
		 return 4;
}

//
//SolitareGameView::SolitareGameView() 
//{
//	solitaireGame = new ISolitaireGame;
//}
//
//SolitareGameView::~SolitareGameView() 
//{
//
//}
//
//void SolitaireGameView::createGameView(*IGameView theGameView)
//{
//	theGameView = new CardAreaView;
//}
//
//*CardCollection SolitaireGameView::getCards(*IGame theGame)
//{
//	return theGame.theCardCollection;
//}
//
//int SolitareGameView::createCardAreaView(*ISolitaireGame solitaireGame, *CardAreaView theCardAreaView)
//{
//	solitaireGame.ca
//}
//
//// Implements IGameView, and supports the factory method for creating itself.
//// Created and deleted by Controller. 
//*IGameView SolitaireGameView::createGameView(IGameView *gameView) {}
//
//// Uses the game to get the appropriate cardCollection for each cardAreaView
//*CardCollection SolitaireGameView::getCards(IGame *game) {}
//
//// then creates each cardAreaView and tells each its position and extent.
//float [] SolitaireGameView::createCardAreaView(ISolitaireGame *solitaireGame, CardAreaView *cardAreaView) {}
//
////Passes the game’s stock, discard, foundation, tableau, hands (as appropriate for the game) to the cardAreaView.
//void SolitaireGameView::passCardsToView(ICardCollection *cardCollection) {}
