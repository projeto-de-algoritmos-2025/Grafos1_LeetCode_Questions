# 301. Remove Invalid Parentheses

Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return _a list of **unique strings** that are valid with the minimum number of removals._ You may return the answer in **any order**.


**Example 1**:

```
Input: s = "()())()"
Output: ["(())()","()()()"]
```

**Example 2**:

```
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
```

**Example 3**:

```
Input: s = ")("
Output: [""]
```

**Constraints**:

* `1 <= s.length <= 25`
* `s` consists of lowercase English letters and parentheses `'('` and `')'`.
* There will be at most `20` parentheses in `s`.


![AC Submission](https://github.com/user-attachments/assets/c1fdeadb-a409-46e8-bdb4-0c1105757320)