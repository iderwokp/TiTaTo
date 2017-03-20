#include <string>
#include <memory>
#include "Hoved.h"
#include "Rekke.h"
#include "Rad.h"
#include "Voblique.h"
#include "Hoblique.h"
#include "Players.h"

using namespace std;

class Start {
	public:
	Start(int sz, vector<Rute>& v): game_size{sz} {
		for(int i = 0;i<sz;++i) rekke_rader.push_back(make_unique<Rekke>(i,sz,v));
		for(int i = 0;i<sz;++i) rekke_rader.push_back(make_unique<Rad>(i,sz,v));

		rekke_rader.push_back(make_unique<Voblique>(0,sz,v));
		rekke_rader.push_back(make_unique<Hoblique>(0, sz, v));
		game();
	}
	~Start() {
		//for(Base_rekker* br: rekke_rader) delete (br);
	}

	void game();
	void refresh(vector<unique_ptr<Base_rekker>>&);
	void Dbg_print_row_status(vector<unique_ptr<Base_rekker>>& vec)const;
	void set(int x, int y, ruteverdi rv, vector<unique_ptr<Base_rekker>>& vec);
	string str_ruteverdi(ruteverdi r)const;

	private:
	vector<unique_ptr<Base_rekker>> rekke_rader {};
	int game_size;
	
};
	
