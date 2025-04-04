// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/?envType=study-plan-v2&envId=top-interview-150

// Node structure for trie
struct trieNode{
    int children[26]; // como no cambiaremos esto, es mejor un arreglo estatico
    int childLen;
    bool isWord;
    trieNode() : isWord(false), childLen(0){ // asi se asigna el valor al momento de construir (varias too)
        fill(begin(children), end(children), -1); // assign para arreglos estaticos
    }
};

// Trie Class
class trie {
public:
    // vector de nodos, que guarda? todos los nodos 
    vector<struct trieNode> nodes;

    // insertamos raiz
    trie() : nodes(1) {} 

    // print function
    void print(){
        for(int i = 0; i < nodes.size(); i++){
            cout << "Node " << i << ": ";
            for(int j = 0; j < 26; j++){
                if(nodes[i].children[j] != -1){
                    cout << (char) ('a' + j) << " (" << nodes[i].children[j] << ") ";
                }
            }
            cout << endl;
        }
    }

    // insert a string into the trie
    void insert(const string& s){
        // star from root 
        int n = 0;
        for(const auto ch : s){
            int c = ch - 'a'; // convertimos a entero
            // create the child if not existed
            if(nodes[n].children[c] == -1){
                nodes[n].children[c] = nodes.size(); // anotamos que el hijo ch del nodo actual esta 
                nodes.push_back(trieNode());         // en la ultima posicion actual del arreglo de nodos
                nodes[n].childLen++;
            }
            n = nodes[n].children[c]; // vamos al nuevo nodo para insertar siguiente letra
        }
        nodes[n].isWord = true; // al terminar de insertar s, marcamos el nodo como el final de s
    }

    string getLCP(){
        // we go down the trie and if we find a node with 2 or more children, we break
        int n = 0; string lcp = ""; char ch;
        while(nodes[n].childLen == 1 && nodes[n].isWord == false){
            // if(nodes[n].isWord == true) break; // break if we find the end of a word
            // cout << "entrando a nodo " << n << endl; 
            for(int j = 0; j < 26; j++){
                if(nodes[n].children[j] != -1){
                    ch = (char) ('a' + j);
                    lcp.push_back(ch);
                    break;
                }
            }
            n = nodes[n].children[ch - 'a']; // we need to convert the char into an index again
        }

        return lcp;
    }

};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // create a trie with the existent words
        trie t;
        for(const auto stg : strs){
            if(stg == "") return "";
            t.insert(stg);
        }
        string lcp = t.getLCP();

        return lcp;
    }
};
