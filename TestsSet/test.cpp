#include "pch.h"
#include "Game.cpp"
#include "Figure.cpp"

Game myGame{};

Figure card0{ 0 };
Figure card0{ 1 };
Figure card0{ 2 };

TEST(drawFigures_should_work, some_tests) {
	myGame.start();

	EXPECT_EQ(myGame.getDisplayed().size(), 12);
	myGame.drawCards(1);
	EXPECT_EQ(myGame.getDisplayed().size(), 13);

}
