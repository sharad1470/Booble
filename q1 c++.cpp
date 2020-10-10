#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Node{
	struct Node *children[256];
	string  frequency;
};
struct Node *makeNode(){
	struct Node *newNode = new Node;
	newNode->frequency = "-1";
	for(int i = 0; i < 26; i++ ){
		newNode->children[i] = NULL;
	}
	return  newNode;
}
void addWord(struct Node *root,string word,string frequency){
		
		for(int i = 0; i < word.length(); i++){
			//cout<<word[i]<<"-----";
			if(!root->children[(int)word[i]]){
				root->children[(int)word[i] ]= makeNode();
				//cout<<word[i]<<"\n";
			}
			root = root->children[(int)word[i]];
		}
		root->frequency = frequency;
		//cout<<"frequecy"<<root->frequency<<"\n";
}
 string search(struct Node *root, string searchWord){
 	//cout<<searchWord<<"\n";
 	for(int i = 0; i < searchWord.length(); i++){
 		if(!root->children[(int)searchWord[i]]){
 			//cout<<searchWord[i]<<"\n";
 			 return "-1";
		 }
		 root = root->children[(int)searchWord[i]];
	 }
	 //cout<<searchWord<<"--"<<root->frequency<<"\n";
	 return root->frequency;
 }

int main(){
	int count = 0;
	struct Node *root = makeNode();
	string record,word,frequency,choice = "-1";
	ifstream dictionary("EnglishDictionary.csv");
	if(dictionary.is_open()){
		while(getline(dictionary,record)){
			word = record.substr(0,record.find(','));
			frequency = record.substr(record.find(',')+1,record.length());
			//cout<<frequency<<"\n";
			addWord(root,word,frequency);
			//cout<<++count<<"\n";
		}
		cout << "ENTER 1 to exit or TYPE the word to be searched:\n INPUT:";
		cin>>choice;
		while(choice != "1" ){
			string res = search(root,choice);
			if(res == "-1")
				cout<<"NO\n";
			else
				cout<<"YES "<<res<<"\n"; 
			cout<< "INPUT:";
			cin>>choice;
		}
	}
	
	return 0;
}
