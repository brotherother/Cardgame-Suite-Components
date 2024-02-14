#include "CardViewFactory.h"
ICardView* CardViewFactory::newCardView() 
{
	return new CardView();
}