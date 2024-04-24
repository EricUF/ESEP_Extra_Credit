#include <string>
#include <iostream>
#include <map>
#include "Header.h"
using namespace std;
using namespace N;

//using a map with keys
int main()
{
    interface keyDatabase;
    // should return null, because A doesn’t exist in the DB yet
    keyDatabase.get("A");

    // should throw an error because a transaction is not in progress
    keyDatabase.put("A", 5);

    // starts a new transaction
    keyDatabase.begin_transaction();

    // set’s value of A to 5, but its not committed yet
    keyDatabase.put("A", 5);

    // should return null, because updates to A are not committed yet
    keyDatabase.get("A");

    // update A’s value to 6 within the transaction
    keyDatabase.put("A", 6);

    // commits the open transaction
    keyDatabase.commit();

    // should return 6, that was the last value of A to be committed
    keyDatabase.get("A");

    // throws an error, because there is no open transaction
    keyDatabase.commit();

    // throws an error because there is no ongoing transaction
    keyDatabase.rollback();

    // should return null because B does not exist in the database
    keyDatabase.get("B");

    // starts a new transaction
    keyDatabase.begin_transaction();

    // Set key B’s value to 10 within the transaction
    keyDatabase.put("B", 10);

    // Rollback the transaction - revert any changes made to B
    keyDatabase.rollback();

    // Should return null because changes to B were rolled back
    keyDatabase.get("B");

    


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
