#ifndef MENU_H
#define MENU_H
constexpr auto PASSWORD =  "1234"; //constexpr�� ����, �Լ�, Ŭ������ ������ Ÿ�ӿ� ������ ����� �� �ֵ��� ���ش�.

#include "header.h"
#include "Customer.h"
#include "Driver.h"
#include "Matching.h"
class Menu : public Driver, Customer, Matching {
	public:
	void customerMenu();

	void add_new();

	void removing();

	void show();

	void modify();

	void driverMenu();

	void password();

	void new_trip();

	void trip_info();

	void cancel_trip(int & id);

	void end_trip();

};
#endif