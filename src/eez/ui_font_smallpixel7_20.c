/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --user-data-dir=C:\Users\David\AppData\Roaming\eezstudio --app-path=C:\Users\David\AppData\Local\Programs\eezstudio\resources\app.asar --no-sandbox --no-zygote --node-integration-in-worker --lang=en-US --device-scale-factor=1 --num-raster-threads=4 --enable-main-frame-before-activation --renderer-client-id=5 --time-ticks-at-unix-epoch=-1717659134851911 --launch-time-ticks=987744505778 --mojo-platform-channel-handle=2664 --field-trial-handle=1652,i,9902630094467640076,1636136552042263741,262144 --enable-features=kWebSQLAccess --disable-features=SpareRendererForSitePerProcess,WinDelaySpellcheckServiceInit,WinRetrieveSuggestionsOnlyOnDemand --variations-seed-version /prefetch:1
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef UI_FONT_SMALLPIXEL7_20
#define UI_FONT_SMALLPIXEL7_20 1
#endif

#if UI_FONT_SMALLPIXEL7_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xfc, 0xf0,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x66, 0x66, 0xff, 0xff, 0x66, 0x66, 0xff, 0xff,
    0x66, 0x66,

    /* U+0024 "$" */
    0x18, 0x7e, 0xff, 0xdb, 0xd8, 0xfe, 0x7f, 0x1b,
    0xdb, 0xff, 0x7e, 0x18,

    /* U+0025 "%" */
    0xe1, 0xe3, 0xe7, 0xe, 0x1c, 0x38, 0x70, 0xe7,
    0xc7, 0x87,

    /* U+0026 "&" */
    0x7c, 0xfe, 0xc6, 0xee, 0x75, 0x3b, 0xdc, 0xce,
    0xf7, 0x7b,

    /* U+0027 "'" */
    0xff,

    /* U+0028 "(" */
    0x36, 0xcc, 0xcc, 0xcc, 0x63,

    /* U+0029 ")" */
    0xc6, 0x33, 0x33, 0x33, 0x6c,

    /* U+002A "*" */
    0xd7, 0xac, 0xe7, 0xf3, 0x9a, 0xf5, 0x80,

    /* U+002B "+" */
    0x30, 0xcf, 0xff, 0x30, 0xc0,

    /* U+002C "," */
    0xdc, 0x80,

    /* U+002D "-" */
    0xff, 0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x1, 0x3, 0x7, 0xe, 0x1c, 0x38, 0x70, 0xe0,
    0xc0, 0x80,

    /* U+0030 "0" */
    0x7e, 0xff, 0xc7, 0xcf, 0xdf, 0xfb, 0xf3, 0xe3,
    0xff, 0x7e,

    /* U+0031 "1" */
    0xf3, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0xff, 0xf0,

    /* U+0032 "2" */
    0x7e, 0xff, 0xc3, 0x3, 0x7f, 0xfe, 0xc0, 0xc0,
    0xff, 0xff,

    /* U+0033 "3" */
    0x7e, 0xff, 0xc3, 0x3, 0x3e, 0x3e, 0x3, 0xc3,
    0xff, 0x7e,

    /* U+0034 "4" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xff, 0x3, 0x3,
    0x3, 0x3,

    /* U+0035 "5" */
    0xff, 0xff, 0xc0, 0xc0, 0xfe, 0xff, 0x3, 0xc3,
    0xff, 0x7e,

    /* U+0036 "6" */
    0x7e, 0xff, 0xc3, 0xc0, 0xfe, 0xff, 0xc3, 0xc3,
    0xff, 0x7e,

    /* U+0037 "7" */
    0x7e, 0xff, 0xc3, 0xc3, 0xc3, 0x3, 0x3, 0x3,
    0x3, 0x3,

    /* U+0038 "8" */
    0x7e, 0xff, 0xc3, 0xc3, 0x7e, 0x7e, 0xc3, 0xc3,
    0xff, 0x7e,

    /* U+0039 "9" */
    0x7e, 0xff, 0xc3, 0xc3, 0xff, 0x7f, 0x3, 0xc3,
    0xff, 0x7e,

    /* U+003A ":" */
    0xf0, 0xf0,

    /* U+003B ";" */
    0xd8, 0x0, 0x37, 0x20,

    /* U+003C "<" */
    0x8, 0xce, 0xee, 0x38, 0xe3, 0x8,

    /* U+003D "=" */
    0xff, 0xf0, 0x3f, 0xfc,

    /* U+003E ">" */
    0x86, 0x38, 0xe3, 0xbb, 0x98, 0x80,

    /* U+003F "?" */
    0x7e, 0xff, 0xc3, 0x3, 0x1f, 0x1e, 0x18, 0x0,
    0x18, 0x18,

    /* U+0040 "@" */
    0x7e, 0xff, 0xc3, 0xdb, 0xdb, 0xdf, 0xdf, 0xc0,
    0xff, 0x7f,

    /* U+0041 "A" */
    0x7e, 0xff, 0xc3, 0xc3, 0xff, 0xff, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+0042 "B" */
    0xfe, 0xff, 0xc3, 0xc3, 0xfe, 0xfe, 0xc3, 0xc3,
    0xff, 0xfe,

    /* U+0043 "C" */
    0x7e, 0xff, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0, 0xc3,
    0xff, 0x7e,

    /* U+0044 "D" */
    0xfc, 0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xfe, 0xfc,

    /* U+0045 "E" */
    0xff, 0xff, 0xc0, 0xc0, 0xfe, 0xfe, 0xc0, 0xc0,
    0xff, 0xff,

    /* U+0046 "F" */
    0xff, 0xff, 0xc0, 0xc0, 0xfe, 0xfe, 0xc0, 0xc0,
    0xc0, 0xc0,

    /* U+0047 "G" */
    0x7e, 0xff, 0xc3, 0xc0, 0xcf, 0xcf, 0xc3, 0xc3,
    0xff, 0x7e,

    /* U+0048 "H" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xff, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+0049 "I" */
    0xff, 0x66, 0x66, 0x66, 0xff,

    /* U+004A "J" */
    0xff, 0xff, 0xc3, 0xc3, 0x3, 0x3, 0x3, 0xc3,
    0xff, 0x7e,

    /* U+004B "K" */
    0xc3, 0xc7, 0xce, 0xdc, 0xf8, 0xf8, 0xdc, 0xce,
    0xc7, 0xc3,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc3,
    0xff, 0xff,

    /* U+004D "M" */
    0x81, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3,
    0xc3, 0xc3,

    /* U+004E "N" */
    0x83, 0xc3, 0xe3, 0xf3, 0xfb, 0xdf, 0xcf, 0xc7,
    0xc3, 0xc1,

    /* U+004F "O" */
    0x7e, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xff, 0x7e,

    /* U+0050 "P" */
    0xfe, 0xff, 0xc3, 0xc3, 0xff, 0xfe, 0xc0, 0xc0,
    0xc0, 0xc0,

    /* U+0051 "Q" */
    0x7e, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xcf, 0xcb,
    0xfd, 0x7f,

    /* U+0052 "R" */
    0xfe, 0xff, 0xc3, 0xc3, 0xff, 0xfe, 0xf8, 0xdc,
    0xce, 0xc7,

    /* U+0053 "S" */
    0x7e, 0xff, 0xc3, 0xc0, 0xfe, 0x7f, 0x3, 0xc3,
    0xff, 0x7e,

    /* U+0054 "T" */
    0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+0055 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xff, 0x7e,

    /* U+0056 "V" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e,
    0x3c, 0x18,

    /* U+0057 "W" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xdb, 0xdb, 0xdb,
    0xff, 0x66,

    /* U+0058 "X" */
    0xc3, 0xe7, 0x7e, 0x3c, 0x18, 0x18, 0x3c, 0x7e,
    0xe7, 0xc3,

    /* U+0059 "Y" */
    0xc3, 0xc3, 0xc3, 0xe7, 0x7e, 0x3c, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xff, 0xff, 0x7, 0xe, 0x1c, 0x38, 0x70, 0xe0,
    0xff, 0xff,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xff,

    /* U+005C "\\" */
    0x80, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7,
    0x3, 0x1,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0xff,

    /* U+005E "^" */
    0x10, 0x71, 0xf7, 0x7c, 0x60,

    /* U+005F "_" */
    0xff, 0xff,

    /* U+0060 "`" */
    0xce, 0x73,

    /* U+0061 "a" */
    0x7c, 0xfc, 0x1b, 0xff, 0xf8, 0xf1, 0xff, 0x7e,

    /* U+0062 "b" */
    0xc1, 0x83, 0x7, 0xef, 0xf8, 0xf1, 0xe3, 0xff,
    0xf8,

    /* U+0063 "c" */
    0x7f, 0xff, 0x6, 0xc, 0x18, 0x30, 0x7f, 0x7e,

    /* U+0064 "d" */
    0x6, 0xc, 0x1b, 0xff, 0xf8, 0xf1, 0xe3, 0xfe,
    0xfc,

    /* U+0065 "e" */
    0x7d, 0xff, 0x1e, 0x3f, 0xff, 0xf0, 0x7f, 0x7e,

    /* U+0066 "f" */
    0x3d, 0xf6, 0x18, 0xfb, 0xe6, 0x18, 0x61, 0x80,

    /* U+0067 "g" */
    0x7f, 0xff, 0x1e, 0x3c, 0x7f, 0xdf, 0x83, 0x7e,
    0xf8,

    /* U+0068 "h" */
    0xc1, 0x83, 0x7, 0xef, 0xf8, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+0069 "i" */
    0xf3, 0xff, 0xf0,

    /* U+006A "j" */
    0x18, 0xc0, 0x31, 0x8c, 0x63, 0x1f, 0xfc,

    /* U+006B "k" */
    0xc1, 0x8f, 0x3e, 0xef, 0x9e, 0x3e, 0x6e, 0xcf,
    0x8c,

    /* U+006C "l" */
    0xff, 0xff, 0xf0,

    /* U+006D "m" */
    0xfe, 0xff, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb,
    0xdb,

    /* U+006E "n" */
    0xfd, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,

    /* U+006F "o" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xff, 0x7c,

    /* U+0070 "p" */
    0xfd, 0xff, 0x1e, 0x3c, 0x7f, 0xff, 0x60, 0xc1,
    0x80,

    /* U+0071 "q" */
    0x7f, 0xff, 0x1e, 0x3c, 0x7f, 0xdf, 0x83, 0x6,
    0xc,

    /* U+0072 "r" */
    0xdd, 0xff, 0x9e, 0xc, 0x18, 0x30, 0x60, 0xc0,

    /* U+0073 "s" */
    0x7f, 0xff, 0x6, 0x7, 0xc0, 0xc1, 0xff, 0xfc,

    /* U+0074 "t" */
    0x61, 0x8f, 0xbe, 0x61, 0x86, 0x18, 0x7c, 0xf0,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff, 0x7e,

    /* U+0076 "v" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7d, 0xdf, 0x1c, 0x10,

    /* U+0077 "w" */
    0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xff,
    0x66,

    /* U+0078 "x" */
    0xc7, 0xdd, 0xf1, 0xc3, 0x87, 0x1f, 0x77, 0xc6,

    /* U+0079 "y" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7f, 0xdf, 0x83, 0x7e,
    0xf8,

    /* U+007A "z" */
    0xff, 0xfc, 0x38, 0xe3, 0x8e, 0x38, 0x7f, 0xfe,

    /* U+007B "{" */
    0x3b, 0x98, 0xcc, 0x61, 0x8c, 0x71, 0xc0,

    /* U+007C "|" */
    0xff, 0xff, 0xf0,

    /* U+007D "}" */
    0xe3, 0x8c, 0x61, 0x8c, 0xc6, 0x77, 0x0,

    /* U+007E "~" */
    0x63, 0xe6, 0x7c, 0x60
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 160, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 144, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 144, .box_w = 5, .box_h = 4, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 7, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 144, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 29, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 49, .adv_w = 144, .box_w = 2, .box_h = 4, .ofs_x = 3, .ofs_y = 6},
    {.bitmap_index = 50, .adv_w = 144, .box_w = 4, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 144, .box_w = 4, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 60, .adv_w = 144, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 67, .adv_w = 144, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 72, .adv_w = 144, .box_w = 3, .box_h = 3, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 74, .adv_w = 144, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 76, .adv_w = 144, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 144, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 175, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 144, .box_w = 2, .box_h = 6, .ofs_x = 3, .ofs_y = 2},
    {.bitmap_index = 187, .adv_w = 144, .box_w = 3, .box_h = 9, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 191, .adv_w = 144, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 144, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 201, .adv_w = 144, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 144, .box_w = 4, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 322, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 392, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 442, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 462, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 472, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 144, .box_w = 4, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 144, .box_w = 4, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 502, .adv_w = 144, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 507, .adv_w = 144, .box_w = 8, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 509, .adv_w = 144, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 511, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 519, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 528, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 144, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 561, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 570, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 579, .adv_w = 144, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 144, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 598, .adv_w = 144, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 618, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 626, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 635, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 644, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 652, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 660, .adv_w = 144, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 668, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 676, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 684, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 701, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 710, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 718, .adv_w = 144, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 725, .adv_w = 144, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 728, .adv_w = 144, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 735, .adv_w = 144, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_smallpixel7_20 = {
#else
lv_font_t ui_font_smallpixel7_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 12,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if UI_FONT_SMALLPIXEL7_20*/

