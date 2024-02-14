#pragma once

#ifndef ROWOFSTACKS_H
#define ROWOFSTACKS_H
#include "IListOfLists.h"
#include "CardList.h"
#include <vector>

class RowOfStacks : public IListOfLists {
private:
	std::vector<CardList*> stackList; //not Stack
	int currentList;

public:
	RowOfStacks();
	~RowOfStacks();

	int getSize();
	ICardList* getFirstList(); //in ILofL
	ICardList* getNextList(); //in ILofL
	ICardList* getLastList(); // in ILofL
	ICardList* getListAtIndex(int); // in ILofL
	virtual int getListIndex(ICardList*); //in ILofL
	virtual int getCardIndex(int listIndex, ICard*); // in ILofL


};

#endif


