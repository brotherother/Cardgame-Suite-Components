#pragma once
#if !defined(IRUMMYGAMESTUB_H)
#define IRUMMYGAMESTUB_H


class ICardList;
class IListOfLists;

class IRummyGameStub 
{
public:
	virtual ICardList* getStock() = 0;
	virtual ICardList* getDiscard() = 0;
	virtual ICardList* getPlayerHand() = 0;
	virtual ICardList* getOpponentHand() = 0;
	virtual IListOfLists* getFoundation() = 0;
	virtual ~IRummyGameStub() {};
};

#endif
