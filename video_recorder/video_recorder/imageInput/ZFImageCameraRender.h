//
//  ZFImageCameraRender.h
//  video_recorder
//
//  Created by 韩志峰 on 2024/11/19.
//

#import <Foundation/Foundation.h>
#import "ZFImageContext.h"
NS_ASSUME_NONNULL_BEGIN

@interface ZFImageCameraRender : NSObject
- (BOOL) prepareRender:(BOOL) isFullYUVRange;
- (void) renderWithSampleBuffer: (CMSampleBufferRef) sampleBuffer aspectRatio:(float)aspectRatio preferredConversion:(const GLfloat *)preferredConversion imageRotation:(ELImageRotationMode) inputTextRotaion;
@end

NS_ASSUME_NONNULL_END
