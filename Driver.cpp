#include "Driver.h"

	void Driver::in_details(int &id)
	{
		d_id_generator(id);
		cout << " ==발급된 운전자 번호는 " << id << " 입니다" << endl;
		setId(id);
		cout << "운전자의 정보를 입력해주세요" << endl;
		cout << " 이름 :: ";
		cin >> dname;
		setName(*dname);
		cout << " 나이 :: ";
		cin >> dage;
		setAge(dage);
		cout << " 전화번호 :: ";
		cin >> phone_no;
		setPhoneNum(*phone_no);
		cout << " 차종(소형,중형,대형) :: ";
		cin >> car_type;
		setCarType(*car_type);
		cout << " 차량 번호 :: ";
		cin >> car_no;
		setCarNum(*car_no);
		book = false;
	}
	
	void Driver::book_d()   // booking 해주는 메소드
	{
		book = true;
	}
	void Driver::unbook_d() // 다시 unbooking 상태로 바꿔주는 메소드
	{
		book = false;
	}

	void Driver::show_details()
	{
		cout << " 운전자 ID :: " << getId() << endl;
		cout << " 운전자 이름 :: " << getName() << endl;
		cout << " 운전자 나이 :: " << getAge() << endl;
		cout << " 운전자 핸드폰번호 :: " << getPhoneNum() << endl;
		cout << " 차종:: " << getCarType() << endl;
		cout << " 차 번호 :: " << getCarNum() << endl;
		if (book)
			cout << " 예약됨 ";
		else if (!book)
			cout << " 예약되지 않음 ";
	}

	void Driver::mod_details()
	{
		cout << " 변결할 운전자의 ID :: " << getId() << endl;
		cout << " 변경할 이름 :: ";
		cin >> dname;
		setName(*dname);
		cout << " 변경할 나이 :: ";
		cin >> dage;
		setAge(dage);
		cout << " 변경할 핸드폰 번호 :: ";
		cin >> phone_no;
		setPhoneNum(*phone_no);
		cout << " 변경할 차종 :: ";
		cin >> car_type;
		setCarType(*car_type);
		cout << " 변경할 차 번호:: ";
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

	void Driver::d_id_generator(int &idg)   // driver 계정을 driver.dat 파일(2진수형태)로 작성. ( id Number 생성자 )
	{
		fstream file1;
		file1.open("driver.dat", ios::in | ios::binary);
		while (file1.read((char*)&d, sizeof(d)))   //만들어진 객체 크기 만큼 파일을 읽음.
		{
			if (d.getId() == idg)   // idg값이 리턴받은 id값과 같을때 idg + 1.
			{
				idg++;
			}
		}
	}