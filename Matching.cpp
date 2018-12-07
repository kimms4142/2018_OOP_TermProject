#include "Matching.h"

void Matching::matching(int & id) {
	fstream file1, file2, fout;
	int matchedCusId1 = 0;
	int matchedCusId2 = 0;
	int matchedCusId3 = 0;

	file1.open("driver.dat", ios::in | ios::binary);
	file2.open("custom.dat", ios::in | ios::binary);
	fout.open("xdriver.dat", ios::out | ios::binary);

	while (file1.read((char*)&d, sizeof(d))) //driver
	{
		if (_strcmpi(d.getCarType(), "소형") == 0 && (!d.getBook())) { //소형이면 매칭해준다
			if (!smallSize.empty()) {
				matchedCusId1 = smallSize.front();
				smallSize.pop();
				d.book_d();
				d.setMatchedId(matchedCusId1);
			}
		}
		else if (_strcmpi(d.getCarType(), "중형") == 0 && (!d.getBook())) {
			if (!middleSize.empty()) {
				matchedCusId1 = middleSize.front();
				middleSize.pop();
				d.book_d();
				d.setMatchedId(matchedCusId1);
			}
		}
		else if (_strcmpi(d.getCarType(), "대형") == 0 && (!d.getBook())) {
			if (!bigSize.empty()) {
				matchedCusId1 = bigSize.front();
				bigSize.pop();
				d.book_d();
				d.setMatchedId(matchedCusId1);
			}
		}
		fout.write((char*)&d, sizeof(d));
	}
	file1.close();
	file2.close();
	fout.close();
	remove("driver.dat");
	rename("xdriver.dat", "driver.dat");
}
void Matching::linked_driver(int & id)
{
	fstream file1, file2;
	file1.open("driver.dat", ios::in | ios::binary);
	file2.open("custom.dat", ios::in | ios::binary);

	while (file2.read((char*)&c, sizeof(c)))
	{
		if (c.getCusId() == id)
		{
			while (file1.read((char*)&d, sizeof(d)))
			{
				if ((c.getCusId() == d.getMatchedId()) && d.getBook())   // 매칭이 된 상태라면
				{
					int x = file1.tellg() / sizeof(d);
					file1.seekp((x - 1) * sizeof(d), ios::beg);
					d.show_details();
					return;
				}
			}
		}
	}
	file1.close();
	file2.close();
}
void Matching::unmatching(int & id) {
	fstream file1, file2, fout;
	file1.open("driver.dat", ios::in | ios::binary);
	file2.open("custom.dat", ios::in | ios::binary);
	fout.open("xdriver.dat", ios::out | ios::binary);

	while (file2.read((char*)&c, sizeof(c)))
	{
		if (c.getCusId() == id)
		{
			while (file1.read((char*)&d, sizeof(d)))
			{
				if ((c.getCusId() == d.getMatchedId()) && d.getBook())
				{
					d.setMatchedId(0);
					d.unbook_d();
					int x = file2.tellg() / sizeof(d);
					file2.seekp((x - 1) * sizeof(d), ios::beg);
					d.show_details();
				}                            
				fout.write((char*)&d, sizeof(d));
			}
		}
	}
	file1.close();
	file2.close();
	fout.close();
	remove("driver.dat");
	rename("xdriver.dat", "driver.dat");
}

