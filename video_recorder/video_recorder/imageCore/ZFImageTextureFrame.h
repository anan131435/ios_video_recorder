//
//  ZFImageTextureFrame.h
//  video_recorder
//
//  Created by 韩志峰 on 2024/11/18.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <CoreGraphics/CGGeometry.h>

typedef struct GPUTextureFrameOptions{
    GLenum mainFilter;
    GLenum magFilter;
    GLenum warpS;
    GLenum warpT;
    GLenum internalFormat;
    GLenum format;
    GLenum type;
} GPUTextureFrameOptions;

NS_ASSUME_NONNULL_BEGIN
// 纹理对象
@interface ZFImageTextureFrame : NSObject
- (id)initWithSize:(CGSize) framebufferSize;
- (id)initWithSize:(CGSize)framebufferSize textureOptions:(GPUTextureFrameOptions) options;
@end

NS_ASSUME_NONNULL_END
