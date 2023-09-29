#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>

int main () {
	using namespace std;
	using namespace std::chrono;

	ifstream input = ifstream("WarAndPeace.txt");

	auto start = steady_clock::now();
	cout << "Parsing War and Peace" << endl;

	// vecteur pour les mots
	vector<pair<string, int>> v;
	bool trouve = false;

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
		/*pos = find(v.begin(), v.end(), word)
		if ( std::find(v.begin(), v.end(), word) != v.end()){
			for (auto& p : v){
				if (std::string::compare(p.first, v) == 0){
					p.second++;
				}
			}
		}
		else{
			v.push_back(make_pair(word, 1));
		}*/
		trouve = false;
		for (auto& p : v){
			if (p.first == word){
				trouve = true;
				p.second++;
				break;
			}
		}
		if (!trouve) v.emplace_back(make_pair(word, 1));

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
    int nb_mots_diff = 0;
    for (int i = 0; i < v.size(); i++){
    	nb_mots_diff++;
    }

    cout << "Nombre de mots différents: " << nb_mots_diff << endl;

    //Nombre d'occurences de chaque mots
    /*for (int i = 0; i < v.size(); i++){
    	cout << "Mot " << v[i].first << " apparait " << v[i].second << " fois " << endl;
    }*/
    for (auto& p : v){
    	if (p.first == "war")
    		cout << "war trouvé " << p.second << " fois " << endl;
    	if (p.first == "peace")
    		cout << "peace trouvé " << p.second << " fois" << endl;
    	if (p.first == "toto")
    		cout << "toto trouvé " << p.second << " fois" << endl;
    }

    return 0;
}


