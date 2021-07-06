#include <assert.h>
#include <dlfcn.h>

#include <iostream>

#include "DynamicLibrary.h"

static void* checkDL(void* x) {
  char *maybe_error = dlerror();
  if (maybe_error != NULL) {
    std::cerr << "Error in dlopen or dlsym: " << maybe_error << std::endl;
    return NULL;
  }

  return x;
}

DynamicLibrary::DynamicLibrary(const char* name, const char* alt_name) {
  handle = checkDL(dlopen(name, RTLD_LOCAL | RTLD_NOW));
  if (!handle) {
    if (alt_name) {
      handle = checkDL(dlopen(alt_name, RTLD_LOCAL | RTLD_NOW));
      if (!handle) {
        std::cerr << "Error in dlopen for library " << name << " and " << alt_name << std::endl;
      }
    } else {
      std::cerr << "Error in dlopen for library " << name << std::endl;
    }
  }
  std::cout << "DynamicLibrary(" << name << ") handle=" << handle << std::endl;
}

void* DynamicLibrary::sym(const char* name) {
  assert(handle);
  auto val = checkDL(dlsym(handle, name));
  std::cout << "DynamicLibrary::sym(" << name << ") value=" << (void*)val << std::endl;
  return val;
}

DynamicLibrary::~DynamicLibrary() {
  if (!handle)
    return;
  std::cout << "DynamicLibrary::dtor handle=" << handle << std::endl;
  dlclose(handle);
}
