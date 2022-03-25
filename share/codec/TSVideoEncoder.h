//
//  TSVideoEncoder.h
//  ffmpeg-demo
//
//  Created by yxibng on 2021/1/19.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>

NS_ASSUME_NONNULL_BEGIN


@class TSVideoEncoder;


@interface TSVideoEncodeConfig : NSObject

//default 15
@property (nonatomic, assign) int fps;

//defaut is captured size
@property (nonatomic, assign) CGSize dimension;


@end


@protocol TSVideoEncoderDelegate <NSObject>

- (void)videoEncoder:(TSVideoEncoder *)videoEncoder
       didEncodeH264:(void *)h264Data
          dataLength:(int)length
          isKeyFrame:(BOOL)isKeyFrame
           timestamp:(NSTimeInterval)timestamp;

@end


@interface TSVideoEncoder : NSObject

@property (nonatomic, weak) id<TSVideoEncoderDelegate>delegate;


@property (strong ,nonatomic, readonly) TSVideoEncodeConfig *encodeConfig;

- (instancetype)initWithDelegate:(id<TSVideoEncoderDelegate>)delegate;
- (void)encodeNv12PixelBuffer:(CVPixelBufferRef)pixelBuffer timestamp:(NSTimeInterval)timestamp;

@end

NS_ASSUME_NONNULL_END
