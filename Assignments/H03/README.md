## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)

- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!)**, order the algorithms from fastest to slowest.<br />
  O(1) <br /> 
  O(logn) <br /> 
  O(n)<br /> 
  O(nlogn)<br /> 
  0(n<sup>2</sup>)<br /> 
  O(n!)
- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program? <br /> 
  4 times as long so 40 seconds

- Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**
- 1) Finding the max element in an unordered stack would require ___O(n)______ operations?
- 2) Finding the min element in an unordered queue would require ___O(n)______ operations?
- 3) Finding some element in some Binary Search Tree would require ___O(h)______ operations?
- 4) Finding some element in a balanced Binary Search Tree would require __O(logn)______ operations?
- 5) Finding some element in an ordered linked list would require __O(n)______ operations (worst case)?
- 6) Finding some element in an ordered linked list would require ___O(n/2)______ operations (average case)?
- 7) Finding some element in an unordered linked list would require ___O(n)______ operations (worst case)?


- 8) For each of the following, count the number of operations where some_statement is executed based on the loops

- 8A) n^2 - outer is n, inner is n
```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
- 8B) n^2 - outer is n/2, inner is n, remove 1/2 (constant)
```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```

- 8C) nlogn - outer is logn, inner is n
```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```

At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm?

In each of the following examples, please choose the best data structure(s).
- 9) Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- 10) Note that there may not be one clear answer.

- 10) You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added.
  list - every new post will be added to the list
- 11) You need to store undo/redo operations in a word processor.<br />
  stack - a new change will be pushed onto the stack and poped off if undone
- 12) You need to evaluate an expression (i.e., parse).<br />
  tree - could use a binary tree were the left childs hold the operation to be performed on sibling
- 13) You need to store the friendship information on a social networking site. I.e., who is friends with who.<br />
  graph - can easily store relationships from person to person
- 14) You need to store an image (1000 by 1000 pixels) as a bitmap.<br />
  array - can store the information for every pixels in a 2d array
- 15) To implement printer spooler so that jobs can be printed in the order of their arrival.<br />
  queue - first jobs sents will performed first (fifo)
- 16) To implement back functionality in the internet browser.<br />
  stack - a new page will pushed onto the stack and pressing the back button will pop current off stack
- 17) To store the possible moves in a chess game.<br />
  set - can hold multiple childs that can be represented as moves
- 18) To store a set of fixed key words which are referenced very frequently.<br />
  hash table
- 19) To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)<br />
  - queue - first to order, first to eat
- 20) To store the genealogy information of biological species.<br />
  graph - species with common info will both point to it
- 21) To store an alphabetized list of names in order to look up quickly.<br />
  hash table
