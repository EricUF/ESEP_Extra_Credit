#pragma once
#include <string>
#include <map>
using namespace std;

namespace N {
	class interface
	{
	public:
		void begin_transaction();
		void put(string key, int value);
		int get(string key);
		void commit();
		void rollback();
		map<string, int> inDatabase;
		map<string, int> tempDatabase;
		bool transaction = false;
	};

	//extern map<string, int> inDatabase;
}

