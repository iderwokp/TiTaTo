#ifndef _hoved_h
#define _hoved_h

#include <vector>
#include <string>
#include <iostream>

using namespace std;
const string str_kryss{"X"};
const string str_sirkel{"O"};
const string str_blank{"."};
const string str_delim{"|"};

enum ruteverdi {Blank, Kryss, Sirkel};

struct Rute {
	string tekst{str_blank};
	ruteverdi rv{Blank};
	
};
struct Koordinat {
	int x {0};
	int y {0};
	Koordinat(): Koordinat(0, 0) {}
	Koordinat(int xx, int yy): x{xx}, y{yy} {}
};

struct Opptelling {
	int antall_blank {0};
	int antall_kryss{0};
	int antall_sirkel {0};
};

class Base_rekker {//Base til Rad, Rekke, Voblique og Hoblique
	public:
		Base_rekker(int bs, vector<Rute>& v):m_brett_size{bs}, m_vr{v} {};
		void Dbg_skriv_meg_ut() const; 
		void sett_verdi(int, ruteverdi);
		ruteverdi les_verdi(int)const;
		void skriv_brett()const;
		void Tell_opp(Opptelling& ot)const;
		Opptelling& ant()  {return ant_;} 
		int finn_1_blank()const;
		virtual int x_koord() const { return -5; }// = 0;// const { return 0; };
		virtual int y_koord() const { return -5; }// = 0;// const { return 0; };
	protected:
		vector<int> index;
		int m_brett_size;
		vector<Rute>& m_vr;
		Opptelling ant_;
};

#endif
