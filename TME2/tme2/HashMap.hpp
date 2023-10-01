#include <list>
#include <vector>
#include <cstring>

using namespace std;

template<typename K, typename V>
class HashMap{
	struct Entry{
		K key;
		V value;

		Entry(const K& k, const V& v): key(k), value(v){}
	};

	size_t sz;
	vector<list<Entry>> tab;

	//Fonction hachage pour insertion
	size_t hash(const K& key){
		return key.size()%sz;
	}

public:
	//Ctor
	HashMap(size_t size)
		:sz(size),
		tab(size){}

	//Destructeur
	~HashMap(){}

	//Contenance
	 bool contains(K& k) {
		size_t i = hash(k);
		for (Entry& entry : tab[i]) {
			if (entry.key == k) {
				return true;
			}
		}
		return false;
	 }

	 //Insertion élément
	 void insert(K& k, V& v) {
		 size_t i = hash(k);
		 for (Entry& entry : tab[i]) {
			 if (entry.key == k) {
				 entry.value = v;
				 return;
			 }
		 }
		 tab[i].emplace_back(k, v);
	 }

	 V& get(const K& k) {
		size_t i = hash(k);
		for (Entry& entry : tab[i]) {
			if (entry.key == k) {
				return entry.value;
			}
		}
		throw out_of_range("La clé " + k + " n'est pas présente");
	}

	 //Longueur du tableau
	 int size(){
		 return sz;
	 }

	 //Nombre de clés différentes
	 int cle_diff(){
		 int nb = 0;
		 for (const list<Entry>& entries : tab) {
			 for (const Entry& entry : entries) {
				 if (entry.value > 0) {
					 nb++;
				 }
			 }
		 }
		 return nb;
	 }

