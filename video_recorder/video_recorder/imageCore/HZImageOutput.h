//
//  HZImageOutput.h
//  video_recorder
//
//  Created by 韩志峰 on 2024/11/18.
//

#import <Foundation/Foundation.h>
#import "ZFImageTextureFrame.h"
#import "ZFImageContext.h"
void runSyncOnVideoProcessingQueue(void (^block)(void));
void runAsyncOnVideoProcessingQueue(void (^block)(void));
void runSyncOnContextQueue(NSObject *context, void(^block)(void));
void runAsyncOnContextQueue(NSObject *context,void(^block)(void));

NS_ASSUME_NONNULL_BEGIN
// 这个类可以向自己的后级节点输出目标纹理对象
// 每一个继承这个类的节点，执行渲染过程结束后，就会遍历targets里面所有的目标节点（即 ELImageInput），执行设置输出纹理对象的方法，然后执行下一个节点的渲染过程
/*
 for(id<ELImageInput> currentTarget in targets) {
    
    [currentTarget setInputTexture: outputTextureFrame]
    [currentTarget newFrameReadyAtTime:frameTime timingInfo:timingInfo]
 
 }
 */
@interface HZImageOutput : NSObject {
    // 输出的纹理对象
    ZFImageTextureFrame *outputTexture;
    //后级节点列表，比如Filter节点的后级列表： GLImageView VideoEncoder
    NSMutableArray<id<ELImageInput>> *targets;
}

- (void)setInputTextureForTarget:(id<ELImageInput>)tartget;
- (ZFImageTextureFrame *)framebuferForOutput;
- (NSArray *)targets;
- (void)addTarget:(id<ELImageInput>)newTarget;
- (void)removeTarget: (id<ELImageInput>)targetToRemove;
- (void)removeAllTargets;

@end

NS_ASSUME_NONNULL_END
