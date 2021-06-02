#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
int winsX;
int winsY;
int draws;
using namespace std;
unsigned short counter = 0;
short key = NULL;
bool flag = 0;
char whoStart;
/*
flag = 0 --> 'X'
flag = 1 --> 'O'
*/
char gamingField[3][3] = {
	{NULL, NULL, NULL},
	{NULL, NULL, NULL},
	{NULL, NULL, NULL}
};
bool canPlay() {
	if (
		(
			gamingField[0][0] == 'O' && gamingField[1][0] == 'X' ||
			gamingField[1][0] == 'O' && gamingField[2][0] == 'X' ||
			gamingField[0][0] == 'O' && gamingField[2][0] == 'X' ||
			gamingField[0][0] == 'X' && gamingField[1][0] == 'O' ||
			gamingField[1][0] == 'X' && gamingField[2][0] == 'O' ||
			gamingField[0][0] == 'X' && gamingField[2][0] == 'O') &&
		(
			gamingField[0][1] == 'O' && gamingField[1][1] == 'X' ||
			gamingField[1][1] == 'O' && gamingField[2][1] == 'X' ||
			gamingField[0][1] == 'O' && gamingField[2][1] == 'X' ||
			gamingField[0][1] == 'X' && gamingField[1][1] == 'O' ||
			gamingField[1][1] == 'X' && gamingField[2][1] == 'O' ||
			gamingField[0][1] == 'X' && gamingField[2][1] == 'O') &&
		(
			gamingField[0][2] == 'O' && gamingField[1][2] == 'X' ||
			gamingField[1][2] == 'O' && gamingField[2][2] == 'X' ||
			gamingField[0][2] == 'O' && gamingField[2][2] == 'X' ||
			gamingField[0][2] == 'X' && gamingField[1][2] == 'O' ||
			gamingField[1][2] == 'X' && gamingField[2][2] == 'O' ||
			gamingField[0][2] == 'X' && gamingField[2][2] == 'O') &&
		(
			gamingField[0][0] == 'O' && gamingField[0][1] == 'X' ||
			gamingField[0][1] == 'O' && gamingField[0][2] == 'X' ||
			gamingField[0][0] == 'O' && gamingField[0][2] == 'X' ||
			gamingField[0][0] == 'X' && gamingField[0][1] == 'O' ||
			gamingField[0][1] == 'X' && gamingField[0][2] == 'O' ||
			gamingField[0][0] == 'X' && gamingField[0][2] == 'O') &&
		(
			gamingField[1][0] == 'O' && gamingField[1][1] == 'X' ||
			gamingField[1][1] == 'O' && gamingField[1][2] == 'X' ||
			gamingField[1][0] == 'O' && gamingField[1][2] == 'X' ||
			gamingField[1][0] == 'X' && gamingField[1][1] == 'O' ||
			gamingField[1][1] == 'X' && gamingField[1][2] == 'O' ||
			gamingField[1][0] == 'X' && gamingField[1][2] == 'O') &&
		(
			gamingField[2][0] == 'O' && gamingField[2][1] == 'X' ||
			gamingField[2][1] == 'O' && gamingField[2][2] == 'X' ||
			gamingField[2][0] == 'O' && gamingField[2][2] == 'X' ||
			gamingField[2][0] == 'X' && gamingField[2][1] == 'O' ||
			gamingField[2][1] == 'X' && gamingField[2][2] == 'O' ||
			gamingField[2][0] == 'X' && gamingField[2][2] == 'O') &&
		(
			gamingField[0][0] == 'O' && gamingField[1][1] == 'X' ||
			gamingField[1][1] == 'O' && gamingField[2][2] == 'X' ||
			gamingField[0][0] == 'O' && gamingField[2][2] == 'X' ||
			gamingField[0][0] == 'X' && gamingField[1][1] == 'O' ||
			gamingField[1][1] == 'X' && gamingField[2][2] == 'O' ||
			gamingField[0][0] == 'X' && gamingField[2][2] == 'O') &&
		(
			gamingField[0][2] == 'O' && gamingField[1][1] == 'X' ||
			gamingField[1][1] == 'O' && gamingField[2][0] == 'X' ||
			gamingField[0][2] == 'O' && gamingField[2][0] == 'X' ||
			gamingField[0][2] == 'X' && gamingField[1][1] == 'O' ||
			gamingField[1][1] == 'X' && gamingField[2][0] == 'O' ||
			gamingField[0][2] == 'X' && gamingField[2][0] == 'O'
			)
		)return 0;
	else return 1;
}
void clearGF() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			gamingField[i][j] = NULL;
}
void showGF() {
	cout << gamingField[0][0] << "|" << gamingField[0][1] << "|" << gamingField[0][2] << endl;
	cout << "-----" << endl;
	cout << gamingField[1][0] << "|" << gamingField[1][1] << "|" << gamingField[1][2] << endl;
	cout << "-----" << endl;
	cout << gamingField[2][0] << "|" << gamingField[2][1] << "|" << gamingField[2][2] << endl;
}
char checkWin() {
	if (gamingField[0][0] == 'X' && gamingField[1][0] == 'X' && gamingField[2][0] == 'X' ||
		gamingField[0][1] == 'X' && gamingField[1][1] == 'X' && gamingField[2][1] == 'X' ||
		gamingField[0][2] == 'X' && gamingField[1][2] == 'X' && gamingField[2][2] == 'X' ||
		gamingField[0][0] == 'X' && gamingField[0][1] == 'X' && gamingField[0][2] == 'X' ||
		gamingField[1][0] == 'X' && gamingField[1][1] == 'X' && gamingField[1][2] == 'X' ||
		gamingField[2][0] == 'X' && gamingField[2][1] == 'X' && gamingField[2][2] == 'X' ||
		gamingField[0][0] == 'X' && gamingField[1][1] == 'X' && gamingField[2][2] == 'X' ||
		gamingField[0][2] == 'X' && gamingField[1][1] == 'X' && gamingField[2][0] == 'X') {
		return 'X';
	}
	else if (
		gamingField[0][0] == 'O' && gamingField[1][0] == 'O' && gamingField[2][0] == 'O' ||
		gamingField[0][1] == 'O' && gamingField[1][1] == 'O' && gamingField[2][1] == 'O' ||
		gamingField[0][2] == 'O' && gamingField[1][2] == 'O' && gamingField[2][2] == 'O' ||
		gamingField[0][0] == 'O' && gamingField[0][1] == 'O' && gamingField[0][2] == 'O' ||
		gamingField[1][0] == 'O' && gamingField[1][1] == 'O' && gamingField[1][2] == 'O' ||
		gamingField[2][0] == 'O' && gamingField[2][1] == 'O' && gamingField[2][2] == 'O' ||
		gamingField[0][0] == 'O' && gamingField[1][1] == 'O' && gamingField[2][2] == 'O' ||
		gamingField[0][2] == 'O' && gamingField[1][1] == 'O' && gamingField[2][0] == 'O') {
		return 'O';
	}
	else return 0;
}
int setPosition(int _key) {
	switch (_key) {
	case 1:
		if (gamingField[2][0] != NULL)
			return 0;
		else {
			if (flag == 0)
				gamingField[2][0] = 'X';
			else {
				gamingField[2][0] = 'O';
				return 1;
			}
		}
		break;
	case 2:
		if (gamingField[2][1] != NULL)
			return 0;
		else {
			if (flag == 0)
				gamingField[2][1] = 'X';
			else {
				gamingField[2][1] = 'O';
				return 1;
			}
			break;
	case 3:
		if (gamingField[2][2] != NULL)
			return 0;
		else {
			if (flag == 0)
				gamingField[2][2] = 'X';
			else {
				gamingField[2][2] = 'O';
				return 1;
			}
		}
		break;
	case 4:
		if (gamingField[1][0] != NULL)
			return 0;
		else {
			if (flag == 0)
				gamingField[1][0] = 'X';
			else {
				gamingField[1][0] = 'O';
				return 1;
			}
		}
		break;
	case 5:
		if (gamingField[1][1] != NULL)
			return 0;
		else {
			if (flag == 0)
				gamingField[1][1] = 'X';
			else {
				gamingField[1][1] = 'O';
				return 1;
			}
		}
		break;
	case 6:
		if (gamingField[1][2] != NULL)
			return 0;
		else {
			if (flag == 0)
				gamingField[1][2] = 'X';
			else {
				gamingField[1][2] = 'O';
				return 1;
			}
		}
		break;
	case 7:
		if (gamingField[0][0] != NULL)
			return 0;
		else {
			if (flag == 0)
				gamingField[0][0] = 'X';
			else {
				gamingField[0][0] = 'O';
				return 1;
			}
		}
		break;
	case 8:
		if (gamingField[0][1] != NULL)
			return 0;
		else {
			if (flag == 0)
				gamingField[0][1] = 'X';
			else {
				gamingField[0][1] = 'O';
				return 1;
			}
		}
		break;
	case 9:
		if (gamingField[0][2] != NULL)
			return 0;
		else {
			if (flag == 0)
				gamingField[0][2] = 'X';
			else {
				gamingField[0][2] = 'O';
				return 1;
			}
		}
		break;
	default:
		return -1;
		break;
		}
	}
}
int checkPosition(int _key) {
	switch (_key) {
	case 1:
		if (gamingField[2][0] != NULL)
			return 0;
		else return 1;
		break;
	case 2:
		if (gamingField[2][1] != NULL)
			return 0;
		else return 1;
		break;
	case 3:
		if (gamingField[2][2] != NULL)
			return 0;
		else return 1;
		break;
	case 4:
		if (gamingField[1][0] != NULL)
			return 0;
		else return 1;
		break;
	case 5:
		if (gamingField[1][1] != NULL)
			return 0;
		else return 1;
		break;
	case 6:
		if (gamingField[1][2] != NULL)
			return 0;
		else return 1;
		break;
	case 7:
		if (gamingField[0][0] != NULL)
			return 0;
		else return 1;
		break;
	case 8:
		if (gamingField[0][1] != NULL)
			return 0;
		else return 1;
		break;
	case 9:
		if (gamingField[0][2] != NULL)
			return 0;
		else return 1;
		break;
	default:
		return -1;
		break;
	}
}
int readKey() {
	int _key = -1;
	switch (_getch()) {
	case 49:
		_key = 1;
		break;
	case 50:
		_key = 2;
		break;
	case 51:
		_key = 3;
		break;
	case 52:
		_key = 4;
		break;
	case 53:
		_key = 5;
		break;
	case 54:
		_key = 6;
		break;
	case 55:
		_key = 7;
		break;
	case 56:
		_key = 8;
		break;
	case 57:
		_key = 9;
		break;
	default:
		_key = 0;
		break;
	}
	return _key;
}
int main() {
	ifstream fin("file.dat");
	fin >> winsX >> winsY >> draws;
	fin.close();
	ofstream fout("file.dat");
	fout.close();
	system("title Tic Tac Toe");
	bool wantContinue = 0;
	do {
		clearGF();
		do {
			cout << "Who's start first?(O/X): ";
			cin >> whoStart;
			if (whoStart == 'X' || whoStart == 'x')
				flag = 0;
			else flag = 1;
			system("cls");
			if (whoStart != 'O' && whoStart != 'X' && whoStart != 'o' && whoStart != 'x')
				cout << "Wrong choose. Type O or X" << endl;
		} while (whoStart != 'O' && whoStart != 'X' && whoStart != 'o' && whoStart != 'x');
		while (!checkWin() && counter < 9 && canPlay()) {
			while (true) {
				if (flag == 1)
					cout << "That's turn for O, choose your position at numpad" << endl;
				else cout << "That's turn for X, choose your position at numpad" << endl;
				showGF();
				key = readKey();
				system("cls");
				if (checkPosition(key) == -1) {
					cout << "Wrong key" << endl;
					continue;
				}
				else if (checkPosition(key) == 0) {
					cout << "Cant be" << endl;
					continue;
				}
				else if (checkPosition(key)) {
					setPosition(key);
					counter++;
					break;
				}
			}
			if (flag == 1)
				flag = 0;
			else flag = 1;
		}
		counter = 0;
		showGF();
		if (checkWin() == 'X') {
			winsX++;
			fstream fout("file.dat");
			fout << winsX << " " << winsY << " " << draws;
			fout.close();
			cout << "\nX is a Winner. Congratulations!!!" << endl;
		}
		else if (checkWin() == 'O') {
			winsY++;
			fstream fout("file.dat");
			fout << winsX << " " << winsY << " " << draws;
			fout.close();
			cout << "\nO is a Winner. Congratulations!!!" << endl;
		}
		else {
			draws++;
			fstream fout("file.dat");
			fout << winsX << " " << winsY << " " << draws;
			fout.close();
			cout << "\n" << "There is no winner" << endl;
		}
		ifstream fin("file.dat");
		fin >> winsX >> winsY >> draws;
		cout << "\nCount of wins:\n\tX - " << winsX << "\n\tO - " << winsY << "\nCount of draws - " << draws << endl;
		fin.close();
		cout << "Do you want continue?(Y/N): ";
		char key = NULL;
		do {
			cin >> key;
			system("cls");
			if (key != 'Y' && key != 'N' && key != 'y' && key != 'n')
				cout << "Wrong enter. Type Y or N\nDo you want continue?";
		} while (key != 'Y' && key != 'N' && key != 'y' && key != 'n');
		if (key == 'Y' || key == 'y')
			wantContinue = 1;
		else wantContinue = 0;
	} while (wantContinue);
}