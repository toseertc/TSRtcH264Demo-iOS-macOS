//
//  TSMVideoSourceImp.m
//  rtc_example_mac
//
//  Created by yxibng on 2020/11/30.
//

#import "TSMVideoSourceImp.h"

@implementation TSMVideoSourceImp

- (TSVideoBufferType)bufferType {
    return TSVideoBufferTypeRawData;
}

- (void)shouldDispose {
    
}

- (BOOL)shouldInitialize {
    return YES;
}

- (int)shouldStart {
    return 0;
}

- (void)shouldStop {
    return;
}

@end
