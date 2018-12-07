#ifndef DRIVER_H
#define DRIVER_H

#include"header.h"

class Driver
{
private:
	char dname[100];   //driver name
	char car_no[50], phone_no[100], car_type[50];
	int dage, d_id, matchedId = 0;
	bool book;
public:
	void in_details(int &id);
	void book_d();
	void unbook_d();

	void show_details();
	void mod_details();
	
	// Getter & Setter
	int  getMatchedId();
	void setMatchedId(int id);

	int getId();
	void setId(int _d_id);

	char* getName();
	void  setName(char _dname);

	int  getAge();
	void setAge(int _dage);

	char* getPhoneNum();
	void  setPhoneNum(char _phone_no);
	
	char* getCarType();
	void  setCarType(char _car_type);

	char* getCarNum();
	void  setCarNum(char _car_no);

	bool getBook();
	void setBook(boolean _book);

	void d_id_generator(int &idg);
}d;
#endif