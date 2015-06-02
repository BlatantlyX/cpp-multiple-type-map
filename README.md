# cpp-multiple-type-map
A wrapper for std::map allowing multiple different types in the data feild.

##### Usage:
include the hpp file.

* Namespace: bx
* Class: mtypemap<KeyType>
* mtypemap functions:
  * `void set<VariableType>(std::string key, T variable)`
  * `T& get<VariableType>(std::string key)`
  * `bool is_set(std::string key)`
  * `void remove(std::string key)`

e.g:
```c++
bx::mtypemap<std::string> m;
m.set<int>("an int", 413);
m.set<double>("a double", 782.38);

m.get<int>("an int")++;

std::cout << m.get<int>("an int");

```
  
##### How it works:
Uses std::unordered_map to store a key and data, where data is a void pointer.
