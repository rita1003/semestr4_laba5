/*
��������� ���� �������� ������� ������������ ����� ����������� ��������, ������� �� ����� 
������� � ����� ��������� ���������.

�������� ����� ������� �� ��������, �������� �� �� �������� ����������� � ������� �����, 
�������������� ��������� ����������� ���������, ��������� �� ���������.
*/

#include <iostream>
#include <fstream>
#include <iomanip> // ��� setw() (������������ ������ � ��������� �����)
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>     // ��� std::getline
#include <conio.h>
#include <stdio.h>

using namespace std;

//������� 1. ������� ��� �������� ���������� ��������� ��������� ����� � ��������� �����

int WordCounter(const string& f, const string& word) {
	ifstream file(f); //����� ��� ������ (������� �������� �����)

	if (!file) { //��������: �������� �� ����?
		cout << "The file is not open" << endl;
		return -1;
	}

	int count = 0; 
	string word_for_searching;

	while (getline(file, word_for_searching, ' ')) {
		if (word_for_searching == word) {
			count++;
		}
	}
	file.close();
	return count;
}

//������� 2.1 �������� � ��������� ���� ��������� �������� Matrix

int Matrix(int a) {
	int matrix[5][5];
	ofstream out("Matrix.txt", ios::app); //ios::app - ����� ���������� � ����� �����)
	srand(a);
	if (out.is_open()) {
		for (int k = 0; k < 5; k++) { //����������� ������� - 5 �� 5 
			for (int j = 0; j<5; j++) {
				matrix[k][j] = 50 - rand() % 100;
				out << setw(5) << matrix[k][j];
			}
			out << endl;
		}
		out << endl;
	}
	out.close();
	return 0;
}

//������� 3.1 �������� � ��������� ���� ��������� �������� Matrix

int MatrixBin(int a) {
	int matrix[5][5];
	ofstream out("Matrix.bin", ios::app); //ios::app - ����� ���������� � ����� �����)
	srand(a);
	if (out.is_open()) {
		for (int k = 0; k < 5; k++) { //����������� ������� - 5 �� 5 
			for (int j = 0; j < 5; j++) {
				matrix[k][j] = 50 - rand() % 100;
				out << setw(5) << matrix[k][j];
			}
			out << endl;
		}
		out << endl;
	}
	out.close();
	return 0;
}

int PrintMatrix(int a[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << setw(5) << a[i][j] << "  ";
		cout << endl;
	}
	return 0;
}

//�������� �����

