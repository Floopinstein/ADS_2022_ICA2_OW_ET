// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Utilities.h"
#include "Car.h"
#include "Date.h"
#include "Gamer.h"
#include "GamerKey.h"
#include "BinaryTree.h"

using namespace std;

//Gamer::Gamer() {
//	(*this).user_id = "ID123";
//	this->first_name = "2";
//	this->email = "John";
//}
//
//Gamer::Gamer(string user_id, string first_name, string email) {
//
//	this->user_id = user_id;
//	this->first_name = first_name;
//	this->email = email;
//
//}
//
//
//string Gamer::getuser_id() {
//	return user_id;
//}
//
//string Gamer::getfirst_name() {
//	return first_name;
//}
//
//string Gamer::getemail() {
//	return email;
//}
//
//
//string Gamer::Change_to_string() {
//	return this->user_id + " - " + this->first_name + " - " + this->email;


void demoSimpleHash();
//void demoDateHash();
//void demoParseString();
void demoCSVToObject();

int main()
{
	cout << endl << "demoSimpleHash()..........." << endl;
	demoSimpleHash();

	//cout << endl << "demoDateHash()..........." << endl;
	//demoDateHash();

	//cout << endl << "demoParseString()..........." << endl;
	//demoParseString();*/

	cout << endl << "demoCSVToObject()..........." << endl;
	demoCSVToObject();

	return 0;
}
//std::size_t myHash() const
//{
//	size_t hash = std::hash<string>()(this->user_id_hash)
//		+ 31 * std::hash<int>()(this->first_name_hash)
//		+ 57 * std::hash<double>()(this->email_hash)
//		+ 349 * date.hash();
//}

void demoSimpleHash() 
{


	hash<string> hasherStr;
	string user_id_hash = "WBC88XPE6LP";
	cout << "hash[" << user_id_hash << "]: " << hasherStr(user_id_hash) << endl;

	string first_name_hash = "Colby";
	cout << "hash[" << first_name_hash << "]: " << hasherStr(first_name_hash) << endl;


	string email_hash = "rutrum.non@aol.org";
	cout << "hash[" << email_hash << "]: " << hasherStr(email_hash) << endl;

	//we can store the hash value using size_t (basically an unsigned int)
	size_t myHash = hasherStr("this is a hash value store in a uint");
	cout << myHash << endl;

}
//void demoDateHash() {
//	Date myDate(25, 12, 2022);
//	cout << myDate << endl;
//	cout << "hash[" << myDate << "]: " << myDate.hash() << endl;
//}

//useful - fails when a row of data contains a field (e.g., address) which contains commas
//void demoParseString()
//{
//	string str = "ford, 2012, 1299.55, 25/12/2022";
//	string delimiter = ",";
//
//	vector<string> rowFromCSV = splitString(str, delimiter);
//
//	if (rowFromCSV.size() == 4)
//	{
//		string make = rowFromCSV[0];
//		int year = stoi(rowFromCSV[1]);
//		double price = stod(rowFromCSV[2]);
//		vector<string> dateWords = splitString(rowFromCSV[3], "/");
//
//		if (dateWords.size() == 3)
//		{
//			int date_day = stoi(dateWords[0]);
//			int date_month = stoi(dateWords[1]);
//			int date_year = stoi(dateWords[2]);
//
//			Date registrationDate(date_day, date_month, date_year);
//			Car myCar(make, year, price, registrationDate);
//
//			cout << "Car: " << myCar << endl;
//		}
//	}
//}

//best - supports rows of data that contain commas and parenthesis - thanks for Derek!
void demoCSVToObject(BinaryTree<GamerKey, Gamer*>& tree)
{
	//note: data is a sub-folder under the folder with main CPP file
	string fileName = "data/data_1000.csv";
	vector<vector<string>> allData = readDelimitedRows(fileName);

	for (vector<string> row : allData) 
	{
		Gamer g = new Gamer(row[0], row[1]);
		GamerKey key(row[0], row[2], row[...]);

		tree.add(key, g);
		/*for (string field : row) 
		{
			cout << field << ", ";
		}
		*/
		cout << endl <<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}