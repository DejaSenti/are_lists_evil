# are_lists_evil
Based on https://isocpp.org/blog/2014/06/stroustrup-lists

Insert a sequence of random integers into a sorted sequence, then remove those elements one by one as determined by a random sequence of positions.

What is needed?

    - For different types of sorted sequences do the following:
        - Build a sequence of random integers of a given size
        - Build a sequence of random positions - this is tricky because with each position, all positions after it need to be subtracted by one in order to avoid removal of nonexisting elements.
        - Start timing
        - Insert the random integers into the sorted sequence
        - Remove the integers according to the list of positions
        - Stop timing

    - Main function:
        - Get a target size
        - Create a list of sorted sequences
        - Create the sequences of integers and positions in the target size
        - For each sequence, perform the insertion and removal

    - Sorted Sequence:
        - Some interface which has an insertion and removal functions
        - Children:
            - Array
            - Vector
            - Singly-Linked List
            - Doubly-Linked List
            - Tree
        - Test for the sequence classes:
            - Validate insertion is sorted
            - Validate removal indeed occurs on the right indices
