#include "header.h"
#include "Menu.h"
int main() 
{
	enum { DRIVER = 1, CUSTOMER, QUIT };
	int command = 0;
	Menu m;
	gotoxy(30, 0);
	cout << " ==================== C N U b e r ==================== " << endl;
	
	cout << "1) 운전자모드\n2) 승객모드\n3) 나가기\n >모드를 선택하세요. => ";
	cin >> command;
	switch (command)
	{
	case DRIVER: m.password(); break;
	case CUSTOMER: m.customerMenu(); break;
	case QUIT: exit(1);
	default: cout << "다시 입력해주세요."; 
	}

	return 0;
}