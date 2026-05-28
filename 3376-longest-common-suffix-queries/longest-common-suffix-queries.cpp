class Solution {
public:

    struct trieNode {

        int idx;
        trieNode* children[26];

        trieNode() {
            idx = 0;

            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }

        ~trieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    trieNode* getNode(int i) {

        trieNode* temp = new trieNode();
        temp->idx = i;

        return temp;
    }

    void insert(trieNode* root, int i, vector<string>& wordsContainer) {

        trieNode* crawler = root;

        string word = wordsContainer[i];
        int n = word.size();

        for (int j = n - 1; j >= 0; j--) {

            int ch_idx = word[j] - 'a';

            if (crawler->children[ch_idx] == NULL) {
                crawler->children[ch_idx] = getNode(i);
            }

            crawler = crawler->children[ch_idx];

            int currIdx = crawler->idx;

            if (wordsContainer[currIdx].size() > n ||
               (wordsContainer[currIdx].size() == n &&
                i < currIdx)) {

                crawler->idx = i;
            }
        }
    }

    int search(trieNode* root, string word) {

        trieNode* crawler = root;

        int result_idx = root->idx;

        for (int i = word.size() - 1; i >= 0; i--) {

            int ch_idx = word[i] - 'a';

            if (crawler->children[ch_idx] == NULL) {
                return result_idx;
            }

            crawler = crawler->children[ch_idx];

            result_idx = crawler->idx;
        }

        return result_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        int m = wordsContainer.size();

        trieNode* root = getNode(0);

        // Store globally smallest string index
        for (int i = 0; i < m; i++) {

            int idx = root->idx;

            if (wordsContainer[i].size() < wordsContainer[idx].size() ||
               (wordsContainer[i].size() == wordsContainer[idx].size() &&
                i < idx)) {

                root->idx = i;
            }
        }

        for (int i = 0; i < m; i++) {
            insert(root, i, wordsContainer);
        }

        vector<int> result;

        for (auto& q : wordsQuery) {
            result.push_back(search(root, q));
        }

        delete root;

        return result;
    }
};