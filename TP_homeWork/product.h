#pragma once
#include <iostream>
using namespace std;
class Product {
public:
	void GetInf(); //�������� ������� ��� ���� � ������
	string GetName();
	float GetPrice();
	int GetQuan();

	void SetName(string word);
	void SetPrice(float money);
	void SetQuan(int cnt);
	
	
	void DeQuan(int cnt);	//�������������, �������� �� ������ ���������� ����� ������
	bool isEmpyQuan(int cnt); //�������� �� ������� �� ������
	void DeInf();	//�������������, ������� ��� ��� ���� ������ ���

private:
	string name; //�������� ��������
	float price = 0; //���� ������
	int quantity = 0; //���������� �� ������, ����������� ����� ���� � �����
};