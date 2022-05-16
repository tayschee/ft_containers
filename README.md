# ft_containers
![42](https://img.shields.io/static/v1?label=&labelColor=000000e&logo=42&message=project&color=000000&style=flate)
![Stars](https://img.shields.io/github/stars/tayschee/ft_containers?style=social)

## Summary
- [About The Project](#about-the-project)
- [Getting Started](#getting-started)
  - [Installation](#installation)
  - [Use Library](#use-library)
- [Knew Difference](knew-difference)
  - [Vector](#vector)
  - [List](#list)
  - [Map](#map)
  - [Stack](#stack)
  - [Queue](#queue)

## About The Project
[ft_containers](https://cdn.intra.42.fr/pdf/pdf/47624/fr.subject.pdf) is project of 42Paris to learn C++ \
It consist to reproduce containers [vector](https://www.cplusplus.com/reference/vector/vector/),
                                  [list](https://www.cplusplus.com/reference/list/list/),
                                  [map](https://www.cplusplus.com/reference/map/map/),
                                  [queue](https://www.cplusplus.com/reference/queue/queue/)
                                  and [stack](https://www.cplusplus.com/reference/stack/stack/)

## Getting Started
### Installation
Clone and move into clone directory:
```
git clone https://github.com/tayschee/ft_containers.git ft_containers
cd ft_containers
```

### Use Library

To use one of those containers in your code, add to your compilation (ex: clang++ -c) :
```
-I path/to/include/
```

## Knew difference
### Vector
Copy of vector didn't introduce specialization for boolean

### List
Like the original list is double linked list with dummy node
method sort() is not optimize

### Map
Contrary to the original my copy is not a red black tree simply a sort binary tree

### Stack
Contrary to the original it doesn't take deque<T> in default container because i didn't code it
 
### Queue
Same than stack
