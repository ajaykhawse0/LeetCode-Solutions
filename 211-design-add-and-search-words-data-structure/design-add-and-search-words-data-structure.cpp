class Node{
    public:
    Node*links[26];
    bool flag = false;

    bool containsKey(char c){
        return (links[c-'a']!=NULL);
    }

    void put(char c,Node*node){
     links[c-'a'] = node;
    }

    Node*get(char c){
        return links[c-'a'];
    }

    void setEnd(){
        flag =  true;
    }

    bool isEnd(){
        return flag;
    }

};


class WordDictionary {
public: Node*root;
    WordDictionary() {
        root = new Node();
    }
  
    void addWord(string word) {
         Node*node = root;

        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());//point to empty(new) trie
            }
           node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool dfs(string &word,int idx,Node*curr){
        if(idx==word.size())return curr->isEnd();

        char c = word[idx];

        if(c=='.'){
            for(auto child:curr->links){
                if(child && dfs(word,idx+1,child))return true;
            }
            return false;
        }
        

        if(!curr->containsKey(c))return false;

        return dfs(word,idx+1,curr->links[c-'a']);
    }
    bool search(string word) {
       return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */