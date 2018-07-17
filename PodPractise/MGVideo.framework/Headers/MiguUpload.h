/*!
 
 @header MiguUpload.h
 
 @abstract MGVideo
 
 @author jiajiguang
 
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MGVideoAttributeModel.h"
/*!
 @class
 @abstract 视频上传类，需创建成为单例类
 */
@interface MiguUpload : NSObject

/*!
 @method
 @abstract 初始化sdk
 @param uid 对应开发者账户ID
 @param atoken 对应开发者账户atoken
 @param ftoken 对应开发者账户ftoken
 */
+ (void)initSdkWithUid:(NSString *)uid atoken:(NSString *)atoken ftoken:(NSString *)ftoken;

/*!
 @method
 @abstract 图片上传
 @param image 图片
 @param ugc_type 图片类型，V34、 V23、H32
 @result 返回结果
 */
+ (NSDictionary *)uploadImageWithImage:(UIImage*)image ugc_type:(NSString *)ugc_type;

/*!
 @method
 @abstract 获取单例
 @return 对象
 */
+ (MiguUpload *)shadeInstance;

/*!
 @method
 @abstract 上传
 @param params 视频相关属性
 */
- (void)uploadVideo:(UploadVideoParams *)params;

/*!
 @method
 @abstract 暂停上传
 */
- (void)pauseUpload;

/*!
 @method
 @abstract 继续上传
 */
- (void)resumeUpload;

/*!
 @method
 @abstract 取消正在上传的视频
 */
- (void)cancelUploadVideo;
@end
