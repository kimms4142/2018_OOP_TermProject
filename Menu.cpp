#include "Menu.h"
void Menu::customerMenu()
{
start:
	char wish;
	system("cls");
	int options, id;
	gotoxy(28, 0);
	cout << " #-CNUber�� ���Ű� ȯ���մϴ�-# " << endl;
	gotoxy(37, 1);
	cout << " #�°� �޴�# " << endl;
	cout << " 1. ���� �ϱ� " << endl;
	cout << " 2. ���� Ȯ�� " << endl;
	cout << " 3. ���� ��� " << endl;
	cout << " 4. ���� ���� " << endl;
	cout << " 5. Driver���� ��ȯ " << endl;
	cout << "�޴��� ������ �ּ��� => ";
	cin >> options;
	switch (options)
	{
	case 1:
		new_trip();
		break;
	case 2:
		trip_info();
		break;
	case 3:
		cout << " �°���ȣ�� �Է����ּ��� :: ";
		cin >> id;
		cancel_trip(id);
		break;
	case 4:
		end_trip();
		break;
	case 5:
		password();
		break;
	default:
		cout << "�޴��� �߸� �Է��ϼ̽��ϴ�.";
		_getch();
	}
	_getch();
	system("cls");
	gotoxy(25, 0);
	cout << " ��� �Ͻðڽ��ϱ�?(Y/N) :: ";
	cin >> wish;
	if ((wish == 'y') || (wish == 'Y'))
		goto start;
	else
	{
		system("cls");
		gotoxy(30, 0);
		cout << " #! �̿��� �ּż� �����մϴ�. !# ";
		gotoxy(35, 1);
		cout << " =====�ȳ��� ������===== \n";
	}
}
void Menu::driverMenu()
{
start:
	system("cls");
	int options;
	char yes;
	gotoxy(25, 0);
	cout << " #- WELCOME TO CNUber -# " << endl;
	gotoxy(27, 1);
	cout << " # �޴��� ������ # " << endl;
	cout << " 1. ���ο� ������ ��� " << endl;
	cout << " 2. ������ ���� " << endl;
	cout << " 3. ������ ���� ���� " << endl;
	cout << " 4. ������ ��� " << endl;
	cout << " 5. �°����� ��ȯ�ϱ� " << endl;
	cout << " �޴��� �������ּ��� =>  ";
	cin >> options;
	switch (options)
	{
	case 1:
		add_new();
		break;
	case 2:
		removing();
		break;
	case 3:
		modify();
		break;
	case 4:
		show();
		break;
	case 5:
		customerMenu();
		break;
	default:
		cout << " �������� �ʴ� �޴��Դϴ�!! ";
		_getch();
	}
	_getch();
	system("cls");
	gotoxy(25, 0);
	cout << " ��� �Ͻðڽ��ϱ�?(Y/N) :: ";
	cin >> yes;
	if ((yes == 'y') || (yes == 'Y'))
		goto start;
	else
	{
		system("cls");
		gotoxy(30, 0);
		cout << " #! �̿��� �ּż� �����մϴ�. !# ";
		gotoxy(35, 1);
		cout << " =====�ȳ��� ������===== \n";
	}
}

