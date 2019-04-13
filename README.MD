#A Star Searching Algorithm
> Reference: [Wikipedia: A* Searching Algorithm](https://en.wikipedia.org/wiki/A*_search_algorithm)
--- 
##Intro
This algorithm class is written based on the [Wikipedia: A* Searching Algorithm](https://en.wikipedia.org/wiki/A*_search_algorithm).
It is easy to complete, and hope it could help you guys.    
Any questions or advices can leave comments or [email](haocheng.zhao14@student.xjtlu.edu.cn) me. 
##Usage
### Header File
Please inlcude the _`Astar.h`_ , _`math.h`_ and _`iostream`_
````
#include <iostream>
#include <math.h>
#include "Astar.h"
````
### Define the `map`
_`char map[ROW][COL]`_ is stored in `Astar.h` class `Astar`
     
|   Characters  |   Meaning             |    
|   :----:      |   :----:              |        
|   '0'         |   Available Point     |
|   '1'         |   None-Available Point|
|   '#'         |   Start/end Point     |
|   '*'         |   Path                |
### Define the `start point` and `end point`
edit the value _`addr[2][2]`_ in `main.cpp`

## Working Pipeline:   
*   Edit the _`map[ROW][COL]`_
````
...
    char map[ROW][COL] = {
            {'0', '0', '0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', '1', '1', '0', '0', '1'},
            {'0', '0', '1', '0', '0', '0', '1', '0'},
            {'0', '0', '0', '0', '1', '1', '0', '0'},
            {'0', '1', '1', '1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '1', '0', '0', '0'},
            {'0', '1', '0', '0', '0', '0', '0', '0'},
            {'0', '1', '0', '1', '0', '0', '0', '0'},
    };
...
};
````
*   Give the value in _`addr[2][2]`_
````
int addr[2][2] = {{1, 1},
                  {7, 7}};
````
*   Declare the variable
````
    Astar astar(addr);
````
*   Calculate the path and pass the _Start Point_ and _End Point_
````
    astar.calculate();
````
*   Print the Path and Map
````
    astar.printPath();
````