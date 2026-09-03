class Solution {
public:
    unordered_map<Node* , Node*> mp;
    Node* solve(Node* node){
        if(mp.count(node)) return mp[node];
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto & ngbr : node->neighbors){
            clone->neighbors.push_back(solve(ngbr));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        return solve(node);
    }
};
