
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#elif defined(LV_BUILD_TEST)
#include "../lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_DUST
#define LV_ATTRIBUTE_IMG_DUST
#endif

static const
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_DUST
uint8_t img_touch_24_map[] = {

    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0x10,0xc3,0x18,0xe3,0x20,0xe3,0x20,0xc3,0x18,0x61,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0xe3,0x18,0x82,0x10,0x20,0x08,0x00,0x00,0x00,0x00,0x20,0x08,0x82,0x10,0xc3,0x18,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0xc3,0x18,0x20,0x08,0x00,0x00,0x21,0x08,0x61,0x08,0x61,0x08,0x20,0x00,0x00,0x00,0x41,0x08,0xc3,0x18,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc3,0x18,0x61,0x08,0x00,0x00,0x82,0x10,0xe3,0x20,0x82,0x10,0x62,0x10,0xc3,0x18,0x82,0x10,0x00,0x00,0x61,0x08,0xa2,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0xc3,0x18,0x00,0x00,0x61,0x08,0xa3,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa3,0x18,0x61,0x08,0x00,0x00,0xe3,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x61,0x08,0x82,0x10,0x00,0x00,0xc3,0x18,0x20,0x00,0x61,0x08,0xe3,0x20,0xc3,0x18,0x41,0x08,0x20,0x08,0xc3,0x18,0x00,0x00,0x82,0x10,0x61,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x62,0x10,0x62,0x10,0x00,0x00,0xe3,0x20,0x00,0x00,0xc3,0x18,0x36,0xe6,0xb4,0xd5,0xe3,0x20,0x00,0x00,0xe3,0x20,0x00,0x00,0x62,0x10,0x62,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x61,0x08,0x82,0x10,0x00,0x00,0x61,0x08,0x00,0x00,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0x00,0x00,0x41,0x08,0x00,0x00,0x82,0x10,0x41,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x08,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0xe3,0x20,0xc3,0x18,0x41,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0xf5,0xdd,0x15,0xde,0xe3,0x20,0xe3,0x20,0xc3,0x18,0x41,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0x15,0xde,0x15,0xde,0xe3,0x20,0x61,0x08,0x41,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x82,0x10,0xe3,0x20,0xc3,0x18,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0x0b,0x73,0x2b,0x73,0xa2,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,0x20,0x14,0xee,0x8c,0x8b,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0xf8,0xfe,0xd8,0xfe,0xe3,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,0x20,0x55,0xf6,0xd3,0xe5,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xa6,0x39,0xf8,0xfe,0xf8,0xfe,0xa6,0x39,0xf8,0xfe,0xf8,0xfe,0xa6,0x39,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,0x20,0x55,0xf6,0x14,0xf6,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,0x20,0x55,0xf6,0x14,0xf6,0xe3,0x20,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,0x20,0x55,0xf6,0x14,0xf6,0xa6,0x39,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xe3,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,0x20,0xf4,0xe5,0x55,0xf6,0x96,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0x36,0xe6,0xc3,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa2,0x18,0x0e,0x9c,0x55,0xf6,0x76,0xf6,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xb0,0xac,0xa2,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x08,0xa6,0x39,0x14,0xee,0x55,0xf6,0x97,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0x97,0xee,0xa6,0x39,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x82,0x10,0xa9,0x62,0x14,0xee,0x55,0xf6,0xb7,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0xf8,0xfe,0x97,0xf6,0xa9,0x62,0x82,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x82,0x10,0xa6,0x39,0x4f,0xa4,0xd3,0xdd,0x76,0xf6,0x96,0xfe,0xb7,0xfe,0xb7,0xfe,0x15,0xe6,0x4f,0x9c,0xa6,0x39,0x82,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0xa2,0x10,0xc3,0x18,0xe3,0x20,0xe3,0x20,0xe3,0x20,0xe3,0x20,0xe3,0x20,0xa2,0x10,0x41,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};

const lv_img_dsc_t img_touch_24 = {
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.cf = LV_COLOR_FORMAT_RGB565,
  .header.flags = 0,
  .header.w = 24,
  .header.h = 24,
  .header.stride = 48,
  .data_size = 1152,
  .data = img_touch_24_map,
};

