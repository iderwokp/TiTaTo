#include<vector>
#include "Hoved.h"

class Hoblique : public Base_rekker {
	public:
		Hoblique(int nr, int bs, vector<Rute>& v) : Base_rekker(bs, v)  {
			init_rekker(m_Radnr);
		}
		virtual int x_koord() const{
			return -2;
		}
		virtual int y_koord() const{
			return -2;
		}
	private:
		
		int m_Radnr {m_brett_size};
		void init_rekker(int);
	
};
