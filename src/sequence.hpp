#pragma once

class sequence {
	int len;
	int cleavage;
	//const char *aminoacids;
public:
	//char *aminoacids;
	sequence();
	~sequence();

	int get_len();
	int get_cleavage();

	void set_cleavage(int _cleavage);
	//void set_aminoacids(char* _aminoacids);
	void set_len(int _l);
	void set_max_len(int _m);
	
};
