#include <iostream>
using namespace std;
int x, y;
char tabla[4][4], SEMN, orice, pozitiiPline;

void Afis() {
	for (int i = 1; i <= 3; i++, cout << endl)
		for (int j = 1; j <= 3; j++)
			cout << tabla[i][j] << ' ';
}
void Reset() {
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			tabla[i][j] = '-';
	SEMN = 'X';
	pozitiiPline = 0;
}
bool VerifVert(int y) {
	if (tabla[1][y] == tabla[2][y] &&
		tabla[2][y] == tabla[3][y] &&
		tabla[1][y] == tabla[3][y])
		return true;
	else
		return false;
}
bool VerifOriz(int x) {
	if (tabla[x][1] == tabla[x][2] &&
		tabla[x][2] == tabla[x][3] &&
		tabla[x][1] == tabla[x][3])
		return true;
	else
		return false;
}
bool VerifDiag() {
	if (tabla[1][1] == tabla[2][2] &&
		tabla[2][2] == tabla[3][3] &&
		tabla[1][1] == tabla[3][3] && 
		tabla[1][1] != '-'
		||
		tabla[1][3] == tabla[2][2] &&
		tabla[2][2]== tabla [3][1] &&
		tabla[1][3]==tabla[3][1] &&
		tabla[1][3]!='-')
		return true;
	else
		return false;
}
bool Verif(int x, int y) {
	if (x == y || x+y-1==3)
	{
		if (VerifOriz(x) || VerifVert(y) || VerifDiag())
			return true;
		else
			return false;
	}
	else
	{
		if (VerifOriz(x) || VerifVert(y))
			return true;
		else
			return false;
	}
	return false;
}

void Devider() {
	for (int i = 1; i <= 50; i++)
		cout << '_';
	cout << '\n' << '\n';
}
 
int main()
{
		Reset();
		while (pozitiiPline < 9) {
			Devider();
			Afis();
			Devider();
			cout << SEMN << " ALEGE\n";
			cin >> x >> y;

			while (tabla[x][y] != '-')
			{
				cout << "NU ESTE O POZITIE VALIDA\n";
				cin >> x >> y;
			}
			tabla[x][y] = SEMN;
			pozitiiPline++;

			if (Verif(x, y)) {
				Devider();
				Afis();
				Devider();
				cout << SEMN << " A CASTIGAT\n";
				Devider();
				return 0;
			}
			if (SEMN == 'X')
				SEMN = '0';
			else
				SEMN = 'X';
		}
		Devider();
		cout << "EGALITATE";
		Devider();
		cin >> orice;
		return 0;
}