void Menu::add_new()
{
	fstream filed;
	system("cls");
	int x;
	filed.open("driver.dat", ios::app | ios::binary);
	filed.seekp(0, ios::end);
	x = filed.tellp() / sizeof(d);
	x++;
	d.in_details(x);
	filed.write((char*)&d, sizeof(d));
	filed.close();
}
void Menu::removing() //driver
{
	fstream fin, fout;
	system("cls");
	int id;
	fin.open("driver.dat", ios::in | ios::binary);   //driver.dat ���� �б�
	fout.open("xdriver.dat", ios::out | ios::binary); //xdriver.dat ���Ͽ� ����. ( �Ѵ� binary���� )
	cout << " ���� �������� ID�� �Է��ϼ��� :: ";
	cin >> id;

	while (fin.read((char*)&d, sizeof(d)))
	{
		if (d.getId() != id)
		{
			fout.write((char*)&d, sizeof(d));
		}
		else
		{
			system("cls");
			gotoxy(30, 0);
			cout << " **������ ������ ���������ϴ�** " << endl;
			d.show_details();
		}
	}
	fin.close();
	fout.close();
	remove("driver.dat");
	rename("xdriver.dat", "driver.dat");
}
void Menu::show() //driver
{
	fstream filed;
	system("cls");
	int options, id;
	filed.open("driver.dat", ios::in | ios::binary);
	cout << " 1. �ش� ID�� ������ ��������" << endl;
	cout << " 2. ��� �������� ��������" << endl;
	cout << " �ɼ��� �������ּ��� :: ";
	cin >> options;
	if (options == 1)
	{
		cout << " �������� ID�� �Է��ϼ��� :: ";
		cin >> id;
	}
	system("cls");
	while (filed.read((char*)&d, sizeof(d)))
	{
		if (options == 1)
		{
			if (d.getId() == id)
			{
				system("cls");
				gotoxy(30, 0);
				cout << " <<<������ ����>>>" << endl;
				d.show_details();
			}
		}
		else if (options == 2)
		{
			d.show_details();
			cout << endl << endl;
		}
	}
	_getch();
	filed.close();
}
void Menu::modify()
{	
	fstream fin, fout;
	system("cls");
	int id;
	
	fin.open("driver.dat", ios::in | ios::binary);   //driver.dat ���� �б�
	fout.open("xdriver.dat", ios::out | ios::binary); //xdriver.dat ���Ͽ� ����. ( �Ѵ� binary���� )
	cout << " ������ �������� ID�� �����ּ��� :: ";
	cin >> id;

	while (fin.read((char*)&d, sizeof(d)))
	{
		if (d.getId() == id)
			d.mod_details();
		fout.write((char*)&d, sizeof(d));

	}
	fin.close();
	fout.close();
	remove("driver.dat");
	rename("xdriver.dat", "driver.dat");
	_getch();
}
void Menu::password()
{
	char pass[10];
	while (true) {
		cout << " ��й�ȣ�� �Է����ּ���(������:q) => ";
		cin >> pass;
		if (!_strcmpi(pass, "1234"))
			driverMenu();
		else if (!_strcmpi(pass, "q"))
			break;

		else cout << " �߸��� ��й�ȣ�Դϴ�. �ٽ� �õ��Ͻʽÿ�! \n";
	}
}

void Menu::new_trip()
{
	fstream filec;
	system("cls");
	int x;
	filec.open("custom.dat", ios::app | ios::binary);
	filec.seekp(0, ios::end);
	x = filec.tellp() / sizeof(c);
	x++;
	cout << " =====������ �Է��� �ּ���!===== " << endl;
	c.get_details(x);

	if (_strcmpi(c.getCusCarType(), "����") == 0)
	{
		Matching::smallSize.push(c.getCusId());
		cout << "�����ڵ��� ���� �Ϸ�";
	}
	else if (_strcmpi(c.getCusCarType(), "����") == 0)
	{
		Matching::middleSize.push(c.getCusId());
		cout << "�����ڵ��� ���� �Ϸ�";
	}
	else if (_strcmpi(c.getCusCarType(), "����") == 0)
	{
		Matching::bigSize.push(c.getCusId());
		cout << "�����ڵ��� ���� �Ϸ�";
	}
	filec.write((char*)&c, sizeof(c));
	filec.close();
	Matching::matching(x);
}
void Menu::trip_info()
{
	fstream filec;
	system("cls");
	int id;
	filec.open("custom.dat", ios::in | ios::binary);
	cout << " ID�� �Է����ּ��� :: ";
	cin >> id;
	while (filec.read((char*)&c, sizeof(c)))
	{
		if (c.getCusId() == 0) {
			cout << "�մ��� �ƹ��� �����ϴ�." << endl;
		}
		else if (c.getCusId() == id)
		{
			c.pf_details();
			cout << endl;
			cout << " <<<������ ����>>> " << endl;
			linked_driver(id);
			
		}
	}
	filec.close();
	_getch();
}

void Menu::cancel_trip(int & id)
{
	fstream fin, fout;
	system("cls");
	fin.open("custom.dat", ios::in | ios::binary);
	fout.open("xcustom.dat", ios::out | ios::binary);
	while (fin.read((char*)&c, sizeof(c)))
	{
		if (c.getCusId() != id)                     //����� �°� ���� ����
		{
			fout.write((char*)&c, sizeof(c));
		}
		else
		{
			system("cls");
			gotoxy(37, 0);
			cout << " ##-��  ��  ��-## " << endl;
			c.pf_details();
			cout << endl;
			cout << " --������ ����-- ";
			cout << endl;
			_getch();
			unmatching(id);;
		}
	}
	fin.close();
	fout.close();
	remove("custom.dat");
	rename("xcustom.dat", "custom.dat");
}

void Menu::end_trip()
{
	system("cls");
	int id;
	cout << " �������� �ϴ� �°���ȣ�� �Է����ּ��� :: ";
	cin >> id;
	system("cls");
	gotoxy(30, 0);
	cout << " #! �̿��� �ּż� �����մϴ�. !# " << endl;
	gotoxy(35, 4);
	cout << " =====�ȳ��� ������===== \n ";
	_getch();
	cancel_trip(id);
}