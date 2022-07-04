// https://leetcode.com/problems/encrypt-and-decrypt-strings/

class Encrypter {
    
    Map<Character, String> en;
    Map<String, Integer> de;

    public Encrypter(char[] keys, String[] values, String[] dictionary) {
        en = new HashMap<>();
        de = new HashMap<>();
        for (int i = 0; i < keys.length; i++) {
            en.put(keys[i], values[i]);
        }
        
        for (int i = 0; i < dictionary.length; i++) {
            String s = encrypt(dictionary[i]);
            de.put(s, de.getOrDefault(s, 0) + 1);
        }    
    }
    
    public String encrypt(String word1) {
        String ret = "";
        for (int i = 0; i < word1.length(); i++) {
            char c = word1.charAt(i);
            ret += en.getOrDefault(c, "^");
        }
        return ret;
    }
    
    public int decrypt(String word2) {
        return de.getOrDefault(word2, 0);
    }
}

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter obj = new Encrypter(keys, values, dictionary);
 * String param_1 = obj.encrypt(word1);
 * int param_2 = obj.decrypt(word2);
 */
