/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

	Copyright (c) GeoWorks 1992 -- All Rights Reserved

PROJECT:	PC GEOS
MODULE:		
FILE:		tif.h

AUTHOR:		Maryann Simmons, May  5, 1992

METHODS:

Name			Description
----			-----------

FUNCTIONS:

Scope	Name			Description
-----	----			-----------

REVISION HISTORY:
	Name	Date		Description
	----	----		-----------
	MS	5/ 5/92   	Initial version.

DESCRIPTION:
	

	$Id: tif.h,v 1.1 97/04/07 11:27:50 newdeal Exp $

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*************************************************************

    TIFF file data structure and constant definition

**************************************************************/

typedef struct tifhdr 
    {
    WORD      byteOrder;    /* 0x4949 for l..m, 0x4d4d for m..lsb */
    WORD      tiffVersion;
    DWORD     ifdOffset;
    } TifHeader;

#define SIZEOFTIFHEADER    8

/*
 * Image File Directory
 */
typedef struct ifd 
    {
    WORD tag;
    WORD type;            /* see defines below             */

#define IFD_BYTE    1
#define IFD_ASCII    2
#define IFD_SHORT    3
#define IFD_LONG    4
#define IFD_RATIONAL    5

    DWORD count;
    DWORD offset;            /* file offset of the actual bits */
    struct ifd *next;
} IFD;

#define  SIZEOFIFD 12

typedef IFD *      PIFD;
typedef IFD FAR *  LPIFD;


/*
 * Internal representation of the header info about an image.
 */
typedef struct {
    DWORD bogus;             /* 1 if we can't deal with this image*/ 
    DWORD height, width;     /* dimensions */
    BYTE resolution;         // 1=full, 2=reduced, 3=single page of many 
    BYTE photoMetric;        // 0 -> 0 is white, 1 -> 0 is black 
    BYTE thresholding;       // 1 = bw scan, else gray-scale 
    BYTE fillOrder;          // 1 -> ms bits filled first, 2 -> ls 
    BYTE orientation;        // see doc 
    BYTE planeConfig;        // 1 = one plane, 2 = mult planes 
    BYTE resUnit;            // 1 no size unit, 2 inches, 3 centimeters 
    BYTE samplesPerPixel;
    BYTE bitsPerSample;
    WORD compression;        // 1 if not compressed 
    DWORD rowsPerStrip;      // number of rows per strip 
    DWORD stripOffset;       // offset to start of strips 
    DWORD stripByteCounts;
    DWORD minValue;
    DWORD maxValue;
    DWORD xResolution;
    DWORD yResolution;
} Image;

/* TIFF TAG mnenomics */
#define TAG_SubfileType            0xff /* obsolete */
#define TAG_NewSubfileType         0xfe
#define TAG_ImageWidth             0x100
#define TAG_ImageLength            0x101
#define TAG_BitsPerSample          0x102
#define TAG_Compression            0x103
#define TAG_PhotometricInterpretation    0x106
#define TAG_Thresholding           0x107 /* obsolete */
#define TAG_CellWidth              0x108 /* obsolete */
#define TAG_CellLength             0x109 /* obsolete */
#define TAG_FillOrder              0x10a /* obsolete */
#define TAG_DocumentName           0x10d /* name of the document where image is
                                       * scanned */
#define TAG_ImageDescription       0x10e /* image description(slug) */
#define TAG_Make                   0x10f /* manufacture of scanner, digitizer */
#define TAG_Model                  0x110 /* scanner, digitizer model */
#define TAG_StripOffsets           0x111
#define TAG_Orientation            0x112 /* obsolete */
#define TAG_SamplesPerPixel        0x115
#define TAG_RowsPerStrip           0x116
#define TAG_StripByteCounts        0x117
#define TAG_MinSampleValue         0x118 /* obsolete */
#define TAG_MaxSampleValue         0x119 /* obsolete */
#define TAG_XResolution            0x11a
#define TAG_YResolution            0x11b
#define TAG_PlanarConfiguration    0x11c
#define TAG_PageName               0x11d // page name of the document where image is
                                       // scanned */
#define TAG_XPosition            0x11e /* x offset of the left of the image */
#define TAG_YPOsition            0x11f /* y offset of the top of the image */
#define TAG_FreeOffsets          0x120 /* obsolete */
#define TAG_FreeByteCounts       0x121 /* obsolete */
#define TAG_GrayResponseUnit     0x122
#define TAG_GrayResponseCurve    0x123
#define TAG_Group3Options        0x124
#define TAG_Group4Options        0x125
#define TAG_ResolutionUnit       0x128
#define TAG_PageNumber           0x129 /* page # of the document where image is
                                       * scanned */
#define TAG_ColorResponseUnit    0x12c
#define TAG_ColorResponseCurves  0x12d
#define TAG_ColorMap             0x140

#define TAG_Software            0x131  /* name of the software used */
#define TAG_DateTime            0x132  /* date & time of creation */
#define TAG_Artish              0x13B  /* Artist/Creator of the image */
#define TAG_HostComputer        0x13C  /* host computer system */
#define TAG_Predictor           0x13D  /* new TAG, not supported */

/* link list for stip offsets */

typedef struct  Strip {
   DWORD  stripOffset;
   DWORD  stripByteCount;
   struct Strip FAR *next;
} STRIP;

typedef STRIP * PSTRIP;
typedef STRIP FAR * LPSTRIP;

void    FreeAllNodes    (IFD *);    /* has to come after IFD typedef */
void    FreeStripNodes  (LPSTRIP);

int     WriteOutputToFile ( HWND );

WORD    fixword    (WORD);     // 68000 integer format! 
DWORD   fixdword   (DWORD);    // 68000 long integer format! 


/* error number mnenomics */
#define     TAGNOTSUPPORT       8

