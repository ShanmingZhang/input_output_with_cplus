//============================================================================
// Name        : input_c++.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void output_to_file(string of_name) {
	ofstream out_file(of_name);
	if (out_file.is_open()) {
		out_file << "This is a line.\n";
		out_file << "This is another line.\n";
		out_file.close();
	} else
		cout << "Can't open file";
}

// read a integer
int input_a_integer_from_file(string if_name) {
	ifstream in_file(if_name);
	if (!in_file) {
		cout << "Cannot Open input data file." << endl;
		exit(1);
	}

	int integer = 0;
	string line;

	//if (getline(in_file, line) && line.size() != 0) {
	if (getline(in_file, line) && line.size() != 0) {
		istringstream in_string(line);
		in_string >> integer;
	}
	return integer;
}

// example: abcde   file: abcde
string input_a_string_from_file(string if_name) {

	ifstream in_file(if_name);
	if (!in_file) {
		cout << "Cannot Open input data file." << endl;
		exit(1);
	}

	string str;
	string line;

	//if (getline(in_file, line) && line.size() != 0) {
	if (getline(in_file, line) && line.size() != 0) {
		istringstream in_string(line);
		in_string >> str;
	}
	return str;
}

//file example
//5
//a b c d e
//file: line1 is length
//      line2  array: a b c d e
int* input_one_dimensional_array_from_file(string if_name) {

	ifstream in_file(if_name);
	if (!in_file) {
		cout << "Cannot Open input data file." << endl;
		exit(1);
	}

	int length = 0;

	string line;

	//if (getline(in_file, line) && line.size() != 0) {
	if (getline(in_file, line) && line.size() != 0) {
		istringstream in_string(line);
		in_string >> length;
	}

	cout << length << endl;

	// type is the same as the type of file data
	string array[length];

	if (getline(in_file, line) && line.size() != 0) {
		istringstream in_string(line);
		cout << line << endl;
		for (int index = 0; index < length; index++) {
			in_string >> array[index];
			cout << array[index] << " ";
		}
	}
	cout << endl << endl;
	return NULL;
}

// file example
// 3 5   # 3 is x items  5 is y items
// a b c d e
// a b c d e
// a b c d e

void input_two_dimensional_array_from_file(string if_name) {

	ifstream in_file(if_name);
	if (!in_file) {
		cout << "Cannot Open input data file." << endl;
		exit(1);
	}

	int x_num = 0, y_num = 0;

	string line;

	//if (getline(in_file, line) && line.size() != 0) {
	if (getline(in_file, line) && line.size() != 0) {
		istringstream in_string(line);
		in_string >> x_num >> y_num;
	}

	string array[x_num][y_num];

	int x_index = 0;
	while (getline(in_file, line) && line.size() != 0) {
		istringstream in_string(line);
		for (int y_index = 0; y_index < y_num; y_index++) {
			in_string >> array[x_index][y_index];
			cout << array[x_index][y_index] << " ";
		}
		cout << endl;
		x_index++;
	}
}

vector<string> get_sub_string_list(string str) {
	vector<string> v;
	for (unsigned i = 0; i < str.length() - 2; i++) {
		v.push_back(str.substr(i, 3));
	}

	sort(v.begin(), v.end());
	return v;
}

int main() {

	string input_file_name = "input_a_integer.txt";

	cout << input_a_integer_from_file(input_file_name) << endl;

	input_file_name = "input_a_string.txt";
	cout << input_a_string_from_file(input_file_name) << endl;

	input_file_name = "input_a_array.txt";
	input_one_dimensional_array_from_file(input_file_name);

	input_file_name = "input_two_array.txt";
	input_two_dimensional_array_from_file(input_file_name);

	string output_file_name = "out_two_array.txt";
	output_to_file("output_a_string.txt");
	return 0;
}
