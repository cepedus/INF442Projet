#include <iostream>
#include <cstdlib>

#include <cassert>
#include <algorithm>
#include <fstream>
#include <cmath>

#include "dict.hpp"

int main(int argc, char **argv){

	int p, q;

	//----- VERIFY INPUT -----//

	if(argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " datafile [p] [q]" << std::endl;
		std::exit(1);
	}
	
	p = atoi(argv[2]);
	q = atoi(argv[3]);
	std::ifstream is(argv[1]);

	if(!is)
	{
		std::cerr << "Unable to open " << argv[1] << std::endl;
		std::exit(1);
	} 

	//----- LOAD FILE -----//

	dict training_set = dict(p, q);
	training_set.load(is);
	std::cout << "Finished loading data from " << argv[1] << ", " << training_set.get_n() << " sequences added" <<std::endl;

	// test N and f
	/* 
	for(char a : training_set.alphabet){
		for(int i = 0; i < 20 ; i ++) std::cout << training_set.f(a, i) << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	*/

	// test g
	/*
	for(char c : training_set.alphabet) std::cout << training_set.g(c) << " ";
	std::cout << std::endl;
	*/

	//----- COMPARE SCORE IN 3.1 -----//
	// mean score for 13, 2 -144.009
	/*
	double score_mean = 0.0;
	
	for(int s = 0; s < training_set.get_n(); s++){
		for(int i = 0; i < training_set.get_sequence(s).length() - (p+q) ;i++){
			std::string sub = training_set.get_sequence(s).substr(i , p + q + 1);
			double subscore = training_set.score(sub);
			if(i == training_set.get_cleavage(s) - p) score_mean += subscore/training_set.get_n();
		}
	}

	std::cout << score_mean << std::endl;
	*/

	for(int i = 0; i < training_set.get_sequence(0).length() - (p+q) ;i++){
			std::string sub = training_set.get_sequence(0).substr(i , p + q + 1);
			double subscore = training_set.score(sub);
			std::cout << sub << " " << pow(subscore + 144.009, 2) <<std::endl;
		}
	






}
