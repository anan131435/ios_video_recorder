//
//  ZFImageVideoCamera.m
//  video_recorder
//
//  Created by 韩志峰 on 2024/11/19.
//

#import "ZFImageVideoCamera.h"
// color conversion (YUV to RGB)
// BT.601 which is the standrad for SDTV
GLfloat colorConversion601Default[] = {
    1.164,  1.164, 1.164,
    0.0, -0.392, 2.017,
    1.596, -0.813,   0.0,
};
// BT.601 full range
GLfloat colorConversion601FullRangeDefault[] = {
    1.0,    1.0,    1.0,
    0.0,    -0.343, 1.765,
    1.4,    -0.711, 0.0,
};
// BT.709 which is the standrad for HDTV
GLfloat colorConversion709Default[] = {
    1.164,  1.164, 1.164,
    0.0, -0.213, 2.112,
    1.793, -0.533,   0.0,
};

GLfloat *colorConversion601 = colorConversion601Default;
GLfloat *colorConversion601FullRange = colorConversion601FullRangeDefault;
GLfloat *colorConversion709 = colorConversion709Default;

@interface ZFImageVideoCamera () {
    dispatch_queue_t _sampleBufferCallbackQueue;
    int32_t _frameRate;
    dispatch_semaphore_t _frameRenderingSemaphone;
    
}

@end


@implementation ZFImageVideoCamera

@end
