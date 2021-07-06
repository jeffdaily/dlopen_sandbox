#pragma once

class DynamicLibrary {
 public:
  explicit DynamicLibrary(const char* name, const char* alt_name = nullptr);

  void* sym(const char* name);

  ~DynamicLibrary();

 private:
  void* handle = nullptr;
};

