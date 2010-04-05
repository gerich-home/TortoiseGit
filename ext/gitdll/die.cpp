#include "stdafx.h"
#include "gitdll.h"
#include "stdio.h"

#define MAX_ERROR_STR_SIZE 512
extern "C" char g_last_error[MAX_ERROR_STR_SIZE]={0};

extern "C" void die_dll(const char *err, va_list params)
{
	memset(g_last_error,0,MAX_ERROR_STR_SIZE);
	vsnprintf(g_last_error, MAX_ERROR_STR_SIZE-1, err, params);	
	throw g_last_error;
}