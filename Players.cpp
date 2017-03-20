#include "Players.h"

ruteverdi Players::read(int x, int y) const {
	if((x<0 || y<0) || (x>(game_size-1) || y>(game_size-1))) { 
		throw Row_error("Read coords out of range.");
		}
	return rekke_rader.at(y)->les_verdi(x);

}

Koordinat Players::rand_koord() const {
	Koordinat k;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
	std::uniform_int_distribution<int> distribution(0, game_size-1);
	//int dice_roll = distribution(generator);
	//auto dice = std::bind ( distribution, generator );
	k.x = distribution(generator);
	k.y = distribution(generator);
	return k;

}

Koordinat Players::comp_ai() {
	Koordinat k;
	if(tomt_brett()) return rand_koord();
	k = mangler_en_for_seier_eller_tap();
	if(k.x>-1) return k;
	//if(k.x == -2) return k;//signal om at return-verdien skal ignoreres


	return tilfeldig_ledig();

}

bool Players::tomt_brett() const {
	
	for(unique_ptr<Base_rekker>& v: rekke_rader) if(v->ant().antall_blank != game_size) return false;

	return true;
}

Koordinat Players::mangler_en_for_seier_eller_tap() {
	int indx{0};
	//int count{ 0 };
	Koordinat k(-1, -1);
	for(unique_ptr<Base_rekker>& v: rekke_rader) {
		//cout << ++count << endl;
		if(v->ant().antall_blank == 1) {
			if(v->ant().antall_kryss == 0 || v->ant().antall_sirkel == 0) {
				
				indx = v->finn_1_blank();
				//cout << "indx = " << indx;
				k = get_koordinat(*v, indx);
				//cout << "\tk: x = " << k.x << " y = " << k.y << endl;

				
				return k;
			}//indre if
		}//Ytre if
	
	}//for
	return k;
}


Koordinat Players::tilfeldig_ledig() const {
	Koordinat k;
	for(;;) {
		k = rand_koord();
		if(read(k.x, k.y) == Blank) return k;
	}
	//kommer aldri hit
}

Koordinat Players::play() {
	if(computer) {
		Koordinat k;
		for(;;) {
			k = comp_ai();
			if(k.x == -2) return k;
			if(read(k.x, k.y) == Blank) return k;
		}

	}
		
	return human();

}

Koordinat Players::human()const {
	Koordinat k;
	std::cout << prompt ;
	for(;;) {
		cin >> k.x >> k.y;// 0 0 for å avslutte
		k.x--;k.y--;//Input starter fra 1,1 til game_size,game_size, mens internt er koordinatsystemet 0-basert
		if(k.x<0) return k; //Avslutte
		if(read(k.x, k.y) == Blank) return k;
		else cout << "Denne ruten er opptatt\n" << prompt;
	}
	
}

Koordinat Players::get_koordinat(const Base_rekker& v, int i) {
	Koordinat k;
	if (v.x_koord() == -1) { //v er en Rekke
		k.x = i;
		k.y = v.y_koord();
		//cout << "   Rekke   ";
	}
	else if (v.y_koord() == -1) { //Rad
		k.x = v.x_koord();
		k.y = i;
		//cout << "   Rad   ";
	}
	else if (v.x_koord() == -3) { //voblique
		k.x = k.y = i % (game_size); // På skrå, er x og y koord like.
		//cout << "   Voblique   ";

	} else if (v.x_koord() == -2) { //hoblique
		//k.x = k.y = i % (game_size); FEIL
		int vec_indx = game_size + (i*game_size) - (i + 1);
		k.x = vec_indx % game_size;
		k.y = static_cast<int> (vec_indx / game_size);
		//cout << "   Hoblique   ";

	} else {//Bør aldri aldri komme hit
		throw Row_error("Dritt-index i Players::get_koordinat()\n");
	}

	return k;
}