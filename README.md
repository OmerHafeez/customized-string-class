# customized-string-class

This repository contains an implementation of a custom string class in C++. The class mimics some of the functionalities of the standard string class, including constructors, destructors, and several member functions for string manipulation.

## Class Definition

The `String` class has the following member variables and functions:

### Member Variables

- `char* data`: Holds the character array that constitutes the string.
- `int length`: The current length of the string that the object contains (number of characters in `data`).

### Constructors

1. **Default Constructor**: Initializes `data` to `nullptr` and `length` to `0`.
    ```cpp
    String();
    ```

2. **Parameterized Constructor**: Initializes `length` to `size` and allocates a new char array of `size`.
    ```cpp
    String(int size);
    ```

3. **Parameterized Constructor with String**: Initializes `length` to the size of `str` and copies the contents of `str` to `data`.
    ```cpp
    String(const char* str);
    ```

4. **Copy Constructor**: Initializes `length` and `data` by copying another `String` object.
    ```cpp
    String(const String& str);
    ```

### Destructor

- Frees the allocated memory for `data`.
    ```cpp
    ~String();
    ```

### Member Functions

1. **Get Length**: Returns the length of the string.
    ```cpp
    int strLength() const;
    ```

2. **Clear**: Clears the string data.
    ```cpp
    void clear();
    ```

3. **Check If Empty**: Checks if the string is empty.
    ```cpp
    bool empty() const;
    ```

4. **Character at Index**: Returns the index of the first occurrence of a character.
    ```cpp
    int charAt(char c) const;
    ```

5. **Get Data**: Returns the actual string data.
    ```cpp
    char* getdata() const;
    ```

6. **Equals**: Checks if the string data is equal to another string.
    ```cpp
    bool equals(char* str) const;
    ```

7. **Equals Ignore Case**: Checks if the string data is equal to another string, ignoring case.
    ```cpp
    bool equalsIgnoreCase(char* str) const;
    ```

8. **Substring**: Returns a substring starting from a given index.
    ```cpp
    char* substring(char* substr, int startIndex) const;
    ```

9. **Substring with End Index**: Returns a substring within a specified range.
    ```cpp
    char* substring(char* substr, int startIndex, int endIndex) const;
    ```

10. **Print**: Prints the string data.
    ```cpp
    void print() const;
    ```
