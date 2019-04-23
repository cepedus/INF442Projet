#pragma once

#include <fstream>
#include <vector> 


class dict{
	int n, p, q;
	std::vector<std::string> sequences;
	std::vector<int> cleavages;
	std::vector<int> lengths;

public:

	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	dict(int _p, int _q);
	~dict();

	int get_n();
	int get_p();
	int get_q();

	void set_p(int _p);
	void set_q(int _q);

	void load(std::ifstream &is);
	std::string get_sequence(int i);
	int get_cleavage(int i);
	int get_length(int i);

	int N(char a, int i);
	double f(char a, int i);
	int g(char a);
	double W(char a, int i);
	double score(std::string w);
};
