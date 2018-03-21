//MAYANK AGRAWAL
//ROLL NO. 150101033

#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    string key;
    int cost;
    node *left;
    node *right;
    string author; 
    string title;
    int publication_year;
    int copies_sold;
}node;
  
void increase(node *root){

    if (root == NULL)
        return ;
    root->cost=(root->cost)*(1.1);
    increase(root->left);
    increase(root->right);   
}

node* insert(node* root,string isbn,int price,string heading,string name,int year,int copies){
    if (root == NULL){
        node *temp =  new struct node;
        temp->key = isbn;
        temp->cost = price;
        temp->publication_year = year;
        temp->copies_sold = copies;
        temp->title = heading;
        temp->author = name;
        temp->left = temp->right = NULL;
    return temp;

    } 
    if (isbn < root->key)
        root->left  = insert(root->left,isbn,price,heading,name,year,copies);
    else if (isbn > root->key)
        root->right = insert(root->right,isbn,price,heading,name,year,copies);   
 
    return root;
}

int cost_search(struct node* root, string key){
    if (root == NULL)
        return -1;
    if (key == root->key)
       return root->copies_sold;
    
    else if (root->key < key)
       return cost_search(root->right, key);
 
    else if (root->key > key)
        return cost_search(root->left, key);


}

void print(node *root){

    if (root == NULL)
        return ;
    print(root->left);
    cout<< "ISBN: "<< root->key <<",  "<<"author: "<< root->author <<",  "<<"cost: " <<root->cost<<endl;
    cout<<"year of publication: "<<root->publication_year<<"   "<<"copies sold:"<<root->copies_sold<<",  "<<"title: "<<root->title<<endl;
    cout<<'\n'<<endl;
    print(root->right);   
}

int main(){

    struct node *root;
    root=insert(NULL,"2389-125-25-00-00",100,"machine learning","s.k bose",2007,500);
    insert(root,"2389-125-25-25-01",200,"image processing","saswata",2016,50);
    insert(root,"2389-125-25-25-10",300,"vlsi","baruah",2017,800);
    insert(root,"2389-125-25-75-20",400,"vlsi1","baruahs",2016,700);
    insert(root,"2389-125-25-45-09",700,"data structure","benny",2012,900);
    insert(root,"2389-125-25-65-07",800,"algorithm","bahaduri",2014,60);
    int t;
    while(1){
        int choice;
        cout<< "insert --1,  increase---2,   find copies sold --3,  print --4,  exit --5"<<endl;
        cin >> choice;
        switch(choice){
            case 1:{
                string isbn,heading,name;
                int price,year,copies;
                cout<< "input isbn: ";
                cin >> isbn;
                cout<< "input cost: ";
                cin>>price;
                cout<< "input title: ";
                cin >>heading;
                cout<< "input author: ";
                cin >> name;
                cout<"input year";
                cin >> year;
                cout <<"input no. of copies sold: ";
                cin>>copies;
                insert(root,isbn,price,heading,name,year,copies);
                break;
            }
            case 2:{
                increase(root);
                break;
            }
            case 3:{
                string s;
                cout<< "give the isbn: ";
                cin >> s;
                cout << cost_search(root,s) <<endl;
                break;
            }
            case 4:{
                print(root);
                break;
            }
            case 5:
                exit(0);


        }

    }
    return 0;
}