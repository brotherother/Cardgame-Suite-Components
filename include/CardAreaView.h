#if !defined CARDAREAVIEW_H
#define CARDAREAVIEW_h

#include"CardView.h"
#include"ICardList.h"
//#include "..\unittest\CardAreaViewTest\IListOfListsStub.h"
#include "Card.h"
//#include "..\unittest\CardAreaViewTest\RowOfStacksStub.h"
#include"typeinfo"
#include"Vector"
#include "RowOfStacks.h"
#include "IListOfLists.h"

#define CARDWIDTH 72
#define CARDHEIGHT 100

class CardIdentity
{
public:
	ICardCollection* cardCollection;
	ICardList* cardList;
	int cardIndex;
};

class CardAreaView
{
private:
	//Position of CardAreaView within the main window (just save these and provide them when requested)
	int xStart;
	int yStart;
	int _xExtent;
	int _yExtent;

	//Size of the card list
	int arraySize;
public:
	//This will construct the card area
	CardAreaView(int windowX, int windowY, int, int, ICardCollection*);
	//CardAreaView(int, int, ICardCollection*);


	//This will display the cards
	void cardViewDisplay(HDC*);

	CardIdentity* click(int x, int y);

	int getPositionX();  // return the CardAreaView's position within the main window
	int getPositionY();	
	int getExtentX();  // return the CardAreaView's extent
	int getExtentY();

protected:				//This allows for the subclass to interact with the parent class attributes
	//ICardCollection object
	ICardCollection* cardObject;
	int xExtentCard;
	int yExtentCard;

	int xOffset;
	int yOffset;
};
#endif

