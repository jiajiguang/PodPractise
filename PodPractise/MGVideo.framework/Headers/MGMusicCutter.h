/*!
 
 @header MGMusicCutter.h
 
 @abstract MGVideo
 
 
 */
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import <UIKit/UIKit.h>
/*!
 @protocol
 @abstract 这个MGMusicCutter类的一个protocol
 */
@protocol MGMusicCutterDelegate <NSObject>

/*!
 @method
 @abstract 播放进度(ms)
 @param Position 进度
 */
- (void)notifyCurrentPosition:(int)Position;
/*!
 @method
 @abstract 裁剪回调
 @param status 裁剪状态
 @param musicPath 裁剪后的音乐地址
 */
- (void)notifyCurrentStauts:(AVAssetExportSessionStatus)status  musicPath:(NSString *)musicPath;
@end
/*!
 @class
 @abstract 咪咕短视频音乐编辑类。
 */
@interface MGMusicCutter : NSObject
/*!
 @property
 @abstract 代理
 */
@property (nonatomic, weak) id<MGMusicCutterDelegate> delegate;

/*!
 @method
 @abstract 设置音乐信息
 */
- (void)setSelectedMusicWithMusicUrl:(NSString *)musicUrl startPos:(int64_t)startPos endpos:(int64_t)endpos;

/*!
 @method
 @abstract 设置裁剪的起始位置(ms)
 */
- (void)setTrimIn:(int64_t)trimIn;

/*!
 @method
 @abstract 设置裁剪的结束位置(ms)
 */
- (void)setTrimOut:(int64_t)trimOut;
/*!
 @method
 @abstract 获取未裁剪Music文件的长度(ms)
 */
- (int64_t)getDuration;

/*!
 @method
 @abstract 获取裁剪的起始位置(ms)
 */
- (int64_t)getTrimI;

/*!
 @method
 @abstract 获取裁剪的结束位置(ms)
 */
- (int64_t)getTrimOut;

/*!
 @method
 @abstract 播放音乐
 */
- (void)playMusic;

/*!
 @method
 @abstract 停止播放音乐
 */
- (void)stopMusic;
/*!
 @method
 @abstract 设置音量
 */
- (void)setVolume:(float)volume;
/*!
 @method
 @abstract 设置播放位置
 */
- (void)seekTo:(int64_t)time;
/*!
 @method
 @abstract 是否正在播放
 */
- (BOOL)isPlaying;
/*!
 @method
 @abstract 重置播放器状态
 */
- (void)reset;

/*!
 @method
 @abstract 设置是不是自动播放
 */
- (void)setAutoPlay:(BOOL)flag;

/*!
 @method
 @abstract 设置是否重复播放
 */
- (void)setLoopPlay:(BOOL)flag;
/*!
 @method
 @abstract 裁剪音乐
 */
- (void)trimingMusic;
@end
