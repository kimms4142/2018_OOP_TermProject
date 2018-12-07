#ifndef MENU_H
#define MENU_H
constexpr auto PASSWORD =  "1234"; //constexpr는 변수, 함수, 클래스를 컴파일 타임에 정수로 사용할 수 있도록 해준다.

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