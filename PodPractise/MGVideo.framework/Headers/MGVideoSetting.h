/*!
 
 @header MGVideoSetting.h
 
 @abstract MGVideo
 
 
 */
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
/**
 *  预览模式
 */
typedef enum : NSUInteger {
    
    /**
     *  普通
     */
    NORMAL,
    
    /**
     *  人脸
     */
    AR_FACE,
    
    /**
     *  滤镜
     */
    FILTER,
    
    /**
     *  全部
     */
    ALL
} PreviewFlag;

/**
 *  分辨率
 */
typedef enum {
    
    /**
     *  前置480、后置540
     */
    MGVideoCaptureResolutionGradeLow = 0,
    
    /**
     *  前置540、后置720
     */
    MGVideoCaptureResolutionGradeMedium,
    
    /**
     *  前置720、后置1080
     */
    MGVideoCaptureResolutionGradeHigh
} MGVideoCaptureResolutionGrade;
/*!
 @class
 @abstract 咪咕短视频视频参数类。
 */
@interface MGVideoSetting : NSObject
/*!
 @property
 @abstract 模式,默认ALL
 */
@property (nonatomic, assign) PreviewFlag flag;
/*!
 @property
 @abstract 视频帧率,默认25
 */
@property (nonatomic, assign) int fps;
/*!
 @property
 @abstract 视频码率 默认10 000 000
 */
@property (nonatomic, assign) int videoBitrate;
/*!
 @property
 @abstract 最大录制时长 毫秒
 */
@property (nonatomic, assign) int64_t maxRecordingTime;
/*!
 @property
 @abstract 最小录制时长 毫秒
 */
@property (nonatomic, assign) int64_t minRecordingTime;
/*!
 @property
 @abstract 每段最小拍摄时长 300毫秒
 */
@property (nonatomic, assign) int mMinRecorderSegment;
/*!
 @property
 @abstract 设置前后摄像头，YES前置、NO后置，默认YES
 */
@property (nonatomic, assign) BOOL frontCam;
/*!
 @property
 @abstract 设置视频的分辨率,默认高
 */
@property (nonatomic, assign) MGVideoCaptureResolutionGrade resolutionGrade;
/*!
 @method
 @abstract 获取单例
 */
+(id) sharedInstance;

@end
