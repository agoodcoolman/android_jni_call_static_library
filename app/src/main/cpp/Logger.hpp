//
// Created by Administrator on 2016/12/14.
//
#define TAG "kaikai"
#define NDK_LOG true
#include <android/log.h>

#ifdef NDK_LOG
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG, __VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG, __VA_ARGS__)
/*#elif C_LOG
#define log_print_verbose( ...)  printf(fmt, ##__VA_ARGS__)
#define log_print_debug( ...) printf(fmt, ##__VA_ARGS__)
#define log_print_info( ...) printf(fmt, ##__VA_ARGS__)
#define log_print_warn( ...)  printf(fmt, ##__VA_ARGS__)
#define log_print_error( ...) printf(fmt,  ##__VA_ARGS__)
#else
#define log_print_verbose( ...)
#define log_print_debug( ...)
#define log_print_info( ...)
#define log_print_warn( ...)
#define log_print_error( ...)*/
#endif
/*


#define LOGV( ... ) log_print_verbose( ##__VA_ARGS__)
#define LOGD( ... ) log_print_debug( ##__VA_ARGS__)
//#define LOGI( ... ) log_print_info( __VA_ARGS__)
#define LOGW( ... ) log_print_warn( ##__VA_ARGS__)
#define LOGE( ... ) log_print_error( ##__VA_ARGS__)
*/




