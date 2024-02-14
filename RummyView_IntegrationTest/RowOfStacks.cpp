#include <iostream>
#include "RowOfStacks.h"

RowOfStacks::RowOfStacks() {
	std::cout << "output";
}

RowOfStacks::~RowOfStacks()
{
}

int RowOfStacks::getSize() {
	return stackList.size();
}

ICardList* RowOfStacks::getFirstList() {
	if (stackList.size() < 1) return 0;
	currentList = 0;
	return stackList[0];
}

ICardList* RowOfStacks::getNextList() {
	currentList++;
	if (currentList > stackList.size() - 1) return 0;
	return stackList[currentList];
}

ICardList* RowOfStacks::getLastList() {
	if (stackList.size() == 0) return 0;
	return stackList[stackList.size() - 1];
}

ICardList* RowOfStacks::getListAtIndex(int index) {
	if (index < 0 || index > stackList.size() - 1 || stackList.size() == 0) return 0;
	return stackList[index];
}


int RowOfStacks::getListIndex(ICardList* cardList) {
	return 0;
}

int RowOfStacks::getCardIndex(int listIndex, ICard* card) {
	return 0;

}




