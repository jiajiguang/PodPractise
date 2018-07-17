/*!
 
 @header MGVideoImageExtractor.h
 
 @abstract MGVideo
 
 
 */
#import <Foundation/Foundation.h>
#import "MGRecordDataModel.h"
#import <UIKit/UIKit.h>

/*!
 @protocol
 @abstract 这个MGVideoImageExtractor类的一个protocol
 */
@protocol MGVideoImageExtractorDelegate<NSObject>

/*!
 @method
 @abstract 抽帧结果
 @param image 抽取结果
 */
- (void)drawingFrameResultWithImages:(UIImage *)image;

@end

/*!
 @class
 @abstract 咪咕短视频视频抽帧类。
 */
@interface MGVideoImageExtractor : NSObject

/*!
 @property
 @abstract 代理
 */
@property (nonatomic, weak) id<MGVideoImageExtractorDelegate> delegate;

/*!
 @property
 @abstract 设置输出视频宽高，默认80*80
 */
@property (nonatomic, assign) CGSize imageSize;

/*!
 @property
 @abstract 设置抽帧的时间间隔，单位毫秒
 */
@property (nonatomic, assign) float extractFrameInterval;

/*!
 @property
 @abstract 设置抽帧的数量
 */
@property (nonatomic, assign) int extractFrameCount;

/*!
 @method
 @abstract 设置视频
 @param videoList 视频列表
 */
- (void)videoList:(NSMutableArray <MGRecordDataModel *> *)videoList;

/*!
 @method
 @abstract 同步抽帧
 @return 返回UIImage数组
 */
- (NSMutableArray <UIImage *> *)syncExtractImageList:(int64_t)startTime endTime:(int64_t)endTime;

/*!
 @method
 @abstract 异步抽帧，通过MGVideoImageExtractorDelegate返回结果
 @param startTime 开始时间，单位毫秒
 @param endTime 结束时间，单位毫秒
 */
- (void)asyncExtractImageList:(int64_t)startTime endTime:(int64_t)endTime;

/*!
 @method
 @abstract 抽帧
 @param time 时间，单位：毫秒
 */
- (UIImage *)getVideoFrameWithTime:(int64_t)time;

@end
