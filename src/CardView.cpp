#include"CardView.h"
const int CARD_HEIGHT = 100;
const int CARD_WIDTH = 72;

//Purpose: Construct a CardView object and sets object variable to be used later in the program for that particular object 
//Parameters: ICard object
//Returns: null
CardView::CardView(ICard* card)
{

	rankCard = card->getRank();
	faceUp = card->isFaceUp();
	selected = card->isSelected();

	if (card->getSuit() == Spades)
	{
		suitCard = 's';
	}
	else if (card->getSuit() == Hearts)
	{
		suitCard = 'h';
	}
	else if (card->getSuit() == Diamonds)
	{
		suitCard = 'd';
	}
	else if (card->getSuit() == Clubs)
	{
		suitCard = 'c';
	}
	else
	{
		cout << "Card suit does not exist" << endl;
	}
	int index = loadImages(suitCard, rankCard);

	//Get index of the front in the cardFrontArray
	frontIndex = getImageFront(suitCard, rankCard);

	//Get the HBITMAP of the back card
	back = getImageBack();
}

//Purpose: Construccts a CardView object and sets the class variables for that object
//Parameters: Suit and int
//Returns: null
CardView::CardView(Suit x, int y)
{

	rankCard = y;

	if (x == Spades)
	{
		suitCard = 's';
	}
	else if (x == Hearts)
	{
		suitCard = 'h';
	}
	else if (x == Diamonds)
	{
		suitCard = 'd';
	}
	else if (x == Clubs)
	{
		suitCard = 'c';
	}
	else
	{
		cout << "Card suit does not exist" << endl;
	}
	int index = loadImages(suitCard, rankCard);

	//Get index of the front in the cardFrontArray
	frontIndex = getImageFront(suitCard, rankCard);

	//Get the HBITMAP of the back card
	back = getImageBack();


}

//Purpose: displays a single card in the subwindow at a particular location. Also displays it face up or face down depending on the card object bool values for that variable
//Parameters: int, int and HDC*
//Returns: null
void CardView::display(int xP, int yP, HDC* DeviceContext)
{
	int x = xP + CARD_WIDTH / 2;
	int y = yP + CARD_HEIGHT / 2;

	HDC hdc = *DeviceContext;
	HDC MemDCCard = CreateCompatibleDC(hdc);

	if (faceUp)		//The value here calls the front image from the array
		SelectObject(MemDCCard, cardFrontArray[frontIndex]);
	else
		SelectObject(MemDCCard, back);

	if (selected)
		BitBlt(hdc, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCINVERT);
	else
		BitBlt(hdc, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCCOPY);

	DeleteDC(MemDCCard);
}
