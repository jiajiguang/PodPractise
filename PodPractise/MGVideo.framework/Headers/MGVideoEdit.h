/*!
 
 @header MGVideoEdit.h
 
 @abstract MGVideo
 
 
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MGVideoConfig.h"
#import "MGRecordDataModel.h"

/**
 *  视频特效类型
 */
typedef enum {
    /**
     *  未知
     */
    MGVideoFxType_Invalid = -1,
    /**
     *  倒放
     */
    MGVideoFxType_Reverse = 1,
    /**
     *  重复
     */
    MGVideoFxType_Repeat,
    /**
     *  慢动作
     */
    MGVideoFxType_Slow
} MGVideoFxType;

/**
 *  资源包类型
 */
typedef enum
{
    /**
     *  视频特效
     */
    MGAssetPackageType_VideoFx = 0,
    /**
     *  视频转场
     */
    MGAssetPackageType_VideoTransition,
    /**
     *  字幕样式
     */
    MGAssetPackageType_CaptionStyle,
    /**
     *  动画贴纸
     */
    MGAssetPackageType_AnimatedSticker,
    /**
     *  主题
     */
    MGAssetPackageType_Theme,
    /**
     *  拍摄场景
     */
    MGAssetPackageType_CaptureScene
} MGAssetPackageType;
//比例值
typedef struct {
    int num;    //分子
    int den;    //分母
} MGRational;

/**
 *  预览模式
 */
typedef enum {
    /**
     *  全屏预览
     */
    MGVideoPreviewSizeModeFullSize = 0,
    /**
     *  根据view大小预览
     */
    MGVideoPreviewSizeModeLiveWindowSize
} MGVideoPreviewSizeMode;
/*!
 @class
 @abstract 咪咕短视频编辑设置类。
 */
@interface MGVideoEditorSetting :NSObject
/*!
 @property
 @abstract 最大时间
 */
@property (nonatomic, assign) int maxCutDuration;
/*!
 @property
 @abstract 最小时间
 */
@property (nonatomic, assign) int minCutDuration;
/*!
 @property
 @abstract 自动播放
 */
@property (nonatomic, assign) BOOL autoplay;


@end
/*!
 @protocol
 @abstract 这个MGVideoEdit类的一个protocol
 */
@protocol MGVideoEditDelegate <NSObject>

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
 @abstract 合成视频失败
 */
- (void)didCompileError;
/*!
 @method
 @abstract 视频合成被取消
 */
- (void)didCompileisCanceled;
/*!
 @method
 @abstract 播放进度
 */
- (void)didPlaybackPosition:(int64_t)position;
/*!
 @method
 @abstract 播放到结尾回调
 */
- (void)didPlaybackEOF;
/*!
 @method
 @abstract 停止播放回调
 */
- (void)didPlaybackStopped;
/*!
 @method
 @abstract 引擎状态变化回调
 */

- (void)didEngineStateChanged:(int)state;
@end

/*!
 @class
 @abstract 咪咕短视频编辑类。
 */
@interface MGVideoEdit : NSObject
/*!
 @property
 @abstract 代理
 */
@property (nonatomic, weak) id<MGVideoEditDelegate> delegate;
/*!
 @property
 @abstract 输出视频设置，默认宽高1280、720，帧率25。请在添加视频前设置
 */
@property (nonatomic, strong) MGVideoConfig *videoConfig;
/*!
 @property
 @abstract 视频编辑设置
 */
@property (nonatomic, strong) MGVideoEditorSetting *videoEditorSetting;

/*!
 @property
 @abstract 特效的类型
 */
@property (nonatomic, assign) MGVideoFxType type;
/*!
 @method
 @abstract 获得视频列表
 */
- (NSMutableArray <MGRecordDataModel *>*)listClipData;
/*!
 @method
 @abstract 添加视频列表
 */
- (void)setClipInfoData:(NSMutableArray <MGRecordDataModel *>*)clipInfoData;

/*!
 @method
 @abstract 设置视频原音音量 默认：1 原始音量
 */
- (void)setVideoSoundVolume:(float)volume;
/*!
 @method
 @abstract 获得视频原音音量
 */
- (float)getVideoSoundVolume;

/*!
 @method
 @abstract 设置BGM声音音量
 */
- (void)setMusicSoundVolume:(float)volume;
/*!
 @method
 @abstract 获得BGM声音音量
 */
- (float)getMusicSoundVolume;
/*!
 
 @method
 @abstract 设置BGM信息
 */
- (void)setMusicInfo:(MGMusicInfo *)info;
/*!
 
 @method
 @abstract 获得BGM信息
 */
- (MGMusicInfo *)getMusicInfo;
/*!
 @method
 @abstract 是否正在预览视频
 */
- (BOOL)isPreviewing;

/*!
 @method
 @abstract 视频预览，裁剪、特效预览
 @param view 预览图层
 */
- (void)previewWithview:(UIView *)view;

/*!
 @method
 @abstract 启动视频预览
 */
