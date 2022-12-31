#include "Game.h"
#include "utility.h"
int main()
{
	//5
	//2 3 5 6 1
	//1 5 4 2 9
	cout << "ÇëÊäÈëÖ½ÅÆÊýÁ¿" << endl;
	int num;
	cin >> num;
	Game A(num);
	A.init();
	A.work();
	return 0;
}