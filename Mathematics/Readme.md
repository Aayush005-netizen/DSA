# DSA Solutions

This folder contains solutions to various DSA problems from LeetCode and Coding Ninja platforms, covering number theory, bit manipulation, arrays, and math-based problems.

---

## Table of Contents

1. [Print All Divisors of a Number](#1-print-all-divisors-of-a-number)
2. [Three Divisors](#2-three-divisors---leetcode-1952)
3. [Four Divisors](#3-four-divisors---leetcode-1390)
4. [Greatest Common Divisor](#4-greatest-common-divisor)
5. [Find Prime Numbers (Sieve)](#5-find-prime-numbers)
6. [All Prime Numbers (Brute Force)](#6-all-prime-numbers-brute-force)
7. [Megaprime Numbers](#7-megaprime-numbers)
8. [Complete Prime Number](#8-complete-prime-number---leetcode-3765)
9. [Two Sum](#9-two-sum---leetcode-1)
10. [Contains Duplicate](#10-contains-duplicate---leetcode-217)
11. [Missing Number](#11-missing-number---leetcode-268)
12. [Find All Numbers Disappeared in an Array](#12-find-all-numbers-disappeared-in-an-array---leetcode-448)
13. [Subtract the Product and Sum of Digits](#13-subtract-the-product-and-sum-of-digits---leetcode-1281)
14. [Reverse Integer](#14-reverse-integer---leetcode-7)
15. [Palindrome Number](#15-palindrome-number---leetcode-9)
16. [Number of 1 Bits](#16-number-of-1-bits---leetcode-191)
17. [Power of Two](#17-power-of-two---leetcode-231)
18. [Complement of Base 10 Integer](#18-complement-of-base-10-integer---leetcode-1009)

---

## 1. Print All Divisors of a Number

**Platform:** Coding Ninjas  
**Difficulty:** Easy  
**File:** `Print_all_Divisors_of_a_number.cpp`

### Problem
Given an integer N, return all divisors of N in ascending order.

### Key Concept — Square Root Optimization
Divisors come in **pairs**. If `i` divides N, then `N/i` also divides N. So we only loop up to √N and collect both at once, giving O(√N) instead of O(N).

For N = 10: pairs are (1,10) and (2,5) → found at i=1 and i=2.

### Approach
1. Count divisors using the pairs trick
2. Allocate array of that size
3. Fill the array with both elements of each pair
4. Sort the array (pairs are added out of order)
5. Set `size` reference so the caller knows how many elements there are

```cpp
int* printDivisors(int n, int &size) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) count++;   // avoid double counting perfect squares
        }
    }

    int* arr = new int[count];
    int idx = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            arr[idx++] = i;
            if (i != n / i)
                arr[idx++] = n / i;
        }
    }

    sort(arr, arr + count);
    size = count;
    return arr;
}
```

### Why `int*` and `int &size`?
- `int*` — returns a pointer to a dynamically allocated array (can't return plain arrays in C++)
- `int &size` — passed by reference so the function can write back the count to the caller

### Complexity
| | Complexity |
|---|---|
| Time | O(√N) |
| Space | O(number of divisors) |

---

## 2. Three Divisors — LeetCode 1952

**Platform:** LeetCode  
**Difficulty:** Easy  
**File:** `1952__Three_Divisors.cpp`

### Problem
Return `true` if N has exactly three positive divisors.

### Key Insight
A number has exactly 3 divisors only if it is the **square of a prime** (e.g., 4 = 2², 9 = 3², 25 = 5²). Their divisors are always: 1, the prime itself, and the square.

### Approach
Count starts at 2 (1 and N are always divisors). Loop from 2 to N/2 and count additional divisors. Early exit if count exceeds 3.

```cpp
bool isThree(int n) {
    int count = 2;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) count++;
        if (count > 3) return false;
    }
    return count == 3;
}
```

### Complexity
| | Complexity |
|---|---|
| Time | O(N) |
| Space | O(1) |

---

## 3. Four Divisors — LeetCode 1390

**Platform:** LeetCode  
**Difficulty:** Medium  
**File:** `1390__Four_Divisors.cpp`

### Problem
Given an array, return the sum of divisors of numbers that have **exactly four divisors**. Return 0 if none exist.

### Approach
For each number, count its divisors. 1 and the number itself are always included (result starts as `1 + num`, count starts at 2). Loop from 2 to num/2. If count ever exceeds 4, return 0 immediately (early exit optimization).

```cpp
int sum_needed_elements(int num) {
    int count = 2;
    int result = 1 + num;
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            result += i;
            count++;
        }
        if (count > 4) return 0;   // early exit
    }
    return (count == 4) ? result : 0;
}

int sumFourDivisors(vector<int>& nums) {
    int result = 0;
    for (auto it : nums)
        result += sum_needed_elements(it);
    return result;
}
```

### Complexity
| | Complexity |
|---|---|
| Time | O(N × M) where M = max value in nums |
| Space | O(1) |

---

## 4. Greatest Common Divisor

**Platform:** Coding Ninjas  
**Difficulty:** Easy  
**File:** `greatest_common_divisor.cpp`

### Problem
Find the GCD of two numbers X and Y.

### Key Concept — Euclidean Algorithm
Based on the mathematical fact:
> GCD(x, y) = GCD(y, x % y)

The original form uses subtraction: GCD(x,y) = GCD(x-y, y). The modulo version compresses repeated subtractions into one step, making it much faster.

**If x < y**, the first iteration automatically swaps them since `x % y = x` when x < y.

```cpp
int findGcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}
```

### Dry Run — GCD(48, 18)
| Step | x | y | x % y |
|---|---|---|---|
| Start | 48 | 18 | 12 |
| 1 | 18 | 12 | 6 |
| 2 | 12 | 6 | 0 |
| 3 | 6 | 0 | — |

Returns **6**.

### Complexity
| | Complexity |
|---|---|
| Time | O(log(min(x,y))) |
| Space | O(1) |

---

## 5. Find Prime Numbers

**Platform:** Coding Ninjas  
**Difficulty:** Easy  
**File:** `Find_prime_numbers.cpp`

### Problem
Print all prime numbers from 2 to N. (N can be up to 10^7)

### Key Concept — Sieve of Eratosthenes
Instead of checking each number individually, mark all **multiples** of every prime as composite. Start marking from `i*i` because smaller multiples were already handled by earlier primes.

```cpp
vector<int> primeNumbersTillN(int N) {
    vector<bool> sieve(N + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= N; j += i)
                sieve[j] = false;
        }
    }

    vector<int> v;
    for (int i = 2; i <= N; i++)
        if (sieve[i]) v.emplace_back(i);
    return v;
}
```

### Why start marking from `i*i`?
For i=5, multiples 10, 15, 20, 25... — but 10=2×5 was already marked by i=2, and 15=3×5 was already marked by i=3. So we safely start from 25 = 5×5.

### Complexity
| | Complexity |
|---|---|
| Time | O(N log log N) |
| Space | O(N) |

---

## 6. All Prime Numbers (Brute Force)

**Platform:** Coding Ninjas  
**Difficulty:** Easy  
**File:** `All_prime_numbers.cpp`

### Problem
Print all prime numbers from 2 to N. (N up to 100)

### Approach
Simple brute force — check each number individually using trial division up to √num.

```cpp
bool is_prime(int num) {
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return false;
    return true;
}
```

### When to use this vs Sieve
- N ≤ 1000 → brute force is fine
- N > 10^4 → use Sieve (this file's approach would TLE)

### Complexity
| | Complexity |
|---|---|
| Time | O(N × √N) |
| Space | O(1) |

---

## 7. Megaprime Numbers

**Platform:** Coding Ninjas  
**Difficulty:** Medium  
**File:** `MegaPrime_Numbers.cpp`

### Problem
Count megaprime numbers in range [Left, Right]. A megaprime is a prime number whose **every individual digit is also prime** (only digits 2, 3, 5, 7 are prime).

### Examples
- 53 → prime ✅, digits 5 and 3 both prime ✅ → megaprime
- 13 → prime ✅, digit 1 not prime ❌ → not megaprime
- 23 → prime ✅, digits 2 and 3 both prime ✅ → megaprime

### Approach
1. Build a sieve up to `right`
2. For each number in [left, right], check if it's prime AND all its digits are in {2,3,5,7}

```cpp
bool allDigitsPrime(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 2 && digit != 3 && digit != 5 && digit != 7)
            return false;
        num /= 10;
    }
    return true;
}

int countMegaPrimeNumber(int left, int right) {
    vector<bool> sieve(right + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= right; i++)
        if (sieve[i])
            for (int j = i * i; j <= right; j += i)
                sieve[j] = false;

    int count = 0;
    for (int i = left; i <= right; i++)
        if (sieve[i] && allDigitsPrime(i)) count++;
    return count;
}
```

### Complexity
| | Complexity |
|---|---|
| Time | O(right × log log right) for sieve + O(right - left) for counting |
| Space | O(right) |

---

## 8. Complete Prime Number — LeetCode 3765

**Platform:** LeetCode  
**Difficulty:** Easy  
**File:** `3765__Complete_Prime_Number.cpp`

### Problem
A number is a Complete Prime if every **prefix** and every **suffix** is also prime.

### Examples
- 23: Prefixes → 2✅, 23✅ | Suffixes → 3✅, 23✅ → **true**
- 233: Prefixes → 2✅, 23✅, 233✅ | Suffixes → 3✅, 33❌ → **false**
- 39: Prefixes → 3✅, 39❌ → **false**

### Approach — Pure Math (no strings)

**Prefixes:** Repeatedly divide by 10 to shrink from the right.
**Suffixes:** Build up a divisor (10^k) and use modulo to extract last k digits.

```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

bool completePrime(int num) {
    // Check all prefixes: 233 → 23 → 2
    int prefix = num;
    while (prefix > 0) {
        if (!isPrime(prefix)) return false;
        prefix /= 10;
    }

    // Check all suffixes: 233 → 33 → 3
    int divisor = 1;
    while (divisor <= num) divisor *= 10;

    while (divisor > 10) {
        divisor /= 10;
        int suffix = num % divisor;
        if (!isPrime(suffix)) return false;
    }

    return true;
}
```

### Complexity
| | Complexity |
|---|---|
| Time | O(d × √num) where d = number of digits |
| Space | O(1) |

---

## 9. Two Sum — LeetCode 1

**Platform:** LeetCode  
**Difficulty:** Easy  
**Language:** Python  
**File:** `1__Two_Sum.cpp`

### Problem
Return indices of two numbers that add up to target.

### Key Concept — HashMap (one pass)
For each number, compute `diff = target - num`. If `diff` was seen before, we found our pair. Otherwise store current number and its index.

```python
def twoSum(self, nums, target):
    prev = {}
    for i, n in enumerate(nums):
        diff = target - n
        if diff in prev:
            return (prev[diff], i)
        prev[n] = i
```

### Why this works
When we're at index `i` with value `n`, we check if `target - n` was seen at any earlier index. If yes, those two indices are the answer.

### Complexity
| | Complexity |
|---|---|
| Time | O(N) |
| Space | O(N) for the hashmap |

---

## 10. Contains Duplicate — LeetCode 217

**Platform:** LeetCode  
**Difficulty:** Easy  
**Language:** Python  
**File:** `217__Contains_Duplicate.cpp`

### Problem
Return true if any value appears at least twice.

### Key Concept
A set stores only unique elements. If the set is smaller than the original array, duplicates exist.

```python
def containsDuplicate(self, nums):
    set_nums = set(nums)
    return len(set_nums) != len(nums)
```

### Complexity
| | Complexity |
|---|---|
| Time | O(N) |
| Space | O(N) |

---

## 11. Missing Number — LeetCode 268

**Platform:** LeetCode  
**Difficulty:** Easy  
**Language:** Python  
**File:** `268__Missing_Number.cpp`

### Problem
Array contains n distinct numbers from [0, n]. Find the missing one.

### Key Concept — Gauss Sum Formula
Sum of 0 to n = n*(n+1)/2. Subtract the actual array sum to get the missing number.

```python
def missingNumber(self, nums):
    return sum(range(len(nums) + 1)) - sum(nums)
```

### Example
nums = [3,0,1], n = 3
Expected sum = 0+1+2+3 = 6
Actual sum = 3+0+1 = 4
Missing = 6 - 4 = **2** ✅

### Complexity
| | Complexity |
|---|---|
| Time | O(N) |
| Space | O(1) |

---

## 12. Find All Numbers Disappeared in an Array — LeetCode 448

**Platform:** LeetCode  
**Difficulty:** Easy  
**Language:** Python  
**File:** `448__Find_All_Numbers_Disappeared_in_an_Array.cpp`

### Problem
Array of n integers where each value is in [1, n]. Return all numbers in [1, n] that are missing.

### Approach
Convert array to a set, then check which numbers from 1 to n are absent.

```python
def findDisappearedNumbers(self, nums):
    set_nums = set(nums)
    return [i for i in range(1, len(nums) + 1) if i not in set_nums]
```

### Follow-up (O(1) space)
Mark visited indices negative. Numbers whose index was never marked are the missing ones — but the set approach is cleaner to read.

### Complexity
| | Complexity |
|---|---|
| Time | O(N) |
| Space | O(N) for the set |

---

## 13. Subtract the Product and Sum of Digits — LeetCode 1281

**Platform:** LeetCode  
**Difficulty:** Easy  
**File:** `1281__Subtract_the_Product_and_Sum_of_Digits_of_an_Integer.cpp`

### Problem
Return `product_of_digits - sum_of_digits` for a given number.

### Approach
Extract digits one by one using `n % 10`, accumulate sum and product, then divide by 10 to move to the next digit.

```cpp
int subtractProductAndSum(int n) {
    int sum = 0, product = 1;
    while (n > 0) {
        int rem = n % 10;
        sum += rem;
        product *= rem;
        n /= 10;
    }
    return product - sum;
}
```

### Example
n = 234: digits are 4, 3, 2
Sum = 9, Product = 24, Answer = 24 - 9 = **15** ✅

### Complexity
| | Complexity |
|---|---|
| Time | O(d) where d = number of digits |
| Space | O(1) |

---

## 14. Reverse Integer — LeetCode 7

**Platform:** LeetCode  
**Difficulty:** Medium  
**File:** `7__Reverse_Integer.cpp`

### Problem
Reverse a 32-bit signed integer. Return 0 if the reversed number overflows.

### Key Concept — Overflow Check Before Multiplying
The tricky part is detecting overflow **before** it happens. If `new_num > INT_MAX/10`, then multiplying by 10 will definitely overflow.

```cpp
int reverse(int x) {
    int new_num = 0;
    while (x != 0) {
        int rem = x % 10;
        if (new_num > INT_MAX/10 || new_num < INT_MIN/10) return 0;
        new_num = 10 * new_num + rem;
        x /= 10;
    }
    return new_num;
}
```

### Why check `INT_MAX/10` and not `INT_MAX`?
Because we check **before** multiplying. If `new_num` is already larger than `INT_MAX/10`, then `new_num * 10` will overflow — so we return 0 preemptively.

### Handles negatives automatically
In C++, `%` on negative numbers gives a negative remainder. So `-123 % 10 = -3`, which naturally builds `-321`.

### Complexity
| | Complexity |
|---|---|
| Time | O(d) where d = number of digits |
| Space | O(1) |

---

## 15. Palindrome Number — LeetCode 9

**Platform:** LeetCode  
**Difficulty:** Easy  
**File:** `9__Palindrome_Number.cpp`

### Problem
Return true if an integer reads the same forwards and backwards.

### Approach
Reuse the `reverse()` function from problem 7. Negative numbers are never palindromes (return -1 for them). If the reversed number equals the original, it's a palindrome.

```cpp
int reverse(int x) {
    int new_num = 0;
    if (x < 0) return -1;
    while (x > 0) {
        if (new_num > INT_MAX/10) return -1;
        new_num = (new_num * 10) + (x % 10);
        x /= 10;
    }
    return new_num;
}

bool isPalindrome(int x) {
    int rev = reverse(x);
    if (rev < 0) return false;
    return rev == x;
}
```

### Complexity
| | Complexity |
|---|---|
| Time | O(d) where d = number of digits |
| Space | O(1) |

---

## 16. Number of 1 Bits — LeetCode 191

**Platform:** LeetCode  
**Difficulty:** Easy  
**File:** `191__Number_of_1_Bits.cpp`

### Problem
Return the number of set bits (1s) in the binary representation of n. Also called **Hamming Weight**.

### Key Concept — Brian Kernighan's Algorithm
`n & (n-1)` clears the **lowest set bit** of n. So counting how many times we can do this until n = 0 gives us the number of set bits.

```cpp
int hammingWeight(int n) {
    int count = 0;
    while (n != 0) {
        n = n & (n - 1);   // clears lowest set bit
        count++;
    }
    return count;
}
```

### Why does `n & (n-1)` clear the lowest set bit?
`n-1` flips the lowest set bit to 0 and all bits below it to 1. ANDing with n clears exactly that lowest set bit.

Example: n = 12 (1100)
- n-1 = 11 (1011)
- n & (n-1) = 1000 → lowest set bit cleared ✅

### Complexity
| | Complexity |
|---|---|
| Time | O(number of set bits) — faster than O(32) |
| Space | O(1) |

---

## 17. Power of Two — LeetCode 231

**Platform:** LeetCode  
**Difficulty:** Easy  
**File:** `231__Power_of_Two.cpp`

### Problem
Return true if n is a power of two.

### Key Insight
A power of two in binary has **exactly one set bit** (e.g., 1=0001, 2=0010, 4=0100, 8=1000). So count the set bits — if exactly 1, it's a power of two.

```cpp
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    int setbit = 0;
    while (n != 0) {
        setbit += (n & 1);   // check last bit
        n >>= 1;             // right shift
    }
    return setbit == 1;
}
```

### Cleaner one-liner (follow-up)
```cpp
return n > 0 && (n & (n - 1)) == 0;
// n & (n-1) clears the lowest set bit
// If result is 0, there was only one set bit → power of two
```

### Complexity
| | Complexity |
|---|---|
| Time | O(log n) — number of bits |
| Space | O(1) |

---

## 18. Complement of Base 10 Integer — LeetCode 1009

**Platform:** LeetCode  
**Difficulty:** Easy  
**File:** `1009__Complement_of_Base_10_Integer.cpp`

### Problem
Return the complement of n — flip all bits in its binary representation.

### Key Concept — Mask
Simply doing `~n` flips all 32 bits, including leading zeros which we don't want. We need a mask of only as many 1s as there are bits in n, then AND with `~n`.

```cpp
int bitwiseComplement(int n) {
    if (n == 0) return 1;
    
    int m = n, mask = 0;
    while (m != 0) {
        mask = (mask << 1) | 1;   // build mask: 0 → 1 → 11 → 111...
        m >>= 1;
    }
    return (~n) & mask;
}
```

### Example — n = 5 (101)
- Build mask: 111 (3 bits, same width as 5)
- `~5` in 32 bits = ...11111010
- `~5 & 111` = 010 = **2** ✅

### Example — n = 10 (1010)
- Build mask: 1111
- `~10 & 1111` = 0101 = **5** ✅

### Complexity
| | Complexity |
|---|---|
| Time | O(log n) — number of bits |
| Space | O(1) |

---

## Quick Reference

| Problem | Key Technique | Time | Language |
|---|---|---|---|
| Print Divisors | Divisor pairs + √N loop | O(√N) | C++ |
| Three Divisors | Count divisors | O(N) | C++ |
| Four Divisors | Count divisors + early exit | O(N×M) | C++ |
| GCD | Euclidean Algorithm | O(log min(x,y)) | C++ |
| Find Primes (large N) | Sieve of Eratosthenes | O(N log log N) | C++ |
| All Primes (small N) | Trial division | O(N√N) | C++ |
| Megaprime Numbers | Sieve + digit check | O(N log log N) | C++ |
| Complete Prime | Prefix/suffix math | O(d × √num) | C++ |
| Two Sum | HashMap (one pass) | O(N) | Python |
| Contains Duplicate | Set comparison | O(N) | Python |
| Missing Number | Gauss Sum Formula | O(N) | Python |
| Find Disappeared Numbers | Set lookup | O(N) | Python |
| Subtract Product & Sum | Digit extraction | O(d) | C++ |
| Reverse Integer | Build reverse + overflow check | O(d) | C++ |
| Palindrome Number | Reverse + compare | O(d) | C++ |
| Number of 1 Bits | Brian Kernighan's Algorithm | O(set bits) | C++ |
| Power of Two | Count set bits | O(log N) | C++ |
| Complement of Base 10 | Bitmask + NOT | O(log N) | C++ |
