/*!
 
 @header MGBeautyConfig.h
 
 @abstract MGVideo
 
 
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/*!
 @class
 @abstract 咪咕短视频美颜类。
 */
@interface MGBeautyConfig : NSObject

/*!
 @property
 @abstract 磨皮，0~1 默认0.5
 */
@property (nonatomic, assign) double strength;

/*!
 @property
 @abstract 亮度，0~1 默认0.5
 */
@property (nonatomic, assign) double whitening;

/*!
 @property
 @abstract 红润，0~1 默认0.5
 */
@property (nonatomic, assign) double reddening;

/*!
 @property
 @abstract 基本脸型程度，0~1 默认0.5
 */
@property (nonatomic, assign) double faceShapeLevel;

/*!
 @property
 @abstract 瘦脸，用于控制脸型大小，0~1 默认0.5
 */
@property (nonatomic, assign) double cheekThinning;

/*!
 @property
 @abstract 大眼，用于控制眼睛大小，0~1 默认0.5
 */
@property (nonatomic, assign) double eyeEnlarging;

@end

