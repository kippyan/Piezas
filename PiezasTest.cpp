/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, toggleTurn){
  Piezas p;
  ASSERT_TRUE(p.toggleTurn() == O);
}

TEST(PiezasTest, pieceAtHappy)
{
  Piezas p;
    ASSERT_TRUE(p.pieceAt(0, 0) == Blank);
}

