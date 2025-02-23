class Node {
  final Map<String, Node> childs;
  bool end;

  Node({required this.childs, required this.end});
}

class Trie {
  late final Node _root;

  Trie() {
    _root = Node(childs: {}, end: false);
  }

  void insert(String word) {
    var current = _root;

    for (int i = 0; i < word.length; i++) {
      var char = word[i];

      if (!current.childs.containsKey(char)) {
        current.childs[char] = Node(childs: {}, end: false);
      }

      current = current.childs[char]!;
    }
    current.end = true;
  }

  bool search(String word) {
    var current = _root;
    for (int i = 0; i < word.length; i++) {
      var char = word[i];

      if (!current.childs.containsKey(char)) {
        return false;
      }

      current = current.childs[char]!;
    }

    return current.end;
  }

  bool startsWith(String prefix) {
    var current = _root;
    for (int i = 0; i < prefix.length; i++) {
      var char = prefix[i];

      if (!current.childs.containsKey(char)) {
        return false;
      }

      current = current.childs[char]!;
    }

    return true;
  }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = Trie();
 * obj.insert(word);
 * bool param2 = obj.search(word);
 * bool param3 = obj.startsWith(prefix);
 */
