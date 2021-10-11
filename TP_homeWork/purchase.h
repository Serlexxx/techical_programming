#pragma once
#include <iostream>
using namespace std;
class Purchase {
public:
	void SetQuanPrice(int cnt); //количество покупаемого товара
	int GetQuanPrice();//количество покупаемого товара

	float GetRes(); //результ за один пункт
	void SetRes(float sum); //результ за один пункт

	void SetProdPrice(float price); //цена за один товар
	float GetProdPrice(); //цена за один товар

private:

	int quantity_price = 0; //колвo покупаемого товара
	float product_price = 0; //цена за один товар
	float result_price = 0; //сумма покупки за один товар
};