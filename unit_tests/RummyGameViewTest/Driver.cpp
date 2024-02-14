#include "CardAreaView.h"
#include "RummyGameView.h"
#include <iostream>
#include "../../ModelLayer/interface/ICardCollection.h"

int main() 
{

	CardAreaView* CardAreaViewT = new CardAreaView;
	RummyGameView* test = new RummyGameView();
	ICardCollection* ICardCollectionT = new ICardCollection();
	IRummyGameStub* IRummyGame = 0;
	IGameView* IGameViewT = 0;
	IGame* IGameT = 0;

	RummyGameView* test = new RummyGameView();
	std::cout << "Testing createGameView with an expected output of 'createGameView' \n";
	test->createGameView(nullptr);
	std::cout << "Testing getCards with an expected output of '00000000' \n";
	std::cout << test->getCards(nullptr) << std::endl;
	std::cout << "Testing createCardAreaView with an expected output of 'createCardAreaView' \n";
	test->createCardAreaView(nullptr, nullptr);
	std::cout << "Testing passCardsToView with an expected output of 'passCardsToView' \n";
	test->passCardsToView(nullptr);
	std::cout << "Testing getPosition with an expected output of '0' \n";
	std::cout<<test->getPosition() << std::endl;
	std::cout << "Testing getExtent with an expected output of '0' \n";
	std::cout << test->getExtent() << std::endl;
	std::cout << "Testing getCardAreaView with an expected output of '00000000' \n";
	std::cout << test->getCardAreaView() << std::endl;
	std::cout << "Testing getNumCardAreaViews with an expected output of '0' \n";
	std::cout << test->getNumCardAreaViews() << std::endl;

	system("pause");
}