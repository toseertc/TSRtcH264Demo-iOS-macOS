//
//  TSMVideoSourceImp.h
//  rtc_example_mac
//
//  Created by yxibng on 2020/11/30.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS
#import <TSRtc_iOS/TSRtcEngineKit.h>
#import <TSRtc_iOS/TSRtcChannel.h>
#endif


#if TARGET_OS_OSX
#import <TSRtc_macOS/TSRtcEngineKit.h>
#import <TSRtc_macOS/TSRtcChannel.h>
#endif


NS_ASSUME_NONNULL_BEGIN

@interface TSMVideoSourceImp : NSObject <TSVideoSourceProtocol>
@property (strong) id<TSVideoFrameConsumer> _Nullable consumer;
@end

NS_ASSUME_NONNULL_END
