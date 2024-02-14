#pragma once
#if !defined(CARDAREAVIEWSTUB_H)
#define CARDAREAVIEWSTUB_H

class ICardCollection;
class IListOfLists;
class ICardList;
class ICard;

class CardAreaViewStub
{
public:
	void cardAreaViewGeneral();
	void cardAreaViewDisplay();
	ICardCollection* getCollection(int, int);
	ICardList* getList(int, int);
	int getIndex(int, int);
};
#endif
