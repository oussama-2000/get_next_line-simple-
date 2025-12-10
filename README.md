This project has been created as part of the 42 curriculum by oamkhou.

Description:

    The Get Next Line project aims to implement a function capable of reading a file descriptor one line at a time, without losing previously read data.
    The goal is to manage buffered reading, dynamic memory allocation, partial reads, and persistent data between function calls.


Instructions:

    compilation :

        mandatory part : cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c 

        bonus part : cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c 

    Execution :

        ./a.out

    

Algorithm Used:

    Explanation:

        The algorithm is based on a loop that:

        1- Reads fixed-size chunks (BUFFER_SIZE) from the file descriptor.
        2- Appends each chunk to a persistent buffer linked to the file descriptor.
        3- Checks if the buffer contains a newline (\n).
        4- Extracts the next full line (including the newline if present).
        5- Updates the buffer by removing the extracted part for the next call.

    justification:

        Efficient : reads in chunks instead of byte b0y byte, reducing system calls.
        Memory safe : uses controlled allocations and frees to avoid leaks.
        Flexible : works with any BUFFER_SIZE and any file descriptor .
        Stateful : keeps leftover data between calls thanks to a static buffer.



       