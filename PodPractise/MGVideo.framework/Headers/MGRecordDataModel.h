/*!
 
 @header MGRecordDataModel.h
 
 @abstract MGVideo
 
 
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/*!
 @class
 @abstract 咪咕短视频录制参数类。
 */
@interface MGRecordDataModel : NSObject
/*!
 @property
 @abstract 录制视频文件路径
 */
@property(strong, nonatomic) NSString *recordVideoPath;
/*!
 @property
 @abstract 录制片段的倍速
 */
@property(assign, nonatomic) float speed;
/*!
 @property
 @abstract 裁剪入点
 */
@property(assign, nonatomic) int64_t trimIn;
/*!
 @property
 @abstract 裁剪出点
 */
@property(assign, nonatomic) int64_t trimOut;
/*!
 @property
 @abstract 时长
 */
@property(assign, nonatomic) int64_t duration;
/*!
 @property
 @abstract 音量
 */
@property(assign, nonatomic) float volume;
/*!
 @property
 @abstract 静音
 */
@property (nonatomic, assign) BOOL mute;

@end
/*!
 @class
 @abstract 咪咕短视频文字参数类。
 */
@interface MGCaptionInfoModel : NSObject
/*!
 @property
 @abstract 文字
 */
@property (nonatomic, strong) NSString *text;
/*!
 @property
 @abstract 颜色
 */
@property (nonatomic, strong) UIColor *color;
/*!
 @property
 @abstract 位置
 */
@property (nonatomic, assign) CGPoint anchorPoint;
/*!
 @property
 @abstract 旋转角度
 */
@property (nonatomic, assign) CGFloat rotation;
/*!
 @property
 @abstract 缩放
 */
@property (nonatomic, assign) CGFloat scale;
/*!
 @property
 @abstract 字体大小
 */
@property (nonatomic, assign) CGFloat fontSize;
/*!
 @property
 @abstract 平移
 */
@property (nonatomic, assign) CGPoint translation;
/*!
 @property
 @abstract uuid
 */
@property (nonatomic, strong) NSString *uuid;
/*!
 @property
 @abstract 类型
 */
@property (nonatomic, strong) NSString *styleId;

@end

/*!
 @class
 @abstract 咪咕短视频贴纸参数类。
 */
@interface MGStickerInfoModel : NSObject
/*!
 @property
 @abstract 锚点
 */
@property (nonatomic, assign) CGPoint anchor;
/*!
 @property
 @abstract 旋转角度
 */
@property (nonatomic, assign) CGFloat rotation;
/*!
 @property
 @abstract 缩放
 */
@property (nonatomic, assign) CGFloat scale;
/*!
 @property
 @abstract 平移
 */
@property (nonatomic, assign) CGPoint translation;
/*!
 @property
 @abstract 包id
 */
@property (nonatomic, strong) NSString *packageId;
/*!
 @property
 @abstract uuid
 */
@property (nonatomic, strong) NSString *uuid;

@end

/*!
 @class
 @abstract 咪咕短视频粒子参数类。
 */
@interface MGParticleInfoModel : NSObject
/*!
 @property
 @abstract 名称
 */
@property (nonatomic, strong) NSString *name;
/*!
 @property
 @abstract 入点
 */
@property (nonatomic, assign) int64_t inPoint;
/*!
 @property
 @abstract 出点
 */
@property (nonatomic, assign) int64_t outPoint;
/*!
 @property
 @abstract 粒子特效位置数组
 */
@property (nonatomic, strong) NSMutableArray *particleLocation;
/*!
 @property
 @abstract 发射器名字
 */
@property (nonatomic, strong) NSMutableArray *emitterName;
/*!
 @property
 @abstract 粒子发射速率
 */
@property (nonatomic, assign) float particleRateValue;
/*!
 @property
 @abstract 粒子大小
 */
@property (nonatomic, assign) float particleSizeValue;
/*!
 @property
 @abstract uuid
 */
@property (nonatomic, strong) NSString *uuid;

@end
/*!
 @class
 @abstract 咪咕短视频滤镜参数类。
 */
@interface MGTimeFilterInfoModel : NSObject
/*!
 @property
 @abstract 入点
 */
@property (nonatomic, assign) int64_t inPoint;
/*!
 @property
 @abstract 出点
 */
@property (nonatomic, assign) int64_t outPoint;
/*!
 @property
 @abstract 名称
 */
@property (nonatomic, strong) NSString *name;
/*!
 @property
 @abstract 是否倒放
 */
@property (assign, nonatomic) BOOL addInReverseMode;

@end
/*!
 @class
 @abstract 咪咕短视频配音参数类。
 */
@interface MGDubbingInfoModel : NSObject
/*!
 @property
 @abstract 配音文件
 */
@property (nonatomic, strong) NSString *dubbingFilePath;
/*!
 @property
 @abstract 入点
 */
@property (nonatomic, assign) int64_t inPoint;
/*!
 @property
 @abstract 文件时长
 */
@property (nonatomic, assign) int64_t duration;
/*!
 @property
 @abstract 速度
 */
@property (nonatomic, assign) float speed;
/*!
 @property
 @abstract 音量
 */
@property (nonatomic, assign) float volume;     

@end

/**
 *  音频播放状态
 */
typedef NS_ENUM (NSInteger,MGPlayState){
    /**
     *  暂停
     */
    MGPause,
    /**
     *  正在播放
     */
    MGPlaying
};
/*!
 @class
 @abstract 咪咕短视频BGM参数类。
 */
@interface MGMusicInfo : NSObject
/*!
 @property
 @abstract BGM地址
 */
@property (nonatomic, strong) NSString *musicPath;
/*!
 @property
 @abstract 入点
 */
@property (nonatomic, assign) int64_t trimIn;
/*!
 @property
 @abstract 出点
 */
@property (nonatomic, assign) int64_t trimOut;
/*!
 @property
 @abstract 时长
 */
@property (nonatomic, assign) int64_t duration;
/*!
 @property
 @abstract 声音
 */
@property (nonatomic, assign) float volume;
/*!
 @property
 @abstract 音乐名称
 */
@property (nonatomic, strong) NSString *musicName;
/*!
 @property
 @abstract 歌手名称
 */
@property (nonatomic, strong) NSString *musicAuthorName;
/*!
 @property
 @abstract 歌曲封面
 */
@property (nonatomic, strong) UIImage *musicCoverImage;
/*!
 @property
 @abstract 播放状态
 */
@property (nonatomic, assign) MGPlayState playState;
/*!
 @property
 @abstract 是否可编辑
 */
@property (nonatomic, assign) BOOL isShowEdit;

@end
/*!
 @class
 @abstract 咪咕短视频滤镜特效参数类。
 */
@interface MGTimelineFilterModel : NSObject
/*!
 @property
 @abstract 滤镜特效模式（倒放，反复，慢动作）
 */
@property(assign, nonatomic) int timelineFxMode;
/*!
 @property
 @abstract 时间线位置（ms）
 */
@property(assign, nonatomic) int64_t timelineFxPosition;
/*!
 @property
 @abstract 慢动作和反复持续时间（ms）
 */
@property (nonatomic, assign) int64_t timelineFxDuration;

@end

/**
 *  音频播放模式
 */
typedef enum {
    /**
     *  重复
     */
    MGMusicPlayRepeat = 0,
    /**
     *  普通
     */
    MGMusicPlayNormal
} MGMusicPlayMode;
