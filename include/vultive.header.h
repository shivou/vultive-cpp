#ifndef _VULTIVE_HEADER_H_
#define _VULTIVE_HEADER_H_

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <map>

#ifdef _WINDLL
#define DllExport __declspec(dllexport)
#else
#define DllExport __declspec(dllimport)
#endif

#define STRING_NULL ""

#ifdef _WIN64
#define BUILD_PLATFORM "x64"
#else
#define BUILD_PLATFORM "x86"
#endif

#endif