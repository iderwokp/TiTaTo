#include "Errors.h"
#include "Hoved.h"

void Base_rekker::Dbg_skriv_meg_ut()const {
 	for(int i = 0;i<m_brett_size;++i) 
 		std::cout << i << "(" << index[i] << ") -> " <<  m_vr[index[i]].tekst << endl;

 }

 void Base_rekker::sett_verdi(int indx, ruteverdi rv) {
 	if(indx<0 || indx > (m_brett_size-1)) {
 		throw Row_error("Sett_verdi(): Index out of range");
 		}
 	string s{};
 	switch (rv) {
 		case Blank:
 			s = str_blank;
 			break;
 		case Kryss:
 			s = str_kryss;
 			break;
 		case Sirkel:
 			s = str_sirkel;
 			break;
 	}
 	m_vr[index[indx]].tekst = s;
 	m_vr[index[indx]].rv = rv;
 }

 ruteverdi Base_rekker::les_verdi(int indx) const{
 	if(indx<0 || indx > (m_brett_size-1)) {
 		cout << "indx=" << indx << " m_brett_size=" << m_brett_size << endl; //" Player=" << str_ruteverdi(rv) << endl;
 		throw Row_error("les_verdi(): Index out of range");
 		}
 	return m_vr[index[indx]].rv;
 	}

 void Base_rekker::skriv_brett()const {
 	int indx {0};
 	for(int i=0;i<m_brett_size;++i) {
 		for(int j=0;j<m_brett_size;++j) {
 			cout << str_delim << m_vr[indx++].tekst; 
 			}
 	 	cout << str_delim  << endl;
 	 }
 }

 void Base_rekker::Tell_opp(Opptelling& ot)const {
 	//Dbg_skriv_meg_ut(); 
 	ot.antall_blank = ot.antall_kryss = ot.antall_sirkel = 0; //Resette tellerne før bruk
	for(int i=0;i<m_brett_size;++i) {

		ruteverdi t = les_verdi(i);
		switch (t) { // m_vr[index[i]].rv) {
			case Blank:
				ot.antall_blank++;
				break;
			case Kryss:
				ot.antall_kryss++;
				break;
			case Sirkel:
				ot.antall_sirkel++;
				break;
			default:
				throw Row_error("Noe er galt i 'Tell_opp'!");
		}//switch
	}//for

 }//Tell_opp

 int Base_rekker::finn_1_blank()const {
 	for(int i=0;i<m_brett_size;++i)
 		if(les_verdi(i) == Blank) return i;
 	return -1;
 }