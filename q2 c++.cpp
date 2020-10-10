#include <bits/stdc++.h> 
using namespace std; 

// Structure for Trie 
struct Trie { 
	bool isEndOfWord; 
	unordered_map<char, Trie*> map; 
	int meaning; 
	// meaning is frequency
}; 

// Function to create a new Trie node 
Trie* getNewTrieNode() 
{ 
	Trie* node = new Trie; 
	node->isEndOfWord = false; 
	return node; 
} 

// Function to insert a word with its meaning 
// in the dictionary built using a Trie 
void insert(Trie*& root, string str, 
			int meaning) 
{ 

	// If root is null 
	if (root == NULL) 
		root = getNewTrieNode(); 

	Trie* temp = root; 
	for (int i = 0; i < str.length(); i++) { 
		char x = str[i]; 

		// Make a new node if there is no path 
		if (temp->map.find(x) == temp->map.end()) 
			temp->map[x] = getNewTrieNode(); 

		temp = temp->map[x]; 
	} 

	// Mark end of word and store the meaning 
	temp->isEndOfWord = true; 
	temp->meaning = meaning; 
} 

// Function to search a word in the Trie 
// and return its meaning if the word exists 
string getMeaning(Trie* root, int word,map<int,string> mp) 
{ 
    
    string pp = "-1";   
// If root is null i.e. the dictionary is empty 
	if (root == NULL) 
		return pp; 

	Trie* temp = root; 
    
    string words = mp[word];
    
	// Search a word in the Trie 
	for (int i = 0; i < words.length(); i++) { 
		temp = temp->map[words[i]]; 
		if (temp == NULL) 
			return pp; 
	} 

	// If it is the end of a valid word stored 
	// before then return its meaning 
	if (temp->isEndOfWord) 
		return words; 
		
	return pp; 
} 

// Driver code 
int main() 
{ 
	Trie* root = NULL; 
    
    map<string,int> ms;
    map<int,string> mp;
    
    int n,i,j,k;
    
    cin >> n;
    // Total number of words/strings in the dictionary
    string ss;
    
    for(i=0;i<n;i++)
    {
        // each string and its associated number (between 0 to N) stored in a map
        cin >> ss;
        cin >> j;
        ms[ss] = j;
        mp[j] = ss;
    }

	// Build the dictionary using Tries
	
	for(auto it=ms.begin();it!=ms.end();it++){
	ss = it->first;
	j = it->second;
	
	// insert each node for string with its associated value
	
	insert(root, ss, j); 

	}
	
	int word;
// word whose value is to be backtracked

	cin >> word;
	
	string result;
	
	result =  getMeaning(root,word,mp); 

    if(result=="-1")
    {
        // word is not present in the dictionary
        cout << "NO such word exists for given number" << endl;
    }
    else
    {
        // word is present in the dictionary and has a frequency j
        cout << "Word associated with " << word << " is " << result << endl;
    }
	return 0; 
}
