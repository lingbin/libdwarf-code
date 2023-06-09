/*
Copyright (c) 2023, David Anderson All rights reserved.

Redistribution and use in source and binary forms, with
or without modification, are permitted provided that the
following conditions are met:

    Redistributions of source code must retain the above
    copyright notice, this list of conditions and the following
    disclaimer.

    Redistributions in binary form must reproduce the above
    copyright notice, this list of conditions and the following
    disclaimer in the documentation and/or other materials
    provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#if 0
#ifndef LLONG_MAX
#define LLONG_MAX    9223372036854775807LL
#endif
#ifndef LLONG_MIN
#define LLONG_MIN    (-LLONG_MAX - 1LL)
#endif
#ifndef ULLONG_MAX
#define ULLONG_MAX   18446744073709551615ULL
#endif
#endif /* 0 */

/* See:
https://stackoverflow.com/questions/3944505/detecting-signed-overflow-in-c-c
*/
int _dwarf_add_check(Dwarf_Signed l, Dwarf_Signed r,
    Dwarf_Signed *sum, Dwarf_Debug dbg,
    Dwarf_Error *error);

/*  Thanks to David Grayson/
codereview.stackexchange.com/questions/98791/
safe-multiplication-of-two-64-bit-signed-integers
*/

int _dwarf_int64_mult(Dwarf_Signed x, Dwarf_Signed y,
    Dwarf_Signed * result, Dwarf_Debug dbg,
    Dwarf_Error*error);

int _dwarf_uint64_mult(Dwarf_Unsigned x, Dwarf_Unsigned y,
    Dwarf_Unsigned * result, Dwarf_Debug dbg,
    Dwarf_Error *error);
