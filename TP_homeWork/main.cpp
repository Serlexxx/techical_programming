#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h> //��� ������� �������
#include "check.h"
#include "product.h"
#include "purchase.h"
#include "man.h"
using namespace std;
static const string NAME = "C:\\Users\\�����������\\source\\repos\\TP_homeWork\\TP_homeWork\\source.txt"; //�������� ���� � �����


int main() {
	setlocale(LC_ALL, "rus");
	char mainSelection, selection, selection_man; //���������
	int verylittleSelect;
	bool mainExit = 1;
	
	while (mainExit) {
		cout << "������. ";
		cout << "���� ����������: " << endl <<
			"1.���� � ������ �������." << endl <<
			"0.������� ����������." << endl;
		cin >> mainSelection;
		switch (mainSelection)
		{
		case '1': {
			system("cls");
			cout << "�� ���: " << endl <<
				"1.����������." << endl <<
				"2.���������." << endl;
			cin >> selection;
				switch (selection)
				{
				case '1': {
					vector<Product> product;
					product.push_back(Product());
					Check check;
					int cnt = 0; //���������� ����������� �������
					
					ifstream file(NAME); //������� ���� �� ����
					//�������� ����� � �������� ��� �� �������
					if (!file.is_open())
					{
						cout << "���! ��������� ����� �������� ���� ������!" << endl;
						cout << "���������� ��� ������� ���� � ��������� ��� �������. �������!" << endl;
						return -1;
					}
					else {
						if (file.peek() == EOF) { cout << "��������, �� �� ������ ������ ��� ������� �� ����� ��� ������ ����������!" << endl; return -1; }
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
						
						cout << "�� ������ ������ �� ����� ���������� ���: " << endl;
						for (int i = 0; i < cnt; i++) {
							cout << i << ". "; product[i].GetInf();
						}
						cout << "��� �� ������� ����������?" << endl << "��� �������� � ������ ������� -1" << endl;
						cin >> verylittleSelect; //����� ������
						if (verylittleSelect >= 0 && verylittleSelect < cnt) {
							cout << "�� ������� - " << product[verylittleSelect].GetName() << endl;
							if (product[verylittleSelect].isEmpyQuan(product[verylittleSelect].GetQuan())) {
								cout << "������� ������� ����������?" << endl;
								cout << "������� ���������� � ��������� 0..." << product[verylittleSelect].GetQuan() << endl;
								int quan = 0;
								cin >> quan;
								bool miniExit = 1;
								while (miniExit) {
									if (quan <= 0) {
										cout << "�� ����� ����������� �����. ����. ���������� �����." << endl;
										cout << "������� ���������� � ��������� 0..." << product[verylittleSelect].GetQuan() << endl;
									}
									else {
										if (quan > product[verylittleSelect].GetQuan()) {
											bool veryMiniExit = 1;
											while (veryMiniExit) {
												cout << "�� ������ ������ ������� ���������� ����� ������ ��� � ��� ����." << endl;
												cout << "������� ���������� � ��������� 0..." << product[verylittleSelect].GetQuan() << endl;
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
											cout << "��������, ���-�� ���?" << endl;
											miniExit = 0;
										}
									}
								}
							}
							else {
								cout << "���. ������� ������ � ��� ���. �������� ���� ���������." << endl;
								cout << "�� ������ ������� ������ �����." << endl;
							}
						}
						else { //����� � ��������� ������������� �����
							if (verylittleSelect == -1)
							{
								
								system("cls");
								cout << "_______���______" << endl;
								float res = 0;
								if (counter != 0) {
									for (int i = 0; i < counter; i++) {
										cout << product[numbers[i]].GetName() << " || ";
										chekes[i].GetInfProd();
										res += chekes[i].GetRes();

									}
									cout << "�����:            " << res <<" ��� "<< endl;
									cout << "��������: �������� �. �." << endl << "��������� � ��� �����!" << endl;
									file.close();
									ofstream file(NAME); //������� ���� �� ����
									//�������� ����� � �������� ��� �� �������
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
								cout << "�� ������ ������ �������������� �����. ���������� �����" << endl;
								//system("cls");
							}
						}
					}
					break;
				}
				case '2': {
					system("cls");
					Man man;
					cout << "�����. ������� ������." << endl;
					string pasword;
					cin >> pasword;
					bool Exit = 1;
					while (Exit) {
						if (pasword != man.GetPasword()) {
							bool miniExit = 1;
							while (miniExit) {
								cout << "�� ����� ���������?" << endl << "���������� �����." << endl;
								cin >> pasword;
								if (pasword == man.GetPasword()) miniExit = 0;
							}
						}
						else {
							system("cls");
							cout << "�����" << endl;
							vector<Product> product;
							//product.push_back(Product());
							
							int cnt = 0; //���������� ����������� �������

							ifstream file_in(NAME); //������� ���� �� ����
							//�������� ����� � �������� ��� �� �������
							if (!file_in.is_open())
							{
								cout << "���! ��������� ����� �������� ���� ������!" << endl;
								cout << "���������� ��� ������� ���� � ��������� ��� �������. �������!" << endl;
								return -1;
							}
							else {
								if (file_in.peek() == EOF) { cout << "���� ����. ���� ��������� �������." << endl; return -1; }
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
							cout << "�� ������ ������ �� ������: " << endl;
							for (int i = 0; i < cnt; i++) {
								cout << i << ". "; product[i].GetInf();
							}
							file_in.close();
							cout << "���� ����������: " << endl <<
								"1.��������." << endl <<
								"2.�������." << endl <<
								"0.������� ����������." << endl;
							cin >> selection_man;
							switch (selection_man)
							{
							case '1': {
								
								string word = ""; float money = 0; int quan = 0;
								cout << "������� �������� �������: " << endl;
								cin >> word;
								cout << "������� ���� �������: " << endl;
								cin >> money;
								cout << "������� ��������� �������: " << endl;
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
												cout << "�� ��������� ������. ������� ���� �� ���� ������ �������� ������" << endl;
											}
										}
									}
									else {
										
										if (money <= 0) {
											bool little_exit = 1;
											cout << "�� ��������� ������. ������� ���� ������ ������ 0!" << endl;
											while (little_exit) {
												cin >> money;
												if (money > 0) {
													little_exit = 0;
												}
												else {
													cout << "�� ��������� ������. ������� ���� ������ ������ 0!" << endl;
												}
											}
										}
										else {
											
											if (quan <= 0) {
												bool little_exit = 1;
												cout << "�� ��������� ������. ������� ����� ������ ������ 0!" << endl;
												while (little_exit) {
													cin >> quan;
													if (quan > 0) {
														little_exit = 0;
													}
													else {
														cout << "�� ��������� ������. ������� ����� ������ ������ 0!" << endl;
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
								ofstream file_out(NAME); //������� ���� �� ����
											//�������� ����� � �������� ��� �� �������
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
								cout << "����� ����� �������?" << endl;
								int enter = 0;
								cin >> enter;
								bool de_exit = 1;
								string word = ""; float money = 0; int quan = 0;
								while (de_exit) {
									if (enter < 0 && enter >= cnt) {
										bool little_exit = 1;
										while (little_exit) {
											cout << "������� ����� � ������� 0..." << cnt-1 << endl;
											cin >> enter;
											if (enter >= 0 && enter < cnt) little_exit = 0;
										}
									}
									else {
										product.erase(product.begin() + enter);
										cnt--;
										ofstream file_out(NAME); //������� ���� �� ����
											//�������� ����� � �������� ��� �� �������
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
								cout << "�� ����� ����������� �����. ����. ���������� �����." << endl;
								break;
							}
						}
					}
					break;
				}
				default:
					cout << "�� ����� ����������� �����. ����. ���������� �����." << endl;
					break;
				}
			break;
		}
		case '0':
			mainExit = 0; //����� �� ����������
			break;
		default:
			cout << "�� ����� ����������� �����. ����. ���������� �����." << endl;
			break;
		}


	}
	return 0;
}


