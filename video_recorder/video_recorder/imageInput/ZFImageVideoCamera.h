//
//  ZFImageVideoCamera.h
//  video_recorder
//
//  Created by 韩志峰 on 2024/11/19.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "HZImageOutput.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZFImageVideoCamera : HZImageOutput<AVCaptureVideoDataOutputSampleBufferDelegate>
- (id)initWithFPS:(int)fps;
- (void)startCapture;
- (void)stopCapture;
- (void)setFrameRate:(int)frameRate;
- (void)setFrameRate;
//切换摄像头: 0-前置 1-后置
- (int)switchFrontBackCamera;
- (void)switchResolution;
@end

NS_ASSUME_NONNULL_END
