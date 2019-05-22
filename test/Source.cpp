﻿//#include "pch.h"
#include"sqlite3.h"
#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main()
{

	char *s1;
	int ret1 = 0;//movie
	const char *select_query = "SELECT startingtime, lastingtime, room from users";
	sqlite3 *db1 = 0;
	std::cout << "Hello World!\n";


	//打开数据库，不存在，创建数据库db
	ret1 = sqlite3_open("./NEW.db", &db1);
	if (ret1 != SQLITE_OK)
	{
		printf("can not open the database\n");
		return 1;
	}
	printf("linked Successful\n");
	//创建表
	ret1 = sqlite3_exec(db1, "create table if not exists users(movieId int(20), movieName varchar(20),room varchar(200), startingTime int(20), lastingTime int(20),SeatStatus varchar(750), price real(500) )", 0, 0, &s1);
	if (ret1 != SQLITE_OK)
	{
		sqlite3_close(db1);
		printf("create error\n");
		return 1;
	}
	printf("create success\n");

	//插入数据
	ret1 = sqlite3_exec(db1, "insert into users values(1,'iron man',20,'s2',1,2,'000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')", 0, 0, &s1);
	
	ret1 += sqlite3_exec(db1, "insert into users values(2,'shazan!',20,'s1',3,4,'00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')", 0, 0, &s1);
	ret1 += sqlite3_exec(db1, "insert into users values(3,'superman',20,'b1',5,6,'00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')", 0, 0, &s1);
	ret1 += sqlite3_exec(db1, "insert into users values(4,'test2',20,'b4',2,2,'00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')", 0, 0, &s1);
	if (ret1 != SQLITE_OK)
	{
		sqlite3_close(db1);
		printf("insert error\n");
		return 1;
	}
	printf("insert success\n");


	

















	cout << "Recent movies are as follows" << endl;
	int nrow1, ncolumn1;
	char ** db1_result;
	ret1 = sqlite3_get_table(db1, select_query, &db1_result, &nrow1, &ncolumn1, &s1);
	if (ret1 != SQLITE_OK)
	{
		printf("select error\n");
		sqlite3_close(db1);
		//return 1;
	}
	int i1, j1;
	for (i1 = 0; i1 < (nrow1 + 1)*ncolumn1; i1 += ncolumn1)
	{
		for (j1 = 0; j1 < ncolumn1; j1++)
		{
			printf("%s  ", db1_result[i1 + j1]);
		}
		printf("\n");
	}
sqlite3_close(db1);












char ** db2_result;




	db1 = 0;
	int nrow, ncolumn;
	char ** db_result;
	cout << "Input your choice";
	int temp;
	cin >> temp;
	//std::string insertStr = "select movieName from users where movieId=(" + to_string(temp) + ")";
	const char *select_query1 = "select * from users ";
	//select_query1
	//std::string insertStr = "select movieName from users ";
	ret1 = sqlite3_get_table(db1, select_query1, &db_result, &nrow, &ncolumn, &s1);
	//char *sqliteInsert = const_cast<char*>(insertStr.c_str());
	//printf("%s  ", db1_result[temp]);







	//这个把数据库的信息读入到变量中

	string PushedMovieName;

	PushedMovieName = db1_result[temp];
	cout << PushedMovieName;

	
	
	
	
	
	
	
	
	//把变量信息读入到变量数组中
	vector<string> vara;
	vector<string> varb;
	vector<string>varc;
	for (int i = 0; i < 3; i++)
	{
		vara.push_back(db1_result[3 * i+3]);
		varb.push_back(db1_result[3 * i + 4]);
		varc.push_back(db1_result[3 * i + 5]);
	}
	vector<int> IVera;
	vector<int> IVerb;

	
	for (int i = 0; i < 3; i++)
	{
		
		IVera.push_back(stoi(vara[i]));
		cout << IVera[i];
		IVerb.push_back(stoi(varb[i]));
		cout << IVerb[i];
		cout << varc[i]<<"\n";
	}
	
	







	
	









	system("pause");
	return 0;
}
/*

	string test;
	const char *select_query2 = "SELECT COUNT(*) FROM users";
	int ret2 = sqlite3_get_table(db1, select_query2, &db_result, &nrow, &ncolumn, &s1);
	test = db_result[1];
	int temptemp = stoi(test);


*/