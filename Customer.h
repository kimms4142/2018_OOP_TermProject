#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "header.h"

class Customer
{
private:
	char cus_name[100], currentLoc[100], destination[100], car_type[10];
	int cus_id = 0;
public:
	void get_details(int &id);
	void pf_details(); 
	
	// Getter & Setter
	int getCusId();
	void setCusId(int _cus_id);
	
	char* getCusName();
	void  setCusName(char _cus_name);

	char* getCusDest();
	void setCusDest(char _destination);

	char* getCurrentLoc();
	void setCurrentLoc(char _currentLoc);

	char* getCusCarType();
	void setCusCarType(char _car_type);

	void c_id_generator(int &idg);
}c;
#endif
