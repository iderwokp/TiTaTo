#include<vector>
#include "Hoved.h"

using namespace std;

class Rekke : public Base_rekker {
	
	public:
		Rekke(int nr, int bs, vector<Rute>& v) :Base_rekker(bs, v), m_Rekkenr{nr} {
			init_rekker(nr);
		}
		virtual int x_koord() const{
			return -1;
		}
		virtual int y_koord() const{
			return m_Rekkenr;
		}
	private:
		int m_Rekkenr;
		void init_rekker(int);
	
};
