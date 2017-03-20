#include<vector>
#include "Hoved.h"

class Voblique : public Base_rekker {
	
	public:
		Voblique(int nr, int bs, vector<Rute>& v): Base_rekker(bs, v)   {
			init_rekker(0);
		}
		virtual int x_koord() const{
			return -3;
		}
		virtual int y_koord() const {
			return -3;
		}
	private:
		int m_Radnr {0};
		void init_rekker(int i);
};
