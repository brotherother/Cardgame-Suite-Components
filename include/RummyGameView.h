#if !defined(RUMMYGAMEVIEW_H)
#define RUMMYGAMEVIEW_H
#include "IRummyGame.h"
#include "IGameView.h"
#include "RowOfStacks.h"
#include "ICardCollection.h"
#include "ICardList.h"
#include "CardList.h"

class IRummyGameView;
class CardAreaView;
class CardList;


class RummyGameView: public IGameView
{
  private:

      CardAreaView* stock;
      CardAreaView* discard;
      CardAreaView* userHand;
      CardAreaView* AIopponentHand;
      CardAreaView* foundation;

  public:

	  RummyGameView(ICardCollection* stock, ICardCollection* discard, ICardCollection* user, ICardCollection* AIopponent, ICardCollection* foundation);
      RummyGameView(IRummyGame*);
      RummyGameView(CardList* c1, CardList* c2, RowOfStacks* foundation);
      ~RummyGameView();

      CardAreaView* getCardAreaView(int id);
      int getNumCardAreaViews();
};

#endif