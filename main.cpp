#include <iostream>
#include <vector>
#include "Errors.h"
#include "Start.h"
#include "Board.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

const int sz = 7;
Board theBoard(sz);
int main(int argc, char** argv) {
	try {
		
		//vector<Rute> v(sz*sz); 
		
		Start st(sz, theBoard.Board_vector);
		}
		catch(Row_error rer) {

			cout << rer.what();
		}
		catch(...) {
			cout << "Noe annet gikk galt.";
			}
	
	return 0;
}
