#include "header.h"
#include "Menu.h"
int main() 
{
	enum { DRIVER = 1, CUSTOMER, QUIT };
	int command = 0;
	Menu m;
	gotoxy(30, 0);
	cout << " ==================== C N U b e r ==================== " << endl;
	
	cout << "1) �����ڸ��\n2) �°����\n3) ������\n >��带 �����ϼ���. => ";
	cin >> command;
	switch (command)
	{
	case DRIVER: m.password(); break;
	case CUSTOMER: m.customerMenu(); break;
	case QUIT: exit(1);
	default: cout << "�ٽ� �Է����ּ���."; 
	}

	return 0;
}