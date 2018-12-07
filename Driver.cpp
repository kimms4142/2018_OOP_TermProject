#include "Driver.h"

	void Driver::in_details(int &id)
	{
		d_id_generator(id);
		cout << " ==�߱޵� ������ ��ȣ�� " << id << " �Դϴ�" << endl;
		setId(id);
		cout << "�������� ������ �Է����ּ���" << endl;
		cout << " �̸� :: ";
		cin >> dname;
		setName(*dname);
		cout << " ���� :: ";
		cin >> dage;
		setAge(dage);
		cout << " ��ȭ��ȣ :: ";
		cin >> phone_no;
		setPhoneNum(*phone_no);
		cout << " ����(����,����,����) :: ";
		cin >> car_type;
		setCarType(*car_type);
		cout << " ���� ��ȣ :: ";
		cin >> car_no;
		setCarNum(*car_no);
		book = false;
	}
	
	void Driver::book_d()   // booking ���ִ� �޼ҵ�
	{
		book = true;
	}
	void Driver::unbook_d() // �ٽ� unbooking ���·� �ٲ��ִ� �޼ҵ�
	{
		book = false;
	}

	void Driver::show_details()
	{
		cout << " ������ ID :: " << getId() << endl;
		cout << " ������ �̸� :: " << getName() << endl;
		cout << " ������ ���� :: " << getAge() << endl;
		cout << " ������ �ڵ�����ȣ :: " << getPhoneNum() << endl;
		cout << " ����:: " << getCarType() << endl;
		cout << " �� ��ȣ :: " << getCarNum() << endl;
		if (book)
			cout << " ����� ";
		else if (!book)
			cout << " ������� ���� ";
	}

	void Driver::mod_details()
	{
		cout << " ������ �������� ID :: " << getId() << endl;
		cout << " ������ �̸� :: ";
		cin >> dname;
		setName(*dname);
		cout << " ������ ���� :: ";
		cin >> dage;
		setAge(dage);
		cout << " ������ �ڵ��� ��ȣ :: ";
		cin >> phone_no;
		setPhoneNum(*phone_no);
		cout << " ������ ���� :: ";
		cin >> car_type;
		setCarType(*car_type);
		cout << " ������ �� ��ȣ:: ";
		cin >> car_no;
		setCarNum(*car_no);
	}

	// Getter & Setter
	int Driver::getMatchedId() {
		return matchedId;
	}
	void Driver::setMatchedId(int id) {
		matchedId = id;
	}
	
	int Driver::getId()
	{
		return d_id;
	}
	void Driver::setId(int _d_id) {
		d_id = _d_id;
	}

	char* Driver::getName() {
		return dname;
	}
	void  Driver::setName(char _dname) {
		*dname = _dname;
	}

	int  Driver::getAge() {
		return dage;
	}
	void Driver::setAge(int _dage) {
		dage = _dage;
	}

	char* Driver::getPhoneNum() {
		return phone_no;
	}
	void  Driver::setPhoneNum(char _phone_no) {
		*phone_no = _phone_no;
	}
	
	char* Driver::getCarType()
	{
		return car_type;
	}
	void Driver::setCarType(char _car_type) {
		*car_type = _car_type;
	}

	char* Driver::getCarNum() {
		return car_no;
	}
	void  Driver::setCarNum(char _car_no) {
		*car_no = _car_no;
	}
	
	bool Driver::getBook()
	{
		return book;
	}
	void Driver::setBook(boolean _book) {
		book = _book;
	}

	void Driver::d_id_generator(int &idg)   // driver ������ driver.dat ����(2��������)�� �ۼ�. ( id Number ������ )
	{
		fstream file1;
		file1.open("driver.dat", ios::in | ios::binary);
		while (file1.read((char*)&d, sizeof(d)))   //������� ��ü ũ�� ��ŭ ������ ����.
		{
			if (d.getId() == idg)   // idg���� ���Ϲ��� id���� ������ idg + 1.
			{
				idg++;
			}
		}
	}