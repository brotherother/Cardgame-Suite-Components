

ISolitaireGame ::public
{
public:
	virtual ICardList* getStock() = 0;
	virtual ICardList* getDiscard() = 0;
	virtual IListOfLists* getFoundation() = 0;
	virtual IListOfLists* getTableau() = 0;
	//virtual void selectedCard(ICardCollection*, ICardList*, int) = 0; // these are inherited from IGame
	//virtual void buttonClicked(std::string, std::string) = 0;
	virtual ~ISolitaireGame() {};
};