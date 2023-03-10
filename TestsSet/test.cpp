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

TEST(select_and_deselect, quantity_check) {
	myGame.start();

	myGame.selectByIndex(0);
	EXPECT_EQ(myGame.getSelectedIndexes().size(), 1);
	myGame.selectByIndex(0);
	EXPECT_EQ(myGame.getSelectedIndexes().size(), 1);
	myGame.selectByIndex(1);
	EXPECT_EQ(myGame.getSelectedIndexes().size(), 2);
	myGame.selectByIndex(1);
	myGame.selectByIndex(1);
	myGame.selectByIndex(5);
	EXPECT_EQ(myGame.getSelectedIndexes().size(), 3);
	myGame.selectByIndex(1);
	myGame.selectByIndex(10);
	myGame.selectByIndex(11);
	EXPECT_EQ(myGame.getSelectedIndexes().size(), 5);
	myGame.deSelectByIndex(5);
	EXPECT_EQ(myGame.getSelectedIndexes().size(), 4);
	myGame.deSelectByIndex(5);
	EXPECT_EQ(myGame.getSelectedIndexes().size(), 4);
	myGame.deSelectByIndex(0);
	EXPECT_EQ(myGame.getSelectedIndexes().size(), 3);
	myGame.clearSelection();
	EXPECT_EQ(myGame.getSelectedIndexes().size(), 0);

	}

TEST(CorrectDisplay, TwelveFiguresAtStart) {
	myGame.start();
  EXPECT_EQ(myGame.getDisplayed().size(), 12);
}

TEST(isASet, shouldWork_once) {
	//EXPECT_EQ()
}