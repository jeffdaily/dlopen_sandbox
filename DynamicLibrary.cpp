#include <assert.h>
#include <dlfcn.h>

#include <iostream>

#include "DynamicLibrary.h"

static void* checkDL(void* x) {
  if (!x) {
    std::cerr << "Error in dlopen or dlsym: " << dlerror() << std::endl;
  }

  return x;
}

DynamicLibrary::DynamicLibrary(const char* name, const char* alt_name) {
  handle = dlopen(name, RTLD_LOCAL | RTLD_NOW);
  if (!handle) {
    if (alt_name) {
      handle = dlopen(alt_name, RTLD_LOCAL | RTLD_NOW);
      if (!handle) {
        std::cerr << "Error in dlopen for library " << name << " and " << alt_name << std::endl;
      }
    } else {
      std::cerr << "Error in dlopen: " << dlerror() << std::endl;
    }
  }
}

void* DynamicLibrary::sym(const char* name) {
  assert(handle);
  return checkDL(dlsym(handle, name));
}

DynamicLibrary::~DynamicLibrary() {
  if (!handle)
    return;
  dlclose(handle);
}
