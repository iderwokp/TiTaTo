#include "Hoblique.h"

void Hoblique::init_rekker(int ) {
	for(int i=0;i<m_brett_size;++i)
		index.push_back(m_brett_size+(i*m_brett_size)-(i+1));
}


// vec_indx = m_brett_size+(i*m_brett_size)-(i+1)
// vec_indx = y*m_brett_size + x
// x = vec_indx % m_brett_size
// y = vec_indx / m_brett_size