# cpp-multiple-type-map
A wrapper for std::map allowing multiple different types in the data feild.
Not complete, but currently usable. Changes are welcome.

##### Usage:
include the hpp file.

Namespace: bx
Class: mtypemap
mtypemap functions:
  `void set<T>(std::string key, T variable)`
  `void get<T>(std::string key)`
  `bool is_set(std::string key)`
  `void remove(std::string key)`

e.g:
```c++
bx::mtypemap m;
m.set<int>("an int", 413);
m.set<double>("a double", 782.38);

m.get<int>("an int")++;

std::cout << m.get<int>("an int");

```
  
##### How it works:
Uses std::unordered_map to store a std::string key and data as a void pointer.
