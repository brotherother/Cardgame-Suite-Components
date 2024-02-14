#include "CardAreaViewStub.h"
#include "ICardCollectionStub.h"
#include "IListOfLists.h"
#include "ICardList.h"
#include "ICard.h"
#include <iostream>



void CardAreaViewStub::cardAreaViewGeneral()
{
	std::cout << "CardAreaViewDisplay \n";
}

void CardAreaViewStub::cardAreaViewDisplay()
{
	std::cout << "CardAreaViewDisplay \n";
}

ICardCollection* CardAreaViewStub::getCollection(int x, int y)
{
	return 0;
}

ICardList* CardAreaViewStub::getList(int x, int y)
{
	return 0;
}

int CardAreaViewStub::getIndex(int x, int y)
{
	return 0;
}