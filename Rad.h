#include <vector>
#include <iostream>
#include "Hoved.h"


class Rad : public Base_rekker {
	
	public:
		Rad(int nr, int bs, vector<Rute>& v) :Base_rekker(bs, v), m_Radnr{nr} {
			init_rekker(nr);
		}

		virtual int x_koord() const{
			return m_Radnr;
		}
		virtual int y_koord() const {
			return -1;
		}
	private:
		int m_Radnr;
		void init_rekker(int r);
	
};
