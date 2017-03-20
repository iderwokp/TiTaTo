#ifndef _players_h_
#define _players_h_
#include <random>
#include <functional>
#include <chrono>
#include <iostream>
#include <memory>
#include "Hoved.h"
#include "Errors.h"



class Players {
	private:
		string prompt{"X Y : "};
		int game_size;
		vector<unique_ptr<Base_rekker>>& rekke_rader;
		bool computer{false};
		ruteverdi rute{Sirkel};
		ruteverdi motstander{Kryss};
		Koordinat rand_koord() const;
		bool tomt_brett() const;
		Koordinat mangler_en_for_seier_eller_tap() ;
		Koordinat tilfeldig_ledig() const;
		ruteverdi read(int x, int y) const;
		Koordinat human() const;
		Koordinat comp_ai();
		Koordinat get_koordinat(const Base_rekker& v, int i);

	public:
		Players(int sz, vector<std::unique_ptr<Base_rekker>>& rr, bool comp, ruteverdi r): game_size{sz}, rekke_rader{rr}, computer{comp}, rute{r} {
			if (rute == Kryss) motstander = Sirkel;
		}

		Koordinat play();
		ruteverdi Ruteverdi() const{ return rute;}


};


#endif