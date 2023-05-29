/*
Copyright (c) 2023, David Anderson
All rights reserved.

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
#ifndef DWARF_ELF_INTERFACE_H
#define DWARF_ELF_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* A few return DW_DLV_OK, DW_DLV_OK, or DW_DLV_NO_ENTRY; */

/*  elf_begin()   create a Dwarf_Elf header record.  */
int _dwarf_elf_begin(int fd, int cmd, Dwarf_Elf **ret_de);

/* elf_end()          Clean up allocated data.  */
int _dwarf_elf_end(Dwarf_Elf*elf);

/*
elf_ndxscn() Get its section number in Elf
Return DW_DLV_OK or DW_DLV_ERROR */
int  _dwarf_elf_ndxscn(DW_Elf_Scn* sec, Dwarf_Unsigned*elf_sec_num);

dw_elf32_ehdr * _dwarf_elf32_newehdr(Dwarf_Elf *);
dw_elf64_ehdr * _dwarf_elf64_newehdr(Dwarf_Elf *);

DW_Elf_Scn    * _dwarf_elf_getscn(Dwarf_Elf*,Dwarf_Unsigned secindex);  

dw_elf32_shdr * _dwarf_elf32_getshdr(DW_Elf_Scn *scn);  
dw_elf64_shdr * _dwarf_elf64_getshdr(DW_Elf_Scn *scn); 

/* elf_getdata()    Retrieve section content data */
DW_Elf_Data * _dwarf_elf_getdata(DW_Elf_Scn *scn,DW_Elf_Data*prev);

/* For adding Dwarf or text or whatever data */
DW_Elf_Data * _dwarf_elf_newdata(DW_Elf_Scn* section);

/*  Creating a new section header */
DW_Elf_Scn * _dwarf_elf_newscn(Dwarf_Elf *);

/*  _dwarf elf_update()     create Elf and Section headers
    and turn internal DWARF etc into character
    blobs (one per section)
    and Write all to the output object file.
*/
int _dwarf_elf_update(Dwarf_Elf *elf, Dwarf_Unsigned *sizefinal);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* DWARF_ELF_INTERFACE_H */

