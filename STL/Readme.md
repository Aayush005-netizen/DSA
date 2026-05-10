# C++ STL (Standard Template Library)

This folder covers the essential STL containers, iterators, and algorithms used in competitive programming and DSA problem solving.

---

## Table of Contents

1. [Pair](#pair)
2. [Vector](#vector)
3. [List](#list)
4. [Deque](#deque)
5. [Stack](#stack)
6. [Queue](#queue)
7. [Priority Queue](#priority-queue)
8. [Set](#set)
9. [Multiset](#multiset)
10. [Unordered Set](#unordered-set)
11. [Map](#map)
12. [Multimap](#multimap)
13. [Unordered Map](#unordered-map)
14. [Lower Bound & Upper Bound](#lower-bound--upper-bound)

---

## Pair

A `pair` stores two values together as a single unit. The two values can be of different types.

```cpp
pair<int, int> p = {1, 3};
cout << p.first << " " << p.second;   // 1 3

// Nested pair
pair<int, pair<int, int>> p3 = {1, {2, 3}};
cout << p3.first << " " << p3.second.first << " " << p3.second.second;  // 1 2 3

// Array of pairs
pair<int, int> arr[] = {{1,2}, {3,4}, {5,6}};
```

**Key points:**
- Access elements using `.first` and `.second`
- Pairs can be nested for storing more than two values
- Useful in maps, sorting, and graph problems (storing edges as pairs)

---

## Vector

A `vector` is a dynamic array that can grow and shrink in size. It is the most commonly used STL container.

```cpp
vector<int> v;
v.push_back(1);       // adds to end
v.emplace_back(2);    // more efficient than push_back, constructs in place

// Initialization
vector<int> v1(5, 10);   // {10, 10, 10, 10, 10}
vector<int> v2(5);        // {0, 0, 0, 0, 0}
vector<int> v3(v1);       // copy of v1
```

### Iterators

```cpp
vector<int> v = {1, 2, 3, 4, 5};

auto it = v.begin();   // points to first element
auto it = v.end();     // points to position AFTER last element
auto it = v.rbegin();  // reverse iterator, points to last element
auto it = v.rend();    // reverse iterator end
```

### Traversal

```cpp
// Using explicit iterator type
for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    cout << *it << " ";

// Using auto (cleaner)
for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << " ";

// Range-based for loop (simplest)
for (auto x : v)
    cout << x << " ";
```

### Common Operations

```cpp
v[0];          // access by index (no bounds check)
v.at(0);       // access by index (with bounds check, throws exception)
v.back();      // last element
v.front();     // first element
v.size();      // number of elements
v.capacity();  // allocated storage size (grows in powers of 2)
v.empty();     // true if empty

v.pop_back();                          // remove last element
v.erase(v.begin() + 1);               // erase element at index 1
v.erase(v.begin() + 1, v.begin() + 4); // erase range [1, 4)

v.insert(v.begin(), 300);             // insert at beginning
v.insert(v.begin() + 1, 2, 10);      // insert 2 copies of 10 at index 1
v.insert(v.begin(), other.begin(), other.end()); // insert another vector

v1.swap(v2);   // swap contents of two vectors
v.clear();     // remove all elements (capacity unchanged)
```

### Capacity vs Size

- `size()` — number of elements currently stored
- `capacity()` — total allocated memory (doubles when exceeded to avoid frequent reallocation)

---

## List

A `list` is a **doubly linked list**. Unlike vector, it allows efficient insertion and deletion at any position, but does not support random access.

```cpp
list<int> ls;
ls.push_back(1);    // insert at end
ls.push_front(2);   // insert at beginning
ls.emplace_back(3);
ls.emplace_front(4);
```

**When to use over vector:** When you need frequent insertions/deletions in the middle of the container. Random access (`ls[i]`) is not supported.

---

## Deque

A `deque` (Double Ended Queue) allows efficient insertion and deletion at **both** ends.

```cpp
deque<int> dq;
dq.push_back(1);    // insert at end
dq.push_front(2);   // insert at front
dq.emplace_back(3);
dq.emplace_front(4);

dq.pop_back();      // remove from end
dq.pop_front();     // remove from front

dq.back();          // access last element
dq.front();         // access first element
```

**Difference from vector:** Vector only efficiently adds/removes at the end. Deque efficiently handles both ends.

---

## Stack

A `stack` follows the **LIFO (Last In First Out)** principle. Think of a stack of plates.

```cpp
stack<int> st;
st.push(1);    // insert at top
st.push(2);
st.push(3);

st.pop();           // remove top element
st.top();           // access top element (without removing)
st.empty();         // true if empty
st.size();          // number of elements

stack<int> st1, st2;
st1.swap(st2);
```

**Use cases:** Function call stack, undo operations, balanced parentheses problems.

---

## Queue

A `queue` follows the **FIFO (First In First Out)** principle. Think of a line at a counter.

```cpp
queue<int> q;
q.push(1);     // insert at back
q.push(2);
q.emplace(3);

q.pop();        // remove from front
q.front();      // access front element
q.back();       // access back element
q.empty();      // true if empty
q.size();       // number of elements

q.back() += 10;   // modify back element
q.front() += 20;  // modify front element
```

**Use cases:** BFS traversal, scheduling problems, sliding window.

---

## Priority Queue

A `priority_queue` gives access to the **largest (or smallest) element** efficiently. By default it is a **max-heap**.

```cpp
priority_queue<int> pq;   // max-heap (default)
pq.push(1);
pq.push(2);
pq.emplace(3);   // {3, 2, 1} internally

pq.pop();         // removes the maximum element (3)
pq.top();         // returns the maximum element (2 after pop)
pq.empty();
pq.size();
```

### Min-Heap

```cpp
priority_queue<int, vector<int>, greater<int>> minpq;
minpq.push(3);
minpq.push(1);
minpq.push(2);
cout << minpq.top();  // 1 (minimum element)
```

**Use cases:** Dijkstra's algorithm, scheduling, finding k-th largest/smallest element.

---

## Set

A `set` stores **unique elements in sorted order**. Internally implemented as a balanced BST (Red-Black Tree).

```cpp
set<int> s;
s.insert(1);
s.insert(2);
s.insert(3);
s.insert(2);   // ignored, duplicates not allowed

s.erase(2);                        // remove element 2
s.find(3);                         // returns iterator to 3, or s.end() if not found
s.count(1);                        // returns 0 or 1 (no duplicates)
s.empty();
s.size();

// Range erase
auto it1 = s.find(2);
auto it2 = s.find(4);
s.erase(it1, it2);   // removes [it1, it2), i.e., 2 and 3 but NOT 4

// Binary search on set
s.lower_bound(2);    // iterator to first element >= 2
s.upper_bound(3);    // iterator to first element > 3
```

**Time complexity:** O(log n) for insert, erase, find.

---

## Multiset

A `multiset` is like a set but **allows duplicate elements**, still stored in sorted order.

```cpp
multiset<int> ms;
ms.insert(1);
ms.insert(1);
ms.insert(1);   // {1, 1, 1}

ms.erase(1);    // CAREFUL: removes ALL occurrences of 1

// To remove only ONE occurrence
ms.erase(ms.find(1));   // removes a single 1

// To remove a range
ms.erase(ms.find(1), ms.find(1) + 2);  // removes two occurrences

int cnt = ms.count(1);   // returns how many times 1 appears
```

**Common pitfall:** `ms.erase(value)` removes **all** occurrences. Use `ms.erase(ms.find(value))` to remove just one.

---

## Unordered Set

An `unordered_set` stores **unique elements with no guaranteed order**. Internally uses a hash table.

```cpp
unordered_set<int> us;
us.insert(1);
us.erase(1);
us.find(1);
us.count(1);
```

**Note:** `lower_bound()` and `upper_bound()` are NOT available as there is no ordering.

| Operation | set | unordered_set |
|---|---|---|
| Insert | O(log n) | O(1) avg, O(n) worst |
| Find | O(log n) | O(1) avg, O(n) worst |
| Erase | O(log n) | O(1) avg, O(n) worst |

**Use unordered_set** when you need fast lookups and don't care about order.

---

## Map

A `map` stores **key-value pairs in sorted order by key**. Each key is unique. Internally a balanced BST.

```cpp
map<int, int> mpp;

mpp[1] = 2;            // insert or update key 1
mpp.insert({3, 4});    // insert pair
mpp.emplace(5, 6);     // construct in place

// Accessing
cout << mpp[1];        // returns value for key 1
cout << mpp[5];        // if key 5 not found, INSERTS (5, 0) and returns 0

// Finding safely (without auto-insert)
auto it = mpp.find(3);
if (it != mpp.end())
    cout << it->second;   // prints 4

// Complex key/value types
map<int, pair<int,int>> mpp2;
map<pair<int,int>, int> mpp3;

mpp2[1] = {2, 3};
mpp3[{2, 3}] = 10;
```

**Key pitfall:** Using `mpp[key]` when key doesn't exist **inserts a default value**. Use `find()` to safely check.

**Time complexity:** O(log n) for all operations.

---

## Multimap

A `multimap` is like a map but **allows duplicate keys**.

```cpp
multimap<int, int> mm;
mm.insert({1, 10});
mm.insert({1, 20});   // allowed, same key different value

// mpp[key] = value syntax NOT allowed in multimap
// Use find() to get a range of values for a key
auto range = mm.equal_range(1);
for (auto it = range.first; it != range.second; it++)
    cout << it->second << " ";   // prints 10 20
```

---

## Unordered Map

An `unordered_map` stores key-value pairs with **no guaranteed key order**. Uses a hash table internally.

```cpp
unordered_map<int, int> ump;
ump[1] = 10;
ump.insert({2, 20});
ump.find(1);
ump.erase(1);
ump.count(2);   // 0 or 1
```

**Note:** `lower_bound()` and `upper_bound()` are NOT available.

| Operation | map | unordered_map |
|---|---|---|
| Insert | O(log n) | O(1) avg, O(n) worst |
| Find | O(log n) | O(1) avg, O(n) worst |
| Erase | O(log n) | O(1) avg, O(n) worst |

**Use unordered_map** when you need fast key lookups and don't need sorted order.

---

## Lower Bound & Upper Bound

These are binary search functions that work on **sorted arrays or containers**.

```cpp
int arr[] = {1, 4, 4, 4, 4, 9, 9, 10, 11};
int n = sizeof(arr) / sizeof(arr[0]);
```

### lower_bound

Returns an iterator/pointer to the **first element >= x**.

```cpp
int ind = lower_bound(arr, arr + n, x) - arr;
```

### upper_bound

Returns an iterator/pointer to the **first element > x**.

```cpp
int ind = upper_bound(arr, arr + n, x) - arr;
```

### Use Cases

**Q1. First occurrence of x:**
```cpp
int ind = lower_bound(arr, arr + n, x) - arr;
if (ind != n && arr[ind] == x) return ind;
else return -1;
```

**Q2. Last occurrence of x:**
```cpp
int ind = upper_bound(arr, arr + n, x) - arr;
ind--;
if (ind >= 0 && arr[ind] == x) return ind;
else return -1;
```

**Q3. Largest number smaller than x (strict lower bound):**
```cpp
int ind = lower_bound(arr, arr + n, x) - arr;
if (ind > 0) return arr[ind - 1];
else return -1;
```

**Q4. Smallest number greater than x (strict upper bound):**
```cpp
int ind = upper_bound(arr, arr + n, x) - arr;
if (ind != n) return arr[ind];
else return -1;
```

### Visual Summary

For array `{1, 4, 4, 4, 4, 9, 9, 10, 11}` and x = 4:

```
lower_bound(4) → points to first 4  (index 1)
upper_bound(4) → points to 9        (index 5, first element > 4)
```

**Time complexity:** O(log n) — uses binary search internally.

---

## Quick Reference — Complexity Summary

| Container | Insert | Delete | Search | Order |
|---|---|---|---|---|
| vector | O(1) amortized | O(n) | O(n) | Insertion order |
| list | O(1) | O(1) | O(n) | Insertion order |
| deque | O(1) both ends | O(1) both ends | O(n) | Insertion order |
| stack | O(1) | O(1) | — | LIFO |
| queue | O(1) | O(1) | — | FIFO |
| priority_queue | O(log n) | O(log n) | O(1) top | Max/Min heap |
| set | O(log n) | O(log n) | O(log n) | Sorted |
| unordered_set | O(1) avg | O(1) avg | O(1) avg | No order |
| map | O(log n) | O(log n) | O(log n) | Sorted by key |
| unordered_map | O(1) avg | O(1) avg | O(1) avg | No order |
