//
//  VideoChatItem.swift
//  rtc_demo_macos
//
//  Created by yxibng on 2021/1/6.
//

#if os(iOS)
import UIKit
import TSRtc_iOS

typealias VIEW_CLASS = UIView
#endif

#if os(OSX)
import Cocoa
import TSRtc_macOS

typealias VIEW_CLASS = NSView
#endif

class VideoChatItem: NSObject {

    class StreamState {
        var online = false
    }
    
    class VideoStreamState : StreamState{
        var streamName = ""
    }

    var uid: String = ""
    var isLocal: Bool = false
    var isFront:Bool! = true
    
    
    let audioState = StreamState()
    let videoState = VideoStreamState()
    
    var videoPlayView: TSVideoPlayView!
    var videoDecoder: TSVideoDecoder = TSVideoDecoder()
    
    
    override init() {
        super.init()
        self.videoDecoder.delegate = self
        self.videoPlayView = TSVideoPlayView()
    }
}

extension VideoChatItem:TSVideoDecoderDelegate {
    func videoDecoder(_ videoDecoder: TSVideoDecoder, receiveDecodedData data: UnsafeMutablePointer<UnsafeMutablePointer<UInt8>>, yuvStride: UnsafeMutablePointer<Int32>, width: Int32, height: Int32, pix_format: TSYUVType) {
        
        let stride_y:Int32 = yuvStride[0]
        let stride_u:Int32 = yuvStride[1]
        let stride_v:Int32 = yuvStride[2]
        
        let y: UnsafeMutableRawPointer = .init(data[0])
        let u: UnsafeMutableRawPointer = .init(data[1])
        let v: UnsafeMutableRawPointer = .init(data[2])
        
        self.videoPlayView.displayI420(y,
                                       u: u,
                                       v: v,
                                       stride_y: stride_y,
                                       stride_u: stride_u,
                                       stride_v: stride_v,
                                       width: width,
                                       height: height)
    }
    
}


extension VideoChatItem: TSVideoSinkProtocol {
    func shouldInitialize() -> Bool {
        return true
    }
    
    func shouldStart() -> Bool {
        return true
    }
    
    func shouldStop() {
        
    }
    
    func shouldDispose() {
        
    }
    
    func bufferType() -> TSVideoBufferType {
        return .H264
    }
    
    func pixelFormat() -> TSVideoPixelFormat {
        return .I420
    }
    
    func renderRawData(_ rawData: UnsafeMutableRawPointer, size: CGSize, pixelFormat: TSVideoPixelFormat, timestamp: Int) {
        self.videoPlayView.displayI420(rawData, frameWidth: Int32(size.width), frameHeight: Int32(size.height))
    }
        
    func renderPacket(_ packet: UnsafeMutableRawPointer, length: Int, bufferType: TSVideoBufferType, keyframe: Bool, timestamp: Int) {
        self.videoDecoder.decodeH264(packet, length: Int32(length), keyframe: keyframe, timestamp: Double(timestamp))
    }
    
}
    
