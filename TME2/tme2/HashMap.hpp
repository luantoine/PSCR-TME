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

	 class iterator{
		 size_t index;
		 forward_list<Entry>::iterator lit;
		 buckets_t& buck;
	 public:
		 iterator(size_t index, forward_list<Entry>::iterator lit, buckets_t& buck)
		 :index(index), lit(lit), buck(buck){}

		 iterator& operator++(){
			 ++lit;
			 if(lit == buck[index].end()){
				 ++index;
				 for(;index < buck.size() && buck[index].empty(); ++index){
					 /*NOP*/
				 }
				 if (index < buck.size()) lit = buck[index].begin();
			 }
			 return *this;
		 }

		 bool operator!=(const iterator& o){
			 if (index == buck.size() && o.index == index) return false;
			 else
			 		return index!=o.index || lit != o.lit
					 //||buck != o.buck; -> necessite == sur map
					 || &buck != &o.buck;

		 }

		 Entry& operator*(){
			 return *lit;
		 }
	 };

		 iterator begin(){
			 for (int index = 0; index < tab.size(); index++){
				 	 if (!tab[index»].empty()){
				 		 return iterator(index, tab[index].begin(), buck)
				 	 }
			}
			 return end();
		 }

		 iterator end(){
			 return iterator(tab.size(), tab[0].end(), tab);
		 }
	 };

