#include "jollyjumper.h"
#include <stdbool.h>
//#include <malloc.h>
#include <stdlib.h>


int isJollyJumber(const int seq[], int size) {

  //Mængden af forskellige vil være én mindre end antallet af tal.
  bool diffs_found[size - 1];
  int diff;

  //Laver array til forskelle, og sætter hver forskel = falsk.
  for (int i = 0; i < size - 1; i++) {
    diffs_found[i] = false;
  }

  //Hvis forskellen er større end antallet af tal, kan det aldrig være en jolly jumper
  for (int i = 1; i < size; i++) {
    diff = abs(seq[i - 1] - seq[i]);

    //Hvis forskellen mellem 2 tal er 0, kan sekvensen aldrig være en jolly jumper.
    if (diff >= size || diff == 0) {
      return 0;
    }

    if (diffs_found[diff - 1] == false) {
      diffs_found[diff - 1] = true;
    }
  };
  //Tjekker om alle forventede forskelle (der er krav for at n-antal talsekvens er en jolly jumper)
  for (int i = 0; i < size - 1; i++) {
    if (diffs_found[i] == false) {
      return 0;
    }
  }
    return 1;
}

