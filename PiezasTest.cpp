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
  ASSERT_TRUE(p.pieceAt(2, 1) == X);
}
TEST(PiezasTest, place4Piece)
{
  Piezas p;
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(1);
  ASSERT_TRUE(p.dropPiece(1) == O);
}

TEST(PiezasTest, placeReset)
{
  Piezas p;
  p.dropPiece(0);
  p.reset();
  ASSERT_TRUE(p.pieceAt(0, 0) == Blank);
}

TEST(PiezasTest, emptyTie)
{
  Piezas p;
  ASSERT_TRUE(p.gameState() == Blank);
}
TEST(PiezasTest, fullTie)
{
  Piezas p;
  for(unsigned int i = 0; i < 3; i++)
    for(unsigned int j = 0; j < 4; j++)
      p.dropPiece(j);
  ASSERT_TRUE(p.gameState() == Blank);
}

TEST(PiezasTest, vertWinX)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(0);
  ASSERT_TRUE(p.gameState() == X);
}
TEST(PiezasTest, vertWinO)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(2);
  p.dropPiece(0);
  ASSERT_TRUE(p.gameState() == O);
}
TEST(PiezasTest, hozWinX)
{
  Piezas p;
  p.dropPiece(0);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(1);
  p.dropPiece(2);
  ASSERT_TRUE(p.gameState() == X);
}
TEST(PiezasTest, hozWinO)
{
  Piezas p;
  p.dropPiece(1);
  p.dropPiece(0);
  p.dropPiece(3);
  p.dropPiece(0);
  p.dropPiece(1);
  p.dropPiece(0);
  ASSERT_TRUE(p.gameState() == O);
}

