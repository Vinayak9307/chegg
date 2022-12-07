#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;
class Tree{
    private:
        char    name[15];
        int     age;
        float   height;
        float   price;

    public:
        Tree(char _name[] , int _age , float _height){
            strcpy(this->name,_name);
            this->age = _age;
            this->height = _height;
            this->price = 0;
        }

        char * getName(){
            return this->name;
        }

        int getAge(){
            return this->age;
        }

        float getHeight(){
            return this->height;
        }

        float getPrice(){
            return this->price;
        }

        void setName(char _name[]){
            strcpy(this->name,_name);
        }

        void setAge(int _age){
            this->age = _age;
        }

        void setHeight(float _height){
            this->height = _height;
        }
        
        void setPrice(float _price){
            this->price = _price;
        }
};

int main()
{
    //Name of the data file
    string inputFileName = "treeData.txt";

    //ifstream is used to open file for reading
    ifstream inputFile;
    
    inputFile.open(inputFileName);

    //this is the array of Tree object but it is pointer to pointer to Tree 
    //type because every element of this array points to a specific tree object 
    //we will initialize it at run time
    Tree ** array = (Tree **) malloc (15 * sizeof(Tree));

    //to keep count of tree objects
    int count = 0;

    while(!inputFile.eof()){
        //name array for name of tree and tree array for the tree word
        char name[15], tree[10];
        int age;
        float height;
        inputFile >> name >> tree >> age >> height;
        array[count] = new Tree(name,age,height);
        count++;
    }

    for(int i = 0; i < count ; i++){
        cout<<"Name: "<<array[i]->getName()<<" Tree Age: "<<array[i]->getAge()<<" Height: "<<array[i]->getHeight()<<endl;
    }

    inputFile.close();
    return 0;
}