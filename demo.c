//
// DL ISO8583 library demo
//

#include "dl_iso8583.h"
#include "dl_iso8583_defs_1987.h"
#include "dl_output.h" // for 'DL_OUTPUT_Hex'



int main ( void )
{
	DL_ISO8583_HANDLER isoHandler;
	DL_ISO8583_MSG     isoMsg;
	DL_UINT8           packBuf[1000];
	DL_UINT16          packedSize;

	/* get ISO-8583 1993 handler */
	DL_ISO8583_DEFS_1987_GetHandler(&isoHandler);

    //
    // Populate/Pack message
    //

	/* initialise ISO message */
	DL_ISO8583_MSG_Init(NULL,0,&isoMsg);

	/* set ISO message fields */
//	const unsigned char *b = "00000000";
	(void)DL_ISO8583_MSG_SetField_Str(0,"0800",&isoMsg);
	(void)DL_ISO8583_MSG_SetField_Str(3,"990000",&isoMsg);
	(void)DL_ISO8583_MSG_SetField_Str(11,"1",&isoMsg);
	(void)DL_ISO8583_MSG_SetField_Str(12,"105029",&isoMsg);
	(void)DL_ISO8583_MSG_SetField_Str(13,"0114",&isoMsg);
	(void)DL_ISO8583_MSG_SetField_Str(42,"19000019",&isoMsg);

	/* output ISO message content */
	DL_ISO8583_MSG_Dump(stdout,NULL,&isoHandler,&isoMsg);
//	printf("the iso8583 is \n%s", &isoMsg);

	/* pack ISO message */
	(void)DL_ISO8583_MSG_Pack(&isoHandler,&isoMsg,packBuf,&packedSize);

	/* free ISO message */
	DL_ISO8583_MSG_Free(&isoMsg);

	/* output packed message (in hex) */
//	DL_OUTPUT_Hex(stdout,NULL,packBuf,packedSize);
//	DL_OUTPUT(NULL, packBuf, packedSize);

	char *s;
    s =  DL_OUTPUT(NULL, packBuf, packedSize);
    printf("%s\n", s);

    char *b;
    b = alpha();
    printf("It is working %s\n", alpha());
    printf("%d\n", (int)strlen(b));
//    free(s);
	//
	// Unpack message
	//

//	/* initialise ISO message */
//	DL_ISO8583_MSG_Init(NULL,0,&isoMsg);
//
//	/* unpack ISO message */
//	(void)DL_ISO8583_MSG_Unpack(&isoHandler,packBuf,packedSize,&isoMsg);
//
//	/* output ISO message content */
//	DL_ISO8583_MSG_Dump(stdout,NULL,&isoHandler,&isoMsg);
//
//	/* free ISO message */
//	DL_ISO8583_MSG_Free(&isoMsg);

	return 0;
}
