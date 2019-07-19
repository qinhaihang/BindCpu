//
// Created by qinhaihang_vendor on 2019/7/19.
//

#include <jni.h>
#include <android/log.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/syscall.h>

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>

//#define __USE_GNU

#include<sched.h>
#include<ctype.h>

#define THREAD_MAX_NUM 100   //1个CPU内的最多进程数

int num = 0; //cpu中核数

#define TAG "Affinity"
#define DEBUG 1

#ifndef CPU_ZERO
#define CPU_SETSIZE 1024
#define __NCPUBITS (8 * sizeof (unsigned long))
typedef struct
{
    unsigned long __bits[CPU_SETSIZE / __NCPUBITS];
} cpu_set_t;

#define CPU_SET(cpu, cpusetp) \
   ((cpusetp)->__bits[(cpu)/__NCPUBITS] |= (1UL << ((cpu) % __NCPUBITS)))
#define CPU_ZERO(cpusetp) \
   memset((cpusetp), 0, sizeof(cpu_set_t))
#else
//#define CPU_SET(cpu, cpustep) ((void)0)
//#define CPU_ZERO(cpu, cpustep) ((void)0)
#endif

#ifdef DEBUG
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
#else
#define LOGD(...) ((void)0)
#define LOGE(...) ((void)0)
#endif

static int getCores() {
    return sysconf(_SC_NPROCESSORS_CONF);
}

extern "C" JNIEXPORT jint JNICALL
Java_com_sensetime_bindcpu_BindToCpu_getCores(JNIEnv *env, jclass type) {
    return getCores();
}

extern "C" JNIEXPORT void JNICALL
Java_com_sensetime_bindcpu_BindToCpu_bindToCpu(JNIEnv *env, jclass type, jint cpu) {
    int cores = getCores();
    LOGD("get cpu number = %d\n", cores);
    if (cpu >= cores) {
        LOGE("your set cpu is beyond the cores,exit...");
        return;
    }

    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(cpu, &mask);
    if (sched_setaffinity(0, sizeof(mask), &mask) == -1)//设置线程CPU亲和力
    {
        LOGD("warning: could not set CPU affinity, continuing...\n");
    } else {
        LOGD("set affinity to %d success", cpu);
    }
}
