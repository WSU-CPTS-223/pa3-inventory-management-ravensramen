#include "hashMap.cpp"
#include "productData.cpp"
#include <list>

//this is the map to search for product based on ID
//<int ID, productData data>

//inherits from unordered map, uses string for id and productData for the product ofc
class idMap : public hashMap<string, productData>{
using hashMap::hashMap;
//insert uses inheirited function

public: 
void findProduct(const string& key){
    //finds if a product exists, if so print details, otherwise print not found

    if (this->find(key)!=nullptr){ //if an item with this keyvalue exists
        productData* foundProduct = this->find(key); //save a copy of the found data to print out

        cout<<"An item with id: "<<key<<" was found in the data set.\n"<<endl;
        cout<<"Here is the information on it: "<<endl;

        //functions to print out data on private members
        cout<<"Product Name: "<< foundProduct->getName()<<endl;
        cout<<"Categories: ";
        foundProduct->printCategories();
        
    }
    else{ //item with key value does not exist in hash map
        cout<<"Item with coresponding ID not found in dataset";
    }

    return;
}
};

///////////////////////////////////////////////////////////////////////////

//another map to store all the items with a given category
//category name is the string, linked list of products is the data
class categoryMap : public hashMap<string, list<productData>>{

using hashMap::hashMap;

public:

void addProductToCategory(const string& category, productData product){
    list<productData>* products = this->find(category); //linked list of products for given category

    if(products){ //if the category already exists in the hash map
        products->push_back(product); //add the new product to the already existing linked list for the category
    }

    else{
        list<productData> newProductCategory; //declare a new product category linked list if not found
        newProductCategory.push_back(product); //add the item to the list
        this->insert(category, newProductCategory);  //insert into the hash map, category name is the key, product linked list is the data
    }
}


void listCategoryItems(const string& category){
    list<productData>* productList = this->find(category);

    if (!productList){ //case 1. no items in hash map stored in this category
        cout<<"No items exist under this category.";
        return;
    }

    cout<<"Here are all the items under category "<<category;
    for(auto& p: *productList){
        cout<<p.getName(); 
    }

}

};

