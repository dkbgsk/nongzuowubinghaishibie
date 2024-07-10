

#ifndef POSIX_HELP_H
#define POSIX_HELP_H

#include <errno.h>
#include <strings.h>
#include <stdint.h>
#include <netinet/in.h>
#include <pthread.h>

#if __cplusplus
extern "C" {
#endif

#define HI_USLEEP_MS    1000

/*
 * Socketpair通道
 * Socketpair channel
 */
typedef struct SkPair {
    int in; // in fd
    int out; // out fd
} SkPair;

/*
 * 创建Socketpair
 * Socketpair create
 */
int SkPairCreate(SkPair* chn);

/*
 * 读完整的消息
 * Read complete message
 */
int FdReadMsg(int fd, HI_VOID* msgBuf, int msgSize);

/*
 * 写完整的消息
 * Write complete message
 */
int FdWriteMsg(int fd, const HI_VOID* msgData, int msgLen);

/*
 * 销毁socketpair
 * Socketpair destroy
 */
void SkPairDestroy(SkPair* chn);

/*
 * 初始化recursive pmutex
 * Init recursive pmutex
 */
void RecurMutexInit(pthread_mutex_t* mutex);

#ifdef __cplusplus
}
#endif
#endif
