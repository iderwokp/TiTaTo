#include<memory>
#include "Hoved.h"
#include "Errors.h"
#include "Players.h"

class Game_play {
	int game_size;
	vector<unique_ptr<Base_rekker>>& rekke_rader;
	ruteverdi rut{Blank};
	void refresh()const;
	void set(int x, int y, ruteverdi rv);
	void skriv_brett()const {rekke_rader[0]->skriv_brett();}
	public:
	Game_play(int sz, vector<unique_ptr<Base_rekker>>& rr): game_size{sz}, rekke_rader{rr} {}
	int check_winner();
	ruteverdi rute_verdi()const { return rut;}
	string str_ruteverdi(ruteverdi r)const;
	int play();
	int sjekke_koordinater(Koordinat ko, Players p);
		

};
