//Hofmiester code from meetings
#if !defined(SOLITAIREGAMEVIEW_H)
#define SOLITAIREGAMEVIEW_H

#include "IGameView.h"
#include "RowOfStacks.h"
#include "ICardCollection.h"
#include "ICardList.h"
#include "CardList.h"
class ISolitaireGame;
class CardAreaView;
class CardList;

class SolitaireGameView : public IGameView
{
	private: 

			 //ISolitaireGame* solitaireGame;
			 CardAreaView* stock;
			 CardAreaView* discard; 
			 CardAreaView* foundation; 
			 CardAreaView* tableau;
	
	public:

		SolitaireGameView(ISolitaireGame*);
			 SolitaireGameView(CardList*, CardList*, RowOfStacks*, RowOfStacks*);// temporary for integration test
		   ~SolitaireGameView();

		CardAreaView* getCardAreaView(int id);
		int getNumCardAreaViews();
};
#endif

//#if !defined(SOLITAIREGAMEVIEW_H)
//#define SOLITAIREGAMEVIEW_H
//
//#include "IGameView.h"
//
//class SolitaireGameView : public IGameView
//{
//private:
//		 IGame* solitaireGame;
//		 IGame* rummyGame;
//
//public:
//		 SolitaireGameView();
//		 ~SolitaireGameView();
//		 virtual void createGameView(*IGameView);
//		 *CardCollection SolitaireGameView::getCards(*IGame);
//		 int[] SolitaireGameView::createCardAreaView(*ISolitaireGame, *CardAreaView);
//		 void passCardsToView(*ICardCollection);
//
//		 // added per instructions
//		 virtual getPosition();
//		 virtual getExtent();
//		 virtual getCardAreaView();
//		 virtual getNumCardAreaViews();
//};
//
//#endif
