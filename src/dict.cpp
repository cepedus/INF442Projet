#include <cassert>
#include <cfloat>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector> 


#include "dict.hpp"


dict::dict(int _p, int _q){
	
	p = _p;
	q = _q;
}

dict::~dict(){
	sequences.erase(sequences.begin(), sequences.end());
	cleavages.erase(cleavages.begin(), cleavages.end());
	lengths.erase(lengths.begin(), lengths.end());
}

int dict::get_n(){return n;}
int dict::get_p(){return p;}
int dict::get_q(){return q;}

void dict::set_p(int _p){p = _p;}
void dict::set_q(int _q){q = _q;}

std::string dict::get_sequence(int i)
{
	return sequences[i];
}

int dict::get_cleavage(int i)
{
	return cleavages[i];
}

int dict::get_length(int i)
{
	return lengths[i];
}

void dict::load(std::ifstream &is){
	std::string line;

	int line_ref = 0; // Keeps track of line in file (3 possible types)
	int current_seq = 0;
	int s1;
	std::string seq;


	while(std::getline (is, line))
	{	
		line_ref ++;
		line_ref %= 3; // 0 for cleavage, 1 for protein, 2 for sequence

		if(line_ref == 1) s1 = std::stoi(line.substr(0, 5));  // recover sequence length
		if(line_ref == 2) seq = line;                      // recover aminoacid sequence
		if(line_ref == 0)                                             // recover cleavage position
		{
			int s2 = line.find("C"); 

			// add sequence to dict
			sequences.push_back(seq);
			cleavages.push_back(s2);
			lengths.push_back(s1);
			
			current_seq++;
		}
			
	}

	n = current_seq;
	is.close();
}

int dict::N(char a, int i){ // uses absolute indexation (pos 0 is first position, not cleavage position)
	int count = 0;
	for(int j = 0; j < n; j++) if(sequences[j][i] == a) count++;
	if(count == 0) return 1; //pseudocount
	return count;
}

double dict::f(char a, int i){ // uses absolute indexation (pos 0 is first position, not cleavage position)
	return (double) N(a, i)/n;
}

int dict::g(char a){
	int count = 0; // does not count characters on first position to avoid M bias
	for(int i = 0; i < n; i++) for(int j = 1; j < sequences[i].length(); j++) if(sequences[i][j] == a) count++;
	if(count == 0) return 1; //pseudocount
	return count;
}

double dict::W(char a, int i){ // uses absolute indexation (pos 0 is first position, not cleavage position)
	return log(f(a, i)) - log(g(a));	
}

double dict::score(std::string w){ // uses absolute indexation (pos 0 is first position, not cleavage position)
	double s = 0.0;
	for(int i = 0; i < p + q; i++) s += W(w[i], i);

	return s;
}

