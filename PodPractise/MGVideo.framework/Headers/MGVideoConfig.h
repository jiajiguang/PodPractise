/*!
 
 @header MGVideoConfig.h
 
 @abstract MGVideo
 
 
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/*!
 @class
 @abstract 咪咕短视频视频设置类。
 */
@interface MGVideoConfig : NSObject
/*!
 @property
 @abstract 视频宽
 */
@property (nonatomic, assign) int videoWidth;
/*!
 @property
 @abstract 视频高
 */
@property (nonatomic, assign) int videoHeight;
/*!
 @property
 @abstract 视频帧率
 */
@property (nonatomic, assign) int videoFps;

@end