- (void)startPreviewWithStartTime:(int64_t)startTime;
/*!
 @method
 @abstract 启动视频预览
 @param startTime 开始时间
 */
- (void)startPreviewWithStartTime:(int64_t)startTime rational:(const MGRational *)rational;
/*!
 @method
 @abstract 启动视频预览
 @param startTime 开始时间
 */
- (void)startPreviewWithStartTime:(int64_t)startTime videoSizeMode:(MGVideoPreviewSizeMode *)videoSizeMode;
/*!
 @method
 @abstract 停止视频预览
 */
- (void)stopPreview;


#pragma mark - 滤镜

/*!
 @method
 @abstract 获取所有滤镜名称
 @retuen    返回所有滤镜名称
 */
- (NSArray *)listAllFilterName;

/*!
 @method
 @abstract 切换滤镜 整个视频都切换滤镜效果
 @filterName 滤镜名称
 */
- (void)switchFilter:(NSString *)filterName;

#pragma mark - 滤镜特效(灵魂出窍、镜像、抖动、波浪、黑魔法、幻觉)
/*!
 @method
 @abstract 设置滤镜特效的数据
  */
- (void)setTimeFilterData:(NSMutableArray <MGTimeFilterInfoModel *>*)TimeFilterData;
/*!
 @method
 @abstract 获取滤镜特效的数据
 */
- (NSMutableArray <MGTimeFilterInfoModel *>*)listTimeFilterData;
/*!
  @method
  @abstract 设置滤镜特效的操作数据
 */
- (void)setOperateTimeFilterData:(NSMutableArray <MGTimeFilterInfoModel *>*)OperateTimeFilterData;
/*!
 @method
 @abstract 获取滤镜特效的操作数据
 */
- (NSMutableArray <MGTimeFilterInfoModel *>*)listOperateTimeFilterData;


/*!
 @method
  @abstract 设置滤镜特效时间开始播放时间与滤镜效果并且要结合stopFilter进行配合使用 不使用stopFilter默认就是到最后时间结束
  @param startPoint 初始开始播放的时间点
  @param filterCode 滤镜code
 */
- (void)startFilter:(int64_t)startPoint filterCode:(NSString *)filterCode;
/*!
  @method
  @abstract 设置滤镜特效的结束点
  @param endPoint 播放设置滤镜的时间结束点
 */
- (void)stopFilter:(int64_t)endPoint;

#pragma mark - 粒子特效
/*!
  @method
  @abstract 应用粒子特效，结束时间默认是到视频结束
 */
- (NSString *)applyMediaEffect:(int64_t)startTime particleName:(NSString *)particleName;

/*!
  @method
  @abstract 停止UUID对应的粒子特效
 */
- (BOOL)stopMediaEffect:(int64_t)endTime uuid:(NSString *)uuid;

/*!
  @method
  @abstract 跟新粒子发射点
 */
- (void)updateParticleEmitPosition:(CGPoint)point;
/*!
 @method
 @abstract 获取粒子特效数据
 */
- (NSMutableArray <MGParticleInfoModel *>*)listParticleEffectData;
/*!
 @method
 @abstract 设置粒子的数据
 */
- (void)setParticleEffectData:(NSMutableArray <MGParticleInfoModel *>*)particleArray;

/*!
 @method
 @abstract 设置粒子的操作数据
 */
- (void)setOperateParticleEffectData:(NSMutableArray <MGParticleInfoModel *>*)operateParticleData;

/*!
 @method
 @abstract 获取粒子的操作数据
 */
- (NSMutableArray <MGParticleInfoModel *>*)listOperateParticleData;
/*!
  @method
   @abstract 取消当前粒子特效
 */
- (void)unApplyMediaEffect:(NSString *)uuid;

/*!
 @method
 @abstract 判断是否为粒子特效
 */
- (BOOL)isParticleFxOfTouchType:(NSString *)packageId;
/*!
 @method
 @abstract 清除所有粒子特效
 */
- (void)removeAllMediaEffects;

#pragma mark - 场景特效(主题)
/*!
 @method
 @abstract 设置主题
 */
- (void)setTheme:(NSString *)theme;
/*!
 @method
 @abstract 获取主题
 */
- (NSString *)getTheme;
/*!
  @method
  @abstract 应用场景特效
 */
- (void)applySceneEffect:(NSString *)sceneEffectId;

/*!
  @method
   @abstract 取消场景特效
 
 */
- (void)unApplySceneEffect;

#pragma mark - 贴纸

/*!
  @method
  @abstract 应用贴纸特效,默认是开始到结束
 */
- (NSString *)applyStickerEffect:(MGStickerInfoModel *)stickerInfo;

/*!
  @method
   @abstract 取消应用贴纸特效
 */
- (void)unApplyStickerEffect:(NSString *)uuid;

/*!
 @method
 @abstract 设置贴纸的位置
 */
- (void)setStickerTranslation:(NSString *)stickerUUID point:(CGPoint)point;

/*!
 @method
 @abstract 获取贴纸的位置
 */
- (CGPoint)getStickerTranslation:(NSString *)stickerUUID;

