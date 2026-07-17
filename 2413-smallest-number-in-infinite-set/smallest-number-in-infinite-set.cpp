class SmallestInfiniteSet {
public:
    int current;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> present;

    SmallestInfiniteSet() {
        current = 1;
    }

    int popSmallest() {
        if (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            present.erase(x);
            return x;
        }

        return current++;
    }

    void addBack(int num) {
        if (num < current && !present.count(num)) {
            pq.push(num);
            present.insert(num);
        }
    }
};