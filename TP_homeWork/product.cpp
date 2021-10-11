#include "product.h"

void Product::GetInf() {
	cout << name << " || " << price << " ÐÓÁ || " << quantity << "ØÒ" << endl;
}

string Product::GetName() {
	return name;
}

float Product::GetPrice() {
	return price;
}

int Product::GetQuan() {
	return quantity;
}


void Product::SetName(string word) {
	name = word;
}

void Product::SetPrice(float money) {
	price = money;
}

void Product::SetQuan(int cnt) {
	if(isEmpyQuan(cnt))
	quantity = cnt;
}


void Product::DeQuan(int cnt) {
	quantity -= cnt;
}

bool Product::isEmpyQuan(int cnt) {
	if (cnt <= 0) {
		DeInf();
		return 0;
	}
	else
		return 1;
}

void Product::DeInf() {
	price = 0; quantity = 0;
}

