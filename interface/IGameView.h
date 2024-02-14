// All Hofmiester code

#if !defined(IGAMEVIEW_H)
#define IGAMEVIEW_H

class CardAreaView;

class IGameView {
public:

		 virtual CardAreaView* getCardAreaView(int id) = 0;
		 virtual int getNumCardAreaViews() = 0;
		 
};
#endif

// Interface for the SolitaireGameView and RummyGameView classes
//
//#if !defined(IGAMEVIEW_H)
//#define IGAMEVIEW_H
//
//
//class IGameView {
//public:
//		 virtual void createGameView(*IGameView) = 0;
//		 virtual getPosition() = 0;
//		 virtual getExtent() = 0;
//		 virtual getCardAreaView() = 0;
//		 virtual getNumCardAreaViews() = 0;
//		 ~IGameView();
//}
//
//
//#endif