/*!
 @method
 @abstract 设置贴纸的缩放比例
 */
- (void)scaleSticker:(NSString *)stickerUUID scale:(float)scale;

/*!
  @method
 @abstract 获取贴纸的缩放比例
 */
- (float)getStickerScale:(NSString *)stickerUUID;

/*!
 @method
 @abstract 拾取贴纸
 */
- (NSString *)selectSticker:(CGPoint)targetPoint;

/*!
  @method
 @abstract 清除所有的贴纸
 */
- (void)removeAllLiveSticker;

/*!
 
 @method
 @abstract 移除贴纸
 */
- (void)removeSticker:(NSString *)stickerUUID;

/*!
 @method
 @abstract 获取贴纸的旋转角度
 */
- (float)getStickerRotation:(NSString *)stickerUUID;
/*!
  @method
 @abstract 设置贴纸的旋转角度
 */
- (void) setStickerRotation:(NSString *)stickerUUID rotation:(float)rotation;

#pragma mark - 字幕
/*!
  @method
 @abstract 开始编辑字幕
 */
- (void)enterCaptionEdit;

/*!
  @method
 @abstract 结束编辑字幕
 */
- (void)endCaptionEdit:(BOOL)bCancel;

/*!
  @method
 @abstract 添加字幕
 */
- (NSString *)addCaption:(MGCaptionInfoModel *)info;

/*!
  @method
 @abstract 设置字幕位置
 */
- (void)setCaptionTranslation:(NSString *)captionUUID point:(CGPoint)point;

/*!
  @method
 @abstract 获取字幕位置
 */
- (CGPoint)getCaptionTranslation:(NSString *)captionUUID;
/*!
  @method
 @abstract 字幕缩放
 */
- (void)scaleCaption:(NSString *)captionUUID scaleX:(float)scaleX scaleY:(float)scaleY;

/*!

 @method
 @abstract 拾取字幕
*/
- (NSString *)selectCaption:(CGPoint)point;
/*!

 @method
 @abstract 移除字幕
*/
- (void)removeCaption:(NSString *)captionUUID;

/*!
 @method
 @abstract 获取字幕缩放的x
 */
- (float)getCaptionScaleX:(NSString *)captionUUID;

/*!
 @method
  @abstract 获取字幕缩放的y
 */
- (float)getCaptionScaleY:(NSString *)captionUUID;


/*!
 @method
 @abstract 获取字幕的旋转角度
 */
- (float) getCaptionRotation:(NSString *)captionUUID;
/*!
 @method
 @abstract 设置字幕的旋转角度
 */
- (void) setCaptionRotation:(NSString *)captionUUID rotation:(float)rotation;


/*!
 @method
 @abstract  合成视频
 */
- (void)startCompileVideo;
/*!
 @method
 @abstract  取消合成视频
 */
- (void)cancelCompileVideo;
/*!
 @method
 @abstract 定位时间线
 */
- (void)seekTimeMs:(int64_t)time;
/*!
 @method
 @abstract 根据时间获取某一帧的图像
 */
- (UIImage *)getVideoFrameWithTime:(int64_t)time;
/*!
 @method
 @abstract 获取缩略图序列的描述数组
 */
- (NSMutableArray *)listThumbnailSequenceDescArray;

/*!
 @method
 @abstract 获取时间线长度
 */
- (int64_t)getDuration;

/*!
 @method
 @abstract 获取当前时间线位置
 */
- (int64_t)getCurrentSampleTimeMs;

/*!
 @method
 @abstract 安装素材包
 */
- (BOOL)installAssetPackage:(NSString *)assetPackageFilePath license:(NSString *)licenseFilePath type:(MGAssetPackageType)type sync:(BOOL)synchronous assetPackageId:(NSMutableString *)assetPackageId;

/*!
 @method
 @abstract 重建时间线
 @return 返回成功与否
 */
- (BOOL)reloadclip;


#pragma mark - 时间特效
/*!
 @method
 @abstract 添加时间特效
 */
- (void)setTimeLineFilterInfo:(MGTimelineFilterModel *)timelineFilter;


/*!
  @method
 @abstract 重新把context的代理设为自身
 */
- (void)resetContextDelegate;

/*!
 @method
 @abstract 视图坐标转换成时间线坐标
  */
- (CGPoint)getCanonicalPoint:(CGPoint)viewPoint;
/*!
 
  @method
 @abstract 清除所有信息
 */
- (void)clearData;


#pragma mark - 配音
/*!
 @method
 @abstract 设置配音的数据
 */
- (void)setDubbingData:(NSMutableArray <MGDubbingInfoModel *>*)dubbingData;
/*!
 @method
 @abstract 获取配音的数据
 */
- (NSMutableArray <MGDubbingInfoModel *>*)listDubbingData;
/*!
 @method
 @abstract 设置音乐播放模式
 */
- (void)setMusicPlayMode:(MGMusicPlayMode)playMode;

/*!
 @method
 @abstract 清楚时间滤镜
 */
- (void)removeAllTimeFilter;

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
