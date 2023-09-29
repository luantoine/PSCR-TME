#include <forward_list>
#include <vector>

using namespace std;

template<typename K, typename V>
class HashMap{
	struct Entry{
		const K key;
		V value;

		Entry(const K& k, V& v): key(k), value(v){}
	};

	size_t sz;
	vector<list<Entry>> tab;

	size_t hash(const K& key) const{
		return strlen(key)%sz;
	}

public:
	//Ctor
	HashMap(size_t size)
		:sz(size),
		tab(size){}

	~HashMap(){}

	void insert(const K& k, V& v){
		int i = hash(key);
		for (Entry& entry : tab[i]){
			if (entry.key == k){
				entry.value = v;
				return;
			}
		}
		tab[i].emplace_back(new Entry(k, v));
	}
};
