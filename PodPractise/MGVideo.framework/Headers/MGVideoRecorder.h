/*!
 
 @header MGVideoRecorder.h
 
 @abstract MGVideo
 
  
 */
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import "MGBeautyConfig.h"
#import "MGVideoSetting.h"
#import "MGRecordDataModel.h"

/**
 *  视频相机状态
 */
typedef NS_ENUM(NSInteger, CameraState)
{
    /**
     *  未知
     */
    StateUnknow = 0,
    /**
     *  开始录制
     */
    StateRecordStarting = 1,
    /**
     *  录制完成
     */
    StateRecordStarted = 2,
    /**
     *  正在拍摄
     */
    StateCapturing = 3,
    /**
     * 拍摄完成
     */
    StateCaptured
};

/**
 *  设置倍数拍摄
 */
typedef NS_ENUM(NSInteger,CameraSpeedMode){
    /**
     *  极慢 0.3
     */
    EPICSpeedMode,
    /**
     *  慢 0.5
     */
    SLOWSpeedMode,
    /**
     *  正常 1
     */
    NORMALSpeedMode,
    /**
     *  快 1.5
     */
    FASTSpeedMode,
    /**
     *  极快 3
     */
    HYPERSpeedMode
};

/**
 *  录制错误
 */
typedef NS_ENUM(NSUInteger, MGVideoRecorderError){
    /**
     *  录制片段太短
     */
    MGInvalidRecordingTime,
    /**
     *  录制文件太短
     */
    MGLessMinRecordingTime,
    /**
     *  录制文件超过最大长度
     */
    MGMoreMaxDuration,
    /**
     *  没有足够的空间
     */
    MGNotEnoughSpace,
    /**
     *  保存失败
     */
    MGSaveFailed,
    /**
     *  未知
     */
    MGUnknow
};
/*!
 @protocol
 @abstract 这个MGVideoRecorder类的一个protocol
 */
@protocol MGVideoRecorderDelegate <NSObject>
/*!
 @method
 @abstract 合成视频进度
 @param progress 对应合成的进度
 */
- (void)didCompileProgress:(int )progress;

/*!
 @method
 @abstract 合成视频结果
 @param path 视频路径
 */
- (void)didCompileOutputVideoPath:(NSString *)path;
/*!
 @method
 @abstract 录制视频成功
 @param videoModel  视频地址
 */
- (void)recordVideoSuccessWithVideoPath:(MGRecordDataModel *)videoModel;
/*!
 @method
 @abstract 正在录制的视频时长的回调接口
 @param duration  正在录制的视频时长
 */
- (void)recordingVideoDuration:(int64_t)duration;
/*!
 @method
 @abstract 录制视频失败
 @param error  错误信息
 */
- (void)recordVideoFailedWithError:(MGVideoRecorderError)error;

/*!
 @method
 @abstract 截图图片成功
 @param image  截图图片
 */
- (void)captureImageSuccessWithimage:(UIImage *)image;
/*!
 @method
 @abstract 进度和时间更新
 @param progress  录制进度
 @param durationTime  视频时长
 */
- (void)recordProgressChanged:(CGFloat)progress durationTime:(CGFloat)durationTime;

@end
/*!
 @class
 @abstract 咪咕短视频视频录制类。
 */
@interface MGVideoRecorder : NSObject

/*!
 @property
 @abstract  代理
 */
@property (weak)id<MGVideoRecorderDelegate>  delegate;
/*!
 @property
 @abstract  设置
 */
@property (nonatomic, strong) MGVideoSetting *videoSetting;
/*!
 @method
 @abstract 创建摄像头
 @param cameraView  摄像头图像
 @return MGVideoRecorder 返回单例
 */
+ (MGVideoRecorder *)creatVideoRecorderWithView:(UIView *)cameraView;

/*!
 @method
 @abstract 人脸检查数量，默认1张，最多设置8张
 */
-(void) setMaxFaces:(int) maxFaceCount;

/*!
 @method
 @abstract 开始预览
 */
- (void)startPreview;

/*!
 @method
 @abstract 停止预览
 */
- (void)stopPreview;

/*!
 @method
 @abstract 人脸贴纸
 */
- (void)setEnableLiveSticker:(BOOL)isEnable;

/*!
 @method
 @abstract 设置是否使用前置摄像头
 @param bFront 是否使用
 */
- (void)setFrontCam:(bool)bFront;

/*!
 @method
 @abstract 开始录制
 */
- (void)startRecord;

/*!
 @method
 @abstract 结束录制
 */
- (void)stopRecord;

/*!
 *  取消录制
 */
- (void)cancelRecord;

/*!
 @method
 @abstract 设置缩放因子
 @param zoom 缩放因子
 */
- (void)setZoom:(CGFloat)zoom;

/*!
 @method
 @abstract 开启闪光灯
 @param flash 开启闪光灯
 */
