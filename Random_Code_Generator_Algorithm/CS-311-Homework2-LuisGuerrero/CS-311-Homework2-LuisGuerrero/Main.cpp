#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <ctime>
#include "Production.h"

using namespace std;

int main()
{
	ofstream outFile;
	outFile.open("RandomCode.txt");
	if (!outFile.is_open())
	{
		cout << "ERROR: File could not be open";
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dis(0, 1);
	
	double rand_num = dis(gen);

	Production prog("<prog>");
	prog.add_rhs("int main() { \n<stat_list> \nreturn 0; }", 1.0);

	Production stat_list("<stat_list>");
	stat_list.add_rhs("<stat>", 0.70);
	stat_list.add_rhs("<stat_list> <stat>", 0.30);

	Production stat("<stat>");
	stat.add_rhs("<cmpd_stat>", 0.10);
	stat.add_rhs("<if_stat>", 0.15);
	stat.add_rhs("<iter_stat>", 0.15);
	stat.add_rhs("<assgn_stat>", 0.30);
	stat.add_rhs("<decl_stat>", 0.30);

	Production cmpd_stat("<cmpd_stat>");
	cmpd_stat.add_rhs("{ <stat_list> }", 1.0);

	Production if_stat("<if_stat>");
	if_stat.add_rhs("if ( <exp> ) \n{ <stat> \n}", 0.30);
	if_stat.add_rhs("if ( <exp> ) \n{ <cmpd_stat> \n}", 0.15);
	if_stat.add_rhs("if ( <exp> ) \n{ <stat> else <stat> }\n", 0.15);
	if_stat.add_rhs("if ( <exp> ) \n{ <cmpd_stat> else <stat> }\n", 0.15);
	if_stat.add_rhs("if ( <exp> ) \n{ <stat> else <cmpd_stat> }\n", 0.15);
	if_stat.add_rhs("if ( <exp> ) \n{ <cmpd_stat> else <cmpd_stat> }\n", 0.10);

	Production iter_stat("<iter_stat>");
	iter_stat.add_rhs("while ( <exp> ) \n{ <stat> }\n", 0.70);
	iter_stat.add_rhs("while ( <exp> ) \n{ <cmpd_stat> }\n", 0.30);

	Production assgn_stat("<assgn_stat>");
	assgn_stat.add_rhs("<id> = <exp>;\n", 1.0);

	Production decl_stat("<decl_stat>");
	decl_stat.add_rhs("<type> <id>;\n", 0.70);
	decl_stat.add_rhs("<type> <assgn_stat>", 0.30);

	Production exp("<exp>");
	exp.add_rhs("<const>", 0.60);
	exp.add_rhs("<id>", 0.30);
	exp.add_rhs("<exp> <op> <exp>", .10);

	Production op("<op>");
	op.add_rhs("+", 0.25);
	op.add_rhs("-", 0.25);
	op.add_rhs("*", 0.25);
	op.add_rhs("/", 0.25);

	Production type("<type>");
	type.add_rhs("int", 0.50);
	type.add_rhs("double", 0.50);

	Production id("<id>");
	id.add_rhs("<char><char_digit_seq>", dis(gen));

	Production constn("<const>");
	constn.add_rhs("<digit><digit_seq>", 1);

	Production char_digit_seq("<char_digit_seq>");
	char_digit_seq.add_rhs(" ", 0.33);
	char_digit_seq.add_rhs("<char><char_digit_seq>", 0.33);
	char_digit_seq.add_rhs("<digit><char_digit_seq>", 0.33);
	
	Production digit_seq("<digit_seq>");
	digit_seq.add_rhs(" ", 0.70);
	digit_seq.add_rhs("<digit><digit_seq>", 0.30);

	Production chart("<char>");
	chart.add_rhs("A",  0.038);
	chart.add_rhs("B", 0.038);
	chart.add_rhs("C", 0.038);
	chart.add_rhs("D", 0.038);
	chart.add_rhs("E", 0.038);
	chart.add_rhs("F", 0.038);
	chart.add_rhs("G", 0.038);
	chart.add_rhs("H", 0.038);
	chart.add_rhs("I", 0.038);
	chart.add_rhs("J", 0.038);
	chart.add_rhs("K", 0.038);
	chart.add_rhs("L", 0.038);
	chart.add_rhs("M", 0.038);
	chart.add_rhs("N", 0.038);
	chart.add_rhs("O", 0.038);
	chart.add_rhs("P", 0.038);
	chart.add_rhs("Q", 0.038);
	chart.add_rhs("R", 0.038);
	chart.add_rhs("S", 0.038);
	chart.add_rhs("T", 0.038);
	chart.add_rhs("U", 0.038);
	chart.add_rhs("V", 0.038);
	chart.add_rhs("W", 0.038);
	chart.add_rhs("X", 0.038);
	chart.add_rhs("Y", 0.038);
	chart.add_rhs("Z", 0.038);
	chart.add_rhs("a", 0.038);
	chart.add_rhs("b", 0.038);
	chart.add_rhs("c", 0.038);
	chart.add_rhs("d", 0.038);
	chart.add_rhs("e", 0.038);
	chart.add_rhs("f", 0.038);
	chart.add_rhs("g", 0.038);
	chart.add_rhs("h", 0.038);
	chart.add_rhs("i", 0.038);
	chart.add_rhs("j", 0.038);
	chart.add_rhs("k", 0.038);
	chart.add_rhs("l", 0.038);
	chart.add_rhs("m", 0.038);
	chart.add_rhs("n", 0.038);
	chart.add_rhs("o", 0.038);
	chart.add_rhs("p", 0.038);
	chart.add_rhs("q", 0.038);
	chart.add_rhs("r", 0.038);
	chart.add_rhs("s", 0.038);
	chart.add_rhs("t", 0.038);
	chart.add_rhs("u", 0.038);
	chart.add_rhs("v", 0.038);
	chart.add_rhs("w", 0.038);
	chart.add_rhs("x", 0.038);
	chart.add_rhs("y", 0.038);
	chart.add_rhs("z", 0.038);

	Production digit("<digit>");
	digit.add_rhs("0", 0.1);
	digit.add_rhs("1", 0.1);
	digit.add_rhs("2", 0.1);
	digit.add_rhs("3", 0.1);
	digit.add_rhs("4", 0.1);
	digit.add_rhs("5", 0.1);
	digit.add_rhs("6", 0.1);
	digit.add_rhs("7", 0.1);
	digit.add_rhs("8", 0.1);
	digit.add_rhs("9", 0.1);

	string str = "<prog>";

	if (str == "<prog>")
	{
		str = prog.expand();
		//cout << str << endl;
	}
	
	while(str.find("<") != string::npos )
	{
		size_t open_bracket = str.find('<');
		size_t closing_bracket = str.find('>');
		string temp = str.substr(open_bracket, (closing_bracket - open_bracket) + 1);

		if (temp == "<stat_list>")
		{
			str.replace(open_bracket, temp.length(), stat_list.expand());
			//cout << str << endl;
		}
		else if (temp == "<stat>")
		{
			str.replace(open_bracket, temp.length(), stat.expand());
			//cout << str << endl;
		}
		else if (temp == "<cmpd_stat>")
		{
			str.replace(open_bracket, temp.length(), cmpd_stat.expand());
			//cout << str << endl;
		}
		else if (temp == "<if_stat>")
		{
			str.replace(open_bracket, temp.length(), if_stat.expand());
			//cout << str << endl;
		}
		else if (temp == "<iter_stat>")
		{
			str.replace(open_bracket, temp.length(), iter_stat.expand());
			//cout << str << endl;
		}
		else if (temp == "<assgn_stat>")
		{
			str.replace(open_bracket, temp.length(), assgn_stat.expand());
			//cout << str << endl;
		}
		else if (temp == "<decl_stat>")
		{
			str.replace(open_bracket, temp.length(), decl_stat.expand());
			//cout << str << endl;
		}
		else if (temp == "<exp>")
		{
			str.replace(open_bracket, temp.length(), exp.expand());
			//cout << str << endl;
		}
		else if (temp == "<op>")
		{
			str.replace(open_bracket, temp.length(), op.expand());
			//cout << str << endl;
		}
		else if (temp == "<type>")
		{
			str.replace(open_bracket, temp.length(), type.expand());
			//cout << str << endl;
		}
		else if (temp == "<id>")
		{
			str.replace(open_bracket, temp.length(), id.expand());
			//cout << str << endl;
		}
		else if (temp == "<const>")
		{
			str.replace(open_bracket, temp.length(), constn.expand());
			//cout << str << endl;
		}
		else if (temp == "<char_digit_seq>")
		{
			str.replace(open_bracket, temp.length(), char_digit_seq.expand());
			//cout << str << endl;
		}
		else if (temp == "<digit_seq>")
		{
			str.replace(open_bracket, temp.length(), digit_seq.expand());
			//cout << str << endl;
		}
		else if (temp == "<char>")
		{
			str.replace(open_bracket, temp.length(), chart.expand());
			//cout << str << endl;
		}
		else if (temp == "<digit>")
		{
			str.replace(open_bracket, temp.length(), digit.expand());
			//cout << str << endl;
		}

		
	}


	cout << str << endl;



	/*
	if (str == "<program>")
	{
		str = "int main() { <stat_list> return 0; }";
		cout << str << endl << endl;
	}
	size_t open_bracket = str.find('<');
	size_t closing_bracket = str.find('>');
	string temp;

	while (open_bracket != string::npos)
	{
		temp = str.substr(open_bracket, (closing_bracket - open_bracket) + 1);
		str.replace(open_bracket, temp.length(), production.expand());
		open_bracket = str.find("<");
		closing_bracket = str.find(">");

		cout << str << endl;
	}

	cout << str << endl;*/
	system("pause");
	return 0;
}