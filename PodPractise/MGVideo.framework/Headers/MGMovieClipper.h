/*!
 
 @header MGMovieClipper.h
 
 @abstract MGVideo
 
 
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MGRecordDataModel.h"

/**
 *  文件类型
 */
typedef enum : NSUInteger {
    /**
     *  视频
     */
    MGMovieClipperTypeVideo,
    /**
     *  音频
     */
    MGMovieClipperTypeAudio,
}MGMovieClipperType;

/**
 *  生成视频类型
 */
typedef enum : NSUInteger {
    /**
     *  全I帧视频
     */
    MGCompileTypeIFrame = 0,
    /**
     *  普通视频
     */
    MGCompileTypeNormal,
}MGComplieType;

/*!
 @protocol
 @abstract 这个MGMediaTrimmer类的一个protocol
 */
@protocol MGMovieClipperDelegate <NSObject>

/*!
 @method
 @abstract 裁剪视频进度
 @param progress 对应合成的进度
 */
- (void)didTrimmerProgress:(int )progress;

/*!
 @method
 @abstract 裁剪视频结果
 @param path 视频路径
 */
- (void)didTrimmerOutputVideoPath:(NSString *)path;

/*!
 @method
 @abstract 裁剪视频失败
 */
- (void)didTrimmerError;

/*!
 @method
 @abstract 播放结束
 */
- (void)playFinish;

/*!
 @method
 @abstract 播放位置
 @param position 播放位置,单位毫秒
 */
- (void)didPlayPosition:(int64_t)position;

/*!
 @method
 @abstract 播放停止
 */
- (void)playStopped;
@end

/*!
 @class
 @abstract 咪咕短视频裁剪类
 */
@interface MGMovieClipper : NSObject

/*!
 @property
 @abstract 代理
 */
@property (nonatomic, weak) id<MGMovieClipperDelegate> delegate;



/*!
 @method
 @abstract 裁剪文件
 @param trimIn 片段裁剪入点（单位毫秒）
 @param trimOut 片段裁剪出点（单位毫秒）
 */
- (void)settrimIn:(int64_t)trimIn trimOut:(int64_t)trimOut;

/*!
 @method
 @abstract 设置视频路径
 @param time 时间，单位：毫秒
 */
- (UIImage *)getVideoFrameWithTime:(int64_t)time;

/*!
 @method
 @abstract 开始裁剪视频
 */
- (void)doMovieClipping:(MGComplieType)compileType;

/*!
 @method
 @abstract 视频预览，裁剪、特效预览
 @param view 预览图层
 */
- (void)previewWithview:(UIView *)view;

/*!
 @method
 @abstract 播放
 @param startTime 开始时间，单位毫秒
 */
- (void)startPreviewWithStartTime:(int64_t)startTime;

/*!
 @method
 @abstract 暂停播放
 */
- (void)stop;

/*!
 @method
 @abstract 返回片段的封面信息
 */
- (NSArray *)getClipCoverArray;

/*!
 @method
 @abstract 定位时间线，单位毫秒
 */
- (void)seekTimeMs:(int64_t)time;

/*!
 @method
 @abstract 获取当前时间线位置
 */
- (int64_t)getCurrentSampleTimeMs;

/*!
 @method
 @abstract 获取缩略图信息数组
 */
- (NSMutableArray *)listThumbnailSequenceDescArray;

/*!
 @method
 @abstract 获取时长
 */
- (int64_t)getDuration;

/*!
 @method
 @abstract 设置当前片段信息
 */
- (void)setClipInfo:(int)index clipInfo:(MGRecordDataModel *)clipInfo;

/*!
 @method
 @abstract 移除当前片段
 */
- (void)removeClip:(int)index;

/*!
 @method
 @abstract 是否正在预览视频
 */
- (BOOL)isPreviewing;
/*!
 @method
 @abstract 获取裁剪的素材片段列表
 */
- (NSMutableArray <MGRecordDataModel *>*)getClipInfoData;

/*!
 @method
 @abstract 设置要裁剪的素材片段列表
 */
- (BOOL)setClipInfoData:(NSMutableArray <MGRecordDataModel *>*)clipInfo;

/*!
 @method
 @abstract 根据片段的索引,获取片段的起始时间
 */
- (int64_t)getTimePositionFromClipIndex:(int)index;

/*!
 @method
 @abstract 根据时间点获取片段的信息(ms)
 */
- (MGRecordDataModel *)getClipInfoFromTime:(long)time;

@end

