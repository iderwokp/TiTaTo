#include "Voblique.h"

void Voblique::init_rekker(int radnr) {
	for(int i=0;i<m_brett_size;++i)
		index.push_back(radnr+(i*m_brett_size)+i);
}


