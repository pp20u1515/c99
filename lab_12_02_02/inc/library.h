#ifndef LIBRARY_H
#define LIBRARY_H

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

// Соглашение о вызовах
#define ARR_DECL __cdecl

ARR_DLL int ARR_DECL fibonacci(int n);

ARR_DLL void ARR_DECL fill_array(int *arr, const int size);

ARR_DLL void ARR_DECL filter(int *src, const int src_size, int *dest, int *dest_size);

#endif // LIBRARY_H