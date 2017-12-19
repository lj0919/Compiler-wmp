#include <iostream>
#include <vector>
#include<string>
#include<string.h>
using namespace std;
class Node {
public:
    int type;//1:stmt 2:expr 3:val 4:var 5:stmts 6: type
    string var_name;//var
    string value;
    string node_name;//stmt expr
    string type_name;//type also needs mark
    vector<Node*> children;
    Node(){
    }
    Node(Node* child,string n_name){
    	children.push_back(child);
    	node_name=n_name;
    }
    Node(Node* child,int tp,string n_name){
    	children.push_back(child);
    	node_name=n_name;
    	type=tp;
    }
    Node(Node* child,string tp_name,int tp,string n_name){
    	children.push_back(child);
    	node_name=n_name;
    	type=tp;
        type_name=tp_name;
    }
    Node(Node* child1,Node* child2,string tp_name,int tp,string n_name){
    	children.push_back(child1);
    	children.push_back(child2);
    	node_name=n_name;
    	type=tp;
        type_name=tp_name;
    }
    Node(int tp,string n_name){
    	type=tp;
    	node_name=n_name;
    }
     Node(Node* child1,Node* child2,int tp,string n_name){
    	children.push_back(child1);
    	children.push_back(child2);
    	node_name=n_name;
    }
    Node(Node* child1,Node* child2,string n_name){
    	children.push_back(child1);
    	children.push_back(child2);
    	node_name=n_name;
    }
    Node(string n_name){
    	node_name=n_name;
    }
    void addChild(Node* child){
        children.push_back(child);
    }
    void addAllChild(Node* node){
    	for(int i=0;i<node->children.size();i++){
    		children.push_back(node->children[i]);
    	}
    }
};