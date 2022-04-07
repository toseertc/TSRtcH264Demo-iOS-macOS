//
//  TSSourceManager.h
//  rtc_demo_264_macos
//
//  Created by ding yusong on 2021/1/20.
//

#import <Foundation/Foundation.h>
#import "TSMVideoSourceImp.h"

NS_ASSUME_NONNULL_BEGIN

@interface TSSourceManager : NSObject
//自定义推流 master
@property (strong, nonatomic, readonly) TSMVideoSourceImp *masterVideoSource;
//自定义推流 master 本地预览
@property (nonatomic, strong) id<TSVideoSinkProtocol> masterVideoSink;

//预测码率，需要更新码率
- (void)onPredictedBitrate:(int)bitrate isLow:(BOOL)isLow;

- (void)start;

- (void)stop;

@end

NS_ASSUME_NONNULL_END
