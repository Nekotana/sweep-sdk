// Make use of the CMake build system or compile manually, e.g. with:
// gcc -std=c99 example.c -lsweep

#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sweep/sweep.h>

int main() {
  // Makes sure the installed library is compatible with the interface
  assert(sweep_is_abi_compatible());

  for (int i = 0; i < 50; i++) {
    fprintf(stdout, "Printing %d from example.c\n", i);
    sweep_sleep_milliseconds(500);
  }
  
  return EXIT_SUCCESS;
}
