class PrefixTree {
private:
    struct Node{
        vector<Node *> ch{26,nullptr};
        bool isString = false;
    };
    Node * root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * now = root;
        for(int i = 0;i<word.size();i++){
            int tmp = tolower(word[i]) - 'a';
            if(now->ch[tmp] == nullptr)
                now->ch[tmp] = new Node();
            now = now->ch[tmp];
        }
        now->isString = true;
    }
    
    bool search(string word) {
        Node * now = root;
        bool isWord;
        for(int i = 0;i<word.size();i++){
            int tmp = tolower(word[i]) - 'a';
            if(now->ch[tmp] == nullptr)
                return false;
            now = now->ch[tmp];
        }
        return now->isString;
    }
    
    bool startsWith(string prefix) {
        Node * now = root;
        for(int i = 0;i<prefix.size();i++){
            int tmp = tolower(prefix[i]) - 'a';
            if(now->ch[tmp] == nullptr)
                return false;
            now = now->ch[tmp];
        }
        return true;
    }
};
