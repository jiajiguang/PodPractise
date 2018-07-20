/*!
 
 @header MGAudioRecorder.h
 
 @abstract MGVideo
 
 
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MGRecordDataModel.h"


/**
 *  音频录制状态
 */
typedef NS_ENUM(NSInteger, AudioRecorderState)
{
    /**
     *  完成
     */
    AudioRecorderStateFinish = 0,
    /**
     *  正在录制
     */
    AudioRecorderStateRecording = 1
    
};
/*!
 @protocol
 @abstract 这个MGAudioRecorder类的一个protocol
 */
@protocol MGAudioRecorderDelegate <NSObject>

@optional

/*!
 @method
 @abstract 录制完成
 @param audioPath 音频路径
 */
- (void)audioRecorderFinish:(NSString *)audioPath;

/*!
 @method
 @abstract 录制出错
 */
- (void)audioRecorderError;

/*!
 @method
 @abstract 录制状态
 */
- (void)audioRecorderState:(AudioRecorderState )state;

/*!
 @method
 @abstract 录制时长
 @param duration 时长，毫秒
 */
- (void)audioRecorderDuration:(int )duration;


@end

/*!
 @class
 @abstract 咪咕短视频音频录制类
 */
@interface MGAudioRecorder : NSObject

/*!
 @property
 @abstract 代理
 */
@property (nonatomic, weak) id<MGAudioRecorderDelegate> delegate;

/*!
 @method
 @abstract 开始录制
 */
- (void)startRecorder;

/*!
 @method
 @abstract 结束录制
 */
- (void)stopRecorder;

/*!
 @method
 @abstract 是否正在录制
 */
- (BOOL)isRecording;
/*!
 @method
 @abstract 设置配音数据
 */
- (void)setDubbingData:(NSMutableArray <MGDubbingInfoModel *>*)audioArray;
/*!
 @method
 @abstract 获得配音数据
 */
- (NSMutableArray <MGDubbingInfoModel *>*)listDubbingData;
/*!
 @method
 @abstract 设置配音操作数据
 */
- (void)setOperateDubbingData:(NSMutableArray <MGDubbingInfoModel *>*)audioOperateArray;
/*!
 @method
 @abstract 获得配音操作数据
 */
- (NSMutableArray <MGDubbingInfoModel *>*)listOperateDubbingData;
@end
