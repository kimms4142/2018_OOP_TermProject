#include "Customer.h"

	void Customer::get_details(int &id)
	{
		c_id_generator(id);
		cout << " ===발급된 승객 번호는 " << id << " 입니다.===" << endl;
		setCusId(id);

		cout << " 이름 :: ";
		cin >> cus_name;
		setCusName(*cus_name);

		cout << " 출발지를 입력해 주세요 :: ";
		cin >> currentLoc;
		setCurrentLoc(*currentLoc);

		cout << " 목적지를 입력해 주세요 :: ";
		cin >> destination;
		setCusDest(*destination);

		cout << "차종을 고르세요(소형,중형,대형) ::";
		cin >> car_type;
		setCusCarType(*car_type);
	}
	void Customer::pf_details()
	{
		cout << getCusName() << "님의 정보는 " << getCurrentLoc() << "에서" << getCusDest() << " 까지 " << getCusCarType() << "를 탑승합니다." << endl;
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

	void Customer::c_id_generator(int &idg)   // driver 계정을 driver.dat 파일(2진수형태)로 작성. ( id Number 생성자 )
	{
		fstream file2;
		file2.open("custom.dat", ios::in | ios::binary);
		while (file2.read((char*)&c, sizeof(c)))   //만들어진 객체 크기 만큼 파일을 읽음.
		{
			if (c.getCusId() == idg)   // idg값이 리턴받은 id값과 같을때 idg + 1.
			{
				idg++;
			}
		}
		file2.close();
	}
