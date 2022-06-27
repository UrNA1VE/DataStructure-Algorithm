// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Map<Node, Node> m = new HashMap<>();
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        if (!m.containsKey(node)) {
            Node clone = new Node(node.val);
            m.put(node, clone);
            for (Node next: node.neighbors) {
                clone.neighbors.add(cloneGraph(next));
            }
        }
        return m.get(node);
        
        
    }
}
