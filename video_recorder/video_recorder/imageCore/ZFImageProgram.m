//
//  ZFImageProgram.m
//  video_recorder
//
//  Created by 韩志峰 on 2024/11/19.
//

#import "ZFImageProgram.h"

@implementation ZFImageProgram {
    NSMutableArray *attributes;
    NSMutableArray *uniforms;
    GLuint program;
    GLuint vertShader;
    GLuint fragShader;
}

- (void)use {
    glUseProgram(program);
}
- (id)initWithVertextShaderString:(NSString *)vShaderString fragmentShaderString:(NSString *)fShaderString {
    self = [super init];
    if (self) {
        attributes = [NSMutableArray new];
        uniforms = [NSMutableArray new];
        program = glCreateProgram();
    }
    return self;
}
- (BOOL)compileShader:(GLuint *)shader
                 type:(GLenum)type
               string:(NSString *)shaderString {
    GLint status;
    const GLchar *source;
    source = (GLchar *)[shaderString UTF8String];
    if (!source) {
        NSLog(@"Failed to load vertex shader");
        return NO;
    }
    *shader = glCreateShader(type);
    glShaderSource(*shader, 1, &source, NULL);
    glCompileShader(*shader);
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &status);
    return  status == GL_TRUE;
    return YES;
}

@end
