0x1E. C - Search Algorithms

#TASKS

File: 0-linear.c
A function that searches for a value in an array of integers using the Linear search algorithm

Prototype : int linear_search(int *array, size_t size, int value);
    Where array is a pointer to the first element of the array to search in
    ize is the number of elements in array
    And value is the value to search for
    Your function must return the first index where value is located
    If value is not present in array or if array is NULL, your function must return -1
    Every time you compare a value in the array to the value you are searching, you have to print this value (see example below)

File: 1-binary.c
A function that searches for a value in a sorted array of integers using the Binary search algorithm

Prototype : int binary_search(int *array, size_t size, int value);
    Where array is a pointer to the first element of the array to search in
    size is the number of elements in array
    And value is the value to search for
    Your function must return the index where value is located
    You can assume that array will be sorted in ascending order
    You can assume that value won’t appear more than once in array
    If value is not present in array or if array is NULL, your function must return -1
    You must print the array being searched every time it changes. (e.g. at the beginning and when you search a subarray) (See example)

File: 2-O
What is the time complexity (worst case) of a linear search in an array of size n?

File: 3-O
What is the space complexity (worst case) of an iterative linear search algorithm in an array of size n?

File: 4-O
What is the time complexity (worst case) of a binary search in an array of size n?

File: 5-O
What is the space complexity (worst case) of a binary search in an array of size n?

File: 6-O
What is the space complexity of this function / algorithm?

File: 100-jump.c
Write a function that searches for a value in a sorted array of integers using the Jump search algorithm

Prototype : int jump_search(int *array, size_t size, int value);
    Where array is a pointer to the first element of the array to search in
    size is the number of elements in array
    And value is the value to search for
    Your function must return the first index where value is located
    You can assume that array will be sorted in ascending order
    If value is not present in array or if array is NULL, your function must return -1
    You have to use the square root of the size of the array as the jump step.
    You can use the sqrt() function included in <math.h> (don’t forget to compile with -lm)
    Every time you compare a value in the array to the value you are searching for, you have to print this value (see example)

File: 101-O
What is the time complexity (average case) of a jump search in an array of size n, using step = sqrt(n)?

File: 102-interpolation.c
A function that searches for a value in a sorted array of integers using the Interpolation search algorithm

Prototype : int interpolation_search(int *array, size_t size, int value);
    Where array is a pointer to the first element of the array to search in
    size is the number of elements in array
    And value is the value to search for
    Your function must return the first index where value is located
    You can assume that array will be sorted in ascending order
    If value is not present in array or if array is NULL, your function must return -1
    To determine the probe position, you can use : size_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]))
    Every time you compare a value in the array to the value you are searching, you have to print this value (see example below)

File: 103-exponential.c
A function that searches for a value in a sorted array of integers using the Exponential search algorithm

Prototype : int exponential_search(int *array, size_t size, int value);
    Where array is a pointer to the first element of the array to search in
    size is the number of elements in array
    And value is the value to search for
    Your function must return the first index where value is located
    You can assume that array will be sorted in ascending order
    If value is not present in array or if array is NULL, your function must return -1
    You have to use powers of 2 as exponential ranges to search in your array
    Every time you compare a value in the array to the value you are searching for, you have to print this value (See example)
    Once you’ve found the good range, you need to use a binary search:
    Every time you split the array, you have to print the new array (or subarray) you’re searching in (See example)

File: 104-advanced_binary.c
A function that searches for a value in a sorted array of integers.

Prototype : int advanced_binary(int *array, size_t size, int value);
Where array is a pointer to the first element of the array to search in
size is the number of elements in array
And value is the value to search for
Your function must return the index where value is located
You can assume that array will be sorted in ascending order
If value is not present in array or if array is NULL, your function must return -1
Every time you split the array, you have to print the new array (or subarray) you’re searching in (See example)
You have to use recursion. You may only use one loop (while, for, do while, etc.) in order to print the array

File: 105-jump_list.c
A function that searches for a value in a sorted list of integers using the Jump search algorithm.

Prototype : listint_t *jump_list(listint_t *list, size_t size, int value);
    Where list is a pointer to the head of the list to search in
    size is the number of nodes in list
    And value is the value to search for
    Your function must return a pointer to the first node where value is located
    You can assume that list will be sorted in ascending order
    If value is not present in head or if head is NULL, your function must return NULL
    You have to use the square root of the size of the list as the jump step.
    You can use the sqrt() function included in <math.h> (don’t forget to compile with -lm)
    Every time you compare a value in the list to the value you are searching, you have to print this value    (see example)
    NOTE: You can find here the functions used in the example. You don’t need to push them, we will compile your file with our own implementation during the correction.

File: 106-linear_skip.c
A function that searches for a value in a sorted skip list of integers.

Prototype : skiplist_t *linear_skip(skiplist_t *list, int value);
    Where list is a pointer to the head of the skip list to search in
    A node of the express lane is placed every index which is a multiple of the square root of the size of the list (see example below)
    And value is the value to search for
    You can assume that list will be sorted in ascending order
    Your function must return a pointer on the first node where value is located
    f value is not present in list or if head is NULL, your function must return NULL
    Every time you compare a value in the list to the value you are searching, you have to print this value (see example below)

File: 107-O
What is the time complexity (average case) of a jump search in a singly linked list of size n, using step = sqrt(n)?

File: 108-O
What is the time complexity (average case) of a jump search in a skip list of size n, with an express lane using step = sqrt(n)?