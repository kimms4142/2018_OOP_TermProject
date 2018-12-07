#include "Menu.h"
void Menu::customerMenu()
{
start:
	char wish;
	system("cls");
	int options, id;
	gotoxy(28, 0);
	cout << " #-CNUber에 오신걸 환영합니다-# " << endl;
	gotoxy(37, 1);
	cout << " #승객 메뉴# " << endl;
	cout << " 1. 예약 하기 " << endl;
	cout << " 2. 예약 확인 " << endl;
	cout << " 3. 예약 취소 " << endl;
	cout << " 4. 예약 종료 " << endl;
	cout << " 5. Driver모드로 전환 " << endl;
	cout << "메뉴를 선택해 주세요 => ";
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
		cout << " 승객번호를 입력해주세요 :: ";
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
		cout << "메뉴를 잘못 입력하셨습니다.";
		_getch();
	}
	_getch();
	system("cls");
	gotoxy(25, 0);
	cout << " 계속 하시겠습니까?(Y/N) :: ";
	cin >> wish;
	if ((wish == 'y') || (wish == 'Y'))
		goto start;
	else
	{
		system("cls");
		gotoxy(30, 0);
		cout << " #! 이용해 주셔서 감사합니다. !# ";
		gotoxy(35, 1);
		cout << " =====안녕히 가세요===== \n";
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
	cout << " # 메뉴를 고르세요 # " << endl;
	cout << " 1. 새로운 운전자 등록 " << endl;
	cout << " 2. 운전자 삭제 " << endl;
	cout << " 3. 운전자 정보 변경 " << endl;
	cout << " 4. 운전자 목록 " << endl;
	cout << " 5. 승객모드로 전환하기 " << endl;
	cout << " 메뉴를 선택해주세요 =>  ";
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
		cout << " 존재하지 않는 메뉴입니다!! ";
		_getch();
	}
	_getch();
	system("cls");
	gotoxy(25, 0);
	cout << " 계속 하시겠습니까?(Y/N) :: ";
	cin >> yes;
	if ((yes == 'y') || (yes == 'Y'))
		goto start;
	else
	{
		system("cls");
		gotoxy(30, 0);
		cout << " #! 이용해 주셔서 감사합니다. !# ";
		gotoxy(35, 1);
		cout << " =====안녕히 가세요===== \n";
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
	fin.open("driver.dat", ios::in | ios::binary);   //driver.dat 파일 읽기
	fout.open("xdriver.dat", ios::out | ios::binary); //xdriver.dat 파일에 쓰기. ( 둘다 binary모드로 )
	cout << " 지울 운전자의 ID를 입력하세요 :: ";
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
			cout << " **운전자 정보가 지워졌습니다** " << endl;
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
	cout << " 1. 해당 ID의 운전자 정보보기" << endl;
	cout << " 2. 모든 운전자의 정보보기" << endl;
	cout << " 옵션을 선택해주세요 :: ";
	cin >> options;
	if (options == 1)
	{
		cout << " 운전자의 ID를 입력하세요 :: ";
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
				cout << " <<<운전자 정보>>>" << endl;
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
	
	fin.open("driver.dat", ios::in | ios::binary);   //driver.dat 파일 읽기
	fout.open("xdriver.dat", ios::out | ios::binary); //xdriver.dat 파일에 쓰기. ( 둘다 binary모드로 )
	cout << " 수정할 운전자의 ID를 적어주세요 :: ";
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
		cout << " 비밀번호를 입력해주세요(나가기:q) => ";
		cin >> pass;
		if (!_strcmpi(pass, "1234"))
			driverMenu();
		else if (!_strcmpi(pass, "q"))
			break;

		else cout << " 잘못된 비밀번호입니다. 다시 시도하십시오! \n";
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
	cout << " =====정보를 입력해 주세요!===== " << endl;
	c.get_details(x);

	if (_strcmpi(c.getCusCarType(), "소형") == 0)
	{
		Matching::smallSize.push(c.getCusId());
		cout << "소형자동차 예약 완료";
	}
	else if (_strcmpi(c.getCusCarType(), "중형") == 0)
	{
		Matching::middleSize.push(c.getCusId());
		cout << "중형자동차 예약 완료";
	}
	else if (_strcmpi(c.getCusCarType(), "대형") == 0)
	{
		Matching::bigSize.push(c.getCusId());
		cout << "대형자동차 예약 완료";
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
	cout << " ID를 입력해주세요 :: ";
	cin >> id;
	while (filec.read((char*)&c, sizeof(c)))
	{
		if (c.getCusId() == 0) {
			cout << "손님이 아무도 없습니다." << endl;
		}
		else if (c.getCusId() == id)
		{
			c.pf_details();
			cout << endl;
			cout << " <<<운전자 정보>>> " << endl;
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
		if (c.getCusId() != id)                     //취소한 승객 빼고 저장
		{
			fout.write((char*)&c, sizeof(c));
		}
		else
		{
			system("cls");
			gotoxy(37, 0);
			cout << " ##-영  수  증-## " << endl;
			c.pf_details();
			cout << endl;
			cout << " --운전자 정보-- ";
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
	cout << " 끝내고자 하는 승객번호를 입력해주세요 :: ";
	cin >> id;
	system("cls");
	gotoxy(30, 0);
	cout << " #! 이용해 주셔서 감사합니다. !# " << endl;
	gotoxy(35, 4);
	cout << " =====안녕히 가세요===== \n ";
	_getch();
	cancel_trip(id);
}