#include "purchase.h"

float Purchase::GetRes() {
	return result_price;
}

int Purchase::GetQuanPrice() {
	return quantity_price;
}
void Purchase::SetRes(float sum) {
	result_price = sum;
}

float Purchase::GetProdPrice() {
	return product_price;
}

void Purchase::SetQuanPrice(int cnt) {
	quantity_price = cnt;
}

void Purchase::SetProdPrice(float price) {
	product_price = price;
}
