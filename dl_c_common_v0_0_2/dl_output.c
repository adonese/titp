/******************************************************************************/
/*                                                                            */
/* Copyright (C) 2007-2007 Oscar Sanderson                                    */
/*                                                                            */
/* This software is provided 'as-is', without any express or implied          */
/* warranty.  In no event will the author(s) be held liable for any damages   */
/* arising from the use of this software.                                     */
/*                                                                            */
/* Permission is granted to anyone to use this software for any purpose,      */
/* including commercial applications, and to alter it and redistribute it     */
/* freely, subject to the following restrictions:                             */
/*                                                                            */
/* 1. The origin of this software must not be misrepresented; you must not    */
/*    claim that you wrote the original software. If you use this software    */
/*    in a product, an acknowledgment in the product documentation would be   */
/*    appreciated but is not required.                                        */
/*                                                                            */
/* 2. Altered source versions must be plainly marked as such, and must not be */
/*    misrepresented as being the original software.                          */
/*                                                                            */
/* 3. This notice may not be removed or altered from any source distribution. */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/* Output Functions                                                           */
/*                                                                            */
/******************************************************************************/

#include <string.h>
#include "dl_output.h"

/******************************************************************************/
//
// CONSTANTS
//

#define kDL_OUTPUT_HEX_COLS        16

/******************************************************************************/

void DL_OUTPUT_Hex(FILE *iOutFile,
                   const char *_iEolStr,
                   const DL_UINT8 *iPtr,
                   DL_UINT32 iNumBytes) {
    DL_UINT32 rowIdx,
            colIdx;
    char *tmpEOL = _iEolStr == NULL ? "\n" : _iEolStr;

    for (rowIdx = 0; rowIdx < (iNumBytes + kDL_OUTPUT_HEX_COLS - 1) / kDL_OUTPUT_HEX_COLS; rowIdx++) {
        /* output hex characters */
        for (colIdx = 0; colIdx < kDL_OUTPUT_HEX_COLS; colIdx++) {
            DL_UINT32 offset = (rowIdx * kDL_OUTPUT_HEX_COLS) + colIdx;

            if (offset >= iNumBytes)
                fprintf(iOutFile, "");
            else
                fprintf(iOutFile, "%02x", (int) (iPtr[offset]));
        } /* end-for (colIdx) */

    } /* end-for (rowIdx) */

    //fprintf(iOutFile, "%d", strlen(*iPtr));
}


 char * DL_OUTPUT(
         const char *_iEolStr,
         const DL_UINT8 *iPtr,
         DL_UINT32 iNumBytes) {

    DL_UINT32 rowIdx, colIdx;
    char *output = malloc(128);

    for (rowIdx = 0; rowIdx < (iNumBytes + kDL_OUTPUT_HEX_COLS - 1) / kDL_OUTPUT_HEX_COLS; rowIdx++) {
        /* output hex characters */
        for (colIdx = 0; colIdx < kDL_OUTPUT_HEX_COLS; colIdx++) {
            DL_UINT32 offset = (rowIdx * kDL_OUTPUT_HEX_COLS) + colIdx;

            if (offset >= iNumBytes)
                sprintf(output, "");
            else
                sprintf(output, "%02x", (int) (iPtr[offset]));
        } /* end-for (colIdx) */

    } /* end-for (rowIdx) */

    return output;
}

char * alpha(){
    char *digit = malloc(sizeof(char));
    char *output = malloc(sizeof(char));
//    output[sizeof(output)-1] = '\0';
//    output[sizeof(digit)-1] = '\0';

    for (int idx = 0; idx <= 28; idx ++){
        sprintf(digit, "%d", idx);
        strcat(output, digit);
    }

    char *returned = output;
    return returned;
}