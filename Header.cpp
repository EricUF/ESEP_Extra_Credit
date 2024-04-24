#include "Header.h" 
#include <iostream> 

using namespace N;

//starts a new transaction
//only one transaction can occur at a time
//during a transaction you can make as many changes to the keys as you want, they should not be visible to get until we commit
void interface::begin_transaction() {
	//set to true
	if (transaction == false) {
		transaction = true;
		tempDatabase = inDatabase;
		cout << "Transaction started." << endl;
	}
}

//create a new key with the provided value if a key doesnt exist, otherwise update the current key with the new value
//if this is called while not in a transaction throw an excpetion
void interface::put(string key, int value) {
	//base case
	try {
		if (transaction != true) {
			throw(transaction);
		}
	}
	catch (bool transaction) {
		cout << "Put failed. A transaction has not started yet." << endl;
		return;
	}

	//key already exists
	if (tempDatabase.find(key) != tempDatabase.end()) {
		cout << "Key value updated." << endl;
		tempDatabase[key] = value;
	}
	//key is not found
	else {
		cout << "Key value inserted." << endl;
		tempDatabase[key] = value;
	}
}

//will return the value associated with the key or null if the key does not exist
//thius can be called anytime
int interface::get(string key) {
	//key is found
	if (inDatabase.find(key) != inDatabase.end()) {
		cout << "Key:" << key << " Value:" << inDatabase[key] << endl;
	}
	//key is not found
	else {
		cout << "Key:" << key << " does not exist, NULL returned." << endl;
		return NULL;
	}
}

//ends transaction
//applies the changes
void interface::commit() {
	//base case
	if (transaction == false) {
		cout << "Commit failed. A transaction has not started yet." << endl;
		return;
	}

	cout << "Data has been committed." << endl;

	//copy over database
	inDatabase = tempDatabase;

	//clear tempDatabase
	tempDatabase.clear();

	//reset transaction
	transaction = false;
}

//end transaction
//abort all changes
void interface::rollback() {
	//base case
	if (transaction == false) {
		cout << "Rollback failed. A transaction has not started yet." << endl;
		return;
	}

	cout << "Data has been rollbacked." << endl;

	//clear tempDatabase
	tempDatabase.clear();

	//reset transaction
	transaction = false;
}