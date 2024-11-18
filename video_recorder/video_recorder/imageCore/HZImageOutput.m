//
//  HZImageOutput.m
//  video_recorder
//
//  Created by 韩志峰 on 2024/11/18.
//

#import "HZImageOutput.h"
void runSyncOnVideoProcessingQueue(void (^block)(void)) {
    dispatch_queue_t videoProgressingQueue = [ZFImageContext sharedContextQueue];
    if (dispatch_get_specific([ZFImageContext contextKey])) {
        block();
    } else {
        dispatch_sync(videoProgressingQueue, block);
    }
}
void runAsyncOnVideoProcessingQueue(void (^block)(void)) {
    dispatch_queue_t videoProgressingQueue = [ZFImageContext sharedContextQueue];
    if (dispatch_get_specific([ZFImageContext contextKey])) {
        block();
    } else {
        dispatch_async(videoProgressingQueue, block);
    }
}
void runSyncOnContextQueue(ZFImageContext *context, void(^block)(void)) {
    dispatch_queue_t videoProgressingQueue = [context contextQueue];
    if (dispatch_get_specific([ZFImageContext contextKey])) {
        block();
    } else {
        dispatch_sync(videoProgressingQueue, block);
    }
}
void runAsyncOnContextQueue(ZFImageContext *context,void(^block)(void)) {
    
}

@implementation HZImageOutput

@end
