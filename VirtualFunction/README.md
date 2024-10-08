 # Person, Professor, and Student Class Simulation

## Overview
This project involves creating three classes: `Person`, `Professor`, and `Student`. 
- `Person` has the attributes `name` and `age`.
- `Professor` and `Student` inherit from `Person` and have additional attributes and functions.
- Each `Professor` and `Student` object gets a unique ID assigned using static variables.

## Classes and Methods
1. **Person (Base Class)**
   - Attributes: `name`, `age`.
   - Methods: `getdata()` and `putdata()` (virtual).

2. **Professor (Derived from Person)**
   - Attributes: `publications`, `cur_id` (unique ID).
   - Methods:
     - `getdata()`: Takes input for `name`, `age`, and `publications`.
     - `putdata()`: Outputs `name`, `age`, `publications`, and `cur_id`.

3. **Student (Derived from Person)**
   - Attributes: `marks[6]`, `cur_id` (unique ID).
   - Methods:
     - `getdata()`: Takes input for `name`, `age`, and `marks` for 6 subjects.
     - `putdata()`: Outputs `name`, `age`, sum of marks, and `cur_id`.

## Input/Output
- **Input**: 
  - First line: Number of objects to be created.
  - For each object:
    - `1` for `Professor` followed by `name`, `age`, and `publications`.
    - `2` for `Student` followed by `name`, `age`, and marks for 6 subjects.
  
- **Output**:
  - For `Professor`: `name`, `age`, `publications`, `cur_id`.
  - For `Student`: `name`, `age`, sum of marks, `cur_id`.

## Example

### Input:
```plaintext
4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87
```
## Output:
```plaintext
Walter 56 99 1
Jesse 18 403 1
Pinkman 22 135 2
White 58 87 2
```
