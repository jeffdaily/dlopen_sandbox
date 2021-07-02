#pragma once

struct DynamicLibrary {

  DynamicLibrary(const char* name, const char* alt_name = nullptr);

  void* sym(const char* name);

  ~DynamicLibrary();

 private:
  void* handle = nullptr;
};

