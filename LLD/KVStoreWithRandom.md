

##

##

```java
import java.io.*;
import java.util.List;
import java.util.Map;
import java.util.*;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.core.JsonProcessingException;

// V get(K) - just get it from hashmap - O(1)
// void put(K, V) - Add k/v to hashmap - O(1) and Add K to an auxillary array - O(1) 
// (K,V) getRandom() - First get random int in [0..list.size()-1] -> use this random index's key to get hashmap k/v -> O(1)

// no limitation on key type, no limitation on value type
class KVStore<K,V> {
    
    Map<K,V> map = new HashMap<>();
    List<K> keys = new ArrayList<>();
    
    public V get(K key) {
        return map.get(key);
    }
    
    public void put(K key, V value) {
        // what if we already have a key in the keys list?
        // We add K key to the list only if it is not present in map.contains(key)
        if(map.containsKey(key) == false) { // key not present in map, we are seeing it for first time
            keys.add(key);
        }
        map.put(key, value);
    }
    
    public Map.Entry<K,V> getRandom() {
        if(map.isEmpty()) {
            return null;
        }
        int randIdx = (int)(Math.random() * keys.size());
        // System.out.println("randIdx - "+randIdx);
        K randKey = keys.get(randIdx);
        // System.out.println(" randKey = " + randKey);
        Map.Entry<K,V> randEntry = new AbstractMap.SimpleEntry(randKey,map.get(randKey));
        return randEntry;
    }
    
    // Map<K,V>.Entry
    // Map.Entry<K,V>
}

// Main class should be named 'Solution'
class Solution {
    public static void main(String[] args) {
        System.out.println("Hello, World");
        
        KVStore<String, String> kvstore = new KVStore();
        
        System.out.println("getRandom() on empty store = " + kvstore.getRandom());
        
        kvstore.put("a", "b");
        kvstore.put("b", "c");
        
        System.out.println("getRandom() on store = " + kvstore.getRandom());
        System.out.println("getRandom() on store = " + kvstore.getRandom());
        kvstore.put("a", "z");
        
        System.out.println(kvstore.getRandom());// b=c
        
        System.out.println(kvstore.get("a"));//b
        System.out.println(kvstore.get("d"));// null
        
        System.out.println(kvstore.getRandom());// b=c
        
        int areturned = 0;
        int breturned = 0;
        for(int i=0;i<100;i++) {
            Map.Entry<String,String> entry = kvstore.getRandom();
            if(entry.getKey().equals("a")) {
                areturned++;
            }
            if(entry.getKey().equals("b")) {
                breturned++;
            }
        }
        
        System.out.println(" a returned = " + areturned + " breturned = " + breturned);
    }
}

```