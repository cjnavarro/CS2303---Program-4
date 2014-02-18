Christopher Navarro
Hoang Minh Ngo
Section: C04

CS2303---Program-4
==================

The purpose of ou program is to take an input, e.g. a body of text, and break it down into individual words (It is important to note we chose to include hyphenated words as single words). While doing this each word is stored within a linked list along with the number of times the word is written and which lines the word appears on. Duplicate words are handle by merely incrementing the word count in the linked list of the already added word. To keep track of the lines of which each word is found on we opted to use a string instead of a list. That way we could smply append the line number to the prexisting string.

Our tar file contains the following pieces:

main.cpp - handles the input of the..

list.cpp

list.h

Makefile


