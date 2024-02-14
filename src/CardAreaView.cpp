#include"CardAreaView.h"
#include "CardList.h"

//Purpose: This function will set up the view area in the main controller
//Parameters: xp and yp are the position of the subwindow in the main window. xExtent and yExtent are the size of the subwindow. ICardCollection is the type of card object to display
//Returns: null
CardAreaView::CardAreaView(int xP, int yP, int xExtent, int yExtent, ICardCollection* cardType)
{
	//Get the position of the subwindow 
	xStart = xP;
	yStart = yP;
	_xExtent = xExtent;
	_yExtent = yExtent;

	//Inputting the size of the cardlist 
	arraySize = cardType->getSize();

	//Still have to get a better idea of this but assuming it is the different in spacing
	xOffset = (xExtent - CARDWIDTH) / (arraySize+1);
	yOffset = (yExtent - CARDHEIGHT) / (arraySize+1);

	if (xOffset == yOffset)
	{
		xOffset = 0;
		yOffset = 0;
	}
	else if (xOffset == 0)
	{
		yOffset = 35;
	}
	else if (yOffset == 0)
	{
		xOffset = 35;
	}
	else
	{
		xOffset = 82;
		yOffset = 35;
	}

	xExtentCard = xExtent;
	yExtentCard = yExtent;

	///Putting the ICardCollection into an object to use in the program
	cardObject = cardType;
}

//Purpose: Displays the card in the subwindow and sets them a x amount apart depending on the card object; whether it vertical, horizontal, or list of list.
//Parameters: HDC, which is the device in which the card will be displayed
//Returns: null
void CardAreaView::cardViewDisplay(HDC* DeviceContext)
{
	int x_off = 0;
	int y_off = 0;
	if (dynamic_cast<ICardList*>(cardObject)) {//if the object is 1d
		CardList* list = (CardList*)cardObject;
		arraySize = list->getSize();
		for (int i = 0; i < arraySize; i++)
		{
			if (i == 0)
			{
				CardView* crd = new CardView(list->getFirst());
				crd->display(x_off, y_off, DeviceContext);
			}
			else
			{
				CardView* crd = new CardView(list->getNext());
				crd->display(x_off, y_off, DeviceContext);

			}
			x_off = x_off + xOffset;
			y_off = y_off + yOffset;
		}
	}
	else {//if 2d
		RowOfStacks* temp = (RowOfStacks*)cardObject;
		for (int i = 0; i < temp->getSize(); i++) {
			ICardList* cl = temp->getListAtIndex(i);
			for (int j = cl->getSize()-1; j >=0; j--) {
				CardView* crd = new CardView(cl->getAt(j));
				crd->display(x_off, y_off, DeviceContext);
				y_off += yOffset;
			}
			x_off += CARDWIDTH + 10;
			y_off = 0;
		}
	}
}

//Purpose: When a user clicks on a card from the window the CardIdentity is returned which holds the card object, the index where it is, and the cardList it is in
//Parameters: x and y values. These is the position of the cursor on a click
//Returns: CardIdentity object --> CardCollection, CardList, CardIndex
CardIdentity* CardAreaView::click(int in_x, int in_y)
{
	CardIdentity* identity = new CardIdentity();
	identity->cardCollection = cardObject;
	if (dynamic_cast<ICardList*>(cardObject)) { // 1d
		int tempIndex = -1;

		if (yExtentCard > xExtentCard) {//horizontally formatted
			int tempY = yOffset * (arraySize - 1);
			tempIndex = arraySize - 1;
			while (in_y < tempY) {
				tempY -= yOffset;
				tempIndex--;
			}
		}
		else {//vertically formatted
			int tempX = xOffset * (arraySize - 1);
			tempIndex = arraySize - 1;
			while (in_x < tempX) {
				tempX -= xOffset;
				tempIndex--;
			}
		}
		identity->cardIndex = tempIndex;
	}
	else { //2d
		//vertical printing first, y = card index, x=list index
		RowOfStacks* tempRows = (RowOfStacks*)cardObject;
		int listIndex = -1;

		xOffset = CARDWIDTH + 10;
		int tempX = (CARDWIDTH + 10) * (arraySize - 1);

		listIndex = arraySize - 1;
		while (in_x < tempX) {
			tempX -= xOffset;
			listIndex--;
		}
		//now find the card index
		ICardList* tempList = tempRows->getListAtIndex(listIndex);//get the list the Y coord gives us
		identity->cardList = tempList;//set identites cardlist for this list
		int cardI = -1;
		int switchCardI = 0;
		int tempY = yOffset * (tempList->getSize() - 1);
		cardI = tempList->getSize() - 1;
		while (in_y < tempY) {
			tempY -= yOffset;
			cardI--;
			switchCardI++;
		}

		identity->cardIndex = switchCardI;
		std::cout << "cardList index: " << listIndex << "\nCard index: " << cardI << std::endl;
	}
	return identity;
}

//Purpose: The x position of the subwindow in the main window
//Parameters: null
//Returns: int 
int CardAreaView::getPositionX()
{
	return xStart;
}

//Purpose: The y position of the subwindow in the main window
//Parameters: null
//Returns: int 
int CardAreaView::getPositionY()
{
	return yStart;
}

//Purpose: The subwindows width in the main window
//Parameters: null
//Returns: int 
int CardAreaView::getExtentX()
{
	return _xExtent;
}

//Purpose: The subwindows height in the main window
//Parameters: null
//Returns: int 
int CardAreaView::getExtentY()
{
	return _yExtent;
}
