#include "Game_play.h"

int Game_play::check_winner() {
	int i{0};
	//for(int i=0;i<game_size*game_size;i++) {
	for(unique_ptr<Base_rekker>& br:rekke_rader) {
		if(br->ant().antall_blank == 0) { //Alle rutene er opptatte
			if(br->ant().antall_kryss == 0) {
				rut = Sirkel;
				return i;
			}//indre  if
			else if (br->ant().antall_sirkel == 0){
			rut = Kryss;
			return i; 
			}//else
		}//ytre if 		
		++i;
	}//for
	return -1; //Ingen vinnere
}
void Game_play::refresh() const{
	for(unique_ptr<Base_rekker>& v: rekke_rader) v->Tell_opp(v->ant());

}
void Game_play::set(int x, int y, ruteverdi rv) {
	if((x<0 || y<0) || (x>game_size || x>game_size)) {
		cout << "X=" << x << " Y=" << y << " Player=" << str_ruteverdi(rv) << endl;
		throw Row_error("Set coords out of range.");
		}
	rekke_rader.at(y)->sett_verdi(x, rv);
	refresh();
}

int Game_play::play() {

	Players menneske(game_size, rekke_rader, true, Kryss);
	Players datamaskin(game_size, rekke_rader, true, Sirkel);
	Koordinat koord;
	int ret;
	int i{0};
	int antall_ruter = game_size*game_size;
	// TODO Rydde opp i denne FIXME
	while(true) {
		skriv_brett();cout << endl;
		koord = menneske.play();
		ret = sjekke_koordinater(koord, menneske);

		if(ret != -1) {
			skriv_brett();
			return ret;
		}//if
		++i; if(i==antall_ruter) break;

		koord = datamaskin.play();
		ret = sjekke_koordinater(koord, datamaskin);

		if(ret != -1) {
			skriv_brett();cout << endl;
			return ret;
		}//if
		++i;if(i==antall_ruter) break;
	}//while

	skriv_brett(); cout << endl;
	return 1000;//Ingen har vunnet
}

string Game_play::str_ruteverdi(ruteverdi r)const {
		string s{};
		switch (r) {
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
	 return s;
	}
int Game_play::sjekke_koordinater(Koordinat ko, Players p) {
	if (ko.x == -1) return -1;
	if (ko.x != -2) set(ko.x, ko.y, p.Ruteverdi()); // -2 betyr at krysset er satt et annet sted
	refresh();
	return check_winner();
}