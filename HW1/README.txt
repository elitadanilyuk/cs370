README
HW1 by Elita Danilyuk, 832995269
===========================================================================
This package includes the following files:
    - README.txt [this file]
    - Starter.c [this is the driver/starter program used to set the seed
        and invokes the Executor through the function get_running_ratio();
        prints the seed and the average running ratio]
    - Executor.c [implements core functionality of this assignment,
        dynamically allocats and de-allocates memory, populates random
        chars, counts vowels and consonants, returns the average value of
        vowels and consonants for all iterations to the Starter;
        prints the number of iterations and the interval that contains
        the maximum amount of vowels]
    - Executor.h: [declares the exposed method get_running_ratio() from
        Executor.c which Starter.c calls on]
    - Makefile [desiged to compile the code, build the executable,
        package the homework, and clean the built and packaged files
        through different make targets and commands]

Valgrind Outputs:
1. With leaks (seed 7)
    ==1473073== Memcheck, a memory error detector
    ==1473073== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==1473073== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
    ==1473073== Command: ./Starter 7
    ==1473073== 
    [Starter]: With seed: 7
    [Executor]: Number of iterations is  77
    [Executor]: Iteration with maximum vowel count is  43
    [Starter]: Running ratio: 0.241263
    ==1473073== 
    ==1473073== HEAP SUMMARY:
    ==1473073==     in use at exit: 9,342 bytes in 77 blocks
    ==1473073==   total heap usage: 78 allocs, 1 frees, 10,366 bytes allocated
    ==1473073== 
    ==1473073== 9,342 bytes in 77 blocks are definitely lost in loss record 1 of 1
    ==1473073==    at 0x4C360A5: malloc (vg_replace_malloc.c:380)
    ==1473073==    by 0x400921: get_running_ratio (Executor.c:104)
    ==1473073==    by 0x400748: main (Starter.c:19)
    ==1473073== 
    ==1473073== LEAK SUMMARY:
    ==1473073==    definitely lost: 9,342 bytes in 77 blocks
    ==1473073==    indirectly lost: 0 bytes in 0 blocks
    ==1473073==      possibly lost: 0 bytes in 0 blocks
    ==1473073==    still reachable: 0 bytes in 0 blocks
    ==1473073==         suppressed: 0 bytes in 0 blocks
    ==1473073== 
    ==1473073== For lists of detected and suppressed errors, rerun with: -s
    ==1473073== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
2. No leaks (with seed 7)
    ==1473401== Memcheck, a memory error detector
    ==1473401== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==1473401== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
    ==1473401== Command: ./Starter 7
    ==1473401== 
    [Starter]: With seed: 7
    [Executor]: Number of iterations is  77
    [Executor]: Iteration with maximum vowel count is  43
    [Starter]: Running ratio: 0.241263
    ==1473401== 
    ==1473401== HEAP SUMMARY:
    ==1473401==     in use at exit: 0 bytes in 0 blocks
    ==1473401==   total heap usage: 78 allocs, 78 frees, 10,366 bytes allocated
    ==1473401== 
    ==1473401== All heap blocks were freed -- no leaks are possible
    ==1473401== 
    ==1473401== For lists of detected and suppressed errors, rerun with: -s
    ==1473401== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
3. No leaks (with seed 91)
    ==1473511== Memcheck, a memory error detector
    ==1473511== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==1473511== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
    ==1473511== Command: ./Starter 91
    ==1473511== 
    [Starter]: With seed: 91
    [Executor]: Number of iterations is  85
    [Executor]: Iteration with maximum vowel count is  59
    [Starter]: Running ratio: 0.246685
    ==1473511== 
    ==1473511== HEAP SUMMARY:
    ==1473511==     in use at exit: 0 bytes in 0 blocks
    ==1473511==   total heap usage: 86 allocs, 86 frees, 11,631 bytes allocated
    ==1473511== 
    ==1473511== All heap blocks were freed -- no leaks are possible
    ==1473511== 
    ==1473511== For lists of detected and suppressed errors, rerun with: -s
    ==1473511== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)