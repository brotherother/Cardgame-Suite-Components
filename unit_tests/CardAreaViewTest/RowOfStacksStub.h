//Sean from AM class helped with creating the stubs
#pragma once
#ifndef ROWOFSTACKSSTUB_H
#define ROWOFSTACKSSTUB_H
#include "IListOfListsStub.h"
#include "CardList.h"
#include <vector>

class RowOfStacksStub : public IListOfListsStub {
private:
    std::vector<CardList*> row;
    int currIndex;
public:
    virtual int getListIndex(ICardList*);
    virtual int getCardIndex(int listIndex, ICard*);

    int getSize();
    ICardList* getFirstList();
    bool isFirst();
    ICardList* getLastList();
    bool isLast();
    ICardList* getNextList();
    ICardList* getPrevious();

    void add(CardList*);
    void add(CardList*, int);
    CardList* remove(int);
    void read(std::string);
    void write();
    RowOfStacksStub();
    ICardList* getListAtIndex(int);
};

#endif
