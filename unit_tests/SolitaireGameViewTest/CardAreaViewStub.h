#pragma once
#if !defined(CARDAREAVIEW_H)
#define CARDAREAVIEW_H

class ICardCollection;
class IListOfLists;
class ICardList;
class ICard;

class CardAreaView
{
public:
	void cardAreaViewGeneral();
	void cardAreaViewDisplay();
	ICardCollection* getCollection(int, int);
	ICardList* getList(int, int);
	int getIndex(int, int);
};
#endif