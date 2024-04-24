#pragma once
#include <iostream>
class Game
{

private:
	char board[9];
	const char X = 'X', O = 'O';
	char turn = X;

	void initializeboard(char* board) {
		for (int i = 0; i < 9; ++i) {
			board[i] = '.';
		}
	}
	void drawBoard(char* board) {
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				std::cout << board[y + x * 3];
			}

			std::cout << std::endl;
		}
	}
	bool askForMoove(char* board, char X, char O, char turn) {
		int pick;
		std::cout << "player " << turn << " pick a number between 0 and 8: ";
		std::cin >> pick;
		if (pick < 0 || pick > 8) {
			std::cout << "Invalid range, please pick a position between 0 and 8, inclusive." << std::endl;
			return false;
		}

		else if (board[pick] != '.') {
			std::cout << "place is already used!!!";
			return false;
		}
		else {
			board[pick] = turn;
			return true;
		}

	}

	bool checkForwin(char* board) {
		// horizontal win
		if ((board[0] != '.') && board[0] == board[1] && board[0] == board[2])
			return true;
		else if ((board[3] != '.') && board[3] == board[4] && board[3] == board[5])
			return true;
		else if ((board[6] != '.') && board[6] == board[7] && board[6] == board[8])
			return true;

		// vertical win
		else if ((board[0] != '.') && board[0] == board[3] && board[0] == board[6])
			return true;
		else if ((board[1] != '.') && board[1] == board[4] && board[1] == board[7])
			return true;
		else if ((board[2] != '.') && board[2] == board[5] && board[2] == board[8])
			return true;

		// diognal win
		else if ((board[0] != '.') && board[0] == board[4] && board[0] == board[8])
			return true;
		else if ((board[2] != '.') && board[2] == board[4] && board[2] == board[6])
			return true;
		else
			return false;
	}

	bool checkFortie(char* board) {
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if (board[y + x * 3] == '.')
					return false;
			}
		}

		return true;

	}


public:

	void start() {
		
		initializeboard(board);

		bool check = false;
		drawBoard(board);
		while (!checkForwin(board) && !checkFortie(board)) {

			if (askForMoove(board, X, O, turn)) {
				drawBoard(board);
				if (turn == X)
					turn = O;
				else
					turn = X;
			}

		}

		if (checkForwin(board)) {
			if (turn == X)
				std::cout << "Its done player O wins it!!";
			else
				std::cout << "Its done player X wins it!!";
		}

		else if (checkFortie(board)) {
			std::cout << std::endl << "It's a draw!";
			
		}


	}
};