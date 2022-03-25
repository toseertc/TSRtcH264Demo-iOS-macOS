//
//  TSVideoDecoder.h
//  ffmpeg-demo
//
//  Created by yxibng on 2021/1/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


#define kYUVElementMaxCount 8

typedef enum : NSUInteger {
    TSYUVTypeNV12,//2 平面
    TSYUVTypeI420,//3 平面
} TSYUVType;

@class TSVideoDecoder;
@protocol TSVideoDecoderDelegate <NSObject>

- (void)videoDecoder:(TSVideoDecoder *)videoDecoder
  receiveDecodedData:(uint8_t *_Nonnull*_Nonnull)data
           yuvStride:(int *)yuvStride
               width:(int)width
              height:(int)height
          pix_format:(TSYUVType)pix_format;

@end


@interface TSVideoDecoder : NSObject


@property (nonatomic, weak) id<TSVideoDecoderDelegate>delegate;

- (instancetype)initWithDelegate:(id<TSVideoDecoderDelegate>)delegate;

- (void)decodeH264:(void *)packet length:(int)length keyframe:(BOOL)keyframe timestamp:(NSTimeInterval)timestamp;

@end

NS_ASSUME_NONNULL_END
