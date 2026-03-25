# DNA Base Composition Counter

A command-line tool written in C that parses FASTA-format DNA sequences 
and computes base frequencies and GC content.

## What it does
- Reads one or more DNA sequences in FASTA format
- Counts occurrences of A, T, G, and C bases
- Computes GC% and AT% content
- Handles lowercase input and unknown bases (N)
- Reports how many sequences were analyzed

## How to compile (if running locally)
gcc dna_counter.c -o dna_counter

## How to run
./dna_counter

Then paste your FASTA input and type END when done.

## Example input
>seq1 Human BRCA1 fragment
ATGCGATCGATCGATCGT
AGCTAGCTAGCATCGATC
>seq2 Mouse homolog
GCTAGCTAGCTAGCTAAT
ATGCGCGCGCTTTTAAAA
END

## Example output
========================================
   Results: 2 sequence(s) analyzed
========================================
  A  :      19  (26.39%)
  T  :      19  (26.39%)
  G  :      17  (23.61%)
  C  :      17  (23.61%)
----------------------------------------
  Total bases  : 72
  GC Content   : 47.22%
  AT Content   : 52.78%
  Sequences    : 2
========================================

## Concepts used
- File I/O with fgets and stdin
- String parsing in C
- FASTA format handling
- Defensive programming (division by zero check)
- toupper() for case-insensitive input

## Author
K Vaishali
MSc Bioinformatics
