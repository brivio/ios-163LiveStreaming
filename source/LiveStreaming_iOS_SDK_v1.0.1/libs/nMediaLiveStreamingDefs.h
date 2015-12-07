//
//  nMediaLiveStreamingDefs.h
//  livestream
//
//  Created by NetEase on 15/8/13.
//  Copyright (c) 2015年 NetEase. All rights reserved.
//

#ifndef livestream_nMediaLiveStreamingDefs_h
#define livestream_nMediaLiveStreamingDefs_h
/*! \file */
//直播推流采集参数
typedef enum LSVideoCodecType{
    
    H264,
    VP9,
    HEVC
    
}LSVideoCodecType;

//直播推流采集参数
typedef enum LSAudioCodecType{
    
    
    AAC,
    GIPS
    
}LSAudioCodecType;

//直播推流采集参数
typedef enum CameraOrientation{
    
    
    CameraOrientationPortrait,          //!< 摄像头采集方向.
    CameraOrientationPortraitUpsideDown,
    CameraOrientationLandscapeRight,
    CameraOrientationLandscapeLeft
    
}CameraOrientation;
/**
 *  直播视频流质量
 */
typedef enum LSVideoStreamingQuality{
    LSVideoStreamingLowQuality,     //!< 视频分辨率：低清.
    LSVideoStreamingMediumQuality,  //!< 视频分辨率：标清.
    LSVideoStreamingHighQuality,    //!< 视频分辨率：高清.
}LSVideoStreamingQuality ;

typedef enum CameraPosition{
    CameraPositionBack,         //!< 后置摄像头.
    CameraPositionFront         //!< 前置摄像头.
    
} CameraPosition;

/**
 *  直播推流视频参数
 */
typedef struct LSVideoParaCtx
{
    int fps;                                        //!< 视频的帧率.
    int bitrate;                                    //!< 码率.
    LSVideoCodecType codec;                         //!< 视频编码器.
    LSVideoStreamingQuality videoStreamingQuality;  //!< 视频分辨率.
    CameraPosition cameraPosition;                  //!< 视频采集前后摄像头.
    CameraOrientation interfaceOrientation;         //!< 视频采集方向.
    
} LSVideoParaCtx;


/**
 *  直播推流音频参数
 */
typedef struct LSAudioParaCtx
{
    int samplerate;         //!< 音频的样本采集率.
    int numOfChannels;      //!< 音频采集的通道数：单声道，双声道.
    int frameSize;          //!< 音频采集的帧大小.
    int bitrate;            //!< 音频编码码率.
    LSAudioCodecType codec; //!< 音频编码器.
    
    
} LSAudioParaCtx;


//直播推流编码发送端参数
//TODO:parameter defined, can move to another .h file,
typedef enum HardWareEncEnable
{
    HRD_NO,
    HRD_AUDIO,
    HRD_VIDEO,
    HRD_AV
}HardWareEncEnable;

typedef enum OutputFormatType{
    OUT_FMT_FLV,
    OUT_FMT_RTMP,
    
}OutputFormatType;

typedef enum OutputStreamType{
    HAVE_AUDIO,
    HAVE_VIDEO,
    HAVE_AV
}OutputStreamType;


/**
 *  直播推流参数
 */
typedef struct LSLiveStreamingParaCtx
{
    HardWareEncEnable eHaraWareEncType; //!< 是否开启硬件编码.
    OutputStreamType eOutStreamType;    //!< 推流类型：音视频，视频，音频.
    OutputFormatType eOutFormatTYpe;    //!< 推流协议：RTP,RTMP,RTSP.
    LSVideoParaCtx sLSVideoParaCtx;     //!< 推流视频相关参数.
    LSAudioParaCtx sLSAudioParaCtx;     //!< 推流音频相关参数.
    
    
} LSLiveStreamingParaCtx;

//open a interface for application layer pass parameter
typedef enum LSMediaOption{
    
    LS_OPTION_FRAME_RATE,                 //!< 设置视频采集编码帧率: MAX_FRAME_RATE = 30,MIN_FRAME_RATE = 1
    LS_OPTION_BITRATE,                    //!< 设置视频编码码率
    LS_OPTION_TRACE_LEVEL,                //!< 设置log信息的输出级别
    LS_OPTION_TRACE_CALLBACK,             //!< 设置log信息的输出回调
    LS_OPTION_GET_STATISTICS,             //!< 得到统计直播推流统计信息
    LS_OPTION_STATISTICS_LOG_INTERVAL,    //!< 设置统计信息间隔
    
}LSMediaOption;


typedef struct Statistics{
    unsigned int videoSendFrameRate;
    unsigned int videoSendBitRate;
    unsigned int videoSendWidth;
    unsigned int videoSendHeight;
    unsigned int videoSetFrameRate;
    unsigned int videoSetBitRate;
    unsigned int videoSetWidth;
    unsigned int videoSetHeight;
    unsigned int audioSendBitRate;
}Statistics;

//set trace level
typedef enum LSMediaLog {
    LS_LOG_QUIET       = 0x00,          //!< log输出模式：不输出
    LS_LOG_ERROR       = 1 << 0,        //!< log输出模式：输出错误
    LS_LOG_WARNING     = 1 << 1,        //!< log输出模式：输出警告
    LS_LOG_INFO        = 1 << 2,        //!< log输出模式：输出信息
    LS_LOG_DEBUG       = 1 << 3,        //!< log输出模式：输出调试信息
    LS_LOG_DETAIL      = 1 << 4,        //!< log输出模式：输出详细
    LS_LOG_RESV        = 1 << 5,        //!< log输出模式：保留
    LS_LOG_LEVEL_COUNT = 6,
    LS_LOG_DEFAULT     = LS_LOG_WARNING	//!< log输出模式：默认输出警告
}LSMediaLog;

//Merge from error massage update
typedef enum ErrorCode{
    ERR_NO = 0,
    ERR_ERROR,
    ERR_PARAM,
    ERR_CTX,
    ERR_ALLOC,
    ERR_CODEC_FOUND,
    ERR_INIT,
    ERR_CODEC_OPEN,
    ERR_IO,
    ERR_AGC_CREATE,
    ERR_AGC_INIT,
    ERR_AUDIO_PREPROCESS,
    ERR_AUDIO_ENCODE,
    ERR_AUDIO_PKT,
    ERR_AUDIO_RELEASE,
    ERR_VIDEO_ENCODE,
    ERR_VIDEO_PKT,
    ERR_VIDEO_RELEASE,
    ERR_TRAILER,
    ERR_OUT_MEDIA_FILEHEADER_WRONG,
    ERR_TIME_OUT,
    ERR_URL_INVALUE,
    ERR_TO_STOP_LIVESTREAMING
    
}ErrorCode;//detail error massage

#endif
