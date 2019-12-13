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

TEST(PiezasTest, toggle1Turn)
{
  Piezas p;
  ASSERT_TRUE(p.toggleTurn() == O);
}
TEST(PiezasTest, toggle2Turn)
{
  Piezas p;
  p.toggleTurn();
  ASSERT_TRUE(p.toggleTurn() == X);
}

TEST(PiezasTest, pieceAtValid)
{
  Piezas p;
  ASSERT_TRUE(p.pieceAt(0, 0) == Blank);
}

TEST(PiezasTest, pieceAtBelowX)
{
  Piezas p;
  ASSERT_TRUE(p.pieceAt(-1, 0) == Invalid);
}
TEST(PiezasTest, pieceAtAboveX)
{
  Piezas p;
  ASSERT_TRUE(p.pieceAt(3, 0) == Invalid);
}
TEST(PiezasTest, pieceAtBelowY)
{
  Piezas p;
  ASSERT_TRUE(p.pieceAt(0, -1) == Invalid);
}
TEST(PiezasTest, pieceAtAboveY)
{
  Piezas p;
  ASSERT_TRUE(p.pieceAt(0, 4) == Invalid);
}

TEST(PiezasTest, place1Piece)
{
  Piezas p;
  p.dropPiece(0);
  ASSERT_TRUE(p.pieceAt(0, 0) == X);
}
TEST(PiezasTest, place2Piece)
{
  Piezas p;
  p.dropPiece(3);
  p.dropPiece(3);
  ASSERT_TRUE(p.pieceAt(1, 3) == O);
}
TEST(PiezasTest, place3Piece)
{
  Piezas p;
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(1);
  ASSERT_TRUE(p.pieceAt(2, 1) == O);
}

