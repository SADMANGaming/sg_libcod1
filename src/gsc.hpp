#ifndef _GSC_HPP_
#define _GSC_HPP_

#define COD1_1_1 111
#define COD1_1_5 115

/* default stuff */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <dlfcn.h> // dlcall
#include <stdarg.h> // va_args
#include <unistd.h> // link, unlink, usleep
#include <dirent.h> // dir stuff
#include <sys/mman.h> // mprotect
#include <execinfo.h> // stacktrace
#include <stddef.h> // offsetof
#include <ctype.h> // toupper
#include <time.h>  // getsystemtime
#include <sys/time.h> // milliseconds
#include <sys/stat.h> // fsize

#include "config.hpp"
#include "declarations.hpp"
#include "cracking.hpp"
#include "functions.hpp"

#include "gsc_entity.hpp"

#if COD_VERSION == COD1_1_5
#include "jump.hpp"
#endif

#if COMPILE_SQLITE == 1
#include "gsc_sqlite.hpp"
#endif

#include "gsc_player.hpp"
#include "gsc_utils.hpp"

#define STACK_UNDEFINED 0
#define STACK_STRING 1
#define STACK_LOCALIZED_STRING 2
#define STACK_VECTOR 3
#define STACK_FLOAT 4
#define STACK_INT 5
#define STACK_OBJECT 7
#define STACK_FUNCTION 9

#define stackPushUndefined Scr_AddUndefined
#define stackPushBool Scr_AddBool
#define stackPushInt Scr_AddInt
#define stackPushFloat Scr_AddFloat
#define stackPushString Scr_AddString
#define stackPushVector Scr_AddVector
#define stackPushEntity Scr_AddEntity
#define stackPushArray Scr_MakeArray
#define stackPushArrayLast Scr_AddArray
#define stackPushObject Scr_AddObject
#define stackPushFunc Scr_AddFunc

#ifndef Q_vsnprintf
int Q_vsnprintf(char *s0, size_t size, const char *fmt, va_list args);
#endif

#ifndef strcmp_constant_time
int strcmp_constant_time(const char *s1, const char *s2);
#endif

int stackGetParams(const char *params, ...);
void stackError(const char *format, ...);

int stackGetParamInt(int param, int *value);
int stackGetParamFunction(int param, int *value);
int stackGetParamString(int param, char **value);
int stackGetParamConstString(int param, unsigned int *value);
int stackGetParamLocalizedString(int param, char **value);
int stackGetParamVector(int param, vec3_t value);
int stackGetParamFloat(int param, float *value);
int stackGetParamObject(int param, unsigned int *value);

xfunction_t Scr_GetCustomFunction(const char **fname, qboolean *fdev);
xmethod_t Scr_GetCustomMethod(const char **fname, qboolean *fdev);

uint64_t Sys_Milliseconds64(void);
char *custom_va(const char *format, ...);


//void gsc_testcommand(scr_entref_t ref);

#endif