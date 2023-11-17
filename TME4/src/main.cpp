#include "Banque.h"
#include <unistd.h> //<windows.h> sur windows

using namespace std;
using namespace pr;
const int NB_THREAD = 10;
int main () {
	vector<thread> threads;
	// TODO : creer des threads qui font ce qui est demandé
	threads.reserve(NB_THREAD);
	int j, k, m;
	int nb_comptes = 10;
	Banque b(nb_comptes, 100);

	for (int i = 0; i < 1000; ++i){
		j = rand() % (nb_comptes + 1); //0 et 10
		k = rand() % (nb_comptes + 1);
		m = rand() % 100 + 1; //montant
		threads.emplace_back(thread(&Banque::transfert, &b, j, k, m)); //&b = this
		//thread(std::mem_function(&Banque::transfert), ref(b), 10, 12);
		this_thread::sleep_for(chrono::milliseconds(rand()% 21));
	}

	for (auto & t : threads) {
		t.join();
	}

	//affichage
	//for (auto& c : )
	// TODO : tester solde = NB_THREAD * JP
	return 0;
}
