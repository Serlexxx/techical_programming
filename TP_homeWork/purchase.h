#pragma once
#include <iostream>
using namespace std;
class Purchase {
public:
	void SetQuanPrice(int cnt); //���������� ����������� ������
	int GetQuanPrice();//���������� ����������� ������

	float GetRes(); //������� �� ���� �����
	void SetRes(float sum); //������� �� ���� �����

	void SetProdPrice(float price); //���� �� ���� �����
	float GetProdPrice(); //���� �� ���� �����

private:

	int quantity_price = 0; //����o ����������� ������
	float product_price = 0; //���� �� ���� �����
	float result_price = 0; //����� ������� �� ���� �����
};