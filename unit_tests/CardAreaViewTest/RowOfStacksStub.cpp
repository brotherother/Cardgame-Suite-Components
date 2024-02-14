//Sean from AM class helped with creating the stubs

#include "RowOfStacksStub.h"
int RowOfStacksStub::getSize() { return row.size(); }

ICardList* RowOfStacksStub::getFirstList()
{
    currIndex = 0;
    ICardList* temp = (ICardList*)((CardList*)row.front());
    return temp;
}

bool RowOfStacksStub::isFirst()
{
    return currIndex == 0;
}

ICardList* RowOfStacksStub::getLastList()
{
    ICardList* temp = (ICardList*)row.back();
    row.pop_back();
    currIndex = row.size() - 1;
    return temp;
}

int RowOfStacksStub::getListIndex(ICardList* t)
{
    int ans = -1;
    for (int i = 0; i < getSize(); i++) {
        if (getListAtIndex(i) == t) {
            ans = i;
        }
    }
    return ans;
}

int RowOfStacksStub::getCardIndex(int listIndex, ICard*)
{
    return 0;
}

bool RowOfStacksStub::isLast()
{
    return (currIndex == getSize() - 1);
}

ICardList* RowOfStacksStub::getNextList()
{
    ICardList* temp = (ICardList*)row.at(currIndex);
    currIndex++;
    return temp;
}

ICardList* RowOfStacksStub::getPrevious()
{
    ICardList* temp = (ICardList*)row.at(currIndex);
    currIndex--;
    return temp;
}

ICardList* RowOfStacksStub::getListAtIndex(int i)
{
    ICardList* temp = row.at(i);
    return temp;
}

void RowOfStacksStub::add(CardList* s) { row.push_back(s); }

void RowOfStacksStub::add(CardList* s, int i) {}

CardList* RowOfStacksStub::remove(int i)
{
    CardList* temp = row.at(i);
    row.erase(row.begin() + i);
    return temp;
}

void RowOfStacksStub::write()
{
}

void RowOfStacksStub::read(std::string filename)
{
}
RowOfStacksStub::RowOfStacksStub() { currIndex = 0; }
