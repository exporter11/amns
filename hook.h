#pragma once
#include <Windows.h>
#include <iostream>

void setup_hooks();
void delete_hooks();
void hook(void* p_class, DWORD functionreplacer, int method, void** p_ogfunc);