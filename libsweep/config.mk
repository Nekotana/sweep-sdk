VERSION_MAJOR = 0
VERSION_MINOR = 1

UNAME := $(shell uname)


ifeq ($(UNAME), Linux)
  # For linux platforms
  PREFIX ?= /usr
  CFLAGS += -O2 -Wall -Wextra -pedantic -std=c99 -Wnonnull -fvisibility=hidden -fPIC -pthread
  LDFLAGS += -shared -Wl,-soname,libsweep.so.$(VERSION_MAJOR)
  LDLIBS += -lpthread
else ifeq ($(UNAME), Darwin)
  # For mac platforms
  $(error macOS build system support missing)
else ifeq ($(UNAME), MINGW32_NT-6.2)
  # For win platforms using MinGW
  PREFIX ?= C:\MinGW
  CC = gcc
  CFLAGS += -O2 -Wall -Wextra -pedantic -std=c99 -Wnonnull -fvisibility=hidden -fPIC -mno-ms-bitfields
  LDFLAGS += -shared -Wl,-soname,libsweep.dll.$(VERSION_MAJOR)
  #$(error $(UNAME) not yet supported)
else
  # For all other platforms
  $(error system not supported)
endif
