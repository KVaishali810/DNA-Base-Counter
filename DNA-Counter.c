#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

 int main() {

    long countA = 0, countT = 0, countG = 0, countC = 0, countOther = 0;
    char line[1024];
    int inSequence = 0;
    int seqCount = 0;

    printf("========================================\n");
    printf("   DNA Base Composition Counter v1.0\n");
    printf("========================================\n");
    printf("Paste FASTA sequences below.\n");
    printf("Type END on a new line when done.\n\n");

    while (fgets(line, sizeof(line), stdin)) {

        line[strcspn(line, "\r\n")] = '\0';

        if (strcmp(line, "END") == 0) break;

        if (line[0] == '\0') continue;  /* skip empty lines */

        if (line[0] == '>') {
            seqCount++;
            printf("[Sequence %d found: %s]\n", seqCount, line + 1);
            inSequence = 1;
            continue;
        }

        if (!inSequence) continue;

        for (int i = 0; line[i] != '\0'; i++) {
            char base = toupper(line[i]);
            if      (base == 'A') countA++;
            else if (base == 'T') countT++;
            else if (base == 'G') countG++;
            else if (base == 'C') countC++;
            else                  countOther++;
        }
    }

    /* safety check before division */
    long total = countA + countT + countG + countC;
    if (total == 0) {
        printf("\nNo valid bases found.\n");
        printf("Make sure each sequence starts with a '>' header line.\n");
        return 1;
    }

    double gcContent = 100.0 * (countG + countC) / total;
    double atContent = 100.0 * (countA + countT) / total;

    printf("\n========================================\n");
    printf("   Results: %d sequence(s) analyzed\n", seqCount);
    printf("========================================\n");
    printf("  A  :  %6ld  (%5.2f%%)\n", countA, 100.0 * countA / total);
    printf("  T  :  %6ld  (%5.2f%%)\n", countT, 100.0 * countT / total);
    printf("  G  :  %6ld  (%5.2f%%)\n", countG, 100.0 * countG / total);
    printf("  C  :  %6ld  (%5.2f%%)\n", countC, 100.0 * countC / total);
    printf("----------------------------------------\n");
    printf("  Total bases  : %ld\n", total);
    printf("  GC Content   : %.2f%%\n", gcContent);
    printf("  AT Content   : %.2f%%\n", atContent);
    printf("  Sequences    : %d\n", seqCount);
    if (countOther > 0)
        printf("  Unknown/N    : %ld\n", countOther);
    printf("========================================\n");

   return 0;
}
