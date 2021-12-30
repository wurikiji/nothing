# Boost library

You should install boost library to compile `prototype` examples properly.
And append `-lboost_serialization` to your compiler options. 
You might need to configure your c++ include path and library path.
Here's my compile command. 

```sh
clang++ --std=c++17 -I{PATH_TO_BOOST_HEADER} -L{PATH_TO_BOOST_LIBRARY} -lboost_serailization {SOURCE_FILE} -o {EXECUTABLE_NAME}
```