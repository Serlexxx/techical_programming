#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h> //для очистки консоли
#include "check.h"
#include "product.h"
#include "purchase.h"
#include "man.h"
using namespace std;
static const string NAME = "C:\\Users\\Программист\\source\\repos\\TP_homeWork\\TP_homeWork\\source.txt"; //указание пути к файлу


int main() {
	setlocale(LC_ALL, "rus");
	char mainSelection, selection, selection_man; //селекторы
	int verylittleSelect;
	bool mainExit = 1;
	
	while (mainExit) {
		cout << "Привет. ";
		cout << "Меню управления: " << endl <<
			"1.Вход в офлайн магазин." << endl <<
			"0.Закрыть приложение." << endl;
		cin >> mainSelection;
		switch (mainSelection)
		{
		case '1': {
			system("cls");
			cout << "Вы кто: " << endl <<
				"1.Покупатель." << endl <<
				"2.Товаровед." << endl;
			cin >> selection;
				switch (selection)
				{
				case '1': {
					vector<Product> product;
					product.push_back(Product());
					Check check;
					int cnt = 0; //количество загруженных товаров
					
					ifstream file(NAME); //указать путь на файл
					//Открытие файла и проверка его на пустоту
					if (!file.is_open())
					{
						cout << "Упс! Товаровед забыл провести учет товара!" << endl;
						cout << "Напомниите ему создать файл и заполнить его товаром. Спасибо!" << endl;
						return -1;
					}
					else {
						if (file.peek() == EOF) { cout << "Извините, но на данный момент наш магазин не может вам ничего предложить!" << endl; return -1; }
						else {
							while (!file.eof()) {
								string word = ""; float money = 0; int quan = 0;
								product.push_back(Product());
								file >> word >> money >> quan;
								if (word != "") {
									product[cnt].SetName(word);
									product[cnt].SetPrice(money);
									product[cnt].SetQuan(quan);
									cnt++;
								}
							}

						}
					}
					
					int counter = 0;
					bool Exit = 1;
					Check* chekes = NULL;
					int* numbers = NULL;
					while (Exit) {
						
						cout << "На данный момент мы можем предложить Вам: " << endl;
						for (int i = 0; i < cnt; i++) {
							cout << i << ". "; product[i].GetInf();
						}
						cout << "Что вы желаете приобрести?" << endl << "Для перехода к оплате введите -1" << endl;
						cin >> verylittleSelect; //выбор товара
						if (verylittleSelect >= 0 && verylittleSelect < cnt) {
							cout << "Вы выбрали - " << product[verylittleSelect].GetName() << endl;
							if (product[verylittleSelect].isEmpyQuan(product[verylittleSelect].GetQuan())) {
								cout << "Сколько желаете приобрести?" << endl;
								cout << "Введите количество в диапазоне 0..." << product[verylittleSelect].GetQuan() << endl;
								int quan = 0;
								cin >> quan;
								bool miniExit = 1;
								while (miniExit) {
									if (quan <= 0) {
										cout << "Вы ввели неправильно число. Аяяй. Попробуйте снова." << endl;
										cout << "Введите количество в диапазоне 0..." << product[verylittleSelect].GetQuan() << endl;
									}
									else {
										if (quan > product[verylittleSelect].GetQuan()) {
											bool veryMiniExit = 1;
											while (veryMiniExit) {
												cout << "Вы хотите купить большее количество этого товара чем у нас есть." << endl;
												cout << "Введите количество в диапазоне 0..." << product[verylittleSelect].GetQuan() << endl;
												cin >> quan;
												if (quan <= product[verylittleSelect].GetQuan()) veryMiniExit = 0;
											}
										}
										else {
											counter++;
											int* number = (int*)realloc(numbers, counter * sizeof(int));
											if (!number) {
												printf("FAIL wtit number massive.");
												return -2;
											}
											else {
												numbers = number;
												numbers[counter-1] = verylittleSelect;
											}

											Check* check = (Check*)realloc(chekes, counter * sizeof(Check));
											if (!check) {
												printf("FAIL wtit check massive.");
												return -3;
											}
											else {
												chekes = check;
												chekes[counter-1].SetProdPrice(product[verylittleSelect].GetPrice());
												chekes[counter-1].SetQuanPrice(quan);
												chekes[counter-1].SetRes(chekes[counter-1].GetProdPrice() * chekes[counter-1].GetQuanPrice());
											}
											
											product[verylittleSelect].DeQuan(quan);
											
											system("cls");
											cout << "Добавили, что-то еще?" << endl;
											miniExit = 0;
										}
									}
								}
							}
							else {
								cout << "Упс. Данного товара у нас нет. Приносим свои извинения." << endl;
								cout << "Вы можете выбрать другой товар." << endl;
							}
						}
						else { //выход и обработка неправильного ввода
							if (verylittleSelect == -1)
							{
								
								system("cls");
								cout << "_______Чек______" << endl;
								float res = 0;
								if (counter != 0) {
									for (int i = 0; i < counter; i++) {
										cout << product[numbers[i]].GetName() << " || ";
										chekes[i].GetInfProd();
										res += chekes[i].GetRes();

									}
									cout << "Итого:            " << res <<" РУБ "<< endl;
									cout << "Продавец: Кокшаров С. С." << endl << "Приходите к нам снова!" << endl;
									file.close();
									ofstream file(NAME); //указать путь на файл
									//Открытие файла и проверка его на пустоту
									if (file.is_open())
									{
										for (int i = 0; i < cnt; i++) {
											file << product[i].GetName() << " " << product[i].GetPrice() << " " << product[i].GetQuan() << endl;;
										}
									}
									file.close();
									
								}
									free(chekes); free(numbers); Exit = 0;
							
							}
							else {
								cout << "Вы хотите купить несуществующий товар. Попробуйте снова" << endl;
								//system("cls");
							}
						}
					}
					break;
				}
				case '2': {
					system("cls");
					Man man;
					cout << "Дороу. Введите пароль." << endl;
					string pasword;
					cin >> pasword;
					bool Exit = 1;
					while (Exit) {
						if (pasword != man.GetPasword()) {
							bool miniExit = 1;
							while (miniExit) {
								cout << "Вы точно товаровед?" << endl << "Попробуйте снова." << endl;
								cin >> pasword;
								if (pasword == man.GetPasword()) miniExit = 0;
							}
						}
						else {
							system("cls");
							cout << "Товар" << endl;
							vector<Product> product;
							//product.push_back(Product());
							
							int cnt = 0; //количество загруженных товаров

							ifstream file_in(NAME); //указать путь на файл
							//Открытие файла и проверка его на пустоту
							if (!file_in.is_open())
							{
								cout << "Упс! Товаровед забыл провести учет товара!" << endl;
								cout << "Напомниите ему создать файл и заполнить его товаром. Спасибо!" << endl;
								return -1;
							}
							else {
								if (file_in.peek() == EOF) { cout << "Файл пуст. Надо загрузить вручную." << endl; return -1; }
								else {
									while (!file_in.eof()) {
										string word = ""; float money = 0; int quan = 0;
										product.push_back(Product());
										file_in >> word >> money >> quan;
										if (word != "") {
											product[cnt].SetName(word);
											product[cnt].SetPrice(money);
											product[cnt].SetQuan(quan);
											cnt++;
										}
									}

								}
							}
							cout << "На данный момент на складе: " << endl;
							for (int i = 0; i < cnt; i++) {
								cout << i << ". "; product[i].GetInf();
							}
							file_in.close();
							cout << "Меню управления: " << endl <<
								"1.Добавить." << endl <<
								"2.Удалить." << endl <<
								"0.Закрыть приложение." << endl;
							cin >> selection_man;
							switch (selection_man)
							{
							case '1': {
								
								string word = ""; float money = 0; int quan = 0;
								cout << "Введите название товвара: " << endl;
								cin >> word;
								cout << "Введите цену товвара: " << endl;
								cin >> money;
								cout << "Введите колиество товвара: " << endl;
								cin >> quan;
								bool Exit = 1;
								while (Exit) {
									if (word == "") {
										bool little_exit = 1;
										while (little_exit) {
											cin >> word;
											if (word != "") {
												little_exit = 0;
											}
											else {
												cout << "Вы допустили ошибку. Введите Хотя бы один символ названия товара" << endl;
											}
										}
									}
									else {
										
										if (money <= 0) {
											bool little_exit = 1;
											cout << "Вы допустили ошибку. Введите цену товара больше 0!" << endl;
											while (little_exit) {
												cin >> money;
												if (money > 0) {
													little_exit = 0;
												}
												else {
													cout << "Вы допустили ошибку. Введите цену товара больше 0!" << endl;
												}
											}
										}
										else {
											
											if (quan <= 0) {
												bool little_exit = 1;
												cout << "Вы допустили ошибку. Введите колво товара больше 0!" << endl;
												while (little_exit) {
													cin >> quan;
													if (quan > 0) {
														little_exit = 0;
													}
													else {
														cout << "Вы допустили ошибку. Введите колво товара больше 0!" << endl;
													}
												}
											}
											else {
												product.push_back(Product());
												
												product[cnt].SetName(word);
												product[cnt].SetPrice(money);
												product[cnt].SetQuan(quan);
												cnt++;
												Exit = 0;
											}
											
										}

									}
									
								}
								system("cls");
								ofstream file_out(NAME); //указать путь на файл
											//Открытие файла и проверка его на пустоту
								if (file_out.is_open())
								{
									for (int i = 0; i < cnt; i++) {
										file_out << product[i].GetName() << " " << product[i].GetPrice() << " " << product[i].GetQuan() << endl;;
									}
									cnt = 0;
								}
								file_out.close();
								break;
							}
							case '2': {
								cout << "Какой товар удаляем?" << endl;
								int enter = 0;
								cin >> enter;
								bool de_exit = 1;
								string word = ""; float money = 0; int quan = 0;
								while (de_exit) {
									if (enter < 0 && enter >= cnt) {
										bool little_exit = 1;
										while (little_exit) {
											cout << "Введите число в периоде 0..." << cnt-1 << endl;
											cin >> enter;
											if (enter >= 0 && enter < cnt) little_exit = 0;
										}
									}
									else {
										product.erase(product.begin() + enter);
										cnt--;
										ofstream file_out(NAME); //указать путь на файл
											//Открытие файла и проверка его на пустоту
										if (file_out.is_open())
										{
											for (int i = 0; i < cnt; i++) {
												file_out << product[i].GetName() << " " << product[i].GetPrice() << " " << product[i].GetQuan() << endl;;
											}
											cnt = 0;
										}
										de_exit = 0;
										file_out.close();
									}
								}
								break;
							}
							case'0': {
								Exit = 0;
								system("cls");
								break;
							}
							default:
								cout << "Вы ввели неправильно число. Аяяй. Попробуйте снова." << endl;
								break;
							}
						}
					}
					break;
				}
				default:
					cout << "Вы ввели неправильно число. Аяяй. Попробуйте снова." << endl;
					break;
				}
			break;
		}
		case '0':
			mainExit = 0; //выход из приложения
			break;
		default:
			cout << "Вы ввели неправильно число. Аяяй. Попробуйте снова." << endl;
			break;
		}


	}
	return 0;
}