int main() {

	//�������� ������ 1

	cout << "Ex.1" << endl << endl;
	
	string f = "text_for_ex1.txt";
	string word;

	cout << "Enter any word: " << endl << endl;
	cin >> word;

	cout << endl<< "The word " << word << " is repeated " << WordCounter(f, word) << " times";

	//�������� ������ 2

	//2.1. ������ ������ � ��������� ���� "Matrix.txt"

	remove("Matrix.txt");

	Matrix(5); //������� 1 � ��������� �����. �������� � ������� - seed ��� ��������� ����������. �����
	Matrix(9); //������� 2 � ��������� �����

	//2.2. ������ ������ �� ���������� ����� 
	ifstream in("Matrix.txt");

	int mat1[5][5];
	int mat2[5][5];

	if (in.is_open()) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				in >> mat1[i][j];
			}
		}
	}

	if (in.is_open()) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				in >> mat2[i][j];
			}
		}
	}

	in.close();//��� ����� ������� �����

	cout << endl << endl << "Ex.2 " << endl << endl;

	cout << "The matrix from file: " << endl << endl;
	cout << "The matrix 1:" << endl << endl;

	PrintMatrix(mat1);

	cout << endl << "The matrix 2:" << endl << endl;

	PrintMatrix(mat2);

	//�������� � �������������� ��������� �����

	//2.3. �������� ������� Matrix � �������� ����

	remove("Matrix.bin");

	MatrixBin(5); //������� 1 � ��������� �����. �������� � ������� - seed ��� ��������� ����������. �����
	MatrixBin(9); //������� 2 � ��������� �����


	//�������� ������ 3

	int searching;

	cout << endl << "Ex. 3" << endl << endl;
	cout << "Hello! This is a book catalogue. Choose your action:" << endl << endl;
	cout << "1. Add new entry" << endl;
	cout << "2. View all entries" << endl;
	cout << "3. Delete entry" << endl;
	cout << "4. Find an entry" << endl;
	cout << "5. Edit entry" << endl << endl;

	cin >> searching;

	string author;
	string title;
	string pages;

	//���������� ���������� ����� � �����
	char* str = new char[1024];
	int flag = 0;
	ifstream books_read("Books.txt");

	while (!books_read.eof()) {
		books_read.getline(str, 1024, '\n');
		flag++;
	}
	books_read.close();

	delete str;


	if (searching == 1) {

		ofstream books("Books.txt", ios::app);

		cout << endl << "You have chosen option 1" << endl;
		cout << endl << "Enter AUTHOR: " << endl << endl;
		cin >> author;
		cout << endl << "Enter TITLE:" << endl << endl;
		cin >> title;
		cout << endl << "Enter PAGES:" << endl << endl;
		cin >> pages;

		if (books.is_open()) {
			books << endl << "000" << flag << setw(18) << author << setw(16) << title << setw(11) << pages;
		}

		books.close();
	}
	
	if (searching == 2) {
		cout << endl << "You have chosen option 2" << endl << endl;

		ifstream books("Books.txt");

		char S[256] = { "" };

		while (!books.eof()) {
			books.getline(S, 256);
			cout << S << endl;
		}

		books.close();
	}

	if (searching == 3) {
		int ID;
		cout << endl << "You have chosen option 3" << endl << endl;
		cout << "Enter ID deleting: " << endl << endl;
		cin >> ID;

		ID++;

		ifstream books("Books.txt");

		int count = 0; //������� �����
		string line; //��� �������� ������
		string line_file_text; //��� �������� ������ ����� 

		while (getline(books, line)) {
			count++;

			if (count < ID) {
				line_file_text.insert(line_file_text.size(), line);
				line_file_text.insert(line_file_text.size(), "\r\n");
			}

			if (count > ID) {
				line.replace(3, 1, to_string(count-2));
				line_file_text.insert(line_file_text.size(), line);
				line_file_text.insert(line_file_text.size(), "\r\n");
			}
		}

		books.close();

		//������ � line_file_text ����� ����������� ���������� ����� �����, ������ ����� ������������ ����

		ofstream books_out;

		books_out.open("Books.txt", ios::trunc | ios::binary); //������� � ��������

		//��������

		books_out.write(line_file_text.c_str(), line_file_text.size());

		books_out.close();

	}

	if (searching == 4) {
		int ID;
		cout << endl << "You have chosen option 4" << endl << endl;
		cout << "Enter ID searching: " << endl << endl;
		cin >> ID;
		cout << endl;

		ifstream books("Books.txt");

		int count = -1; //������� �����
		string line; //��� �������� ������
		string head; //��� �������� ��������

		int flug = 0;

		while (getline(books, line)) {
			count++;

			if (count == 0) {
				head = line;
			}

			if (count == ID) {
				cout << head << endl;
				cout << line;
				flug = 1;
			}
		}

		if (flug == 0) {
			cout << "NONE ID" << endl;
		}

		books.close();
	}

	if (searching == 5) {
		int setting;
		int ID;

		cout << endl << "You have chosen option 5" << endl << endl;
		cout << "Which ID of book do you want to edit?" << endl << endl;
		cin >> ID;
		cout << endl << "Which setting do you want to edit?" << endl << endl;
		cout << "1. Author" << endl;
		cout << "2. Title" << endl;
		cout << "3. Pages" << endl << endl;

		cin >> setting;

		cout << endl;

		ifstream books("Books.txt");

		string line;
		string line_file_text; //��� �������� ������ ����� 
		int count = -1; //������� �����

		while (getline(books, line)) {
			count++;

			if (count != ID) {
				line_file_text.insert(line_file_text.size(), line);
				line_file_text.insert(line_file_text.size(), "\r\n");
			}
			else {
				if (setting == 1) {
					string author;
					cout << "Enter new AUTHOR:" << endl << endl;
					cin >> author;
					cout << endl;
					line.erase(5, 17);
					line.insert(5, author);
					for (int i = 0; i < (17 - author.size()); i++) {
						line.insert(5, " ");
					}
					line_file_text.insert(line_file_text.size(), line);
					line_file_text.insert(line_file_text.size(), "\r\n");
				}

				if (setting == 2) {
					string title;
					cout << "Enter new TITLE: " << endl << endl;
					cin >> title;
					cout << endl;
					line.erase(24, 14);
					line.insert(24, title);
					for (int i = 0; i < (14 - title.size()); i++) {
						line.insert(24, " ");
					}
					line_file_text.insert(line_file_text.size(), line);
					line_file_text.insert(line_file_text.size(), "\r\n");
				}

				if (setting == 3) {
					string pages;
					cout << "Enter new PAGES:" << endl << endl;
					cin >> pages;
					cout << endl;
					line.erase(40, 9);
					line.insert(40, pages);
					for (int i = 0; i < (9 - pages.size()); i++) {
						line.insert(40, " ");
					}
					line_file_text.insert(line_file_text.size(), line);
					line_file_text.insert(line_file_text.size(), "\r\n");

				}

				if (setting != (1 || 2 || 3)) {
					cout << "ERROR" << endl;
				}
			}

		}

		books.close();

		//������ � line_file_text ����� ����������� ���������� ����� �����, ������ ����� ������������ ����

		ofstream books_out;

		books_out.open("Books.txt", ios::binary); //������� � ��������

		//��������

		books_out.write(line_file_text.c_str(), line_file_text.size());

		books_out.close();
	}

	return 0;
}