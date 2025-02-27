#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
 **/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
 **/
Piezas::Piezas()
{
  board = std::vector<std::vector<Piece> >(BOARD_ROWS, std::vector<Piece>(BOARD_COLS, Blank));
  turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
 **/
void Piezas::reset()
{
  for(unsigned int i = 0; i < BOARD_ROWS; i++){
    for(unsigned int j = 0; j < BOARD_COLS; j++){
      board[i][j] = Blank;
    }
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
 **/ 
Piece Piezas::dropPiece(int column)
{
  if(board[0][column] == Blank){
    board[0][column] = turn;
  }else if(board[1][column] == Blank){
    board[1][column] = turn;
  }else if(board[2][column] == Blank){
    board[2][column] = turn;
  }else{
    return turn;
  }
  return toggleTurn();
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
 **/
Piece Piezas::pieceAt(int row, int column)
{
  if(row < 0 || column < 0 || row > BOARD_ROWS - 1 || column > BOARD_COLS - 1)
    return Invalid;
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
 **/
Piece Piezas::gameState()
{
  int max_x_streak = 0, cur_x_streak = 0, max_o_streak = 0, cur_o_streak = 0;
  Piece prev_piece = Invalid;
  for(unsigned int i = 0; i < BOARD_ROWS; i++){
    for(unsigned int j = 0; j < BOARD_COLS; j++){
      checkPiece(i, j, cur_x_streak, max_x_streak, cur_o_streak, max_o_streak, prev_piece);
    }
    cur_x_streak = 0;
    cur_o_streak = 0;
    prev_piece = Invalid;
  }
  for(unsigned int j = 0; j < BOARD_COLS; j++){
    for(unsigned int i = 0; i < BOARD_ROWS; i++){
      checkPiece(i, j, cur_x_streak, max_x_streak, cur_o_streak, max_o_streak, prev_piece);
    }
    cur_x_streak = 0;
    cur_o_streak = 0;
    prev_piece = Invalid;
  }
  if(max_x_streak > max_o_streak)
    return X;
  if(max_x_streak < max_o_streak)
    return O;
  return Blank;
}
void Piezas::checkPiece(const int i, const int j, int& cur_x, int& max_x, int& cur_o, int& max_o, Piece& prev_piece){
    prev_piece = board[i][j];
  if(board[i][j] == X){
    cur_x++;
    cur_o = 0;
    max_x = cur_x > max_x ? cur_x : max_x;
  }else if(board[i][j] == O){
    cur_o++;
    cur_x = 0;
    max_o = cur_o > max_o ? cur_o : max_o;
  }else{
    cur_x = 0;
    cur_o = 0;
  }
}

Piece Piezas::toggleTurn()
{
  if(turn == X)
    turn = O;
  else if(turn == O)
    turn = X;
  return turn;
}
