//
//  ZFImageProgram.h
//  video_recorder
//
//  Created by 韩志峰 on 2024/11/19.
//

#import <Foundation/Foundation.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#define STRINGZE(x) #x
#define STRINGZE2(x) STRINGZE(x)
#define SHADER_STRING(text) @STRINGZE2(text)
NS_ASSUME_NONNULL_BEGIN

@interface ZFImageProgram : NSObject
- (void)use;
- (BOOL)link;
- (GLuint)uniformIndex:(NSString *)uniformName;
- (GLuint)attributeIndex:(NSString *)attributeName;
- (void)addAttribute:(NSString *)attributeName;
- (id) initWithVertextShaderString:(NSString *)vShaderString fragmentShaderString:(NSString *)fShaderString;
@end

NS_ASSUME_NONNULL_END
