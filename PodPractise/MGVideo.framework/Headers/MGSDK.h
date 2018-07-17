/*!
 
 @header MGSDK.h
 
 @abstract MGVideo
 
 
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/*!
 @class
 @abstract 咪咕短视频授权类
 */
@interface MGSDK : NSObject
/*!
 @method
 @abstract 获取单例
 */
+(id) sharedInstance;
/*!
 @method
 @abstract 设置授权文件路径
 */
- (BOOL)verifySdkLicenseFile:(NSString *)licensePath;
@end