- (void)setFlash:(BOOL)flash;

/*!
 @method
 @abstract 判断闪光灯是否打开
 */
- (BOOL)isFlashOn;

/*!
 @method
 @abstract 删除最后一段视频
 */
- (BOOL)deleteLastRecorder;

/*!
 @method
 @abstract 删除所有片段
 */
- (BOOL)deleteAllRecorder;

/*!
 @method
 @abstract 获取Mic音量
 */
- (float)getAudioSoundGain;

/*!
 @method
 @abstract 获取摄像头的数量
 */
- (int)getCameraDeviceCount;

/*!
 @method
 @abstract 获取摄像头的录制状态
 */
- (CameraState)getCameraState;

/*!
 @method
 @abstract 获取录制的最大时间
 */
- (int)getMaxRecordingTime;

/*!
 @method
 @abstract 获取Mic采集是否静音状态
 */
- (BOOL)getMicMute;

/*!
 @method
 @abstract 获取录制的最小时间
 */
- (int)getMinRecordingTime;

/*!
 @method
 @abstract 已录制的视频总时长
 */
- (int64_t)getMovieDuration;


/*!
 @method
 @abstract 获取BGM信息
 */
- (MGMusicInfo *)getMusicInfo;

/*!
 @method
 @abstract 获取BGM音量
 */
- (float)getMusicSoundGain;

/*!
 @method
 @abstract 获取缩放因子
 */
- (float)getZoom;

/*!
 @method
 @abstract 设置Mic音量
 @param volume 取值0~1
 */
- (void)setAudioSoundGain:(float)volume;

/*!
 @method
 @abstract 设置BGM音量
 @param volume 取值0~1
 */
- (void)setMusicSoundGain:(float)volume;

/*!
 @method
 @abstract 获取录制视频片段
 */
- (NSMutableArray <MGRecordDataModel *> *)listRecorderFilePaths;

/*!
 @method
 @abstract 设置视频片段
 */
- (void)setListRecorderFile:(NSMutableArray <MGRecordDataModel *> *)recorderFileArray;

/*!
 @method
 @abstract 设置BGM信息
 */
- (void)setMusicInfo:(MGMusicInfo *)info;

/*!
 @method
 @abstract 设置倍数
 @param speedMode  速度类型
 */
- (void)setRecordSpeed:(CameraSpeedMode )speedMode;
/*!
 @method
 @abstract 合成视频
 */
- (void)compileVideo;

/*!
 @method
 @abstract 截取图片，拍照
 */
- (void)captureFrame;

/*!
 @method
 @abstract 移除所有特效
 */
- (void)removeAllCaptureVideoFilter;

/*!
 @method
 @abstract 切换滤镜
 @param code 滤镜代号，移除传nil
 @return BOOL 是否成功切换滤镜
 */
- (BOOL)switchFilter:(NSString *)code;

/*!
 @method
 @abstract 销毁
 */
- (void)destory;

/*!
 @method
 @abstract 得到所有滤镜效果名称
 */
- (NSArray *)listallfilterName;

/*!
 @method
 @abstract 设置贴纸，移除贴纸传nil
 @param path 路径
 */
- (void)showStickerPath:(NSString *)path;

/*!
 @method
 @abstract 设置美颜
 @param config 相关美颜设置
 */
- (void)setBeautyConfigWithConfig:(MGBeautyConfig *)config;

/*!
 @method
 @abstract 启动自动聚焦
 @param focusPointOfInterest 自动聚焦的目标点，坐标为实时预览窗口的自身坐标系
 */
- (void)startAutoFocus:(CGPoint)focusPointOfInterest;

/*!
 @method
 @abstract 启动自动曝光调节
 @param pointOfInterest 曝光调节点
 */
- (void)startAutoExposure:(CGPoint)pointOfInterest;

/*!
 @method
 @abstract 设置最大录制时长，大于最大时间将停止
 @param time 单位毫秒
 */
- (void)setMaxRecordingTime:(int)time;

/*!
 @method
 @abstract 设置麦克风静音
 @param mute 麦克风静音
 */
- (void)setMicMute:(BOOL)mute;

/*!
 @method
 @abstract 设置最小录制时长
 @param time 单位毫秒
 */
- (void)setMinRecordingTime:(int)time;

/*!
 @method
 @abstract 设置水印
 @param watermarkFilePath 水印地址
 @param displayWidth 水印的宽
 @param displayHeight 水印的高
 @param opacity 透明度
 @param position 0对应右上角 1左上角、2左下角、3右下角
 */
-(void)setUserWatermarkForCapture:(NSString *)watermarkFilePath
                     displayWidth:(int)displayWidth
                    displayHeight:(int)displayHeight
                          opacity:(float)opacity
                         position:(int )position;

/*!
 @method
 @abstract 移除水印
 */
-(void)removeUserWatermarkForCapture;


@end
