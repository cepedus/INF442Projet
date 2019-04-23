#include "sequence.hpp"


sequence::sequence()
{
    cleavage = -1;
    len = 0;
    //aminoacids = new const char[60]();
}

sequence::~sequence()
{
    //delete[] aminoacids;
}

int sequence::get_len()
{
    return len;
}

int sequence::get_cleavage()
{
    return cleavage;
}

void sequence::set_cleavage(int _cleavage)
{
    cleavage = _cleavage;
}

/*void sequence::set_aminoacids(char* _aminoacids)
{
    aminoacids = _aminoacids;
}*/

void sequence::set_len(int _l)
{
    len = _l;
}