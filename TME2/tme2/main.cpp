#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>

#include "HashMap.hpp"

int main () {
	using namespace std;
	using namespace std::chrono;

	ifstream input = ifstream("tme2/WarAndPeace.txt");

	auto start = steady_clock::now();
	cout << "Parsing War and Peace" << endl;

	/* vecteur
	vector<pair<string, int>> v;
	bool trouve = false;*/

	// HashMap
	HashMap<string, int> hmap(10000);
	int init = 1; //Pour insérer valeur initiale


	size_t nombre_lu = 0;
	// prochain mot lu
	string word;
	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");
	while (input >> word) {
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);
		/* Avec le vecteur
		 * pos = find(v.begin(), v.end(), word)
		if ( std::find(v.begin(), v.end(), word) != v.end()){
			for (auto& p : v){
				if (std::string::compare(p.first, v) == 0){
					p.second++;
				}
			}
		}
		else{
			v.push_back(make_pair(word, 1));
		}
		trouve = false;
		for (auto& p : v){
			if (p.first == word){
				trouve = true;
				p.second++;
				break;
			}
		}
		if (!trouve) v.emplace_back(make_pair(word, 1));*/

		//HashMap
		if (hmap.contains(word))
			hmap.get(word)++;
		else
			hmap.insert(word, init);


		// word est maintenant "tout propre"
		if (nombre_lu % 100 == 0)
			// on affiche un mot "propre" sur 100
			cout << nombre_lu << ": "<< word << endl;
		nombre_lu++;
	}
	input.close();

	cout << "Finished Parsing War and Peace" << endl;

	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

    cout << "Found a total of " << nombre_lu << " words." << endl;


    // Nombre de mots différents
    int nb_mots_diff = hmap.cle_diff();
    /*for (int i = 0; i < v.size(); i++){
    	nb_mots_diff++;
    }*/

    cout << "Nombre de mots différents: " << nb_mots_diff << endl;

    //Nombre d'occurences de chaque mots
    /*for (int i = 0; i < v.size(); i++){
    	cout << "Mot " << v[i].first << " apparait " << v[i].second << " fois " << endl;
    }*/

    /*for (auto& p : v){
    	if (p.first == "war")
    		cout << "war trouvé " << p.second << " fois " << endl;
    	if (p.first == "peace")
    		cout << "peace trouvé " << p.second << " fois" << endl;
    	if (p.first == "toto")
    		cout << "toto trouvé " << p.second << " fois" << endl;
    }*/

    cout << "war trouvé " << hmap.get("war") << " fois" << endl;
    cout << "peace trouvé " << hmap.get("peace") << " fois" << endl;
    cout << "toto trouvé " << hmap.get("toto") << " fois" << endl;

    /*for (const auto& entries : hmap.tab) {
		for (const auto& entry : entries) {
			wordCountVector.emplace_back(entry.key, entry.value);
		}
	}*/
    //Vecteur de paires
    //vector<pair<string, int>> hvector(hmap.begin(), hmap.end());

    return 0;
}


