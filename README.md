TESTING FUNCTIONS AND LOGIC:

The test cases included check that both unordered map containers basic operations are functioning
as intended. These are common operations throughout the program and edge cases are included as well.
I tried creating a class to encapsulate these, but ran into many redefinition errors, so these are all
in one self-sufficient function in functions.cpp. 

If assert fails, the proper message is displayed on the debug window.

TEST 1: Insert into map 
Test case checks that inputting a id key and associated product data is properly stored in the
unordered map based on the hash function. 

    - Case 1 Reg: Find function will return the data of the item inserted (as expected)
`   - Case 2 Edge: Inserting an item with the same key will result in overwrite (colision handeling, overwrite)

TEST 2: Check size of map
After inserting a few items into the hashmap, we should easily be able to retrieve the number of items. This is useful for rehashing or other manipulation of our data set that we may have to do later.

    -Case 1 Reg: Insert a couple of items (key,value pairs) into the map, the proper size should
    be returned
    -Case 2 Edge: An empty map should return a proper size too, not messing up because of a nullptr

TEST 3: Erasing items from map
If we input the key of a item that we want to delete from our data set, it should be able to be retreived and removed accordingly.

    -Case 1 Reg: Insert an item, erase it with our erase function, delete it, and upon searching for it, it should not be found in the set
    -Case 2 Edge: Attempt to erase an item that was not inserted into the map, this should not crash the program or incorrectly modify the size field


