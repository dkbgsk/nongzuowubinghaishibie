

#include <iostream>
#include "unistd.h"
#include "sdk.h"
#include "sample_media_ai.h"
#include "sample_media_opencv.h"

using namespace std;

/*
 * 函数：显示用法
 * function: show usage
 */
static void SAMPLE_AI_Usage(char* pchPrgName)
{
    printf("Usage : %s <index> \n", pchPrgName);
    printf("index:\n");
    printf("\t 0) cnn trash_classify(resnet18).\n");
    printf("\t 1) hand classify(yolov2+resnet18).\n");
    printf("\t 2) tennis detect(opencv).\n");
}

/*
 * 函数：ai sample主函数
 * function : ai sample main function
 */
int main(int argc, char *argv[])
{
    HI_S32 s32Ret = HI_FAILURE;
    sample_media_opencv mediaOpencv;
    if (argc < 2 || argc > 2) { // 2: argc indicates the number of parameters
        SAMPLE_AI_Usage(argv[0]);
        return HI_FAILURE;
    }

    if (!strncmp(argv[1], "-h", 2)) { // 2: used to compare the first 2 characters
        SAMPLE_AI_Usage(argv[0]);
        return HI_SUCCESS;
    }
    sdk_init();
    /*
     * MIPI为GPIO55，开启液晶屏背光
     * MIPI is GPIO55, Turn on the backlight of the LCD screen
     */
    system("cd /sys/class/gpio/;echo 55 > export;echo out > gpio55/direction;echo 1 > gpio55/value");

    switch (*argv[1]) {
        case '0':
            SAMPLE_MEDIA_CNN_TRASH_CLASSIFY();
            break;
        case '1':
            SAMPLE_MEDIA_HAND_CLASSIFY();
            break;
        case '2':
            mediaOpencv.SAMPLE_MEDIA_TENNIS_DETECT();
            break;
        default:
            SAMPLE_AI_Usage(argv[0]);
            break;
    }
    sdk_exit();
    SAMPLE_PRT("\nsdk exit success\n");
    return s32Ret;
}
