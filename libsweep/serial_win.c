#include "serial.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct sweep_serial_error {
  const char* what; // always literal, do not free
} sweep_serial_error;

typedef struct sweep_serial_device { int32_t fd; } sweep_serial_device;

// Constructor hidden from users
static sweep_serial_error_s sweep_serial_error_construct(const char* what) {
  SWEEP_ASSERT(what);

  sweep_serial_error_s out = (sweep_serial_error_s)malloc(sizeof(sweep_serial_error));
  SWEEP_ASSERT(out && "out of memory during error reporting");

  out->what = what;
  return out;
}

const char* sweep_serial_error_message(sweep_serial_error_s error) {
  SWEEP_ASSERT(error);

  return error->what;
}

void sweep_serial_error_destruct(sweep_serial_error_s error) {
  SWEEP_ASSERT(error);

  free(error);
}

static bool sweep_serial_detail_wait_readable(sweep_serial_device_s serial, sweep_serial_error_s* error) {
  SWEEP_ASSERT(serial);
  SWEEP_ASSERT(error);

  return false;
}

sweep_serial_device_s sweep_serial_device_construct(const char* port, int32_t bitrate, sweep_serial_error_s* error) {
  SWEEP_ASSERT(port);
  SWEEP_ASSERT(bitrate > 0);
  SWEEP_ASSERT(error);

  return NULL;
}

void sweep_serial_device_destruct(sweep_serial_device_s serial) {
  SWEEP_ASSERT(serial);

  sweep_serial_error_s ignore = NULL;
  sweep_serial_device_flush(serial, &ignore);
  (void)ignore; // nothing we can do here

  free(serial);
}

void sweep_serial_device_read(sweep_serial_device_s serial, void* to, int32_t len, sweep_serial_error_s* error) {
  SWEEP_ASSERT(serial);
  SWEEP_ASSERT(to);
  SWEEP_ASSERT(len >= 0);
  SWEEP_ASSERT(error);
}

void sweep_serial_device_write(sweep_serial_device_s serial, const void* from, int32_t len, sweep_serial_error_s* error) {
  SWEEP_ASSERT(serial);
  SWEEP_ASSERT(from);
  SWEEP_ASSERT(len >= 0);
  SWEEP_ASSERT(error);
}

void sweep_serial_device_flush(sweep_serial_device_s serial, sweep_serial_error_s* error) {
  SWEEP_ASSERT(serial);
  SWEEP_ASSERT(error);
}
