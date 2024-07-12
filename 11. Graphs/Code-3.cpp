// Clone a Graph
// https://leetcode.com/problems/clone-graph/

unordered_map<Node*, Node*> m;
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        Node* copy = new Node(node->val);
        m[node] = copy;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (int i = 0; i < curr->neighbors.size(); i++) {
                Node* neighbor = curr->neighbors[i];
                if (m.find(neighbor) == m.end()) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[curr]->neighbors.push_back(m[neighbor]);
            }
        }
        return copy;
    }