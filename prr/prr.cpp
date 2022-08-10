#include <iostream>
using namespace std;
int x, y, scor[2], SCORMAXIM = 1;
char tabla[4][4], SEMN, orice, pozitiiPline;

void Devider() {
	for (int i = 1; i <= 50; i++)
		cout << '_';
	cout << '\n' << '\n';
}

void Afis() {
	Devider();
	for (int i = 1; i <= 3; i++, cout << endl)
		for (int j = 1; j <= 3; j++)
			cout << tabla[i][j] << ' ';
	Devider();
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

void AfisScor() {
	Devider();
	printf("SCOR\nX => %d | %d <= 0\n", scor[0], scor[1]);
	Devider();
}
 
int main()
{
	while (scor[0] < SCORMAXIM && scor[1] < SCORMAXIM) {
		Reset();
		while (pozitiiPline < 9) {
			Afis();
			cout << SEMN << " ALEGE:\n";
			cin >> x >> y;

			while (tabla[x][y] != '-')
			{
				cout << "NU ESTE O POZITIE VALIDA!\n";
				cin >> x >> y;
			}
			tabla[x][y] = SEMN;
			pozitiiPline++;

			if (Verif(x, y)) {
				Afis();
				cout << SEMN << " A CASTIGAT!\n";
				if (SEMN == 'X')
					scor[0]++;
				else
					scor[1]++;
				AfisScor();
				break;
			}
			if (SEMN == 'X')
				SEMN = '0';
			else
				SEMN = 'X';

			if (pozitiiPline == 9) {
				Devider();
				cout << "EGALITATE!\n";
				Devider();
			}
		}
		
		printf("Scrie orice pentru a continua: ");
		cin >> orice;
	}
	Devider();
	if (scor[0] == SCORMAXIM)
		printf("X A CASTIGAT JOCUL!\n");
	else
		printf("0 A CASTIGAT JOCUL!\n");
	Devider();
	return 0;
}

