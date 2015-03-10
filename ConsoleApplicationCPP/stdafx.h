// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

#define _property(_type, _name, _get, _put) __declspec(property(get=_get, put=_put)) _type _name
#define _property_readonly(_type, _name, _get) __declspec(property(get=_get)) _type _name
