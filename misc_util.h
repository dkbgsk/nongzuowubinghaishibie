

#ifndef MISC_UTIL_H
#define MISC_UTIL_H

#include <stdbool.h>
#include <stdint.h>

#include "ai_infer_process.h"

#if __cplusplus
extern "C" {
#endif

/*
 * RGB888常用的颜色
 * RGB888 commonly used colors
 */
#define RGB888_RED          ((uint32_t)0xFF0000)
#define RGB888_GREEN        ((uint32_t)0x00FF00)
#define RGB888_BLUE         ((uint32_t)0x0000FF)
#define RGB888_YELLOW       ((uint32_t)0xFFFF00)
#define RGB888_WHITE        ((uint32_t)0xFFFFFF)
#define RGB888_BLACK        ((uint32_t)0x000000)

/*
 * 将整数放大到给定的倍数范围
 * Amplify the integer to the given multiple range
 */
int IntZoomTo(int n, double rate, double rateMin, double rateMax);

/*
 * 按比例转换坐标
 * Convert coordinates proportionally
 */
void RectBoxTran(RectBox* box, int srcWidth, int srcHeight, int dstWidth, int dstHeight);

#ifdef __cplusplus
}
#endif
#endif
