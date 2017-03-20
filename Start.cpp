#include <vector>
#include <memory>
#include "Errors.h"
#include "Start.h"
#include "Game_play.h"

void Start::game() {
	Game_play gp(game_size, rekke_rader);
	int w = gp.play();
	if (w == 1000) {
		cout << "Uavgjort!" << endl;
		return;
	}
	if( w != -1) {
		cout << str_ruteverdi(gp.rute_verdi()) << " vant\n";// på linje " << w << endl;
	} else {
		cout << "Avbrutt." << endl;
		}

}



void Start::Dbg_print_row_status(vector<unique_ptr<Base_rekker>>& vec)const {
	
	for(auto& v: vec) {
		cout << "Blank: " << v->ant().antall_blank << "  Kryss: " << v->ant().antall_kryss << "  Sirkel: " << v->ant().antall_sirkel << "\n";
	}

}



string Start::str_ruteverdi(ruteverdi r)const {
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