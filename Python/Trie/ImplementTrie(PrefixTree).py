# https://leetcode.com/problems/implement-trie-prefix-tree/

class Node:

    def __init__(self, char=None):
        self.end = 0
        self.char = char
        self.children = {}

    def make_end(self):
        self.end = 1

    def make_child(self, child):
        self.children[child.char] = child


class Trie:

    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        start = self.root
        i = 0
        while i < len(word):
            char = word[i]
            if char in start.children:
                start = start.children[char]
                i += 1
            else:
                break

        while i < len(word):
            child = Node(word[i])
            start.make_child(child)
            start = child
            i += 1
        if i == len(word):
            start.make_end()


    def search(self, word: str) -> bool:
        i = 0
        start = self.root
        while i < len(word) and word[i] in start.children:
            start = start.children[word[i]]
            i += 1
        if i == len(word) and start.end:
            return True
        return False


    def startsWith(self, prefix: str) -> bool:
        i = 0
        start = self.root
        while i < len(prefix) and prefix[i] in start.children:
            start = start.children[prefix[i]]
            i += 1
        if i == len(prefix):
            return True
        return False


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)https://leetcode.com/problems/implement-trie-prefix-tree/
