#include "Customer.h"

	void Customer::get_details(int &id)
	{
		c_id_generator(id);
		cout << " ===�߱޵� �°� ��ȣ�� " << id << " �Դϴ�.===" << endl;
		setCusId(id);

		cout << " �̸� :: ";
		cin >> cus_name;
		setCusName(*cus_name);

		cout << " ������� �Է��� �ּ��� :: ";
		cin >> currentLoc;
		setCurrentLoc(*currentLoc);

		cout << " �������� �Է��� �ּ��� :: ";
		cin >> destination;
		setCusDest(*destination);

		cout << "������ ������(����,����,����) ::";
		cin >> car_type;
		setCusCarType(*car_type);
	}
	void Customer::pf_details()
	{
		cout << getCusName() << "���� ������ " << getCurrentLoc() << "����" << getCusDest() << " ���� " << getCusCarType() << "�� ž���մϴ�." << endl;
	}

	int Customer::getCusId()
	{
		return cus_id;
	}
	void Customer::setCusId(int _cus_id) {
		cus_id = _cus_id;
	}

	char* Customer::getCusName() {
		return cus_name;
	}
	void Customer::setCusName(char _cus_name) {
		*cus_name = _cus_name;
	}

	char* Customer::getCurrentLoc()
	{
		return currentLoc;
	}
	void Customer::setCurrentLoc(char _currentLoc) {
		*currentLoc = _currentLoc;
	}


	char* Customer::getCusDest()
	{
		return destination;
	}
	void Customer::setCusDest(char _destination)
	{
		*destination = _destination;
	}

	
	char* Customer::getCusCarType()
	{
		return car_type;
	}
	void Customer::setCusCarType(char _car_type) {
		*car_type = _car_type;
	}

	void Customer::c_id_generator(int &idg)   // driver ������ driver.dat ����(2��������)�� �ۼ�. ( id Number ������ )
	{
		fstream file2;
		file2.open("custom.dat", ios::in | ios::binary);
		while (file2.read((char*)&c, sizeof(c)))   //������� ��ü ũ�� ��ŭ ������ ����.
		{
			if (c.getCusId() == idg)   // idg���� ���Ϲ��� id���� ������ idg + 1.
			{
				idg++;
			}
		}
		file2.close();
	}
