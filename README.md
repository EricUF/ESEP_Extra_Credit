# ESEP_Extra_Credit

This programs can be run with the ESEP.cpp file being edited accordinly. It uses a map data structure to store the keys and values.

1. Functions
- begin_transaction() - Will start a transaction. Put, commit, and rollback can only be called when a transaction has started.
- put(key,value) - Will insert a key and value into a map. The key is a string and the value is an integer.
- get(key) - Will return the value for the given key. This will only return values from the current database and not a transaction in progress.
- commit() - Will commit the current transaction to the database and end the transaciton.
- rollback() - Will discard any changes made from the current transaction and end the transaciton.

To use the program, you first need to create a header object from the interface class in the ESEP.cpp file. For example, I did (interface keyDatabase;).
The next step is to use the functions from above such as (keyDatabase.get("A");). When the program is run the corresponding messages will output to the terminal.

To modify this assignment to become an offical assignment for the future, perhaps the program could require a visual aspect towards it or maybe display the assignment through a web browser. The program could also be made with a CSV file that writes and reads the data instead. Another modification to consider for this assignment is for the user to create an interace in the terminal that will allow them to repeatedly use the functions until they exit with a menu option of the functions.
