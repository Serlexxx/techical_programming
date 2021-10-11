#pragma once
#include <iostream>
using namespace std;
class Product {
public:
	void GetInf(); //поностью выводит всю инфу о товаре
	string GetName();
	float GetPrice();
	int GetQuan();

	void SetName(string word);
	void SetPrice(float money);
	void SetQuan(int cnt);
	
	
	void DeQuan(int cnt);	//уникаольность, удаление со склада купленного колво товара
	bool isEmpyQuan(int cnt); //проверка на пустоту на складе
	void DeInf();	//уникаольность, выводит кое что если товара нет

private:
	string name; //название продукта
	float price = 0; //цена товара
	int quantity = 0; //количество на складе, указывается после цены в файле
};