//
//  ZFImageContext.h
//  video_recorder
//
//  Created by 韩志峰 on 2024/11/18.
//

#import <Foundation/Foundation.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <CoreMedia/CoreMedia.h>
#import "ZFImageTextureFrame.h"
typedef enum {
    kELImageNoRotation,
    KELImageFlipHorizonal
} ELImageRotationMode;

NS_ASSUME_NONNULL_BEGIN

@interface ZFImageContext : NSObject
@property (nonatomic, readonly) dispatch_queue_t contextQueue;
@property (nonatomic, retain, readonly) EAGLContext *context;
@property (nonatomic, readonly) CVOpenGLESTextureCacheRef coreVideoTextureCache;
+ (void *)contextKey;
// 获取渲染线程的OpenGL上下文
+ (ZFImageContext *)sharedImageProgressingContext;
+ (BOOL)supportsFastTextureUpload;
+ (dispatch_queue_t)sharedContextQueue;
+ (void)useImageProcessingContext;
- (CVOpenGLESTextureCacheRef)coreVideoTextureCache;
- (void)useShareGroup:(EAGLSharegroup *)sharegroup;
- (void)useAsCurrentContext;
@end

NS_ASSUME_NONNULL_END

@protocol ELImageInput <NSObject>

- (void)setInputTexture:(ZFImageTextureFrame *)textureFrame;
// 渲染操作
- (void)newFrameReadyAtTime:(CMTime)frameTime timingInfo:(CMSampleTimingInfo)timingInfo;

@end
