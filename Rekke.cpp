#include "Rekke.h"


void Rekke::init_rekker(int rekkenr) {
	int x = (rekkenr+1)*m_brett_size-m_brett_size;
	for(int i=0;i<m_brett_size;++i) 
		index.push_back(x+i);
}
