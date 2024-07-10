

#ifndef BASE_INTERFACE_H
#define BASE_INTERFACE_H

#include <stdint.h>
#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif

HI_S32 ConfBaseInit(const char* cfgFilePath);
bool IsMainThrd(void);
void ConfBaseExt(void);

int GetCfgInt(const char* key, int defVal);
double GetCfgDouble(const char* key, double defVal);
bool GetCfgBool(const char* key, bool defVal);
const char* GetCfgStr(const char* key, const char* defVal);

int SectGetCfgInt(const char* section, const char* field, int defVal);
double SectGetCfgDouble(const char* section, const char* field, double defVal);
bool SectGetCfgBool(const char* section, const char* field, bool defVal);
const char* SectGetCfgStr(const char* section, const char* field, const char* defVal);

int HiStrxfrm(char *s1, char *s2, int n);

#ifdef __cplusplus
}
#endif
#endif
