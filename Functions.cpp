#include "Functions.h"

void ReadingData(Data* (&d), int& n, string filename)
{
	ifstream file_name(filename);
	string line_from_file;
	
	if (file_name) {
		file_name >> n;
		d = new Data[n];
		while (getline(file_name, line_from_file))
		{
				for (int i = 0; i < n; i++) {
					file_name >> line_from_file;
					line_from_file.erase(remove(line_from_file.begin(), line_from_file.end(), ','), line_from_file.end()); //������� ������� �� ������ � �����
					int res = stoi(line_from_file); //�� string � int
					d[i].speed.one = res;
					
					file_name >> line_from_file;
					line_from_file.erase(remove(line_from_file.begin(), line_from_file.end(), ','), line_from_file.end());//������� ������� �� ������ � �����
					res = stoi(line_from_file); //�� string � int
					d[i].date.day = res;
					
					file_name >> line_from_file;
					line_from_file.erase(remove(line_from_file.begin(), line_from_file.end(), ','), line_from_file.end());//������� ������� �� ������ � �����
					res = stoi(line_from_file); //�� string � int
					d[i].location.lokal = res;
				}
			
		}
		
		
		cout << "������ �������! ";
	}
	else
		cout << "������ " << endl;
}

void SpeedSorting(Data* d, int n)
{
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (d[i].speed.one < d[i + 1].speed.one) {
				int x0 = d[i].speed.one;
				int x1 = d[i].date.day; // ������� �������������� ����������
				int x2 = d[i].location.lokal;

				d[i].speed.one = d[i + 1].speed.one; // ������ �������
				d[i].date.day = d[i + 1].date.day;
				d[i].location.lokal = d[i + 1].location.lokal;
				
				d[i + 1].speed.one = x0;
				d[i + 1].date.day = x1;
				d[i + 1].location.lokal = x2; // �������� ���������
			}
		}
	}
	cout << "�������� ������ � ������� " << endl;
}

void Excel(Data* d, int n)
{
	ofstream fout("db_excel.xls");
	for (int i = 0; i < n; i++)
	{
		fout << d[i].speed.one<<"\t";
		fout << d[i].date.day<<"\t";
		fout << d[i].location.lokal<<"\t";
		fout << endl;
	}
	

}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "������ �" << i + 1 << ":" << endl;

		cout << "Speed: " << d[i].speed.one << endl;
		cout << "Data: " << d[i].date.day << endl;
		cout << "Location " << d[i].location.lokal << endl;
		cout << "____________________________" << endl;
	}
}