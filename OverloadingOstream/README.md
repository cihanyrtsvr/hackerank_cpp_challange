The task is to overload the << operator for Person class in such a way that for p being an instance of class Person the result of:

`   std::cout << p << " " <<  << std::endl;   `

produces the following output:

`first_name=,last_name=` 

where:

*    is the value of p's first\_name\_
    
*    is the value of p's last\_name\_
    
*    is an arbitrary std::string value
    

**Input Format**

The input is read by the provided locked code template. In the only line of the input there are 3 space-separated strings first\_name, last\_name, event. The values of first\_name and last\_name will be used to create an object p of type Person. The value of event will be used by the provided code to produce the output.

**Constraints**

*   Each word in the input contains only English letters and is no longer than 15 characters
    

**Output Format**

The output should be produced by the provided locked code template. This code will use the implementation of Person public methods and the overloaded << operator to produce the output. Specifically, the output wiil be produced by the following code:

The output should be produced by the provided locked code template. This code will use the implementation of Person public methods and the overloaded << operator to produce the output. Specifically, the output wiil be produced by the following code:

`cout << p << " " << event << endl;`

**Sample Input 0**

`   john doe registered   `

**Sample Output 0**

`   first_name=john last_name=doe registered   `